#include "Vect.h"
#include "PlayerJudged.h"

Vect::Vect(const Parameter & param) : Character(param)
{
}

Vect::Vect()
{
}

Vect::~Vect()
{
}

bool Vect::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon5_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Vect;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Vect * Vect::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Vect(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
