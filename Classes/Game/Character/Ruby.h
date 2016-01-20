#ifndef _RUBY_H_
#define _RUBY_H_

#include "Character.h"

class Ruby : public Character
{
public:
	Ruby(const Parameter& param);
	Ruby();
	~Ruby();
	bool init(const cocos2d::Vec2& position)override;
	static Ruby* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif