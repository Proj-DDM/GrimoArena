#include "ResultState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameMainScene.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Utility/Modal/ModalLayer.h"
#include "Game/Layer/UILayer.h"

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

	if (mSceneState < SCENEEND){
		(this->*updateFunc[mSceneState])(at);
	}
}

void ResultState::fadeIn(float at){

	mSceneState = MAIN;
}

void ResultState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void ResultState::fadeOut(float at){
	mSceneState = SCENEEND;

	ModalLayer::EventListener* listener = ModalLayer::EventListener::create();
	listener->onButtonYes = CC_CALLBACK_0(ResultState::onPushYesButton, this);
	listener->onButtonNo = CC_CALLBACK_0(ResultState::onPushNoButton, this);

	auto modalLayer = ModalLayer::create(listener, "mouitid.png", "un.png", "iya.png");
	auto isScene = cocos2d::Director::getInstance()->getRunningScene();

	isScene->addChild(modalLayer);
}

void ResultState::mainStart(float at){
	
	mUpdateState = UPDATELOOP;
}

void ResultState::mainLoop(float at){

	
}

void ResultState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool ResultState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	mUpdateState = UPDATEEND;
	return true;
}

void ResultState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){


}

void ResultState::onPushYesButton(){

	auto uiLayer = UILayer::create();

	auto firstScene = SceneCreator::createScene(GameMainScene::create(uiLayer),uiLayer);
	auto scene = TransitionFade::create(1.5f, firstScene, Color3B::BLACK);

	Director::getInstance()->replaceScene(scene);

}

void ResultState::onPushNoButton(){

	auto nextScene = SceneCreator::createScene(TitleScene::create());
	auto scene = TransitionFade::create(1.5f, nextScene, Color3B::WHITE);

	Director::getInstance()->replaceScene(scene);

}