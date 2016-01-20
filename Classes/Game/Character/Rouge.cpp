#include "Rouge.h"
#include "PlayerJudged.h"

Rouge::Rouge(const Parameter & param) : Character(param)
{
}

Rouge::Rouge()
{
}

Rouge::~Rouge()
{
}

bool Rouge::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon4_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Rouge;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Rouge * Rouge::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Rouge(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
