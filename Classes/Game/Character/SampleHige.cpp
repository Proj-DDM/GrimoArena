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
	sprite = Sprite::create("attack_fire1.png");
	sprite->setScale(0.1f);
	addChild(sprite);
	setPosition(position);
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