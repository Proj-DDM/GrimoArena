#include "TitleState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Utility/SceneSupport/FadeScene.h"
#include "../GameMain/GameMainScene.h"
#include "Game/Layer/UILayer.h"

using namespace cocos2d;

using namespace cocos2d;

TitleState* TitleState::create(Layer* layer){

	auto obj = new TitleState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool TitleState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;

	mCount = 0;

	auto title = Sprite::create("Scene/Title/title.png");
	parentLayer->addChild(title);
	title->setPosition(Director::getInstance()->getVisibleSize() / 2);

	return true;
}

void TitleState::update(float at){

	if (mSceneState < SCENEEND)
	{
		(this->*updateFunc[mSceneState])(at);
	}
	else
	{


	}
}

void TitleState::fadeIn(float at){
	mSceneState = MAIN;
}

void TitleState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void TitleState::fadeOut(float at){
	mSceneState = SCENEEND;

	//シーン切り替え
	auto func = []()
	{
		auto uiLayer = UILayer::create();
		return SceneCreator::createScene(GameMainScene::create(uiLayer), uiLayer);
	};

	auto scene = FadeScene::create(1.5f, func);

	Director::getInstance()->replaceScene(scene);
}

void TitleState::mainStart(float at){
	
	mUpdateState = UPDATELOOP;
}

void TitleState::mainLoop(float at){


}

void TitleState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;

}

bool TitleState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	mUpdateState = UPDATEEND;
	return true;
}

void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){


}