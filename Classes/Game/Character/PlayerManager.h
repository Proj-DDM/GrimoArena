#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <vector>
#include "cocos2d.h"

class Player;

class PlayerManager : public cocos2d::Node
{
protected:
	PlayerManager();
	~PlayerManager();

public:

	using Players = std::vector<Player*>;

	static PlayerManager* create();

	virtual bool init() override;

	void update(float at) override;

	void setPlayer(cocos2d::Node* node, cocos2d::Vec2 p1pos, cocos2d::Vec2 p2pos);

	Player* getTurnPlayer();

	Players m_Players;


private:
	void push(cocos2d::Vec2 pos,int number,std::string name);

};

#endif