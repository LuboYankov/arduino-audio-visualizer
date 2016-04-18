#include <MatrixVisualizer.h>

#include <LedControlMS.h>

#define OCTAVE 1
#define FFT_N 16

#include <InputProcessor.h>

unsigned char* data;
InputProcessor i;
LedControl lc = LedControl(12,11,10,1);
MatrixVisualizer mv = MatrixVisualizer();

void setup() {
  Serial.begin(115200);
  TIMSK0 = 0;
  ADCSRA = 0xe5;
  ADMUX = 0x40;
  DIDR0 = 0x01;
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  while(1) {
    cli();
    i.readInput();
    i.fftAnalyze();
    data = i.processFftResponse();
    for (byte i = 0; i < FFT_N/2; i++) {
     mv.visualizeSignal(lc, data);
     //Serial.print(data[i]);
     //Serial.print(" ");
    }
    //Serial.println("");
    sei();
  }
}
