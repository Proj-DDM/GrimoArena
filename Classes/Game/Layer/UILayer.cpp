#include "UILayer.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
#include "../Character/PlayerDeck.h"
#include "../Character/CharacterPanel.h"
#include "../UI/ParameterView.h"

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
	auto onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, onTouchMoved, onTouchEnd, nullptr);
	playerDeck = PlayerDeck::create();
	this->addChild(playerDeck);
	this->schedule(schedule_selector(UILayer::update));
	this->scheduleUpdate();
	view = ParameterView::create();
	addChild(view);
	view->setVisible(false);
	setTag(1);


	return true;
}

void UILayer::update(float deltaTime)
{
	playerDeck->update(deltaTime);
}

bool UILayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	//auto touch = getParent()->getChildByName("");
	if (!playerDeck->onTouchBegan(touch, event))
	{
		view->setVisible(false);
		return false;
	}
	
	return true;
}

void UILayer::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	playerDeck->onTouchMoved(touch,event);
}

void UILayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	playerDeck->onTouchEnded(touch, event);
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