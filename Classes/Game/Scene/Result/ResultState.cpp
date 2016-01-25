#include "ResultState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameMainScene.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Utility/Modal/ModalLayer.h"
#include "Game/Layer/UILayer.h"
#include "Utility/SceneSupport/FadeScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

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

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/BGM/BGM_result.mp3");
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);

	return true;
}

void ResultState::update(float at){

	if (mSceneState < SCENEEND){
		(this->*updateFunc[mSceneState])(at);
	}
}

void ResultState::fadeIn(float at){
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/BGM/BGM_result.mp3");
	mSceneState = MAIN;
}

void ResultState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void ResultState::fadeOut(float at){
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);

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

	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
	}
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

	//シーン切り替え
	auto func = []()
	{
		auto uiLayer = UILayer::create();
		return SceneCreator::createScene(GameMainScene::create(uiLayer), uiLayer);
	};

	auto scene = FadeScene::create(1.5f, func);

	Director::getInstance()->replaceScene(scene);

}

void ResultState::onPushNoButton(){

	//シーン切り替え
	auto func = []()
	{
		auto uiLayer = UILayer::create();
		return SceneCreator::createScene(GameMainScene::create(uiLayer), uiLayer);
	};

	auto scene = FadeScene::create(1.5f, func);

	Director::getInstance()->replaceScene(scene);

}