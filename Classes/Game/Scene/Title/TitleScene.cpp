#include "TitleScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene()
{
	mState->release();
}

TitleScene* TitleScene::create(){
	auto obj = new TitleScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool TitleScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = TitleState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(TitleScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

	this->scheduleUpdate();

	return true;
}

void TitleScene::update(float at){
	mState->update(at);
}

bool TitleScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}

void TitleScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}