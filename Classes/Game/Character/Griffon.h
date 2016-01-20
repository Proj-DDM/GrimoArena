#ifndef _GRIFFON_H_
#define _GRIFFON_H_

#include "Character.h"

class Griffon : public Character
{
public:
	Griffon(const Parameter& param);
	Griffon();
	~Griffon();
	bool init(const cocos2d::Vec2& position)override;
	static Griffon* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif
