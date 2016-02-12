#ifndef SKILLFIELD_H
#define	SKILLFIELD_H

#include "cocos2d.h"
#include <array>

class Skill
{
public:
//スキルステータス
	struct Status
	{
		int damage{ 0 };   //ダメージスキル
		int attack{ 0 };   //攻撃力アップ
		int speed{ 0 };    //移動速度アップ
		int moveY{ 0 };    //移動量アップ
		int hp{ 0 };       //体力回復
		std::array<int, 50> skillField;


		Status(){};
	};

//変数
private:
	Status status;


public:
	Skill(){};

	~Skill(){};

	std::array<int, 50>& getArray() { return status.skillField; }

	const Status getStatus() { return this->status; }

	void setStatus(Status status) { this->status = status; }
};

#endif