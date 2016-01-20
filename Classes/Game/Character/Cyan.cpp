#include "Cyan.h"
#include "PlayerJudged.h"

Cyan::Cyan(const Parameter & param) : Character(param)
{
}

Cyan::Cyan()
{
}

Cyan::~Cyan()
{
}

bool Cyan::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon4_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Cyan;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Cyan * Cyan::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Cyan(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
