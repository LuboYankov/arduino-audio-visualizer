/*
==> Lubomir Yankov
*/

#include <Arduino.h>
#include <MatrixVisualizer.h>
#include <LedControlMS.h>

LedControl lc = LedControl(12,11,10,1);

MatrixVisualizer mv = MatrixVisualizer();

void setup() {
    lc.shutdown(0,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0,8);
    /* and clear the display */
    lc.clearDisplay(0);
}

void loop() {
  // Sample column lightings
  mv.lightUpColumn(lc, 5, 0);
  delay(300);
  mv.shutDownColumn(lc, 0);
  delay(200);
  mv.lightUpColumn(lc, 6, 3);
  delay(300);
  mv.shutDownColumn(lc, 3);
  delay(200);
  mv.lightUpColumn(lc, 2, 4);
  delay(300);
  mv.shutDownColumn(lc, 3);
  delay(200);
}
