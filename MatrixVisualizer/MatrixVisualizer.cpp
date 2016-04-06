/*
==> Lubomir Yankov
*/

#include "Arduino.h"
#include "MatrixVisualizer.h"
#include "LedControlMS.h"

void
MatrixVisualizer::lightUp(LedControl lc, int row, int col) {
	lc.setLed(0, row, col, true);
}

void
MatrixVisualizer::shutDown(LedControl lc, int row, int col) {
	lc.setLed(0, row, col, false);
}

void
MatrixVisualizer::lightUpColumn(LedControl lc, int row, int col) {
	for(int i=0; i <= row; i++) {
		lc.setLed(0, i, col, true);
		delay(20);
	}
}

void
MatrixVisualizer::shutDownColumn(LedControl lc, int col) {
	for(int i=7; i >= 0; i--) {
		lc.setLed(0, i, col, false);
		delay(20);
	}
}

void
MatrixVisualizer::visualizeSignal(int buffer[]) {
	// TODO
}
