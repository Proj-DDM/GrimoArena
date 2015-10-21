#include "ColorChange.h"
#include "cocos2d.h"
#include <array>
#include <stdlib.h>

using namespace cocos2d;

ColorChange::ColorChange() {}

ColorChange::~ColorChange() {}

void ColorChange::changeColor(Node* node, int value) {
	mColorChangePosition = value;
	setPanel(node, value);
	//setColor(node, value);
}

void ColorChange::setPanel(Node* node, int value) {
	int charaPoint = 0;
	int colorChangePoint = 0;
	int mDifferenceCount = 0;
	//仮のキャラデータ
	std::array<int, 25> testArray = {0, 0, 0, 0, 0,
									 0, 0, 0, 0, 0,
									 0, 1, 2, 1, 0,
									 0, 0, 0, 0, 0,
									 0, 0, 0, 0, 0};
	for (int i = 0; i < testArray.size(); ++i){
		CCLOG("%i", testArray[i]);
		if (testArray[i] == 1){
			colorChangePoint = i;
			CCLOG("%i", colorChangePoint);
		}
		if (testArray[i] == 2){
			charaPoint = i;
			CCLOG("%i", charaPoint);
		}
		mDifferenceCount = charaPoint - colorChangePoint;
		mDifferenceCount = abs(mDifferenceCount);
		if (charaPoint > colorChangePoint) {
			mColorChangePosition = value - mDifferenceCount;
			setColor(node, mColorChangePosition);
		}
		if (charaPoint < colorChangePoint ) {
			mColorChangePosition = value + mDifferenceCount;
			setColor(node, mColorChangePosition);
		}
		setColor(node, mColorChangePosition);
	}
}

void ColorChange::posCast(Node* node, int value) {

}

void ColorChange::setColor(Node* node, int value) {
	//ここに変換式メソッド
	posCast(node, value);
	auto panel = (Sprite*)node->getChildren().at(value);
	auto panelSprite = (Sprite*)panel->getChildByName(panel->getName());
	//ターン制が完成したら変える
	if (panelSprite->getColor() == Color3B::WHITE){
		panelSprite->setColor(Color3B::BLUE);
	}
}

void ColorChange::allClear() {

}