#include "StageManager.h"
#include "StageDataReader.h"
#include "ColorChange\ColorChange.h"
#include "PanelCore.h"
#include "Utility/DeleteContainer.h"
#include "StagePanel.h"
#include "../../../Character/PlayerDeck.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#include "../../../UI/ParameterView.h"


using namespace cocos2d;
namespace
{
	std::vector < Character* > Mysort(std::vector < Character* > contener)
	{
		std::vector < Character* > sortContener;

		for each (Character* chara in contener)
		{
			sortContener.push_back(chara);
			if (sortContener.size() == 1) continue;

			for (int i = 0; i < sortContener.size(); ++i)
			{
				if (sortContener.at(i)->getParameter().speed < sortContener.back()->getParameter().speed)
				{
					Character* sortChara;
					std::swap(sortChara, sortContener.back());

					for (int y = sortContener.size() - 1; i < y; --y)
					{
						sortContener.at(y) = std::move(sortContener.at(y - 1));
					}
					sortContener.at(i) = std::move(sortChara);

					continue;
				}
			}
		}


		return sortContener;
	}
}

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
	manager->update(at);
	if (mCount <= 0) { mCount = 0; }
	if (mCount >= 99) { mCount = 99; }

	auto uiLayer = this->getParent()->getParent()->getChildByTag(1);
	if (!uiLayer->getChildByTag(NUMBERTAG)) return;
	int mana = playerManager->getTurnPlayer()->getMana();
	dynamic_cast<Sprite*>(uiLayer->getChildByTag(NUMBERTAG))->setTextureRect(Rect(32 * mana, 0, 32, 32));

}

int StageManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	
	auto uiLayer = getParent()->getParent()->getChildByTag(1);
	mId = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"))->getCharacterID();
	mParam = Parameter(10, 10, 10);
	int vectData[25];
	if (manager->onTouchBegan(touch, event))
	{
		if (touch->getLocation().y <= 120) {
			manager->getParameter().vect;
		}
		auto ui = dynamic_cast<ParameterView*>(getParent()->getParent()->getChildByTag(1)->getChildByName("View"));
		ui->setParameter(manager->getParameter());
	}
	return true;
}

void StageManager::onTouchMove(cocos2d::Point pos) {}

void StageManager::onTouchEnd(cocos2d::Point pos) {
	if (pos.y <= 120) return;

	auto uiLayer = getParent()->getParent()->getChildByTag(1);
	auto deck = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"));

	int panelNumber = this->touchPos(pos);
	mIsChengeColor = true;

	auto test = PanelCore::isCreate(panelNumber);

	if (panelNumber >= 0 && PanelCore::isCreate(panelNumber) && deck->getIsSummons()){
		Vec2 pos = Vec2((panelNumber % 9 + 1) * 64 - 16, (panelNumber / 9 + 1) * 64 + 96);
		manager->add(factory.create(deck->getCharacterID(), pos, panelNumber));

		std::array<int, 25> charavect{};
		charaContainer = manager->getCaras();
		for (int i = 0; i < 25; ++i) {
			mTestArray[i] = charaContainer.back()->getParameter().vect[i];
		}
		mTestArray;
		StagePanel* panel = getPanel(panelNumber);

		if (mIsChengeColor == true) {
			auto changer = std::make_shared< ColorChange >();
			changer->changeColor(panel->getChildByName(panel->getName()), panelNumber, m_Container, false, 2, mTestArray);
			mIsChengeColor = false;
		}
	}
}
void StageManager::checkOnPanel() {
	int changeNumber;
	int charauser = 0;
	//CCLOG("%i", user);
	charaContainer = manager->getCaras();
	for (int i = 0; i < charaContainer.size(); ++i) {
		changeNumber = charaContainer.at(i)->getParameter().position;
		charauser = (int)charaContainer.at(i)->getCharacterUser();
		StagePanel* panel = getPanel(changeNumber);
		auto changer = std::make_shared< ColorChange >();
		changer->changeColor(panel->getChildByName(panel->getName()), changeNumber, m_Container, true, charauser, mTestArray);
	}
}

void StageManager::deadChangePanel(int user, int pos) {
	int changeNumber;
	int charauser = 0;
	charaContainer = manager->getCaras();
	for (int i = 0; i < charaContainer.size(); ++i) {
		changeNumber = charaContainer.at(i)->getParameter().position;
		charauser = (int)charaContainer.at(i)->getCharacterUser();
		StagePanel* panel = getPanel(changeNumber);
		auto changer = std::make_shared< ColorChange >();
		changer->changeColor(panel->getChildByName(panel->getName()), pos, m_Container, false, user, mTestArray);
	}
}

std::vector < Character* > StageManager::getCaras() {
	charaContainer = Mysort(charaContainer);
	return manager->getCaras();
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
			return i;
		}
		i++;
	}
	return -1;
}

Player* StageManager::getTurnPlayer(){
	return playerManager->getTurnPlayer();
}

const cocos2d::Color3B& StageManager::getTurnPlayerColor(){
	return playerColorArray[SequenceManager::GetInstance()->getTurnPlayer()];
}

//namespace{
//	void setSprite(Node* node, const Vec2& pos, const std::string& name, int tag){
//
//	}
//}

void StageManager::setUI()
{
	auto uiLayer = this->getParent()->getParent()->getChildByTag(1);

	if (uiLayer->getChildByTag(ICONTAG)) uiLayer->removeChildByTag(ICONTAG);
	if (uiLayer->getChildByTag(MANATAG)) uiLayer->removeChildByTag(MANATAG);
	if (uiLayer->getChildByTag(NUMBERTAG)) uiLayer->removeChildByTag(NUMBERTAG);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto action = FadeIn::create(2);

	//プレイヤーアイコン
	auto icon = playerManager->createIcon();
	icon->setPosition(Vec2(visibleSize.width - icon->getContentSize().width / 2, icon->getContentSize().height / 2));
	icon->setOpacity(0);
	icon->setTag(ICONTAG);
	icon->runAction(action);
	uiLayer->addChild(icon);

	//マナ画像
	auto action2 = FadeIn::create(2);
	auto manaImage = Sprite::create("mana.png");
	manaImage->setPosition(Vec2(visibleSize.width - manaImage->getContentSize().width * 5, manaImage->getContentSize().height * 2));
	manaImage->setOpacity(0);
	manaImage->setTag(MANATAG);
	manaImage->runAction(action2);
	uiLayer->addChild(manaImage);


	//数字
	auto action3 = FadeIn::create(2);
	int mana = playerManager->getTurnPlayer()->getMana();
	auto numberImage = Sprite::create("number.png", Rect(0 * mana, 0 , 0 * mana + 32, 32));
	numberImage->setPosition(Vec2(visibleSize.width - numberImage->getContentSize().width * 4, numberImage->getContentSize().height * 2));
	numberImage->setOpacity(0);
	numberImage->setTag(NUMBERTAG);
	numberImage->runAction(action3);
	uiLayer->addChild(numberImage);

	////フェイズ表記
	//auto action4 = FadeIn::create(2);
	//auto PhaseImage = Sprite::create("MAINPHASE.png");
	//PhaseImage->setScale(0.2f);
	//PhaseImage->setPosition(Vec2(PhaseImage->getContentSize().width, visibleSize.height - PhaseImage->getContentSize().height));
	//PhaseImage->setOpacity(0);
	//PhaseImage->setTag(PHASETAG);
	//PhaseImage->runAction(action4);
	//uiLayer->addChild(PhaseImage);

}
