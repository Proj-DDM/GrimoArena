#ifndef _Cerberus_H_
#define _Cerberus_H_

#include "Character.h"

class Cerberus : public Character
{
public:
	Cerberus(const Parameter& param);
	Cerberus();
	~Cerberus();
	bool init(const cocos2d::Vec2& position)override;
	static Cerberus* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif