#ifndef _CYAN_H_
#define _CYAN_H_

#include "Character.h"

class Cyan : public Character
{
public:
	Cyan(const Parameter& param);
	Cyan();
	~Cyan();
	bool init(const cocos2d::Vec2& position)override;
	static Cyan* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif