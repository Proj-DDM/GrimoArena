#ifndef _EDITSCENE_H_
#define _EDiTSCENE_H_

#include "cocos2d.h"
#include "EditState.h"

class EditScene : public cocos2d::Layer
{
public:
	EditScene();
	~EditScene();
	bool init();
	static EditScene* create();
	void update(float deltaTime);

	EditState* mState;
	
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	
};

#endif
