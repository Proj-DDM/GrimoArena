#include "EditState.h"
using namespace cocos2d;

EditState * EditState::create(cocos2d::Layer * layer)
{
	auto obj = new EditState();

	if (obj && obj->init(layer)) {
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool EditState::init(cocos2d::Layer * layer)
{
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;
	table = CharacterTable::create();
	parentLayer->addChild(table);
	manager = EditStageManager::create();
	layer->addChild(manager);
	mCount = 0;
	return true;
}

void EditState::update(float dt)
{
	(this->*updateFunc[mSceneState])(dt);
}

void EditState::fadeIn(float dt)
{
}

void EditState::sceneMain(float dt)
{
	(this->*mainFunc[mUpdateState])(dt);
}

void EditState::fadeOut(float dt)
{
}

bool EditState::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	cocos2d::Vec2 touchPoint = touch->getLocation();
	manager->onTouchBegan(touchPoint);
	return true;
}

void EditState::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	cocos2d::Vec2 touchPoint = touch->getLocation();
	manager->onTouchEnd(touchPoint);
}

void EditState::mainStart(float at)
{
}

void EditState::mainLoop(float at)
{
}

void EditState::mainEnd(float at)
{
}
