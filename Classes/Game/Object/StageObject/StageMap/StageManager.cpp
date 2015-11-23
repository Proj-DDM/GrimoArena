﻿#include "StageManager.h"
#include "StageDataReader.h"
#include "ColorChange\ColorChange.h"
#include "PanelCore.h"
#include "Utility/DeleteContainer.h"
#include "StagePanel.h"
#include "../../../Character/PlayerDeck.h"

using namespace cocos2d;

StageManager::~StageManager(){
	
}

StageManager* StageManager::create() {
	auto inst = new StageManager();
	
	if ( inst && inst->init() ) {
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool StageManager::init() {
	if ( !Node::init() ) {
		return false;
	}
	m_Container.clear();

	this->schedule(schedule_selector(StageManager::update));
	mCount = 0;
	mTestTrun = 1;
	
	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(&m_Container,this);
	
	factory.init();
	manager = CharacterManager::create();

	addChild(manager);

	auto pos = this->getPanel(4)->getPosition();

	//プレイヤーマネージャーの実装（予定）
	playerManager = PlayerManager::create();
	auto pos1 = this->getPanel(4)->getPosition();
	auto pos2 = this->getPanel(94)->getPosition();

	playerManager->setPlayer(this, pos1, pos2);


	addChild(playerManager);

	return true;
}

void StageManager::update(float at) {
	if (mCount <= 0) { mCount = 0; }
	if (mCount >= 99) { mCount = 99; }
}

void StageManager::focusPanel(Node* node) {
}

void StageManager::changeColor(Node* node) {

}

int StageManager::onTouchBegan(cocos2d::Point pos) {
	if (pos.y <= 120) return false;
	auto uiLayer = getParent()->getParent()->getChildByTag(1);
	mId = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"))->getCharacterID();
	mParam = Parameter(10, 10, 10);
	//CCLOG("%i", (int)player->getParameter().vect[1]);
	int vectData[25];
}

void StageManager::onTouchMove(cocos2d::Point pos) {}

void StageManager::onTouchEnd(cocos2d::Point pos) {
	if (pos.y <= 120) return;
	mIsChengeColor = true;

	int panelNumber = this->touchPos(pos);
	if (panelNumber >= 0){
		Vec2 pos = Vec2((panelNumber % 9 + 1) * 64 - 16, (panelNumber / 9 + 1) * 64 + 96);
		manager->add(factory.create(mId, mParam, pos));
	}
	manager->getContainer((int)mId);
}

StagePanel* StageManager::getPanel(int number){
	if (!m_Container[number]) return nullptr;

	return m_Container[number];
}

int StageManager::touchPos(cocos2d::Point pos){
	int i = 0;

	for (auto& node : m_Container){

		Rect targetBox = node->getBoundingBox();
		targetBox.setRect(targetBox.getMinX() - 32, targetBox.getMinY() - 32,
			node->getContentSize().width, node->getContentSize().height);

		if (targetBox.containsPoint(pos)){
			if (mIsChengeColor == true) {
				auto changer = std::make_shared< ColorChange >();
				changer->changeColor(node->getChildByName(node->getName()), i, m_Container, mTestTrun);
				mIsChengeColor = false;
				++mTestTrun;
			}
			return i;
		}
		i++;
	}
	return -1;
}

Player* StageManager::getTurnPlayer(){

	return playerManager->getTurnPlayer();

}