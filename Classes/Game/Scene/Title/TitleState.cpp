#include "TitleState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Utility/SceneSupport/FadeScene.h"
#include "Game/Scene/GameMain/GameMainScene.h"
#include "Game/Layer/UILayer.h"
#include "Utility/Particle/SimpleParticle.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

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

	auto titlebg = Sprite::create("Scene/Title/title_bg.png");
	parentLayer->addChild(titlebg);
	titlebg->setPosition(Director::getInstance()->getVisibleSize() / 2);

	
	auto titleWing = Sprite::create("Scene/Title/title_wing.png");
	parentLayer->addChild(titleWing);
	titleWing->setPosition(Director::getInstance()->getVisibleSize() / 2);

	auto title = Sprite::create("Scene/Title/title.png");
	parentLayer->addChild(title);
	title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 + 50));
	title->setScale(2.f);

	auto titlestart = Sprite::create("Scene/Title/title_start.png");
	parentLayer->addChild(titlestart);
	titlestart->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, titlestart->getContentSize().height * 4.5f));

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/BGM/bgm_title.mp3");
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);

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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/BGM/bgm_title.mp3");
	mSceneState = MAIN;
}

void TitleState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void TitleState::fadeOut(float at){
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
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
	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
	}
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