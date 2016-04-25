/*
==> Lubomir Yankov
*/

#ifndef MATRIXVISUALIZER_H__
#define MATRIXVISUALIZER_H__

#include "Arduino.h"
#include "LedControlMS.h"

class MatrixVisualizer {
public:
	void lightUp(LedControl lc, int row, int col);
	void shutDown(LedControl lc, int row, int col);
	void lightUpColumn(LedControl lc, int row, int col);
	void shutDownColumn(LedControl lc, int col);
	void checkRange(LedControl lc, unsigned char* data, int i, int min, int max);
	void visualizeSignal(LedControl lc, unsigned char* data);
};

#endif