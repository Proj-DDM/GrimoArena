#include "PlayerDeck.h"
#include "CharacterPanel.h"
#include "../Test/SamplePanel.h"
#include "../Test/HigePanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
#include "Character.h"
#include "SampleHige.h"	
#include "SampleKamata.h"
#include "CharacterFactory.h"
#include "../UI/ParameterView.h"

using namespace cocos2d;

PlayerDeck::PlayerDeck() :nowCharacterID(CharacterID::Length),isSummons(false)
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

void PlayerDeck::add(Character* panel)
{
	addChild(panel);
	deck.push_back(panel);
}

void PlayerDeck::deckInit()
{
	//using PositionX = std::vector < int > ;
	//PositionX positionX{ 46, 118, 192, 266, 336, 406 };
	int positionX[] = { 46, 118, 192, 266, 336, 406 };
	
	CharacterFactory factory;
	factory.init();
	add(factory.create(CharacterID::WaterAttribute, Vec2(positionX[0],60)));
	add(factory.create(CharacterID::WaterAttribute, Vec2(positionX[1], 60)));
	add(factory.create(CharacterID::Kamata,         Vec2(positionX[2], 60)));
	add(factory.create(CharacterID::Kamata,         Vec2(positionX[3], 60)));
	add(factory.create(CharacterID::FireAttribute,  Vec2(positionX[4], 60)));
	add(factory.create(CharacterID::FireAttribute,  Vec2(positionX[5], 60)));
}

void PlayerDeck::update(float deltaTime)
{
	for (auto& panel : deck)
	{
		if (panel->IsTouch())
		{
			if (nowCharacterID == panel->getCharacterID()) 
				return;
			nowCharacterID = panel->getCharacterID();

			nowParameter = panel->getParameter();
		}
	}
}

bool PlayerDeck::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	isSummons = false;
	
	for (auto& panel : deck)
	{
		if (panel->onTouchBegan(touch, event))
		{
			isSummons = true;
			CharacterFactory factory;
			factory.init();
			auto character = factory.create(panel->getCharacterID(),touch->getLocation());
			character->setName("summon");
			character->setOpacity(80);
			addChild(character);
			auto view = dynamic_cast<ParameterView*>(getParent()->getChildByName("View"));
			view->setParameter(panel->getParameter());
			continue;
		}
	}
	if (isSummons) return true;
	return false;
}

void PlayerDeck::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Node* sprite = getChildByName("summon");
	Vec2 delta = touch->getDelta();
	Vec2 position = sprite->getPosition();
	Vec2 newPosition = position + delta;
	sprite->setPosition(newPosition);
}

void PlayerDeck::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	removeChildByName("summon");
}