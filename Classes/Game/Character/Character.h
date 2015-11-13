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
	virtual Character* create(const Parameter& param, const cocos2d::Vec2& position);
protected:
	Parameter parameter;
	cocos2d::Sprite* sprite;
	int indexNumber;
};


#endif