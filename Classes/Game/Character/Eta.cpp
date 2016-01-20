#include "Eta.h"
#include "PlayerJudged.h"

Eta::Eta(const Parameter & param): Character(param)
{
}

Eta::Eta()
{
}

Eta::~Eta()
{
}

bool Eta::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon6_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Eta;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Eta * Eta::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Eta(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
