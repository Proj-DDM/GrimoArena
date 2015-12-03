#include "Player.h"
#include "Utility/Math/MyMath.h"
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
	sprite->setScale(0.06f);
	addChild(sprite);
	setPosition(position);
	
	return true;
}

Player* Player::create( const cocos2d::Vec2& position,int number)
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

void Player::setPosition(const cocos2d::Vec2& position){
	sprite->setPosition(Vec2(position.x - 32,position.y - 32));

}

cocos2d::Rect Player::getBoundingBox() const {
	return sprite->getBoundingBox();
}


const cocos2d::Vec2& Player::getPosition() const {
	return sprite->getPosition();
}

void Player::mathMana(const int value){
	this->mana += value;
	this->mana = MyMath::clamp(this->mana, 0, 6);
}