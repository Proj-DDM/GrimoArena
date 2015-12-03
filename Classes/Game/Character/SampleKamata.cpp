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
	sprite = Sprite::create("mon2_tati_r.png");
	//sprite->setScale(0.1f);
	addChild(sprite);
	id = CharacterID::FireAttribute;
	sprite->setPosition(position);
	return true;
}


Kamata* Kamata::create(const Parameter& param, const cocos2d::Vec2& position)
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

Kamata* Kamata::create(const cocos2d::Vec2& position)
{
	auto chara = new Kamata();

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}