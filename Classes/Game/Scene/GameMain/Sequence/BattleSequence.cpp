#include "BattleSequence.h"
#include "SequenceManager.h"
#include "EndSequence.h"
#include "Game\Object\StageObject\StageMap/StageManager.h"


BattelSequence::BattelSequence(StageManager* stageManager) :ISequence(stageManager)
{
	mState = S_START;
}


BattelSequence::~BattelSequence()
{
}

S_STATUS BattelSequence::update(float at){

	if (mState < S_NULL){
		(this->*updateFunc[mState])(at);
	}

	return mState;
}

void BattelSequence::start(float at){
	mState = S_MAIN;
}

void BattelSequence::main(float at){
	mState = S_END;
}

void BattelSequence::end(float at){

	SequenceManager::GetInstance()->nextScene(new EndSequence(mStageManager));
	mState = S_NULL;
}

bool BattelSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touchPoint);

	return true;
}

bool BattelSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}