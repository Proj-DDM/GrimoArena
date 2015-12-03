#include "ResultState.h"
#include "Utility/SceneSupport/SceneCreator.h"

using namespace cocos2d;

using namespace cocos2d;

ResultState* ResultState::create(Layer* layer){

	auto obj = new ResultState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool ResultState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;

	mCount = 0;

	return true;
}

void ResultState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void ResultState::fadeIn(float at){
	mSceneState = MAIN;
}

void ResultState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void ResultState::fadeOut(float at){
	mSceneState = FADEIN;
}

void ResultState::mainStart(float at){
	
	mUpdateState = UPDATELOOP;
}

void ResultState::mainLoop(float at){

	mUpdateState = UPDATEEND;
}

void ResultState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool ResultState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){


	return true;
}

void ResultState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){


}