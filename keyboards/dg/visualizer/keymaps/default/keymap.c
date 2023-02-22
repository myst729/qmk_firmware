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
#define FFT_FREQUENCY_BANDS 10

// RGB
#define RGB_HEIGHT 6
#define RGB_WIDTH 6

// adjust reference to get remove background noise
float reference = log10(50.0);
unsigned long samplingPeriod;
double cutoffFrequencies[FFT_FREQUENCY_BANDS];
double vReal[FFT_SAMPLES];
double vImag[FFT_SAMPLES];
uint8_t power;

int oldHeight[20];
int oldMax[20];

uint8_t my_hues[] = { 0, 43, 85, 128, 170, 213 };

long dg_micros(void) {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void dg_yield(void) {
  // do nothing
}

void matrix_init_user(void) {
  power = fft_exponent(FFT_SAMPLES);
  samplingPeriod = (1.0 / FFT_SAMPLING_FREQ ) * pow(10.0, 6);

  // Calculate cutoff frequencies, make a logarithmic scale base
  double basePot = pow(FFT_SAMPLING_FREQ / 2.0, 1.0 / FFT_FREQUENCY_BANDS);
  for (int i = 0; i < FFT_FREQUENCY_BANDS; i++) {
    cutoffFrequencies[i] = pow(basePot, i + 1);
  }
}

void matrix_scan_user(void) {
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

  double median[20];
  double max[20];
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

  int rgbCol = 0;

  for (int i = FFT_FREQUENCY_BANDS - 4; i > 0; i--) {
    int newHeight = 0;
    int newMax = 0;
    // calculate actual decibels
    if (median[i] > 0 && max[i] > 0) {
      newHeight = 6.0 * (log10(median[i]) - reference);
      newMax = 6.0 * (log10(max[i]) - reference);
    }

    // adjust minimum and maximum levels
    if (newHeight < 0 || newMax < 0) {
      newHeight = 0;
      newMax = 0;
    }
    if (newHeight > RGB_HEIGHT) {
      newHeight = RGB_HEIGHT;
    }
    if (newMax > RGB_HEIGHT) {
      newMax = RGB_HEIGHT;
    }

    // turn off the whole column of RGBs
    for (int l = 0; l < 6; l++) {
      int led_index = rgbCol * 6 + l;
      if (newMax < l + 1) {
        sethsv(HSV_OFF, (LED_TYPE *)&led[led_index]);
      } else if (newHeight < l + 1) {
        uint8_t max_val = 255 * newHeight / (l + 1);
        sethsv(my_hues[rgbCol], 255, max_val, (LED_TYPE *)&led[led_index]);
      } else {
        sethsv(my_hues[rgbCol], 255, 255, (LED_TYPE *)&led[led_index]);
      }
    }

    oldMax[i] = newMax;
    oldHeight[i] = newHeight;
    rgbCol++;
  }

  rgblight_set();
}
