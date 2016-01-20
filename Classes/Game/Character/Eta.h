#ifndef _ETA_H_
#define _ETA_H_

#include "Character.h"

class Eta : public Character
{
public:
	Eta(const Parameter& param);
	Eta();
	~Eta();
	bool init(const cocos2d::Vec2& position)override;
	static Eta* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif