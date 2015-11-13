#include "Character.h"

Character::Character(const Parameter& param)
	:parameter(param)
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