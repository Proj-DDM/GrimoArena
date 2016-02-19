#include "ColorChange.h"
#include "cocos2d.h"
#include <array>
#include <stdlib.h>
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"

#define MAX_ARRAY  24

using namespace cocos2d;

ColorChange::ColorChange() {}

ColorChange::~ColorChange() {}

void ColorChange::changeColor(Node* node, int value, PanelContainer container, bool move, int user, const std::array<int, 25> testarray) {
	mBaseLine = Vec2(0,0);
	mCharaLine = Vec2(0,0);
	mUser = user;
	mTestArray = testarray;
	setPanel(node, value, container, move);
}

void ColorChange::setPanel(Node* node, int value, PanelContainer container, bool move) {
	//仮のキャラデータ
	if (move == true) {
		mTestArray = 
			{ 0, 0, 0, 0, 0,
			  0, 0, 0, 0, 0,
			  0, 0, 2, 0, 0,
			  0, 0, 0, 0, 0,
			  0, 0, 0, 0, 0 };
	}
	if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER2) {
		std::reverse(mTestArray.begin(), mTestArray.end());
	}
	if (mUser == 4) {
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
			break;
		}
	}
	checkColor(node, value, container);
}

void ColorChange::checkColor(Node* node, int value, PanelContainer container) {
	
	mPanelLine = Vec2(0, 0);

	mChangePanelNum = value;

	for (int i = 0; i < mTestArray.size(); ++i){
		
		if (mTestArray[i] >= 1){
			mPanelLine.x = i % 5 - mBaseLine.x;
			mPanelLine.y = (MAX_ARRAY - i) / 5 - mBaseLine.y;
			//CCLOG("%i", (int)mPanelLine.x);

			int test_x = value % 9 + mPanelLine.x;

			if (test_x >= 0 && test_x < 9){
				mChangePanelNum =  value + mPanelLine.x + mPanelLine.y * 9;

				if (mChangePanelNum < 0) continue;
				if (mChangePanelNum > 98) continue;
				if (mChangePanelNum == P1POS) continue;
				if (mChangePanelNum == P2POS) continue;

				StagePanel* obj = container[mChangePanelNum];

				setColor(obj, mChangePanelNum);
			}
		}
	}
}

void ColorChange::setColor(StagePanel* node, int value) {
	if (mUser == 0) {
		node->sprite->setColor(Color3B::BLUE);
	}
	else if (mUser == 1) {
		node->sprite->setColor(Color3B::RED);
	} else {
		if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER1) {
			node->sprite->setColor(Color3B::BLUE);
		}
		else {
			node->sprite->setColor(Color3B::RED);
		}
	}
	if (mUser == 3) {
		node->sprite->setColor(Color3B::BLUE);
	} else if (mUser == 4) {
		node->sprite->setColor(Color3B::RED);
	}
}