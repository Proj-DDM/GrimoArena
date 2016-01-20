#ifndef _DRYARD_H_
#define _DRYARD_H_

#include "Character.h"

class DryArd : public Character
{
public:
	DryArd(const Parameter& param);
	DryArd();
	~DryArd();
	bool init(const cocos2d::Vec2& position)override;
	static DryArd* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif