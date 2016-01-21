#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "ResultState.h"

class ResultScene : public cocos2d::Layer
{
public:
	ResultScene();
	~ResultScene();

	static ResultScene* create();

	bool init();

	ResultState* mState;

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