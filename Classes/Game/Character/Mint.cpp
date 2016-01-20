#include "Mint.h"
#include "PlayerJudged.h"

Mint::Mint(const Parameter & param) : Character(param)
{
}

Mint::Mint()
{
}

Mint::~Mint()
{
}

bool Mint::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon1_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Mint;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Mint * Mint::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Mint(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
