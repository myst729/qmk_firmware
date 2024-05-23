#include "fft.h"

uint8_t fft_revision(void) {
  return(FFT_LIB_REV);
}

uint8_t fft_exponent(uint16_t value) {
  // Calculates the base 2 logarithm of a value
  uint8_t result = 0;
  while (((value >> result) & 1) != 1) result++;
  return(result);
}

void fft_parabola(double x1, double y1, double x2, double y2, double x3, double y3, double *a, double *b, double *c) {
  double reversed_denom = 1 / ((x1 - x2) * (x1 - x3) * (x2 - x3));
  *a = (x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2)) * reversed_denom;
  *b = (x3 * x3 * (y1 - y2) + x2 * x2 * (y3 - y1) + x1*x1 * (y2 - y3)) * reversed_denom;
  *c = (x2 * x3 * (x2 - x3) * y1 + x3 * x1 * (x3 - x1) * y2 + x1 * x2 * (x1 - x2) * y3) * reversed_denom;
}

void fft_swap(double *x, double *y) {
  double temp = *x;
  *x = *y;
  *y = temp;
}

void fft_compute(double *vReal, double *vImag, uint16_t samples, uint8_t power, uint8_t dir) {
  // Computes in-place complex-to-complex FFT
  // Reverse bits
  uint16_t j = 0;
  for (uint16_t i = 0; i < (samples - 1); i++) {
    if (i < j) {
      fft_swap(&vReal[i], &vReal[j]);
      if(dir == FFT_REVERSE)
        fft_swap(&vImag[i], &vImag[j]);
    }
    uint16_t k = (samples >> 1);
    while (k <= j) {
      j -= k;
      k >>= 1;
    }
    j += k;
  }
  // Compute the FFT
  double c1 = -1.0;
  double c2 = 0.0;
  uint16_t l2 = 1;
  for (uint8_t l = 0; (l < power); l++) {
    uint16_t l1 = l2;
    l2 <<= 1;
    double u1 = 1.0;
    double u2 = 0.0;
    for (j = 0; j < l1; j++) {
       for (uint16_t i = j; i < samples; i += l2) {
          uint16_t i1 = i + l1;
          double t1 = u1 * vReal[i1] - u2 * vImag[i1];
          double t2 = u1 * vImag[i1] + u2 * vReal[i1];
          vReal[i1] = vReal[i] - t1;
          vImag[i1] = vImag[i] - t2;
          vReal[i] += t1;
          vImag[i] += t2;
       }
       double z = ((u1 * c1) - (u2 * c2));
       u2 = ((u1 * c2) + (u2 * c1));
       u1 = z;
    }
    c2 = sqrt((1.0 - c1) / 2.0);
    c1 = sqrt((1.0 + c1) / 2.0);
    if (dir == FFT_FORWARD) {
      c2 = -c2;
    }
  }
  // Scaling for reverse transform
  if (dir != FFT_FORWARD) {
    for (uint16_t i = 0; i < samples; i++) {
       vReal[i] /= samples;
       vImag[i] /= samples;
    }
  }
}

void fft_complex_to_magnitude(double *vReal, double *vImag, uint16_t samples) {
  // vM is half the size of vReal and vImag
  for (uint16_t i = 0; i < samples; i++) {
    vReal[i] = sqrt(pow(vReal[i], 2) + pow(vImag[i], 2));
  }
}

void fft_dc_removal(double *vData, uint16_t samples) {
  // calculate the mean of vData
  double mean = 0;
  for (uint16_t i = 0; i < samples; i++) {
    mean += vData[i];
  }
  mean /= samples;
  // Subtract the mean from vData
  for (uint16_t i = 0; i < samples; i++) {
    vData[i] -= mean;
  }
}

