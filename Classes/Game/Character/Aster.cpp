#include "Aster.h"
#include "PlayerJudged.h"

Aster::Aster(const Parameter & param) : Character(param)
{
}

Aster::Aster()
{
}

Aster::~Aster()
{
}

bool Aster::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon7_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::Aster;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Aster * Aster::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Aster(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
