#include "Myu.h"
#include "PlayerJudged.h"

Myu::Myu(const Parameter & param) : Character(param)
{
}

Myu::Myu()
{
}

Myu::~Myu()
{
}

bool Myu::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon6_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Myu;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Myu * Myu::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Myu(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
