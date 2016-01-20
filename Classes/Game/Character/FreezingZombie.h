#ifndef _FREEZINGZOMBIE_H_
#define _FREEZINGZOMBIE_H_

#include "Character.h"

class FreezingZombie : public Character
{
public:
	FreezingZombie(const Parameter& param);
	FreezingZombie();
	~FreezingZombie();
	bool init(const cocos2d::Vec2& position)override;
	static FreezingZombie* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif