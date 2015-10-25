#include "SampleKamata.h"

using namespace cocos2d;

Kamata::Kamata(const Parameter& param) : Character(param)
{
}

Kamata::Kamata()
{
}

Kamata::~Kamata()
{
}

bool Kamata::init(const cocos2d::Vec2& position)
{
	sprite = Sprite::create("attack_fire1.png");
	sprite->setScale(0.1f);
	addChild(sprite);
	setPosition(position);
	return true;
}

Kamata* Kamata::create()
{
	auto instance = new Kamata();

	if (instance){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

Kamata* Kamata::clone(const Parameter& param, const cocos2d::Vec2& position)
{
	auto chara = new Kamata(param);

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}