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
	}
}

void
MatrixVisualizer::shutDownColumn(LedControl lc, int col) {
	for(int i=7; i >= 0; i--) {
		lc.setLed(0, i, col, false);
	}
}

void
MatrixVisualizer::checkRange(LedControl lc, unsigned char* data, int i, int min, int max) {
	int difference = (max - min)/6;
	if(((int)data[i] > (int)(min+(1*difference)))&&((int)data[i] < (int)(min+(2*difference)))) {
		lightUpColumn(lc, 1, i-1);
	}
	if(((int)data[i] > (int)(min+(2*difference)))&&((int)data[i] < (int)(min+(3*difference)))) {
		lightUpColumn(lc, 2, i-1);
	}
	if(((int)data[i] > (int)(min+(3*difference)))&&((int)data[i] < (int)(min+(4*difference)))) {
		lightUpColumn(lc, 3, i-1);
	}
	if(((int)data[i] > (int)(min+(4*difference)))&&((int)data[i] < (int)(min+(5*difference)))) {
		lightUpColumn(lc, 4, i-1);
	}
	if(((int)data[i] > (int)(min+(5*difference)))&&((int)data[i] < (int)(min+(6*difference)))) {
		lightUpColumn(lc, 5, i-1);
	}
	if(((int)data[i] > (int)(min+(6*difference)))&&((int)data[i] < (int)(min+(7*difference)))) {
		lightUpColumn(lc, 6, i-1);
	}
	shutDownColumn(lc, i-1);
}

void
MatrixVisualizer::visualizeSignal(LedControl lc, unsigned char* data) {
	// checkRange(lc, data, 1, 30, 150);
	// checkRange(lc, data, 2, 30, 150);
	// checkRange(lc, data, 3, 30, 150);
	checkRange(lc, data, 4, 50, 150);
	// checkRange(lc, data, 5, 30, 150);
	// checkRange(lc, data, 6, 30, 150);
	// checkRange(lc, data, 7, 30, 150);
}
