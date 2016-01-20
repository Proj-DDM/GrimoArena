#include "Fenrir.h"
#include "PlayerJudged.h"

Fenrir::Fenrir(const Parameter & param) : Character(param)
{
}

Fenrir::Fenrir()
{
}

Fenrir::~Fenrir()
{
}

bool Fenrir::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon3_icon_b") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Fenrir;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Fenrir * Fenrir::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Fenrir(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
