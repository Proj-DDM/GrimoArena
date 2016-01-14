#include "GameMainScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

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

	mState = GameMainState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(GameMainScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(GameMainScene::onTouchEnded, this);
	auto onTouchMove = CC_CALLBACK_2(GameMainScene::onTouchMoved, this);

	auto size = cocos2d::Director::getInstance()->getVisibleSize();

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, onTouchMove, onTouchEnd, nullptr);

    auto node = Node::create();
    this->addChild(node);

	this->uiLayer = layer;

	this->scheduleUpdate();

	auto endButton = cocos2d::MenuItemImage::create("turnend.png", "turnend.png",CC_CALLBACK_0(GameMainScene::onEndButton,this));

	endButton->setPosition(cocos2d::Vec2(endButton->getContentSize().width / 4, size.height - endButton->getContentSize().height / 2));
	endButton->setScale(0.5f);
	auto menu = cocos2d::Menu::create(endButton,nullptr);
	menu->setPosition(cocos2d::Point::ZERO);
	this->uiLayer->addChild(menu);

	auto viewButton = cocos2d::MenuItemImage::create("turnend.png", "turnend.png", CC_CALLBACK_0(GameMainScene::onViewButton, this));

	viewButton->setPosition(cocos2d::Vec2(Director::getInstance()->getVisibleSize().width - viewButton->getContentSize().width, size.height - viewButton->getContentSize().height / 2));
	viewButton->setScale(0.5f);
	auto viewMenu = cocos2d::Menu::create(viewButton, nullptr);
	viewMenu->setPosition(cocos2d::Point::ZERO);
	this->uiLayer->addChild(viewMenu);

	return true;
}

void GameMainScene::update(float at){
	mState->update(at);
}

bool GameMainScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
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