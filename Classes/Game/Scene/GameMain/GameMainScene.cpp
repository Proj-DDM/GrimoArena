#include "GameMainScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

GameMainScene::GameMainScene() {}

GameMainScene::~GameMainScene()
{
	mState->release();
}

GameMainScene* GameMainScene::create(){
	auto obj = new GameMainScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool GameMainScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = GameMainState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(GameMainScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(GameMainScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

    auto node = Node::create();
    this->addChild(node);

	this->scheduleUpdate();

	auto endButton = cocos2d::MenuItemImage::create("turnend.png", "turnend.png",CC_CALLBACK_0(GameMainScene::onEndButton,this));

	endButton->setPosition(cocos2d::Vec2(endButton->getContentSize().width, 750));
	endButton->setScale(0.5f);
	auto menu = cocos2d::Menu::create(endButton,nullptr);
	menu->setPosition(cocos2d::Point::ZERO);
	this->addChild(menu);

	return true;
}

void GameMainScene::update(float at){
	mState->update(at);
}

bool GameMainScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}

void GameMainScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}

void GameMainScene::onEndButton(){
	mState->onEndButton();
}