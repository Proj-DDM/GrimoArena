#ifndef _CHARACTERPARAMETER_H_
#define _CHARACTERPARAMETER_H_

#include "HP.h"
#include "../../Utility/FileIO/CharaData.h"

struct Parameter
{
	int speed;
	std::string name;
	HP hp;
	int attackPoint;
	int cost;
	Move move;
	int attribute;
	int vect[25];
	int position;
	int stock { -1 };


	Parameter() :hp(0), attackPoint(0), speed(0), cost(0), attribute(0), name(""), position(0), stock( 3 )
	{

	}

	Parameter(int _hp, int _attackPoint, int _speed) :hp(_hp), attackPoint(_attackPoint), speed(_speed)
	{

	}

	bool operator == (const Parameter& param)
	{
		if (this->name != param.name)return false;
		if (this->hp != param.hp)return false;
		if (this->attackPoint != param.attackPoint)return false;
		if (this->attribute != param.attribute)return false;
		if (this->cost != cost)return false;
		if (this->move != param.move)return false;
		if (this->speed != param.speed)return false;
		if (this->vect != param.vect)return false;

		return true;
	}
};

#endif