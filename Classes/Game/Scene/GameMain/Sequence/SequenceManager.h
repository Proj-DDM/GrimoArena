#pragma once

#include "ISequence.h"
#include <stack>
#include "cocos2d.h"

enum GAMESEQUENCE{
	OPERATION_SEQUENCE,
	BATTLE_SEQUENCE,
	END_SEQUENCE,
	NULL_SEQUENCE
};

class SequenceManager 
{
private:
	SequenceManager();
	~SequenceManager();

	SequenceManager& operator=(const SequenceManager&);

public:
	void init();

	bool update(float at);

	void push(ISequence* sequence);

	void pop();

	void nextScene(ISequence* sequence);

	static SequenceManager* GetInstance();

	void Release();

	void addTurn();

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


private:

	std::stack<ISequence*> m_SequenceStack;
	ISequence* currentSequence;
	ISequence* nextSequence;
	int m_Turn;
	GAMESEQUENCE m_Sequence;

	// P1
	// P2
};

