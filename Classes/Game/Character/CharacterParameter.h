#ifndef _CHARACTERPARAMETER_H_
#define _CHARACTERPARAMETER_H_

#include "HP.h"
#include "../../Utility/FileIO/CharaData.h"

struct Parameter
{
	HP hp;
	int attackPoint;
	int speed;
	int cost;
	Move move;
	int attribute;

	Parameter() :hp(0), attackPoint(0), speed(0)
	{

	}

	Parameter(int _hp, int _attackPoint, int _speed) :hp(_hp), attackPoint(_attackPoint), speed(_speed)
	{

	}
};

#endif