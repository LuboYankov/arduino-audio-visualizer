#ifndef INPUTPROCESSOR_H__
#define INPUTPROCESSOR_H__

class InputProcessor {
public:
	int* readInput();
	int* fftAnalyze(int data[]);
	int* processFftResponse(int response[]);
};

#endif