#include "OperationSequence.h"

OperationSequence::OperationSequence()
{
}


OperationSequence::~OperationSequence()
{
}

S_STATUS OperationSequence::update(float at){
	
	if (mState < S_NULL){
		(this->*updateFunc[mState])(at);
	}

	return mState;
}

void OperationSequence::start(float at){

}

void OperationSequence::main(float at){

}

void OperationSequence::end(float at){

}