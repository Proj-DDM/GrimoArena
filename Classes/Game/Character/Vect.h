#ifndef _VECT_H_
#define _VECT_H_

#include "Character.h"

class Vect : public Character
{
public:
	Vect(const Parameter& param);
	Vect();
	~Vect();
	bool init(const cocos2d::Vec2& position)override;
	static Vect* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif