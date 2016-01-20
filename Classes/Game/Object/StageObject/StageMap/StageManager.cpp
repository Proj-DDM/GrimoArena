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

	//プレイヤーマネージャー
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

void StageManager::onTouchMove(cocos2d::Point pos) 
{

}

void StageManager::onTouchEnd(cocos2d::Point pos) {
	//if (pos.y <= this->getPanel(0)->getPositionY() - this->getPanel(0)->getContentSize().height / 2) return;

	auto uiLayer = getParent()->getParent()->getChildByTag(1);
	auto deck = dynamic_cast<PlayerDeck*>(uiLayer->getChildByName("Deck"));

	int panelNumber = this->touchPos(pos);
	mIsChengeColor = true;

	if (panelNumber >= 0 && PanelCore::isCreate(panelNumber) && deck->getIsSummons()){

		//召喚予定パネルを取得
		StagePanel* panel = this->getPanel(panelNumber);

		//召喚
		if (!summon(deck->getCharacterID(), panel->getPosition(), panelNumber)) return;

		 std::array<int, 25> charavect{};
		 charaContainer = manager->getCaras();
		 for (int i = 0; i < 25; ++i) {
			 mTestArray[i] = charaContainer.back()->getParameter().vect[i];
		 }

		//色変更が可能なら
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
		if (changeNumber < 0 || this->m_Container.size() < changeNumber) continue;

		StagePanel* panel = getPanel(changeNumber);
		auto changer = std::make_shared< ColorChange >();
		changer->changeColor(panel->getChildByName(panel->getName()), changeNumber, m_Container, true, charauser, mTestArray);
	}
}

void StageManager::deadChangePanel(int user, int pos, std::array<int, 25> array) {
	int changeNumber;
	int charauser = 0;
	charaContainer = manager->getCaras();
	for (int i = 0; i < charaContainer.size(); ++i) {
		changeNumber = charaContainer.at(i)->getParameter().position;
		charauser = (int)charaContainer.at(i)->getCharacterUser();

		if (changeNumber < 0 || this->m_Container.size() < changeNumber) continue;
		StagePanel* panel = getPanel(changeNumber);
		auto changer = std::make_shared< ColorChange >();
		changer->changeColor(panel->getChildByName(panel->getName()), pos, m_Container, false, user, array);
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
		targetBox.setRect(targetBox.getMinX() - PANELSIZE / 2, targetBox.getMinY() - PANELSIZE / 2,
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

void StageManager::setUI()
{
	auto uiLayer = this->getParent()->getParent()->getChildByTag(1);

	if (uiLayer->getChildByTag(ICONTAG))		 uiLayer->removeChildByTag(ICONTAG);
	if (uiLayer->getChildByTag(NUMBERTAG))		 uiLayer->removeChildByTag(NUMBERTAG);
	if (uiLayer->getChildByTag(ICONBACK))		 uiLayer->removeChildByTag(ICONBACK);
	if (uiLayer->getChildByTag(PLAYER_HP_FRAME)) uiLayer->removeChildByTag(PLAYER_HP_FRAME);
	if (uiLayer->getChildByTag(PLAYER_HP_BACK))  uiLayer->removeChildByTag(PLAYER_HP_BACK);
	if (uiLayer->getChildByTag(HP_FRAME_BACK))	 uiLayer->removeChildByTag(HP_FRAME_BACK);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto action = FadeIn::create(2);

	//アイコン背景
	auto iconBack = Sprite::create("Scene/Main/UI_playerFrame.png");
	iconBack->setPosition(Vec2(iconBack->getContentSize().width / 2.8f, iconBack->getContentSize().height * 1.25));
	iconBack->setTag(ICONBACK);
	uiLayer->addChild(iconBack);

	//プレイヤーアイコン
	auto icon = playerManager->createIcon();
	icon->setPosition(Vec2(icon->getContentSize().width / 1.85, icon->getContentSize().height * 2.1));
	icon->setTag(ICONTAG);
	uiLayer->addChild(icon);

	//HPバックバー
	auto hpBackBar = Sprite::create("Scene/Main/hp_framebg.png");
	hpBackBar->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, hpBackBar->getContentSize().height * 4.8));
	hpBackBar->setTag(ICONTAG);
	uiLayer->addChild(hpBackBar);

	//HPバー
	auto hpBar = Sprite::create("Scene/Main/p_player.png");
	hpBar->setPosition(Vec2(hpBackBar->getPositionX() + 50, hpBackBar->getPositionY()));
	hpBar->setTag(ICONTAG);
	uiLayer->addChild(hpBar);

	//HPフレーム
	auto hpFrame = Sprite::create("Scene/Main/hp_frame.png");
	hpFrame->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, hpFrame->getContentSize().height * 4.8));
	hpFrame->setTag(PLAYER_HP_FRAME);
	uiLayer->addChild(hpFrame);

	uiLayer->addChild(playerManager->createManaDisplay());

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

bool StageManager::summon(const CharacterID& id, const Vec2& position,int panelNumber)
{
	auto obj = factory.create(id, position  - Vec2(PANELSIZE / 2, PANELSIZE / 2),panelNumber);

	//プレイヤーの周りでキャラが離されたか判定
	auto check = [this, panelNumber, obj]()
	{
		for (int i = -1; i < 2; i += 2)
		{
			//上下左右
			if (this->getTurnPlayer()->getPanelNumber() == panelNumber + i) return true;
			if (this->getTurnPlayer()->getPanelNumber() == panelNumber + i * 9) return true;

			//斜め
			for (int k = -1; k < 2; k += 2)
			{
				if (this->getTurnPlayer()->getPanelNumber() == panelNumber + i * 9 + k) return true;
			}
		}

		return false;
	};

	if (!check()) return false;

	//召喚コスト分のマナがあるなら召喚
	if (playerManager->getTurnPlayer()->getMana() < obj->getParameter().cost) return false;

	//マナを消費
	playerManager->mathMana(-(obj->getParameter().cost));

	manager->add(obj);

	return true;

}
