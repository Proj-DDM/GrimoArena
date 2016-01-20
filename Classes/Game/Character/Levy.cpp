#include "Levy.h"
#include "PlayerJudged.h"

Levy::Levy(const Parameter & param): Character(param)
{
}

Levy::Levy()
{
}

Levy::~Levy()
{
}

bool Levy::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon7_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Levy;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Levy * Levy::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Levy(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
