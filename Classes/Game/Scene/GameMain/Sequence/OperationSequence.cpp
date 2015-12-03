#include "OperationSequence.h"
#include "SequenceManager.h"
#include "BattleSequence.h"
#include "Game\Object\StageObject\StageMap/StageManager.h"
#include "Utility/Modal/ModalLayer.h"

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

	mTurnPlayer = mStageManager->getTurnPlayer();
	
	mState = S_MAIN;

	isPlayerMove = TOUCH;
}

void OperationSequence::main(float at){

}

void OperationSequence::end(float at){
	
	SequenceManager::GetInstance()->nextScene(new BattelSequence(mStageManager));

	if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER2){
		mState = S_START;
		return;
	}

	mState = S_NULL;
}

bool OperationSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	if (mState != S_MAIN ) return false;


	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touchPoint);

	isTouch(touchPoint);

	return true;
}

bool OperationSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	
	mStageManager->onTouchEnd(touch->getLocation());

	return true;
}

void OperationSequence::isTouch(cocos2d::Vec2 touchPos){

	if (isPlayerMove == NULL_MOVE) return;

	cocos2d::Rect targetBox = mTurnPlayer->getBoundingBox();

	if (targetBox.containsPoint(touchPos)){
		this->isPlayerMove = MOVE;
		
		return;
	}

	move(touchPos);
}

void OperationSequence::move(const cocos2d::Vec2& touchPos){


	int number = (((int)touchPos.x - 32) / 64) + (((int)touchPos.y - 128) / 64 * 9);

	if (isPlayerMove != MOVE || mStageManager->getPanel(number)->getColor() != mStageManager->getTurnPlayerColor()) return;

	this->touchPos = touchPos;

	ModalLayer::EventListener* listener = ModalLayer::EventListener::create();
	listener->onButtonYes = CC_CALLBACK_0(OperationSequence::onPushYesButton, this);
	listener->onButtonNo = CC_CALLBACK_0(OperationSequence::onPushNoButton, this);

	auto modalLayer = ModalLayer::create(listener);
	auto isScene = cocos2d::Director::getInstance()->getRunningScene();

	isScene->addChild(modalLayer);
}

void OperationSequence::onEndSequence()
{
	mState = S_END;
}

void OperationSequence::onPushYesButton(){

	int number = (((int)touchPos.x - 32) / 64) + (((int)touchPos.y - 128) / 64 * 9);

	auto sprite = mStageManager->getPanel(number)->getColor();

	if (mStageManager->getPanel(number)->getPosition() == mTurnPlayer->getPosition()) return;

	mTurnPlayer->setPosition(mStageManager->getPanel(number)->getPosition());

	isPlayerMove = NULL_MOVE;
}

void OperationSequence::onPushNoButton(){
	
	isPlayerMove = TOUCH;
}
