/* 
 * Ivelin Slavchev
 */

#define OCTAVE 1

#include "Arduino.h"
#include "FFT.h"
#include "InputProcessor.h"	

void
InputProcessor::readInput() {
  for (int i = 0; i < 512; i += 2) {
    while(!(ADCSRA & 0x10));
    ADCSRA = 0xf5;
    byte m = ADCL;
    byte j = ADCH;
    int k = (j << 8) | m;
    k -= 0x0200;
    k <<= 6;
    fft_input[i] = k;
    fft_input[i+1] = 0;
  }
}

void
InputProcessor::fftAnalyze() {
  fft_reorder();
  fft_run();
}

unsigned char*
InputProcessor::processFftResponse() {
  fft_mag_octave();
  return fft_oct_out;
}

int*
InputProcessor::printInput() {
  return fft_input;
}