#include "ColorChange.h"
#include "cocos2d.h"
#include <array>
#include <stdlib.h>

#define MAX_ARRAY  24

using namespace cocos2d;

ColorChange::ColorChange() {}

ColorChange::~ColorChange() {}

void ColorChange::changeColor(Node* node, int value) {
	mCount = 0;
	mBaseLine = Vec2(0,0);
	mCharaLine = Vec2(0,0);
	setPanel(node, value);
}

void ColorChange::setPanel(Node* node, int value) {
	//仮のキャラデータ
	mTestArray = {0, 0, 0, 0, 0,
				  0, 1, 0, 1, 0,
				  0, 0, 2, 0, 0,
				  0, 1, 0, 1, 0,
				  0, 0, 0, 0, 0 };

	for (int i = 0; i < mTestArray.size(); ++i) {
		if (mTestArray[i] == 2){
			mCharaLine.x = i % 5;
			mCharaLine.y = i / 5;
			mBaseLine.x = mCharaLine.x;
			mBaseLine.y = mCharaLine.y;
			mCharaLine.x = 0;
			mCharaLine.y = 0;
			CCLOG("%i", (int)mBaseLine.x);
		}
	}
	mCount = 0;
	checkColor(node, value);
	/*for (int i = 0; i < testArray.size(); ++i){
		CCLOG("%i", testArray[i]);
		if (testArray[i] == 1){
			colorChangePoint = i;
			CCLOG("%i", colorChangePoint);
		}
		if (testArray[i] == 2){
			mCharaPos = i;
			CCLOG("%i", mCharaPos);
		}
		if (mCharaPos != 0) {
			mDifferenceCount = mCharaPos - colorChangePoint;
			mDifferenceCount = abs(mDifferenceCount);
		}
		//基本1~11
		if (mCharaPos > colorChangePoint) {
			mColorChangePosition = value + mDifferenceCount;
			setColor(node, mColorChangePosition);
		}
		//基本13~24
		if (mCharaPos < colorChangePoint) {
			mColorChangePosition = value - mDifferenceCount;
			setColor(node, mColorChangePosition);
		}
	}*/
}

void ColorChange::checkColor(Node* node, int value) {
	if (mCount >= mTestArray.size()) return;
	mPanelLine = Vec2(0,0);
	mChangePanelNum = value;
	if (mTestArray[mCount] == 1){
		mPanelLine.x = mCount % 5 - mBaseLine.x;
		mPanelLine.y = (MAX_ARRAY - mCount) / 5 - mBaseLine.y;
		CCLOG("%i", (int)mPanelLine.x);
	}
	int test_x = value % 9 + mPanelLine.x;

	if (test_x >= 0 && test_x < 9){
		mChangePanelNum += mPanelLine.x + mPanelLine.y * 9;
		setColor(node, mChangePanelNum);
	}

	++mCount;
	checkColor(node, value);
}

void ColorChange::setColor(Node* node, int value) {
	if (value < 0 || value > 98) return;
	auto panel = (Sprite*)node->getChildren().at(value);
	auto panelSprite = (Sprite*)panel->getChildByName(panel->getName());
	//ターン制が完成したら変える
	if (panelSprite->getColor() == Color3B::WHITE){
		panelSprite->setColor(Color3B::BLUE);
	}
}

void ColorChange::allClear() {

}