#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "CharacterParameter.h"

class Character : public cocos2d::Node
{
public:
	Character( const Parameter& param );
	Character();
	~Character();
	virtual bool init(const cocos2d::Vec2& position);
	virtual Character* clone(const Parameter& param, const cocos2d::Vec2& position) = 0;
protected:
	Parameter parameter;
	cocos2d::Sprite* sprite;
};


#endif