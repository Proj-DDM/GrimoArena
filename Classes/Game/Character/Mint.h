#ifndef _MINT_H_
#define _MINT_H_

#include "Character.h"

class Mint : public Character
{
public:
	Mint(const Parameter& param);
	Mint();
	~Mint();
	bool init(const cocos2d::Vec2& position)override;
	static Mint* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif