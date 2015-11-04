#ifndef _SAMPLEHASHIGO_H_
#define _SAMPLEHASHIGO_H_

#include "../Character/Character.h"

class Hashigo : public Character
{
public:
	Hashigo();
	Hashigo(const Parameter& param);
	~Hashigo();

	bool init(const cocos2d::Vec2& position)override;
	static Hashigo* create(const Parameter& param, const cocos2d::Vec2& position);


private:

};

#endif