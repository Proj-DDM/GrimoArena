#include "GameMainScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"
#include "Game/Layer/UILayer.h"


GameMainScene::GameMainScene() {}

GameMainScene::~GameMainScene()
{
	mState->release();
}

GameMainScene* GameMainScene::create(cocos2d::Layer* layer){
	auto obj = new GameMainScene();

	if (obj && obj->init(layer)){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool GameMainScene::init(cocos2d::Layer* layer){
	if (!Layer::init())
	{
		return false;
	}

	mState = GameMainState::create(this,layer);

	auto onTouchBegan = CC_CALLBACK_2(GameMainScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(GameMainScene::onTouchEnded, this);
	auto onTouchMove = CC_CALLBACK_2(GameMainScene::onTouchMoved, this);

	auto size = cocos2d::Director::getInstance()->getVisibleSize();

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, onTouchMove, onTouchEnd, nullptr);

    auto node = Node::create();
    this->addChild(node);

	this->uiLayer = layer;

	this->scheduleUpdate();

	UILayer::EventListener* lisner = UILayer::EventListener::create();
	lisner->onViewButton = CC_CALLBACK_0(GameMainScene::onViewButton, this);
	lisner->onEndButton = CC_CALLBACK_0(GameMainScene::onEndButton, this);
	lisner->onBackButton = CC_CALLBACK_0(GameMainScene::onEndButton, this);
	lisner->onGiveUpButton = CC_CALLBACK_0(GameMainScene::onEndButton, this);

	dynamic_cast<UILayer*>(this->uiLayer)->createMenuButton(lisner);

	return true;
}

void GameMainScene::onEnter()
{
	mState->onEnter();
	Layer::onEnter();
}

void GameMainScene::update(float at){
	mState->update(at);
}

bool GameMainScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	dynamic_cast<UILayer*>(this->uiLayer)->closeMenu();
	mState->onTouchBegan(touch, event);
	return true;
}

void GameMainScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchMoved(touch, event);
}

void GameMainScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}

void GameMainScene::onEndButton(){
	mState->onEndButton();
}

void GameMainScene::onViewButton(){
	mState->onViewButton();
}