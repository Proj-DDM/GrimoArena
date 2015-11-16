#include "OperationSequence.h"
#include "SequenceManager.h"
#include "BattleSequence.h"
#include "Game\Object\StageObject\StageMap/StageManager.h"

OperationSequence::OperationSequence(StageManager* stageManager) : ISequence(stageManager)
{
	mState = S_START;
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
	mState = S_MAIN;
}

void OperationSequence::main(float at){
	mState = S_END;
}

void OperationSequence::end(float at){
	
	SequenceManager::GetInstance()->nextScene(new BattelSequence(mStageManager));
	mState = S_NULL;
}

bool OperationSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touchPoint);

	return true;
}

bool OperationSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}