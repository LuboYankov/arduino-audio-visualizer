#define OCTAVE 1
#define FFT_N 16

#include <InputProcessor.h>
#include <LedControlMS.h>
#include <MatrixVisualizer.h>

unsigned char* data;
InputProcessor i;
LedControl lc = LedControl(12, 11, 10, 1);
MatrixVisualizer mv = MatrixVisualizer();

void setup() {
  Serial.begin(115200);
  TIMSK0 = 0;
  ADCSRA = 0xe5;
  ADMUX = 0x40;
  DIDR0 = 0x01;
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK1 = (1 << TOIE1);
  TCCR1B |= (1 << CS11);
  sei();
}

ISR(TIMER1_OVF_vect) {
  i.readInput();
  i.fftAnalyze();
  data = i.processFftResponse();
  mv.visualizeSignal(lc, data);
}

void loop() {
  /*for (byte i = 0; i < FFT_N/2; i++) {
   Serial.print(data[i]);
   Serial.print(" ");
  }
  Serial.println("");*/
}