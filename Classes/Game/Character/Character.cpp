#include "Character.h"
using namespace cocos2d;

Character::Character(const Parameter& param)
	:parameter(param), isTouch(false)
{
	
}

Character::Character() : parameter(0,0,0)
{
}

Character::~Character()
{
}

bool Character::init(const cocos2d::Vec2& position)
{
	return true;
}

Character* Character::create(const Parameter& param, const cocos2d::Vec2& position)
{
	auto chara = new Character(param);

	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}


Parameter Character::getParameter(){

	return this->parameter;
}

bool Character::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto target = sprite;
	Point touchPoint = touch->getLocation();	//タッチ座標の取得
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(touchPoint))
	{
		sprite->setColor(Color3B::RED);
		isTouch = true;
		return true;
	}
	sprite->setColor(Color3B::WHITE);
	isTouch = false;
	return false;
}

void Character::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}