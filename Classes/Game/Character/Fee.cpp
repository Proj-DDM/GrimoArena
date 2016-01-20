#include "Fee.h"
#include "PlayerJudged.h"

Fee::Fee(const Parameter & param) : Character(param)
{
}

Fee::Fee()
{
}

Fee::~Fee()
{
}

bool Fee::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon6_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Fee;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Fee * Fee::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Fee(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
