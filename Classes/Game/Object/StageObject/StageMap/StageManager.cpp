#include "StageManager.h"
#include "StageDataReader.h"
#include "StageFactory.h"

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

	mPanelNode = Node::create();
	mPanelNode->setName("PanelNode");
	this->addChild(mPanelNode);

	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(mPanelNode);
	changeColor();
	focusPanel(mPanelNode);
	return true;
}

void StageManager::update(float at) {
	int a = 0;
}

void StageManager::changeColor() {
	auto panel = (Sprite*)mPanelNode->getChildren().at(6);
	auto panelSprite = (Sprite*)panel->getChildByName(panel->getName());
	panelSprite->setColor(Color3B::BLUE);
}

void StageManager::focusPanel(Node* node) {

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto lis = EventListenerKeyboard::create();

	lis->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode){
			
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(lis, node);

}

void StageManager::onTouchBegan(cocos2d::Point pos) {}

void StageManager::onTouchMove(cocos2d::Point pos) {}

void StageManager::onTouchEnd(cocos2d::Point pos) {}
