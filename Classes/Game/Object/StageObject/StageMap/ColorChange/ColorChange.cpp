#include "ColorChange.h"
#include "cocos2d.h"
#include <array>
#include <stdlib.h>

#define MAX_ARRAY  24

using namespace cocos2d;

ColorChange::ColorChange() {}

ColorChange::~ColorChange() {}

void ColorChange::changeColor(Node* node, int value, PanelContainer container, int trun) {
	mBaseLine = Vec2(0,0);
	mCharaLine = Vec2(0,0);
	mTestTrun = trun;
	setPanel(node, value, container, trun);
}

void ColorChange::setPanel(Node* node, int value, PanelContainer container, int trun) {
	//仮のキャラデータ
	mTestArray = {0, 0, 0, 0, 0,
				  0, 0, 1, 0, 0,
				  0, 0, 2, 0, 0,
				  0, 1, 0, 1, 0,
				  0, 0, 0, 0, 0 };
	if (mTestTrun % 2 == 0) {
		std::reverse(mTestArray.begin(), mTestArray.end());
	}

	for (int i = 0; i < mTestArray.size(); ++i) {
		if (mTestArray[i] == 2){
			mCharaLine.x = i % 5;
			mCharaLine.y = i / 5;
			mBaseLine.x = mCharaLine.x;
			mBaseLine.y = mCharaLine.y;
			mCharaLine.x = 0;
			mCharaLine.y = 0;
			//CCLOG("%i", (int)mBaseLine.x);
		}
	}
	checkColor(node, value, container);
}

void ColorChange::checkColor(Node* node, int value, PanelContainer container) {
	
	mPanelLine = Vec2(0, 0);

	mChangePanelNum = value;

	for (int i = 0; i < mTestArray.size(); ++i){
		
		if (mTestArray[i] >= 1 ){
			mPanelLine.x = i % 5 - mBaseLine.x;
			mPanelLine.y = (MAX_ARRAY - i) / 5 - mBaseLine.y;
			//CCLOG("%i", (int)mPanelLine.x);

			int test_x = value % 9 + mPanelLine.x;

			if (test_x >= 0 && test_x < 9){
				mChangePanelNum =  value + mPanelLine.x + mPanelLine.y * 9;


				if (mChangePanelNum < 0) continue;

				if (mChangePanelNum > 98) return;

				if (mChangePanelNum == PLAYER1) return;

				if (mChangePanelNum == PLAYER2) return;

				StagePanel* obj = container[mChangePanelNum];

				setColor(obj, mChangePanelNum);
			}
		}
	}
}

void ColorChange::setColor(StagePanel* node, int value) {
	//ターン制が完成したら変え
	//if (node->sprite->getColor() == Color3B::WHITE){
	//}
	if (mTestTrun % 2 == 0) {
		node->sprite->setColor(Color3B::BLUE);
	} else {
		node->sprite->setColor(Color3B::RED);
	}
}

void ColorChange::allClear() {

}