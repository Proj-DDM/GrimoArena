#include "FreezingZombie.h"
#include "PlayerJudged.h"

FreezingZombie::FreezingZombie(const Parameter & param) : Character(param)
{
}

FreezingZombie::FreezingZombie()
{
}

FreezingZombie::~FreezingZombie()
{
}

bool FreezingZombie::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon2_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::FreezingZombie;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

FreezingZombie * FreezingZombie::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new FreezingZombie(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
