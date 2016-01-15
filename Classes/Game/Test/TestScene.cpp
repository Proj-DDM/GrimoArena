#include "TestScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"
#include "../Character/CharacterPanel.h"
#include "../Character/PlayerDeck.h"

using namespace cocos2d;

TestScene::TestScene()
{

}

TestScene::~TestScene()
{
}



bool TestScene::init()
{
	// e‚Ì‰Šú‰»ˆ—‚ðŒÄ‚Ô
	if (!Layer::init())
	{
		return false;
	}

	auto debugLabel = Label::createWithTTF("Katsumi", "Font/MarkerFelt.ttf", 64);
	debugLabel->setColor(Color3B::RED);
	debugLabel->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	debugLabel->setPosition(Vec2(40, 1200));
	this->addChild(debugLabel);

	this->schedule(schedule_selector(TestScene::update));
	auto onTouchBegan = CC_CALLBACK_2(TestScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(TestScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

	this->scheduleUpdate();

	factory.init();
	manager = CharacterManager::create();
	addChild(manager);
	return true;
}

void TestScene::update(float deltaTime)
{
	
}

TestScene* TestScene::create()
{
	auto instance = new TestScene();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

bool TestScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	Vec2 touchPoint = touch->getLocation();
	if (touchPoint.y <= 120) return false;
	auto uiLayer = getParent()->getChildByTag(1);
	auto id = CharacterID::WaterAttribute;
	auto param = Parameter(10,10,10);
	manager->add(factory.create(id,touchPoint,0));
	return true;
}


void TestScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}