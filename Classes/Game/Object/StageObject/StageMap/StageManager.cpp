#include "StageManager.h"
#include "StageDataReader.h"
#include "StageFactory.h"
#include "ColorChange\ColorChange.h"

using namespace cocos2d;

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

	this->schedule(schedule_selector(StageManager::update));
	mCount = 0;
	mPanelNode = Node::create();
	mPanelNode->setName("PanelNode");
	this->addChild(mPanelNode);

	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(mPanelNode);
	focusPanel(mPanelNode);
	changeColor(mPanelNode);

	return true;
}

void StageManager::update(float at) {
	if (mCount <= 0) { mCount = 0; }
	if (mCount >= 99) { mCount = 99; }
}

void StageManager::focusPanel(Node* node) {

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto lis = EventListenerKeyboard::create();
	auto lis2 = EventListenerKeyboard::create();

	lis->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode){
			++mCount;
		}
	};

	lis2->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode){
			--mCount;
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(lis, node);
	dispatcher->addEventListenerWithSceneGraphPriority(lis2, node);
}

void StageManager::changeColor(Node* node) {
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto lis = EventListenerKeyboard::create();

	lis->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (EventKeyboard::KeyCode::KEY_C == keyCode){
			auto changer = std::make_shared< ColorChange >();
			changer->changeColor(mPanelNode, mCount);
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(lis, node);
}

void StageManager::onTouchBegan(cocos2d::Point pos) {
	int a = 0;
}

void StageManager::onTouchMove(cocos2d::Point pos) {}

void StageManager::onTouchEnd(cocos2d::Point pos) {}
