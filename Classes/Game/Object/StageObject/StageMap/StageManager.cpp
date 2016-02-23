#include "StageManager.h"
#include "StageDataReader.h"
#include "ColorChange\ColorChange.h"
#include "PanelCore.h"
#include "Utility/DeleteContainer.h"
#include "StagePanel.h"
#include "Game/UI/ParameterView.h"
#include "Game/Character/PlayerDeck.h"
#include "Game/Layer/UILayer.h"
#include "Utility/Particle/SimpleParticle.h"
#include "Utility/Animation/SpriteAnimation.h"



using namespace cocos2d;
namespace
{
	std::vector < Character* > Mysort(std::vector < Character* > contener)
	{
		std::vector < Character* > sortContener;

		for(Character* chara : contener )
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

	std::array<cocos2d::Color3B, 2> playerColorArray{ { cocos2d::Color3B::BLUE, cocos2d::Color3B::RED } };
}

StageManager::~StageManager(){
	
}

StageManager* StageManager::create(Layer* layer) {
	auto inst = new StageManager();
	
	if ( inst && inst->init(layer) ) {
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool StageManager::init(Layer* layer) {
	if ( !Node::init() ) {
		return false;
	}
	isAnime = false;
	m_Container.clear();

	this->schedule(schedule_selector(StageManager::update));
	mCount = 0;
	mTestTrun = 1;

	//auto bable = SimpleParticle::create("effect_god.plist", Point(100, 100));
	//this->addChild(bable, 30);
	
	auto fac = std::make_shared< StageFactory >();
	fac->createPanel(&m_Container,this);
	
	factory.init();
	manager = CharacterManager::create();
	
	addChild(manager);

	//プレイヤーマネージャー
	playerManager = PlayerManager::create(layer);
	auto pos1 = this->getPanel(4)->getPosition();
	auto pos2 = this->getPanel(94)->getPosition();
	m_Container.at(4)->sprite->setColor(Color3B::BLUE);
	m_Container.at(94)->sprite->setColor(Color3B::RED);
	playerManager->setPlayer(this, pos1, pos2);

	addChild(playerManager);

	playerManager->createPlayerDisplay();

	this->uiLayer = layer;

	return true;
}

void StageManager::update(float at) {
	manager->update(at);
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

Vec2 StageManager::playerPos(int id) {
	Vec2 player1Pos;
	CCLOG("id 0 PlayrPosX %i", (int)playerManager->m_Players.at(id)->getSprite()->getPosition().x);
	CCLOG("id 0 PlayrPosY %i", (int)playerManager->m_Players.at(id)->getSprite()->getPosition().y);
	player1Pos.x = (int)playerManager->m_Players.at(id)->getSprite()->getPosition().x;
	player1Pos.y = (int)playerManager->m_Players.at(id)->getSprite()->getPosition().y;
	return player1Pos;
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

const cocos2d::Color3B StageManager::getTurnPlayerColor(){
	return playerColorArray[SequenceManager::GetInstance()->getTurnPlayer()];
}

void StageManager::setUI(GAMESEQUENCE sequence)
{
	if (sequence == GAMESEQUENCE::OPERATION_SEQUENCE)
	{
		playerManager->setHPBar();
		playerManager->setMana();

		UILayer::PHASETYPE phase { UILayer::PHASETYPE::P1 };

		if (this->getTurnPlayer()->getName() == "Player2") phase = UILayer::PHASETYPE::P2;

		dynamic_cast<UILayer*>(this->uiLayer)->setPhaseSprite(phase);

		int number = 0;
		if (this->getTurnPlayer()->getName() == "Player2") number = 1;

		dynamic_cast<UILayer*>(this->uiLayer)->setDeck(number);

		return;
	}

	dynamic_cast<UILayer*>(this->uiLayer)->setPhaseSprite(UILayer::PHASETYPE::AI);

}

void StageManager::setRoundSprite()
{
	dynamic_cast<UILayer*>(this->uiLayer)->setRoundSprite();
}

bool StageManager::summon(const CharacterID& id, const Vec2& position, int panelNumber)
{
	auto obj = factory.create(id, position - Vec2(PANELSIZE / 2, PANELSIZE / 2), panelNumber);

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

	obj->read();
	manager->add(obj);
	manager->test(obj->getSkillParameter().getArray(), Vec2(0, 0), panelNumber,obj->getSkillParameter(),obj->getCharacterUser());


	for (Character* chara : manager->getCaras())
	{
		if (chara->getParameter().hp.isDead() == true) {
			int pos;
			pos = chara->getParameter().position;

			std::array<int, 25> charavect{};
			for (int k = 0; k < 25; ++k) {
				charavect[k] = chara->getParameter().vect[k];
			}
			int number = (chara->getCharacterUser() == CharacterUser::Player1) ? 1 : 2;

			this->deadChangePanel(number + 2, pos, charavect);	
		}	
	}
}

int StageManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	
	auto uiLayer = getParent()->getParent()->getChildByTag(1);

	int vectData[25];
	if (manager->onTouchBegan(touch, event))
	{
		if (touch->getLocation().y <= 120) {
			manager->getParameter().vect;
		}
		auto ui = dynamic_cast<ParameterView*>(getParent()->getParent()->getChildByTag(1)->getChildByName("View"));
		Parameter param{ manager->getParameter() };
		ui->setParameter(param);
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
			 charavect[i] = charaContainer.back()->getParameter().vect[i];
		 }

		//色変更が可能なら
		if (mIsChengeColor == true) {
			auto changer = std::make_shared< ColorChange >();
			changer->changeColor(panel->getChildByName(panel->getName()), panelNumber, m_Container, false, 2, charavect);
			mIsChengeColor = false;
		}
	}
}

int StageManager::allCheck(int id) {
	//id = 0 BRUE, id = 1 RED
	int brue, red;
	UserDefault* userdef = UserDefault::getInstance();
	brue = 0, red = 0;
	//BRUE
	if (id == 0) {
		for (int i = 0; i < m_Container.size(); ++i) {
			if (m_Container.at(i)->getColor() == Color3B::BLUE) {
				 ++brue;
				 userdef->setIntegerForKey("blue", brue);
			}
		}
		return brue;
	}
	//RED
	if (id == 1) {
		for (int i = 0; i < m_Container.size(); ++i) {
			if (m_Container.at(i)->getColor() == Color3B::RED) {
				++red;
				userdef->setIntegerForKey("red", red);
			}
		}
		return red;
	}
}
