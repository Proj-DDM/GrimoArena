#include "ColorChange.h"
#include "cocos2d.h"
#include <array>
#include <stdlib.h>

#define MAX_ARRAY  24

using namespace cocos2d;

ColorChange::ColorChange() {}

ColorChange::~ColorChange() {}

void ColorChange::changeColor(Node* node, int value, PanelContainer container) {
	mCount = 0;
	mBaseLine = Vec2(0,0);
	mCharaLine = Vec2(0,0);
	setPanel(node, value, container);
}

void ColorChange::setPanel(Node* node, int value, PanelContainer container) {
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
	checkColor(node, value, container);
}

void ColorChange::checkColor(Node* node, int value, PanelContainer container) {
	
	mPanelLine = Vec2(0, 0);

	mChangePanelNum = value;

	for (int i = 0; i < mTestArray.size(); ++i){
		
		if (mTestArray[i] >= 1 ){
			mPanelLine.x = i % 5 - mBaseLine.x;
			mPanelLine.y = (MAX_ARRAY - i) / 5 - mBaseLine.y;
			CCLOG("%i", (int)mPanelLine.x);

			int test_x = value % 9 + mPanelLine.x;

			if (test_x >= 0 && test_x < 9){																																																																																																																																																																																																																																																																																//ago
				mChangePanelNum =  value + mPanelLine.x + mPanelLine.y * 9;


				if (mChangePanelNum < 0) continue;

				if (mChangePanelNum > 98) return;

				StagePanel* obj = container[mChangePanelNum];

				setColor(obj, mChangePanelNum);
			}
		}
	}
}

void ColorChange::setColor(StagePanel* node, int value) {	
	//ターン制が完成したら変える
	if (node->sprite->getColor() == Color3B::WHITE){
		node->sprite->setColor(Color3B::BLUE);
	}
}

void ColorChange::allClear() {

}