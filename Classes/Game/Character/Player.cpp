#include "Player.h"
#include "Utility/Math/MyMath.h"
using namespace cocos2d;

#define MAX_HP 500

Player::Player()
{
}

Player::~Player()
{
}



bool Player::init(const cocos2d::Vec2& position, const std::string& name)
{
	parameter = Parameter(500, 0, 0);
	sprite = Sprite::create(name);
	addChild(sprite);
	setPosition(position);
	
	return true;
}

Player* Player::create(const cocos2d::Vec2& position, int number, const std::string& name)
{
	auto chara = new Player();

	if (chara && chara->init(position,name)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}

void Player::setPosition(const cocos2d::Vec2& position){
	sprite->setPosition(Vec2(position.x - ICONSIZE / 2, position.y - ICONSIZE / 2));

	this->panelNumber = CharactorCore::convertPositonToNumber(this->sprite->getPositionX(), this->sprite->getPositionY());

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

cocos2d::Sprite* Player::setIcon(std::string textureName){
	return nullptr;
}