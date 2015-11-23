#ifndef _COLOR_CHANGE_H_
#define _COLOR_CHENGE_H_

#include "cocos2d.h"
#include "../PanelCore.h"
#include <array>

class ColorChange{
public:
	ColorChange();
	~ColorChange();
public:
	void changeColor(cocos2d::Node* node, int value, PanelContainer container, int trun);
	void setPanel(cocos2d::Node* node, int value, PanelContainer container, int trun);
	void posCast(cocos2d::Node* node, int value, PanelContainer container);
	//êFïœÇ¶é¿çs
	void checkColor(cocos2d::Node* node, int value, PanelContainer container);
	void setColor(StagePanel* node, int value);
	void allClear();
public:
	int mChangePanelNum;
	int mTestTrun;
	cocos2d::Vec2 mBaseLine;
	cocos2d::Vec2 mCharaLine;
	cocos2d::Vec2 mPanelLine;
	std::array<int, 25> mTestArray;
};

#endif