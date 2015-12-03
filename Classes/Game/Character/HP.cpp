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
	return (hp <= 0);
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

bool HP::operator==(const HP& hp)
{
	if (this->hp == hp.getHp())
	{
		return true;
	}
	return false;
}

bool HP::operator!=(const HP& hp)
{
	if (this->hp != hp.getHp())
	{
		return true;
	}
	return false;
}

int HP::getHp()const
{
	return std::max(hp, 0);
}