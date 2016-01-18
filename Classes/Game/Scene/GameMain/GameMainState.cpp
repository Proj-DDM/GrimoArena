#include "GameMainState.h"
#include "GameMainScene.h"

#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Test/TestScene.h"
#include "Game/Object/StageObject/StageMap/StagePanel.h"
#include "../../../Utility/FileIO/CharaReader.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#include "Game/Scene/GameMain/Sequence/OperationSequence.h"
#include "Game/Scene/Result/ResultScene.h"
#include "Utility/Camera/Camera.h"
#include "Game/Layer/UILayer.h"


using namespace cocos2d;

GameMainState* GameMainState::create(Layer* layer){

	auto obj = new GameMainState();
	
	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool GameMainState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;


	mStageManager = StageManager::create();

	parentLayer->addChild(mStageManager);

	mCount = 0;

	CustomCamera::getInstance().createCamera();
	CustomCamera::getInstance().setTargetLayer(this->parentLayer);
	CustomCamera::getInstance().setFollowTarget(mStageManager->getTurnPlayer());

	return true;
}

void GameMainState::update(float at){

	if (mSceneState <= SCENEEND)
	{
		(this->*updateFunc[mSceneState])(at);
	}
}

void GameMainState::fadeIn(float at){
	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){	
	
	camera->release();

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

	CustomCamera::getInstance().moveEye(Vec3(this->movePos.x - touch->getLocation().x, this->movePos.y - touch->getLocation().y, 0));

	this->movePos = touch->getLocation();
}

void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	SequenceManager::GetInstance()->onTouchEnded(touch, event);
}

void GameMainState::onEndButton(){
	CustomCamera::getInstance().removeTarget();

	SequenceManager::GetInstance()->setEndSequence();

	CustomCamera::getInstance().setFollowTarget(mStageManager->getTurnPlayer()->getSprite());
}

void GameMainState::onViewButton(){
	if (this->isView)
	{
		CustomCamera::getInstance().removeTarget();
		CustomCamera::getInstance().setFollowTarget(mStageManager->getTurnPlayer()->getSprite());
	}
	else
	{
		CustomCamera::getInstance().removeTarget();
		CustomCamera::getInstance().startLayer();
	}

	this->isView = !this->isView;
}