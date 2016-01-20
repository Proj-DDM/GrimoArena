#ifndef _KELVIN_H_
#define _KELVIN_H_

#include "Character.h"

class Kelvin : public Character
{
public:
	Kelvin(const Parameter& param);
	Kelvin();
	~Kelvin();
	bool init(const cocos2d::Vec2& position)override;
	static Kelvin* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif