#pragma once

#include "ISequence.h"
#include <queue>
#include "cocos2d.h"

enum GAMESEQUENCE{
	OPERATION_SEQUENCE,
	BATTLE_SEQUENCE,
	END_SEQUENCE,
	NULL_SEQUENCE
};

class SequenceManager : public cocos2d::Node
{
public:
	SequenceManager();
	~SequenceManager();

	void update(float at);

	void push();

	void pop();

private:

	std::queue<ISequence*> m_SequenceQueue;
	int m_Turn;
	GAMESEQUENCE m_Sequence;

	// P1
	// P2
};

