#include "EditScene.h"
#include "../../../Utility/cocosAssistant/ListenerAssistant.h"


EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

bool EditScene::init()
{
	mState = EditState::create(this);
	auto onTouchBegan = CC_CALLBACK_2(EditScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(EditScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, nullptr, onTouchEnd, nullptr);


	this->scheduleUpdate();
	return true;
}

EditScene * EditScene::create()
{
	auto obj = new EditScene();

	if (obj && obj->init()) {
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

void EditScene::update(float deltaTime)
{
	mState->update(deltaTime);
}

bool EditScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	mState->onTouchBegan(touch, event);
	return true;
}

void EditScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	mState->onTouchEnded(touch, event);
}
