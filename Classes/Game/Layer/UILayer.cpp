#include "UILayer.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
#include "../Character/PlayerDeck.h"
#include "../Character/CharacterPanel.h"

using namespace cocos2d;

UILayer::UILayer()
{
}

UILayer::~UILayer()
{
}

bool UILayer::init()
{

	auto onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(UILayer::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, nullptr, onTouchEnd, nullptr);
	playerDeck = PlayerDeck::create();
	this->addChild(playerDeck);
	this->schedule(schedule_selector(UILayer::update));
	this->scheduleUpdate();

	setTag(1);



	return true;
}

void UILayer::update(float deltaTime)
{
	playerDeck->update(deltaTime);
}

bool UILayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	/*auto sprite = Sprite::create("kamata.JPG");
	sprite->setScale(.2f);
	sprite->setPosition(300, 300);
	this->addChild(sprite);*/
	return true;
}

void UILayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}

UILayer* UILayer::create()
{
	auto layer = new UILayer();

	if (layer && layer->init()){
		layer->retain();
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return nullptr;
}