#include "Orthros.h"
#include "PlayerJudged.h"

Orthros::Orthros(const Parameter & param) : Character(param)
{
}

Orthros::Orthros()
{
}

Orthros::~Orthros()
{
}

bool Orthros::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon3_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Orthros;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Orthros * Orthros::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Orthros(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
