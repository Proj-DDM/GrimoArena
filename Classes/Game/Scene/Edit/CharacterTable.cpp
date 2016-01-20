#include "CharacterTable.h"
#include "../../Character/SampleHige.h"
#include "../../Character/SampleKamata.h"
#include "../../../Utility/cocosAssistant/ListenerAssistant.h"
#include "../../Character/CharacterFactory.h"
#include "../../Character/CharacterType.h"
#include "../../Character/Zombie.h"

using namespace cocos2d;

CharacterTable::CharacterTable()
{
}

CharacterTable::~CharacterTable()
{
	//•ÛŽ‚µ‚Ä‚¢‚éƒpƒlƒ‹‚ð‚·‚×‚Äíœ
	CharacterContainer::iterator i = container.begin();
	while (i != container.end())
	{
		CC_SAFE_RELEASE(*i);
		++i;
	}
}

bool CharacterTable::init()
{
	container.clear();
	auto sprite = Sprite::create();
	sprite->setTextureRect(Rect(0, 0, 1024, 200));
	sprite->setColor(Color3B::GREEN);
	setName("Table");

	auto onTouchBegan = CC_CALLBACK_2(CharacterTable::onTouchBegan, this);
	auto onTouchMove  = CC_CALLBACK_2(CharacterTable::onTouchMoved, this);
	auto onTouchEnd = CC_CALLBACK_2(CharacterTable::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, onTouchMove, onTouchEnd, nullptr);

	sprite->setPosition(Director::getInstance()->getWinSize().width / 2, 150);
	addChild(sprite);
	
	int positionX[] = { ICONSIZE / 2, positionX[0] + ICONSIZE, positionX[1] + ICONSIZE,
		positionX[2] + ICONSIZE, positionX[3] + ICONSIZE, positionX[4] + ICONSIZE };

	CharacterFactory factory;
	factory.init();
	
	add(factory.create(CharacterID::RottenwoodZombie, Vec2(positionX[0], 200),0));
	add(factory.create(CharacterID::Rouge,			Vec2(positionX[1], 200),0));
	add(factory.create(CharacterID::Ruby,  Vec2(positionX[2], 200),0));
	add(factory.create(CharacterID::Sapphire, Vec2(positionX[3], 200), 0));
	add(factory.create(CharacterID::Vect, Vec2(positionX[4], 200), 0));
	add(factory.create(CharacterID::Zombie, Vec2(positionX[5], 200), 0));
	
	return true;
}

void CharacterTable::update(float deltaTime)
{
}

void CharacterTable::add(Character * chara)
{
	container.push_back(chara);
	this->addChild(chara);
}

bool CharacterTable::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	for (auto& panel : container)
	{
		if (panel->onTouchBegan(touch, event))
		{
			isSummons = true;
			CharacterFactory factory;
			factory.init();
			auto character = factory.create(panel->getCharacterID(), touch->getLocation(),0);
			character->setName("summon");
			character->setOpacity(80);
			addChild(character);
			/*auto view = dynamic_cast<ParameterView*>(getParent()->getChildByName("View"));
			view->setParameter(panel->getParameter());*/
			this->nowCharacterID = panel->getCharacterID();
			continue;
		}
	}
	if (isSummons) return true;
	return false;
}

void CharacterTable::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Node* sprite = getChildByName("summon");
	if (!sprite)return;
	Vec2 delta = touch->getDelta();
	Vec2 position = sprite->getPosition();
	Vec2 newPosition = position + delta;
	sprite->setPosition(newPosition);
}

void CharacterTable::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	removeChildByName("summon");
}

CharacterTable * CharacterTable::create()
{
		auto obj = new CharacterTable();

	if (obj && obj->init()) {
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}
