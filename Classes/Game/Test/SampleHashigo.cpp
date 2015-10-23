#include "SampleHashigo.h"

using namespace cocos2d;

Hashigo::Hashigo(const Parameter& param) : Character(param)
{
}

Hashigo::Hashigo()
{
}

Hashigo::~Hashigo()
{
}

bool Hashigo::init(const cocos2d::Vec2& position)
{
	sprite = Sprite::create("attack_water1.png");
	sprite->setScale(0.5f);
	addChild(sprite);
	setPosition(position);
	return true;
}

Hashigo* Hashigo::create()
{
	auto instance = new Hashigo();

	if (instance){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

Hashigo* Hashigo::clone(const Parameter& param, const cocos2d::Vec2& position)
{
	auto chara = new Hashigo(param);

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}