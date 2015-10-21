#ifndef _COLOR_CHANGE_H_
#define _COLOR_CHENGE_H_

#include "cocos2d.h"

class ColorChange{
public:
	ColorChange();
	~ColorChange();
public:
	void changeColor(cocos2d::Node* node, int value);
	void setPanel(cocos2d::Node* node, int value);
	void posCast(cocos2d::Node* node, int value);
	void setColor(cocos2d::Node* node, int value);
	void allClear();
public:
	int mColorChangePosition;
};

#endif