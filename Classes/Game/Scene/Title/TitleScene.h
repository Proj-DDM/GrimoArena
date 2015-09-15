#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "TitleState.h"
#include "Utility/Audio/ADX2Player.h"


class TitleScene : public cocos2d::Layer
{
public:
	TitleScene();
	~TitleScene();

	static TitleScene* create();

	bool init();

	TitleState* mState;

	void update(float at);

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    ADX2Player* ply;

};

#endif