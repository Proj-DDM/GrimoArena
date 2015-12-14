#include "SampleHige.h"

using namespace cocos2d;

Hige::Hige(const Parameter& param) : Character(param)
{
}

Hige::Hige()
{
}

Hige::~Hige()
{
}

bool Hige::init(const cocos2d::Vec2& position)
{
	sprite = Sprite::create("Chara/fairy_green.png");
	//sprite->setScale(0.1f);
	id = CharacterID::WaterAttribute;
	addChild(sprite);
	sprite->setPosition(position);
	return true;
}


Hige* Hige::create(const Parameter& param, const cocos2d::Vec2& position)
{
	auto chara = new Hige(param);

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}

Hige* Hige::create(const cocos2d::Vec2& position)
{
	auto chara = new Hige();

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}