void fft_windowing(double *vData, uint16_t samples, uint8_t windowType, uint8_t dir) {
  // Weighing factors are computed once before multiple use of FFT
  // The weighing function is symmetric; half the weighs are recorded
  double samplesMinusOne = (double)samples - 1.0;
  for (uint16_t i = 0; i < (samples >> 1); i++) {
    double indexMinusOne = (double)i;
    double ratio = (indexMinusOne / samplesMinusOne);
    double weighingFactor = 1.0;
    // Compute and record weighting factor
    switch (windowType) {
    case FFT_WIN_TYP_RECTANGLE: // rectangle (box car)
      weighingFactor = 1.0;
      break;
    case FFT_WIN_TYP_HAMMING: // hamming
      weighingFactor = 0.54 - (0.46 * cos(TWO_PI * ratio));
      break;
    case FFT_WIN_TYP_HANN: // hann
      weighingFactor = 0.54 * (1.0 - cos(TWO_PI * ratio));
      break;
    case FFT_WIN_TYP_TRIANGLE: // triangle (Bartlett)
      weighingFactor = 1.0 - ((2.0 * abs(indexMinusOne - (samplesMinusOne / 2.0))) / samplesMinusOne);
      break;
    case FFT_WIN_TYP_NUTTALL: // nuttall
      weighingFactor = 0.355768 - (0.487396 * (cos(TWO_PI * ratio))) + (0.144232 * (cos(FOUR_PI * ratio))) - (0.012604 * (cos(SIX_PI * ratio)));
      break;
    case FFT_WIN_TYP_BLACKMAN: // blackman
      weighingFactor = 0.42323 - (0.49755 * (cos(TWO_PI * ratio))) + (0.07922 * (cos(FOUR_PI * ratio)));
      break;
    case FFT_WIN_TYP_BLACKMAN_NUTTALL: // blackman nuttall
      weighingFactor = 0.3635819 - (0.4891775 * (cos(TWO_PI * ratio))) + (0.1365995 * (cos(FOUR_PI * ratio))) - (0.0106411 * (cos(SIX_PI * ratio)));
      break;
    case FFT_WIN_TYP_BLACKMAN_HARRIS: // blackman harris
      weighingFactor = 0.35875 - (0.48829 * (cos(TWO_PI * ratio))) + (0.14128 * (cos(FOUR_PI * ratio))) - (0.01168 * (cos(SIX_PI * ratio)));
      break;
    case FFT_WIN_TYP_FLT_TOP: // flat top
      weighingFactor = 0.2810639 - (0.5208972 * cos(TWO_PI * ratio)) + (0.1980399 * cos(FOUR_PI * ratio));
      break;
    case FFT_WIN_TYP_WELCH: // welch
      weighingFactor = 1.0 - pow((indexMinusOne - samplesMinusOne / 2.0) / (samplesMinusOne / 2.0), 2);
      break;
    }
    if (dir == FFT_FORWARD) {
      vData[i] *= weighingFactor;
      vData[samples - (i + 1)] *= weighingFactor;
    }
    else {
      vData[i] /= weighingFactor;
      vData[samples - (i + 1)] /= weighingFactor;
    }
  }
}

void fft_major_peak(double *vData, uint16_t samples, double samplingFrequency, double *f, double *v) {
  double maxY = 0;
  uint16_t IndexOfMaxY = 0;
  //If sampling_frequency = 2 * max_frequency in signal,
  //value would be stored at position samples/2
  for (uint16_t i = 1; i < ((samples >> 1) + 1); i++) {
    if ((vData[i - 1] < vData[i]) && (vData[i] > vData[i + 1])) {
      if (vData[i] > maxY) {
        maxY = vData[i];
        IndexOfMaxY = i;
      }
    }
  }
  double delta = 0.5 * ((vData[IndexOfMaxY - 1] - vData[IndexOfMaxY + 1]) / (vData[IndexOfMaxY - 1] - (2.0 * vData[IndexOfMaxY]) + vData[IndexOfMaxY + 1]));
  double interpolatedX = ((IndexOfMaxY + delta) * samplingFrequency) / (samples - 1);
  if (IndexOfMaxY == (samples >> 1)) {
    //To improve calculation on edge values
    interpolatedX = ((IndexOfMaxY + delta) * samplingFrequency) / (samples);
  }
  // returned value: interpolated frequency peak apex
  *f = interpolatedX;
  *v = abs(vData[IndexOfMaxY - 1] - (2.0 * vData[IndexOfMaxY]) + vData[IndexOfMaxY + 1]);
}

void fft_major_peak_parabola(double *vData, uint16_t samples, double samplingFrequency, double *f) {
  double maxY = 0;
  uint16_t IndexOfMaxY = 0;
  //If sampling_frequency = 2 * max_frequency in signal,
  //value would be stored at position samples/2
  for (uint16_t i = 1; i < ((samples >> 1) + 1); i++) {
    if ((vData[i - 1] < vData[i]) && (vData[i] > vData[i + 1])) {
      if (vData[i] > maxY) {
        maxY = vData[i];
        IndexOfMaxY = i;
      }
    }
  }
  double freq = 0;
  if( IndexOfMaxY > 0) {
    // Assume the three points to be on a parabola
    double a,b,c;
    fft_parabola(IndexOfMaxY-1, vData[IndexOfMaxY-1], IndexOfMaxY, vData[IndexOfMaxY], IndexOfMaxY+1, vData[IndexOfMaxY+1], &a, &b, &c);
    // Peak is at the middle of the parabola
    double x = -b / (2 * a);
    // And magnitude is at the extrema of the parabola if you want It...
    // double y = a*x*x+b*x+c;
    // Convert to frequency
    freq = (x * samplingFrequency) / (samples);
  }
  *f = freq;
}
