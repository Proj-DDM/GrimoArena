#include "PlayerDeck.h"
#include "CharacterPanel.h"
#include "../Test/HigePanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
#include "Character.h"
#include "CharacterFactory.h"
#include "Game/UI/ParameterView.h"


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
	auto sprite = Sprite::create("Scene/Main/ui_party_frame.png");
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
	removeAllChildren();

	//using PositionX = std::vector < int > ;
	//PositionX positionX{ 46, 118, 192, 266, 336, 406 };
	int positionX[] = { ICONSIZE / 2, positionX[0] + ICONSIZE, positionX[1] + ICONSIZE, 
				positionX[2] + ICONSIZE, positionX[3] + ICONSIZE, positionX[4] + ICONSIZE };
	auto ui = this->getChildByName("Deck");

	CharacterFactory factory;
	factory.init();

	add(factory.create(CharacterID::Cerberus, Vec2(positionX[0], 130), 0));
	add(factory.create(CharacterID::Fee, Vec2(positionX[1], 130), 0));
	add(factory.create(CharacterID::Lilith, Vec2(positionX[2], 130), 0));
	add(factory.create(CharacterID::Phoenix, Vec2(positionX[3], 130), 0));
	add(factory.create(CharacterID::Ruby, Vec2(positionX[4], 130), 0));
	add(factory.create(CharacterID::Rouge, Vec2(positionX[5], 130), 0));
}

void PlayerDeck::deckInitByP1()
{
	removeAllChildren();

	//using PositionX = std::vector < int > ;
	//PositionX positionX{ 46, 118, 192, 266, 336, 406 };
	int positionX[] = { ICONSIZE / 2, positionX[0] + ICONSIZE, positionX[1] + ICONSIZE,
		positionX[2] + ICONSIZE, positionX[3] + ICONSIZE, positionX[4] + ICONSIZE };
	auto ui = this->getChildByName("Deck");

	CharacterFactory factory;
	factory.init();

	add(factory.create(CharacterID::Cerberus, Vec2(positionX[0], 130), 0));
	add(factory.create(CharacterID::Fee, Vec2(positionX[1], 130), 0));
	add(factory.create(CharacterID::Lilith, Vec2(positionX[2], 130), 0));
	add(factory.create(CharacterID::Phoenix, Vec2(positionX[3], 130), 0));
	add(factory.create(CharacterID::Ruby, Vec2(positionX[4], 130), 0));
	add(factory.create(CharacterID::Rouge, Vec2(positionX[5], 130), 0));
}

void PlayerDeck::deckInitByP2()
{
	removeAllChildren();

	//using PositionX = std::vector < int > ;
	//PositionX positionX{ 46, 118, 192, 266, 336, 406 };
	int positionX[] = { ICONSIZE / 2, positionX[0] + ICONSIZE, positionX[1] + ICONSIZE,
		positionX[2] + ICONSIZE, positionX[3] + ICONSIZE, positionX[4] + ICONSIZE };
	auto ui = this->getChildByName("Deck");

	CharacterFactory factory;
	factory.init();

	add(factory.create(CharacterID::Aster, Vec2(positionX[0], 130), 0));
	add(factory.create(CharacterID::DryArd, Vec2(positionX[1], 130), 0));
	add(factory.create(CharacterID::Eta, Vec2(positionX[2], 130), 0));
	add(factory.create(CharacterID::Griffon, Vec2(positionX[3], 130), 0));
	add(factory.create(CharacterID::Mint, Vec2(positionX[4], 130), 0));
	add(factory.create(CharacterID::Emerald, Vec2(positionX[5], 130), 0));
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
		if (panel->onTouchCheck(touch->getLocation()))
		{
			isSummons = true;
			CharacterFactory factory;
			factory.init();
			auto character = factory.create(panel->getCharacterID(),touch->getLocation(), 0);
			character->setName("summon");
			character->setOpacity(80);
			addChild(character);
			ParameterView* view = dynamic_cast<ParameterView*>(getParent()->getChildByName("View"));
			Parameter param { panel->getParameter() };
			
			view->setParameter(param);
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