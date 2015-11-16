#include "EndSequence.h"
#include "SequenceManager.h"
#include "OperationSequence.h"
#include "Game\Object\StageObject\StageMap/StageManager.h"


EndSequence::EndSequence(StageManager* stageManager) :ISequence(stageManager)
{
	mState = S_START;
}


EndSequence::~EndSequence()
{
}

S_STATUS EndSequence::update(float at){

	if (mState < S_NULL){
		(this->*updateFunc[mState])(at);
	}

	return mState;
}

void EndSequence::start(float at){
	mState = S_MAIN;
}

void EndSequence::main(float at){
	mState = S_END;
}

void EndSequence::end(float at){

	auto sequenceManager = SequenceManager::GetInstance();
	sequenceManager->nextScene(new OperationSequence(mStageManager));
	
	sequenceManager->addTurn();
	mState = S_NULL;
}

bool EndSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touchPoint);

	return true;
}

bool EndSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}