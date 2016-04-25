/* 
 * Ivelin Slavchev
 */

#ifndef INPUTPROCESSOR_H__
#define INPUTPROCESSOR_H__

#include "Arduino.h"

class InputProcessor {
public:
	void readInput();
	void fftAnalyze();
	unsigned char* processFftResponse();
};

#endif