#ifndef _CHARACTERTYPE_H_
#define _CHARACTERTYPE_H_

#include <string>

enum class CharacterID
{
	Aster,
	Cerberus,
	Cockatrice,
	Cyan,
	DryArd,
	Emerald,
	Eta,
	Fee,
	Fenrir,
	FreezingZombie,
	Griffon,
	Kelvin,
	Levy,
	Lilith,
	Mint,
	Myu,
	Orthros,
	Phoenix,
	RottenwoodZombie,
	Rouge,
	Ruby,
	Sapphire,
	Vect,
	Zombie,
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