#ifndef _ROTTERNWOODZOMBIE_H_
#define _ROTTERNWOODZOMBIE_H_

#include "Character.h"

class RotternWoodZombie : public Character
{
public:
	RotternWoodZombie(const Parameter& param);
	RotternWoodZombie();
	~RotternWoodZombie();
	bool init(const cocos2d::Vec2& position)override;
	static RotternWoodZombie* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif