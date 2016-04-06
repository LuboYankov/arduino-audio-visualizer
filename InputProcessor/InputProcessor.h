#ifndef INPUTPROCESSOR_H__
#define INPUTPROCESSOR_H__

class InputProcessor {
public:
	void readInput();
	void fftAnalyze();
	unsigned char* processFftResponse();
};

#endif