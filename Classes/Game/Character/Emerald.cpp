#include "Emerald.h"
#include "PlayerJudged.h"

Emerald::Emerald(const Parameter & param) : Character(param)
{
}

Emerald::Emerald()
{
}

Emerald::~Emerald()
{
}

bool Emerald::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon1_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Emerald;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Emerald * Emerald::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Emerald(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
