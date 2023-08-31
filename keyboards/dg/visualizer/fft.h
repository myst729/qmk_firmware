#ifndef FFT_H
#define FFT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FFT_LIB_REV 0x14
#define FFT_FORWARD 0x01
#define FFT_REVERSE 0x00

/* Windowing type */
#define FFT_WIN_TYP_RECTANGLE 0x00 /* rectangle (Box car) */
#define FFT_WIN_TYP_HAMMING 0x01 /* hamming */
#define FFT_WIN_TYP_HANN 0x02 /* hann */
#define FFT_WIN_TYP_TRIANGLE 0x03 /* triangle (Bartlett) */
#define FFT_WIN_TYP_NUTTALL 0x04 /* nuttall */
#define FFT_WIN_TYP_BLACKMAN 0x05 /* blackman */
#define FFT_WIN_TYP_BLACKMAN_NUTTALL 0x06 /* blackman nuttall */
#define FFT_WIN_TYP_BLACKMAN_HARRIS 0x07 /* blackman harris*/
#define FFT_WIN_TYP_FLT_TOP 0x08 /* flat top */
#define FFT_WIN_TYP_WELCH 0x09 /* welch */

/* Mathematial constants */
#define TWO_PI 6.28318531
#define FOUR_PI 12.56637061
#define SIX_PI 18.84955593

uint8_t fft_revision(void);
uint8_t fft_exponent(uint16_t value);
void fft_parabola(double x1, double y1, double x2, double y2, double x3, double y3, double *a, double *b, double *c);
void fft_swap(double *x, double *y);
void fft_compute(double *vReal, double *vImag, uint16_t samples, uint8_t power, uint8_t dir);
void fft_complex_to_magnitude(double *vReal, double *vImag, uint16_t samples);
void fft_dc_removal(double *vData, uint16_t samples);
void fft_windowing(double *vData, uint16_t samples, uint8_t windowType, uint8_t dir);
void fft_major_peak(double *vData, uint16_t samples, double samplingFrequency, double *f, double *v);
void fft_major_peak_parabola(double *vData, uint16_t samples, double samplingFrequency, double *f);

#endif
