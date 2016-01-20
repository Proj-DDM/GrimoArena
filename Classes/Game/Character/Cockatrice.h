#ifndef _COCKATRICE_H_
#define _COCKATRICE_H_

#include "Character.h"

class Cockatrice : public Character
{
public:
	Cockatrice(const Parameter& param);
	Cockatrice();
	~Cockatrice();
	bool init(const cocos2d::Vec2& position)override;
	static Cockatrice* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif