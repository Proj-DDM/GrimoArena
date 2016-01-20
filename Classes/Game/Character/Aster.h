#ifndef _Aster_H_
#define _Aster_H_

#include "Character.h"

class Aster : public Character
{
public:
	Aster(const Parameter& param);
	Aster();
	~Aster();
	bool init(const cocos2d::Vec2& position)override;
	static Aster* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif