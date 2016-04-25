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
	for (int i = 0; i <= row; i++) {
		lc.setLed(0, i, col, true);
	}
}

void
MatrixVisualizer::shutDownColumn(LedControl lc, int col) {
	for (int i = 7; i >= 0; i--) {
		lc.setLed(0, i, col, false);
	}
}

void
MatrixVisualizer::checkRange(LedControl lc, unsigned char* data, int i, int min, int max) {
	int difference = (max - min) / 6;
	for (int j = 1; j <= 7; j++) {
		if (((int)data[i] > (int)(min + (j*difference))) && ((int)data[i] < (int)(min + ((j+1)*difference)))) {
			lightUpColumn(lc, j, i-1);
		}
	}
	shutDownColumn(lc, i-1);
}

void
MatrixVisualizer::visualizeSignal(LedControl lc, unsigned char* data) {
	for (int i = 1; i <= 8; i++) {
		checkRange(lc, data, i, 30, 150);
	}
}