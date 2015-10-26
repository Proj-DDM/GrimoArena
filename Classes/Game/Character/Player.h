#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();
	bool init(const cocos2d::Vec2& position)override;
	static Player* create();

private:
	
};

#endif