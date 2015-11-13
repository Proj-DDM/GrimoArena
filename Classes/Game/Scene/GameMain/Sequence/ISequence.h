#ifndef ISEQUENCE_H
#define ISEQUENCE_H

#include "cocos2d.h"

enum S_STATUS{
	S_START = 0,
	S_MAIN,
	S_END,
	S_NULL
};

class ISequence {

public:

	ISequence() : mState(S_START){

		updateFunc[0] = &ISequence::start;
		updateFunc[1] = &ISequence::main;
		updateFunc[2] = &ISequence::end;

	}

	virtual S_STATUS update(float at) = 0;
	
	virtual void main(float at) = 0;


	virtual void start(float at) = 0;

	virtual void end(float at) = 0;

protected:
	void(ISequence::*updateFunc[S_STATUS::S_NULL])(float at);

	S_STATUS mState;
};

#endif