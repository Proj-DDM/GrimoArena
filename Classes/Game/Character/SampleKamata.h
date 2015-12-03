#ifndef _SAMPLEKAMATA_H_
#define _SAMPLEKAMATA_H_

#include "Character.h"

class Kamata : public Character
{
public:
	Kamata(const Parameter& param);
	Kamata();
	~Kamata();
	bool init(const cocos2d::Vec2& position)override;
	static Kamata* create(const Parameter& param, const cocos2d::Vec2& position);
	static Kamata* create(const cocos2d::Vec2& position);
private:

};


#endif