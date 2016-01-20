#include "Lilith.h"
#include "PlayerJudged.h"

Lilith::Lilith(const Parameter & param) : Character(param)
{
}

Lilith::Lilith()
{
}

Lilith::~Lilith()
{
}

bool Lilith::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon7_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Lilith;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Lilith * Lilith::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Lilith(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
