#include "Griffon.h"
#include "PlayerJudged.h"

Griffon::Griffon(const Parameter & param) : Character(param)
{
}

Griffon::Griffon()
{
}

Griffon::~Griffon()
{
}

bool Griffon::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon8_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Griffon;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Griffon * Griffon::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Griffon(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
