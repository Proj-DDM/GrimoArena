#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "CharacterParameter.h"
#include "CharacterType.h"
#include <vector>

class Character : public cocos2d::Node
{
public:
	Character( const Parameter& param );
	Character();
	~Character();
	virtual bool init(const cocos2d::Vec2& position);
	Parameter& getParameter();		//キャラのパラメータ
	CharacterState& getState();

	Character* create(const Parameter& param, const cocos2d::Vec2& position);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void setOpacity(int alpha);
	

	CharacterID getCharacterID() const
	{
		return id;
	}

	CharacterUser getCharacterUser() const
	{
		return user;
	}

	bool IsTouch()const
	{
		return isTouch;
	}


protected:
	Parameter parameter;
	cocos2d::Sprite* sprite;
	CharacterID id;
	CharacterUser user;
	CharacterState state;
	bool isTouch;
};


#endif