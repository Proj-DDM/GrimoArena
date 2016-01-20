#include "Kelvin.h"
#include "PlayerJudged.h"

Kelvin::Kelvin(const Parameter & param) : Character(param)
{
}

Kelvin::Kelvin()
{
}

Kelvin::~Kelvin()
{
}

bool Kelvin::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon5_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Kelvin;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Kelvin * Kelvin::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Kelvin(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
