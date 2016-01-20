#include "Phoenix.h"
#include "PlayerJudged.h"

Phoenix::Phoenix(const Parameter & param) : Character(param)
{
}

Phoenix::Phoenix()
{
}

Phoenix::~Phoenix()
{
}

bool Phoenix::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon8_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Phoenix;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Phoenix * Phoenix::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Phoenix(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
