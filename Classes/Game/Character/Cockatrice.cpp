#include "Cockatrice.h"
#include "PlayerJudged.h"

Cockatrice::Cockatrice(const Parameter & param) : Character(param)
{
}

Cockatrice::Cockatrice()
{
}

Cockatrice::~Cockatrice()
{
}

bool Cockatrice::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon8_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Cockatrice;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Cockatrice * Cockatrice::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Cockatrice(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
