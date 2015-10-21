#ifndef _STAGE_MANAGER_H_
#define _STAGE_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>

class StageManager : public cocos2d::Node {
	
protected:
	
	StageManager() = default;
	
	~StageManager() = default;
	
public:
	
	static StageManager* create();
	
	virtual bool init() override;

	void update(float at) override;

	void onTouchBegan(cocos2d::Point pos);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

	void reset();

	void changeColor(cocos2d::Node* node);

	void focusPanel(cocos2d::Node* node);
private:
	cocos2d::Node*	mPanelNode;
public:
	int mCount;
};

#endif