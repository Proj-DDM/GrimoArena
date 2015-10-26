#include "PlayerDeck.h"
#include "CharacterPanel.h"
#include "../Test/SamplePanel.h"
#include "../Test/HigePanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"

using namespace cocos2d;

PlayerDeck::PlayerDeck() :nowCharacterID(CharacterID::FireAttribute)
{

}

PlayerDeck::~PlayerDeck()
{
	//•ÛŽ‚µ‚Ä‚¢‚éƒpƒlƒ‹‚ð‚·‚×‚Äíœ
	Deck::iterator i = deck.begin();
	while (i != deck.end())
	{
		CC_SAFE_RELEASE(*i);
		++i;
	}
}

bool PlayerDeck::init()
{
	if ( !Node::init() ) return false;
	deck.clear();
	auto sprite = Sprite::create();
	sprite->setTextureRect(Rect(0, 0, 1024, 100));
	sprite->setColor(Color3B::GREEN);
	setName("Deck");

	auto onTouchBegan = CC_CALLBACK_2(PlayerDeck::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(PlayerDeck::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, nullptr, onTouchEnd, nullptr);

	sprite->setPosition(Director::getInstance()->getWinSize().width / 2, 60);
	addChild(sprite);
	deckInit();
	return true;
}

PlayerDeck* PlayerDeck::create()
{
	auto instance = new PlayerDeck();

	if (instance && instance->init()){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

void PlayerDeck::add(CharacterPanel* panel,float positionX)
{
	addChild(panel);
	panel->setPosition(positionX,60);
	deck.push_back(panel);
}

void PlayerDeck::deckInit()
{
	//using PositionX = std::vector < int > ;
	//PositionX positionX{ 46, 118, 192, 266, 336, 406 };
	int positionX[] = { 46, 118, 192, 266, 336, 406 };
	
	add(KamataPanel::create(), positionX[0]);
	add(CharacterPanel::create(), positionX[1]);
	add(HigePanel::create(), positionX[2]);
	add(CharacterPanel::create(), positionX[3]);
	add(CharacterPanel::create(), positionX[4]);
	add(CharacterPanel::create(), positionX[5]);
}

void PlayerDeck::update(float deltaTime)
{
	for (auto& panel : deck)
	{
		if (panel->IsTouch())
		{
			if (nowCharacterID == panel->getCharacterID()) return;
			nowCharacterID = panel->getCharacterID();
		}
	}
}

bool PlayerDeck::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	for (auto& panel : deck)
	{
		panel->onTouchBegan(touch,event);
	}
	return true;
}

void PlayerDeck::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}