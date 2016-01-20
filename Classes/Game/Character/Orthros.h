#ifndef _ORTHROS_H_
#define _ORTHROS_H_

#include "Character.h"

class Orthros : public Character
{
public:
	Orthros(const Parameter& param);
	Orthros();
	~Orthros();
	bool init(const cocos2d::Vec2& position)override;
	static Orthros* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif