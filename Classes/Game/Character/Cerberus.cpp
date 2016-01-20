#include "Cerberus.h"
#include "PlayerJudged.h"

Cerberus::Cerberus(const Parameter & param) : Character(param)
{
}

Cerberus::Cerberus()
{
}

Cerberus::~Cerberus()
{
}

bool Cerberus::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon3_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Cerberus;
	sprite->setPosition(position);
	this->addChild(sprite);
	return true;
}

Cerberus * Cerberus::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Cerberus(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
