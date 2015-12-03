#include "ResultScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

ResultScene::ResultScene() {}

ResultScene::~ResultScene()
{
	mState->release();
}

ResultScene* ResultScene::create(){
	auto obj = new ResultScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool ResultScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = ResultState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(ResultScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

	this->scheduleUpdate();

	return true;
}

void ResultScene::update(float at){
	mState->update(at);
}

bool ResultScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}

void ResultScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}