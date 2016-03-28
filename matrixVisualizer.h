#ifndef MATRIXVISUALIZER_H__
#define MATRIXVISUALIZER_H__

class MatrixVisualizer {
public:
	void lightUp(int row, int col);
	void shutDown(int row, int col);
	void visualizeSignal(int buffer[]);
};

#endif
