#include "GameMainState.h"
#include "GameMainScene.h"

#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Test/TestScene.h"
#include "Game/Object/StageObject/StageMap/StagePanel.h"
#include "Utility/FileIO/CharaReader.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#include "Game/Scene/GameMain/Sequence/OperationSequence.h"
#include "Game/Scene/Result/ResultScene.h"
#include "Utility/Camera/Camera.h"
#include "Game/Layer/UILayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


using namespace cocos2d;

GameMainState* GameMainState::create(Layer* layer,Layer* uiLayer){

	auto obj = new GameMainState();
	
	if (obj && obj->init(layer,uiLayer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool GameMainState::init(Layer* layer,Layer* uiLayer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;

	mStageManager = StageManager::create(uiLayer);
	parentLayer->addChild(mStageManager);

	mCount = 0;

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/BGM/battle02.mp3");
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);

	return true;
}

void GameMainState::onEnter()
{
	gremo::Camera::getInstance().setUseCamera(CameraFlag::USER1);
	gremo::Camera::getInstance().setPosition(mStageManager->getTurnPlayer()->getPosition());
}

void GameMainState::update(float at){

	if (mSceneState <= SCENEEND)
	{
		(this->*updateFunc[mSceneState])(at);
	}
}

void GameMainState::fadeIn(float at){
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/BGM/battle02.mp3");
	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){	

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	mSceneState = SCENEEND;	

	auto nextScene = SceneCreator::createScene(ResultScene::create());
	auto scene = TransitionFade::create(1.5f, nextScene, Color3B::BLACK);

	Director::getInstance()->replaceScene(scene);
}

void GameMainState::mainStart(float at){
	SequenceManager::GetInstance()->init();
	SequenceManager::GetInstance()->nextScene(new OperationSequence(mStageManager));

	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){
	
	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
	}

	if (SequenceManager::GetInstance()->update(at)) mUpdateState = UPDATEEND;
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}


bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	SequenceManager::GetInstance()->onTouchBegan(touch, event);
	
	if (isView) this->movePos = touch->getLocation();

	return true;
}

void GameMainState::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (!isView || dynamic_cast<UILayer*>(dynamic_cast<GameMainScene*>(this->parentLayer)->uiLayer)->isSummon()) return;

	this->movePos = touch->getLocation();
	//mStageManager->onTouchMove(gremo::Camera::getInstance().convertTouchPosition(touch));


	auto move = touch->getPreviousLocation() - touch->getLocation();
	gremo::Camera::getInstance().movePosition(Vec2(move.x, move.y));
}

void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	SequenceManager::GetInstance()->onTouchEnded(touch, event);
}

void GameMainState::onEndButton(){

	SequenceManager::GetInstance()->setEndSequence();

	gremo::Camera::getInstance().setPosition(mStageManager->getTurnPlayer()->getPosition());
}

void GameMainState::onViewButton(){
	if (this->isView)	
	{
		gremo::Camera::getInstance().setPosition(mStageManager->getTurnPlayer()->getPosition());
	}

	this->isView = !this->isView;
}