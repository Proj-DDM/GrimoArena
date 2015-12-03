#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "CharacterParameter.h"
#include "CharacterType.h"

class Character : public cocos2d::Node
{
public:
	Character( const Parameter& param );
	Character();
	~Character();
	virtual bool init(const cocos2d::Vec2& position);
	Parameter getParameter();		//�L�����̃p�����[�^

	Character* create(const Parameter& param, const cocos2d::Vec2& position);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void setOpacity(int alpha);
	

	CharacterID getCharacterID() const
	{
		return id;
	}

	bool IsTouch()const
	{
		return isTouch;
	}


protected:
	Parameter parameter;
	cocos2d::Sprite* sprite;
	CharacterID id;
	bool isTouch;
};


#endif