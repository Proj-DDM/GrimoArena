#pragma once

#include "ISequence.h"

class OperationSequence : public ISequence
{
public:
	OperationSequence();
	~OperationSequence();

	S_STATUS update(float at) override;

	void main(float at) override;

	void start(float at) override;

	void end(float at) override;
};

