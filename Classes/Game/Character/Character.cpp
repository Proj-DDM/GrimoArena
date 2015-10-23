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
	parameter.hp = 10;
	return true;
}
