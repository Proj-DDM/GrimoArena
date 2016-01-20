#include "Ruby.h"
#include "PlayerJudged.h"

Ruby::Ruby(const Parameter & param) : Character(param)
{
}

Ruby::Ruby()
{
}

Ruby::~Ruby()
{
}

bool Ruby::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon1_icon_r") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Ruby;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Ruby * Ruby::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Ruby(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
