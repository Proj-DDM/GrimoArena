#include "DryArd.h"
#include "PlayerJudged.h"

DryArd::DryArd(const Parameter & param) : Character(param)
{
}

DryArd::DryArd()
{
}

DryArd::~DryArd()
{
}

bool DryArd::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon5_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::DryArd;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

DryArd * DryArd::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new DryArd(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
