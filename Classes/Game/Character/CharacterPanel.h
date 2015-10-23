#ifndef _CHARACTERPANEL_H_
#define _CHARACTERPANEL_H_

#include "cocos2d.h"
#include "CharacterType.h"

class CharacterPanel:public cocos2d::Node
{

public:
	static CharacterPanel* create();
	virtual bool init()override;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	CharacterID getCharacterID()const;

	virtual void setPosition(float x, float y)override
	{
		mSprite->setPosition(x, y);
	}

	bool IsTouch() const
	{
		return isTouch;
	}

protected:
	CharacterPanel();
	~CharacterPanel();
protected:
	cocos2d::Sprite* mSprite;
	CharacterID charaID;
	bool isTouch;
};


#endif