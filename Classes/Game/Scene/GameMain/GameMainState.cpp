#include "GameMainState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Test/TestScene.h"
#include "../../Character/PlayerDeck.h"
#include "Game/Object/StageObject/StageMap/StagePanel.h"
#include "../../../Utility/FileIO/CharaReader.h"

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

	camera = new cocos2d::ActionCamera();
	camera->autorelease();
	/*camera->setTarget(layer);
	auto eye = camera->getEye();
	eye.y = -0.0000003;
	camera->setEye(eye);*/
	camera->startWithTarget(layer);

	factory.init();
	manager = CharacterManager::create();
	parentLayer->addChild(manager);

	return true;
}

void GameMainState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void GameMainState::fadeIn(float at){
	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){	
	mSceneState = FADEIN;	
}

void GameMainState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){
	auto test = mStageManager;

	//パネルを塗り替えるラムダ式を登録
	auto func = [test](int number){
		auto panel = test->getPanel(number);
		if (!panel) return;
		auto panelSprite = (Sprite*)panel->getChildByName(panel->getName());
		panelSprite->setColor(cocos2d::Color3B::BLUE);
	};
	
	manager->update(func);
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}


bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	Vec2 touchPoint = touch->getLocation();
	if (touchPoint.y <= 120) return false;
	auto uiLayer = parentLayer->getParent()->getChildByTag(1);
	auto id = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"))->getCharacterID();
	auto param = Parameter(10, 10, 10);
	
	int panelNumber = mStageManager->onTouchBegan(touchPoint);
	if( panelNumber >= 0){
		Vec2 pos = Vec2((panelNumber % 9  + 1) * 64 - 32, (panelNumber / 9  + 1)* 64 - 32);
		manager->add(factory.create(id, param, pos));
	}
	return true;
}

void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}