#ifndef _SAPPHIRE_H_
#define _SAPPHIRE_H_

#include "Character.h"

class Sapphire : public Character
{
public:
	Sapphire(const Parameter& param);
	Sapphire();
	~Sapphire();
	bool init(const cocos2d::Vec2& position)override;
	static Sapphire* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif
