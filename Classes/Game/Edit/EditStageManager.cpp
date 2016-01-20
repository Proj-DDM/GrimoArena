#include "EditStageManager.h"
#include "../Object/StageObject/StageMap/ColorChange/ColorChange.h"
#include "../Scene/Edit/CharacterTable.h"

using namespace cocos2d;

EditStageManager::EditStageManager()
{
}

EditStageManager::~EditStageManager()
{
}

EditStageManager * EditStageManager::create()
{
	auto inst = new EditStageManager();

	if (inst && inst->init()) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

bool EditStageManager::init()
{
	if (!Node::init()) {
		return false;
	}
	m_Container.clear();

	this->schedule(schedule_selector(EditStageManager::update));
	mCount = 0;
	mTestTrun = 1;

	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(&m_Container, this);

	factory.init();
	manager = CharacterManager::create();

	addChild(manager);

	auto pos = this->getPanel(4)->getPosition();

	return true;
}

void EditStageManager::update(float at)
{
	if (mCount <= 0) { mCount = 0; }
	if (mCount >= 99) { mCount = 99; }
}


int EditStageManager::onTouchBegan(cocos2d::Point pos)
{

	mId = dynamic_cast<CharacterTable*>(this->getParent()->getChildByName("Table"))->getCharacterID();
	return 0;
}

void EditStageManager::onTouchMove(cocos2d::Point pos)
{
}

void EditStageManager::onTouchEnd(cocos2d::Point pos)
{
	if (pos.y <= 120) return;
	mIsChengeColor = true;

	int panelNumber = this->touchPos(pos);

	auto test = PanelCore::isCreate(panelNumber);

	if (panelNumber >= 0 && PanelCore::isCreate(panelNumber)) {
		
		Vec2 pos = Vec2((panelNumber % 9 + 1) * 64 - 16, (panelNumber / 9 + 1) * 64 + 96);
		auto param = Parameter();
		manager->add(factory.create(mId, pos,0));

		StagePanel* panel = getPanel(panelNumber);
		if (mIsChengeColor == true) {
			auto changer = std::make_shared< ColorChange >();
			//changer->changeColor(panel->getChildByName(panel->getName()), panelNumber, m_Container,false,1 ,mTestTrun);
			mIsChengeColor = false;
			++mTestTrun;
		}
	}
	manager->getContainer((int)mId);
}


void EditStageManager::changeColor(cocos2d::Node * node)
{
}

void EditStageManager::focusPanel(cocos2d::Node * node)
{
}

StagePanel * EditStageManager::getPanel(int number)
{
	if (!m_Container[number]) return nullptr;

	return m_Container[number];
}

int EditStageManager::touchPos(cocos2d::Point pos)
{
	int i = 0;

	for (auto& node : m_Container) {

		Rect targetBox = node->getBoundingBox();
		targetBox.setRect(targetBox.getMinX() - 32, targetBox.getMinY() - 32,
			node->getContentSize().width, node->getContentSize().height);

		if (targetBox.containsPoint(pos)) {
			return i;
		}
		i++;
	}
	return -1;
}
