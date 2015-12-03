#include "HP.h"
#include <algorithm>

HP::HP(int value) :hp(value)
{
}

HP::HP() : hp(0)
{
}

HP::~HP()
{
}

bool HP::isDead()
{
	return (hp < 0);
}

HP& HP::operator-=(int point)
{
	this->hp -= point;
	return *this;
}

HP& HP::operator+=(int point)
{
	this->hp += point;
	return *this;
}

int HP::getHp()const
{
	return std::max(hp, 0);
}