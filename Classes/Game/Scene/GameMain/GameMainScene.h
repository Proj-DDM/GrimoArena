#ifndef GAMEMAINSCENE_H
#define GAMEMAINSCENE_H

#include "GameMainState.h"

class GameMainScene : public cocos2d::Layer
{
public:
	GameMainScene();
	~GameMainScene();

	static GameMainScene* create();

	bool init();

	GameMainState* mState;

	void update(float at);

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif