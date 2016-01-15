#ifndef _CHARACTERTYPE_H_
#define _CHARACTERTYPE_H_

#include <string>

enum class CharacterID
{
	FireAttribute,
	WaterAttribute,
	Kamata,
	Length
};

enum class CharacterUser {
	Player1,
	Player2
};

enum class CharacterState {
	SupportWait,
	SupportEnd,
	MoveWait,
	MoveEnd,
	AttackWait,
	AttackEnd,
	Dead,
};

#endif