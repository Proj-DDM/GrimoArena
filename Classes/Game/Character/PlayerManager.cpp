#include "PlayerManager.h"
#include "Player.h"
#include "../Scene/GameMain/Sequence/SequenceManager.h"


#define PLAYER1_START_NUM 4
#define PLAYER2_START_NUM 94


PlayerManager::PlayerManager()
{
	

}


PlayerManager::~PlayerManager()
{
}


PlayerManager* PlayerManager::create(){

	auto obj = new PlayerManager();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;

}

bool PlayerManager::init(){

	if (!Node::init()){
		return false;
	}

	m_Players.clear();

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

	player->setName(name);

	m_Players.push_back(player);
}

Player* PlayerManager::getTurnPlayer(){
	return m_Players.at(SequenceManager::GetInstance()->getTurnPlayer());
}
