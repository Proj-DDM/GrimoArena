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
	sprite = Sprite::create("Chara/fairy_red.png");
	addChild(sprite);
	id = CharacterID::Kamata;
	sprite->setPosition(position);
	return true;
}

Hashigo* Hashigo::create(const Parameter& param, const cocos2d::Vec2& position)
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