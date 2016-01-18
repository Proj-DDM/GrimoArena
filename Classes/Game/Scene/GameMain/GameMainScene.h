#ifndef GAMEMAINSCENE_H
#define GAMEMAINSCENE_H

#include "GameMainState.h"

class GameMainScene : public cocos2d::Layer
{
public:

	cocos2d::Layer* uiLayer;

	GameMainScene();
	~GameMainScene();

	static GameMainScene* create(cocos2d::Layer* layer);

	bool init(cocos2d::Layer* layer);

	GameMainState* mState;

	void update(float at);

	void onEndButton();

	void onViewButton();

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	//タッチ中
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif