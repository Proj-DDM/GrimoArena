#include "StageManager.h"
#include "StageDataReader.h"
#include "ColorChange\ColorChange.h"
#include "PanelCore.h"
#include "Utility/DeleteContainer.h"
#include "StagePanel.h"
#include "../../../Character/PlayerDeck.h"
#include "../../../UI/ParameterView.h"

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
	
	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(&m_Container,this);
	
	factory.init();
	manager = CharacterManager::create();

	addChild(manager);

	auto pos = this->getPanel(0)->getPosition();
	player = Player::create(pos, 0);

	addChild(player);

	return true;
}

void StageManager::update(float at) {
	if (mCount <= 0) { mCount = 0; }
	if (mCount >= 99) { mCount = 99; }

	//パネルを塗り替えるラムダ式を登録
	/*auto func = [this](int number){
		auto panel = this->getPanel(number);
		if (!panel) return;
		auto panelSprite = (Sprite*)panel->getChildByName(panel->getName());
		panelSprite->setColor(cocos2d::Color3B::BLUE);
	};*/

	//manager->update(func);

}

void StageManager::focusPanel(Node* node) {
}

void StageManager::changeColor(Node* node) {

}

int StageManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	if (manager->onTouchBegan(touch, event))
	{
		auto ui = dynamic_cast<ParameterView*>(getParent()->getParent()->getChildByTag(1)->getChildByName("View"));
		ui->setParameter(manager->getParameter());
	}
	return 0;
}

void StageManager::onTouchMove(cocos2d::Point pos) {

}

void StageManager::onTouchEnd(cocos2d::Point pos) {
	auto uiLayer = getParent()->getParent()->getChildByTag(1);
	auto deck = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"));

	if (!deck->getIsSummons())return;
	int panelNumber = this->touchPos(pos);
	if (panelNumber >= 0) {
		Vec2 pos = Vec2((panelNumber % 9 + 1) * 64 - 16, (panelNumber / 9 + 1) * 64 + 96);
		manager->add(factory.create(deck->getCharacterID(), pos));
	}
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
			auto changer = std::make_shared< ColorChange >();
			changer->changeColor(node->getChildByName(node->getName()), i, m_Container);
			return i;
		}

		i++;
	}

	return -1;
}