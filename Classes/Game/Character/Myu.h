#ifndef _MYU_H_
#define _MYU_H_

#include "Character.h"

class Myu : public Character
{
public:
	Myu(const Parameter& param);
	Myu();
	~Myu();
	bool init(const cocos2d::Vec2& position)override;
	static Myu* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif