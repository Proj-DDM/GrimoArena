#include "Player.h"
using namespace cocos2d;



Player::Player()
{
}

Player::~Player()
{
}

Player* Player::create()
{
	auto instance = new Player();

	if (instance&&init){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
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
