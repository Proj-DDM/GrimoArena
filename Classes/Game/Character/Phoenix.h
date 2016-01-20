#ifndef _PHOENIX_H_
#define _PHOENIX_H_

#include "Character.h"

class Phoenix : public Character
{
public:
	Phoenix(const Parameter& param);
	Phoenix();
	~Phoenix();
	bool init(const cocos2d::Vec2& position)override;
	static Phoenix* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif