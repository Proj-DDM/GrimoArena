#include "PlayerManager.h"
#include "Player.h"
#include "../Scene/GameMain/Sequence/SequenceManager.h"
#include <array>


#define PLAYER1_START_NUM 4
#define PLAYER2_START_NUM 94

namespace
{
	//std::array< std::string, 2 > iconNames = { "UI/Player/core.png" , "player2icon.png" };

}

PlayerManager::PlayerManager()
{
	

}


PlayerManager::~PlayerManager()
{
}


PlayerManager* PlayerManager::create(cocos2d::Node* layer){

	auto obj = new PlayerManager();

	if (obj && obj->init(layer)){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;

}

bool PlayerManager::init(cocos2d::Node* layer){

	if (!Node::init()){
		return false;
	}

	m_Players.clear();

	this->layer = layer;
	return true;

}
void PlayerManager::update(float at){

}


void PlayerManager::setPlayer(cocos2d::Node* node, cocos2d::Vec2 p1pos, cocos2d::Vec2 p2pos){

	push(p1pos, PLAYER1_START_NUM, "Player1");
	push(p2pos, PLAYER2_START_NUM, "Player2");
}

void PlayerManager::push(cocos2d::Vec2 pos, int number, std::string name){
	auto player = Player::create(pos, number);

	this->addChild(player);

	player->setCameraMask((int)CameraFlag::USER1);

	player->setName(name);

	m_Players.push_back(player);
}

Player* PlayerManager::getTurnPlayer(){
	return m_Players.at(SequenceManager::GetInstance()->getTurnPlayer());
}

void PlayerManager::createPlayerDisplay()
{
	this->ui = PlayerUI::create();
	this->layer->addChild(ui);
	this->layer->addChild(this->createManaDisplay());

	this->ui->setHPBar(this->getTurnPlayer()->getParameter().hp.getHp());
}

Mana* PlayerManager::createManaDisplay()
{
	if (this->mana) this->mana->removeFromParent();

	this->mana = Mana::create(m_Players.at(SequenceManager::GetInstance()->getTurnPlayer())->getMana());

	return this->mana;
}

void PlayerManager::mathMana(int value)
{
	this->getTurnPlayer()->mathMana(value);

	this->mana->setMana(this->getTurnPlayer()->getMana());
}

void PlayerManager::setHPBar()
{
	this->ui->setHPBar(this->getTurnPlayer()->getParameter().hp.getHp());
}