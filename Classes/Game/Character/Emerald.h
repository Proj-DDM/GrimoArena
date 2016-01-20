#ifndef _EMERALD_H_
#define _EMERALD_H_

#include "Character.h"

class Emerald : public Character
{
public:
	Emerald(const Parameter& param);
	Emerald();
	~Emerald();
	bool init(const cocos2d::Vec2& position)override;
	static Emerald* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif