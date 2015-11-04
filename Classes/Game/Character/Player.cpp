#include "Player.h"
using namespace cocos2d;



Player::Player()
{
}

Player::~Player()
{
}



bool Player::init(const cocos2d::Vec2& position)
{
	parameter = Parameter(500, 0, 0);
	sprite = Sprite::create("player.png");
	sprite->setScale(0.5f);
	addChild(sprite);
	setPosition(position);
	return true;
}

Player* Player::create( const cocos2d::Vec2& position)
{
	auto chara = new Player();

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}