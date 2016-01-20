#include "Sapphire.h"
#include "PlayerJudged.h"

Sapphire::Sapphire(const Parameter & param) : Character(param)
{
}

Sapphire::Sapphire()
{
}

Sapphire::~Sapphire()
{
}

bool Sapphire::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon1_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Sapphire;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Sapphire * Sapphire::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Sapphire(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
