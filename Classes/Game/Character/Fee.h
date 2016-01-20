#ifndef _FEE_H_
#define _FEE_H_

#include "Character.h"

class Fee : public Character
{
public:
	Fee(const Parameter& param);
	Fee();
	~Fee();
	bool init(const cocos2d::Vec2& position)override;
	static Fee* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif