#ifndef _LEVY_H_
#define _LEVY_H_

#include "Character.h"

class Levy : public Character
{
public:
	Levy(const Parameter& param);
	Levy();
	~Levy();
	bool init(const cocos2d::Vec2& position)override;
	static Levy* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif