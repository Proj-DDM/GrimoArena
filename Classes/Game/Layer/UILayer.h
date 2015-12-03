#ifndef _UILAYER_H_
#define _UILAYER_H_

#include "cocos2d.h"

class PlayerDeck;
class ParameterView;

class UILayer:public cocos2d::Layer
{
public:
	

	static UILayer* create();

	virtual bool init()override;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void update(float deltaTime)override;

protected:
	UILayer();
	~UILayer();

private:
	PlayerDeck* playerDeck;
	ParameterView* view;
};


#endif
