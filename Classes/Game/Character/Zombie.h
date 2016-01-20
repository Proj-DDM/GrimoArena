#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "Character.h"

class Zombie : public Character
{
public:
	Zombie(const Parameter& param);
	Zombie();
	~Zombie();
	bool init(const cocos2d::Vec2& position)override;
	static Zombie* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif