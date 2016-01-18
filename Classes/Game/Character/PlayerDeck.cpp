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
	auto sprite = Sprite::create("ui_party_frame.png");
	//sprite->setTextureRect(Rect(0, 0, 1024, 400));
	//sprite->setColor(Color3B::GREEN);
	setName("Deck");


	sprite->setPosition(Director::getInstance()->getWinSize().width / 2, sprite->getContentSize().height / 2);
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
	int positionX[] = { ICONSIZE / 2, positionX[0] + ICONSIZE, positionX[1] + ICONSIZE, 
				positionX[2] + ICONSIZE, positionX[3] + ICONSIZE, positionX[4] + ICONSIZE };
	auto ui = this->getChildByName("Deck");

	CharacterFactory factory;
	factory.init();

	add(factory.create(CharacterID::WaterAttribute, Vec2(positionX[0], 60), 0));
	add(factory.create(CharacterID::WaterAttribute, Vec2(positionX[1], 60), 0));
	add(factory.create(CharacterID::Kamata,         Vec2(positionX[2], 60), 0));
	add(factory.create(CharacterID::Kamata,         Vec2(positionX[3], 60), 0));
	add(factory.create(CharacterID::FireAttribute,  Vec2(positionX[4], 60), 0));
	add(factory.create(CharacterID::FireAttribute,  Vec2(positionX[5], 60), 0));
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
			auto character = factory.create(panel->getCharacterID(),touch->getLocation(), 0);
			character->setName("summon");
			character->setOpacity(80);
			addChild(character);
			auto view = dynamic_cast<ParameterView*>(getParent()->getChildByName("View"));
			view->setParameter(panel->getParameter());
			this->nowCharacterID = panel->getCharacterID();
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
	Parameter param;
	sprite->setPosition(newPosition);
}

void PlayerDeck::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	removeChildByName("summon");
}