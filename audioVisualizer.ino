#define OCTAVE 1
#define FFT_N 256

#include <InputProcessor.h>

unsigned char* data;
InputProcessor i;

void setup() {
  Serial.begin(115200);
  TIMSK0 = 0;
  ADCSRA = 0xe5;
  ADMUX = 0x40;
  DIDR0 = 0x01;
}

void loop() {
  i.readInput();
  i.fftAnalyze();
  data = i.processFftResponse();
  for (byte i = 0; i < FFT_N/2; i++) { 
   Serial.println(data[i]);
  }
}
