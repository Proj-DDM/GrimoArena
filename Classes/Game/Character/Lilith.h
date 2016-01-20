#ifndef _LILITH_H_
#define _LILITH_H_

#include "Character.h"

class Lilith : public Character
{
public:
	Lilith(const Parameter& param);
	Lilith();
	~Lilith();
	bool init(const cocos2d::Vec2& position)override;
	static Lilith* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif