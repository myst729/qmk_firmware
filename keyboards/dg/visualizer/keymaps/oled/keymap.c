#include <sys/time.h>
#include "fft.h"
#include "analog.h"

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(RGB_TOG, RGB_MOD, RGB_RMOD)
};

// MIC
#define FFT_ANALOG_PIN A0
#define FFT_SAMPLES 1024 // power of 2
#define FFT_SAMPLING_FREQ 30000 // 15 kHz Fmax = sampleF /2 
#define FFT_AMPLITUDE 100 // sensitivity
#define FFT_FREQUENCY_BANDS 54

// OLED
#define OLED_SCREEN_WIDTH 128
#define OLED_SCREEN_HEIGHT 32
#define OLED_BAR_WIDTH 2
#define OLED_BAR_GAP 1
#define OLED_BARS 43

// adjust reference to get remove background noise
float reference = log10(50.0);
unsigned long samplingPeriod;
double cutoffFrequencies[FFT_FREQUENCY_BANDS];
double vReal[FFT_SAMPLES];
double vImag[FFT_SAMPLES];
uint8_t power;

int oldHeight[60];
int oldMax[60];

long dg_micros(void) {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void dg_yield(void) {
  // do nothing
}

void dg_oled_fill_rect_raw (uint8_t x, uint8_t y, uint8_t width, uint8_t height, const char data) {
  for (int v = y; v < y + height; v++) {
    for (int h = x; h < x + width; h++) {
      oled_write_raw_byte(data, v * OLED_SCREEN_WIDTH + h);
    }
  }
}

void dg_oled_fill_rect (uint8_t x, uint8_t y, uint8_t width, uint8_t height, bool on) {
  for (int v = y; v < y + height; v++) {
    for (int h = x; h < x + width; h++) {
      oled_write_pixel(h, v, on);
    }
  }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  power = fft_exponent(FFT_SAMPLES);
  samplingPeriod = (1.0 / FFT_SAMPLING_FREQ ) * pow(10.0, 6);

  // Calculate cutoff frequencies, make a logarithmic scale base
  double basePot = pow(FFT_SAMPLING_FREQ / 2.0, 1.0 / FFT_FREQUENCY_BANDS);
  for (int i = 0; i < FFT_FREQUENCY_BANDS; i++) {
    cutoffFrequencies[i] = pow(basePot, i + 1);
  }

  dg_oled_fill_rect(0, 0, OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, false);
  return rotation;
}

bool oled_task_user (void) {
  // take samples
  for (int i = 0; i < FFT_SAMPLES; i++) {
    unsigned long currentTime = dg_micros();
    int value = analogReadPin(FFT_ANALOG_PIN);
    vReal[i] = value;
    vImag[i] = 0;
    while (dg_micros() < (currentTime + samplingPeriod)) {
      dg_yield();
    }
  }

  // compute FFT
  fft_dc_removal(vReal, FFT_SAMPLES);
  fft_windowing(vReal, FFT_SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  fft_compute(vReal, vImag, FFT_SAMPLES, power, FFT_FORWARD);
  fft_complex_to_magnitude(vReal, vImag, FFT_SAMPLES);

  double median[60];
  double max[60];
  int index = 0;
  double hzPerSample = (1.0 * FFT_SAMPLING_FREQ) / FFT_SAMPLES;
  double hz = 0;
  double maxinband = 0;
  double sum = 0;
  int count = 0;
  for (int i = 2; i < (FFT_SAMPLES / 2) ; i++) {
    count++;
    sum += vReal[i];
    if (vReal[i] > max[index]) {
      max[index] = vReal[i];
    }
    if (hz > cutoffFrequencies[index]) {
      median[index] = sum / count;
      sum = 0.0;
      count = 0;
      index++;
      max[index] = 0;
      median[index] = 0;
    }
    hz += hzPerSample;
  }

  // calculate median and maximum per frequency band
  if (sum > 0.0) {
    median[index] = sum / count;
    if (median[index] > maxinband) {
      maxinband = median[index];
    }
  }

  dg_oled_fill_rect(0, 0, OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, false);
  int bar = 0;

  for (int i = FFT_FREQUENCY_BANDS - 1; i > 10; i--) {
    int newHeight = 0;
    int newMax = 0;
    // calculate actual decibels
    if (median[i] > 0 && max[i] > 0) {
      newHeight = 20.0 * (log10(median[i]) - reference);
      newMax = 20.0 * (log10(max[i]) - reference);
    }

    // adjust minimum and maximum levels
    if (newHeight < 0 || newMax < 0) {
      newHeight = 1;
      newMax = 1;
    }
    if (newHeight >= OLED_SCREEN_HEIGHT - 2) {
      newHeight = OLED_SCREEN_HEIGHT - 3;
    }
    if (newMax >= OLED_SCREEN_HEIGHT - 2) {
      newMax = OLED_SCREEN_HEIGHT - 3;
    }

    int barX = bar * (OLED_BAR_WIDTH + OLED_BAR_GAP);
    // // remove old level median
    // if (oldHeight[i] > newHeight) {
    //   dg_oled_fill_rect(barX, newHeight + 1, OLED_BAR_WIDTH, oldHeight[i], false);
    // }
    // // remove old max level
    // if (oldMax[i] > newHeight) {
    //   for (int j = oldMax[i]; j > newHeight; j -= 2) {
    //     dg_oled_fill_rect(barX, j, OLED_BAR_WIDTH, 1, false);
    //   }
    // }

    // paint new max level
    for (int j = newMax; j > newHeight; j -= 2) {
      dg_oled_fill_rect(barX, j, OLED_BAR_WIDTH, 1, true);
    }
    // paint new level median
    dg_oled_fill_rect(barX, 1, OLED_BAR_WIDTH, newHeight, true);

    oled_render();

    oldMax[i] = newMax;
    oldHeight[i] = newHeight;
    bar++;
  }
  return false;
}
