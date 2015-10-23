#ifndef _CHARACTERPARAMETER_H_
#define _CHARACTERPARAMETER_H_

#include "HP.h"

struct Parameter
{
	HP hp;
	int attackPoint;
	int speed;

	Parameter(int _hp, int _attackPoint, int _speed) :hp(_hp), attackPoint(_attackPoint), speed(_speed)
	{

	}
};

#endif