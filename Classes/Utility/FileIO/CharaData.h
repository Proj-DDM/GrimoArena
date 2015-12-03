#ifndef CHARADATA_H
#define CHARADATA_H

#include <string>

struct Move
{
	int x;
	int y;
};

struct CharaData
{
	std::string textureName;

	int hp;
	
	Move move;

	int attack;

	int speed;

	int attribute;

	int cost;

	int vect[25];

	CharaData(){

		textureName = "";

		hp = 0;

		move.x = 0;
		
		move.y = 0;

		attack = 0;

		speed = 0;

		attribute = 0;

		cost = 0;

	}
	
};

#endif