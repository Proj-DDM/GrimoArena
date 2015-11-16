#ifndef _SAMPLEHIGE_H_
#define _SAMPLEHIGE_H_

#include "Character.h"

class Hige : public Character
{
public:
	Hige(const Parameter& param);
	Hige();
	~Hige();
	bool init(const cocos2d::Vec2& position)override;
	static Hige* create(const Parameter& param, const cocos2d::Vec2& position);
	static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif