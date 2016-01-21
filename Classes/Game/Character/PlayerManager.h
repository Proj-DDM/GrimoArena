#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <vector>
#include "cocos2d.h"
#include "../../proj.win32/Mana.h"
#include "PlayerUI.h"

class Player;
class Mana;

class PlayerManager : public cocos2d::Node
{
protected:
	PlayerManager();
	~PlayerManager();

public:

	using Players = std::vector<Player*>;

	static PlayerManager* create(cocos2d::Node* layer);

	virtual bool init(cocos2d::Node* layer);

	void update(float at) override;

	void setPlayer(cocos2d::Node* node, cocos2d::Vec2 p1pos, cocos2d::Vec2 p2pos);

	Player* getTurnPlayer();

	Players m_Players;

	void createPlayerDisplay();

	Mana* createManaDisplay();

	void mathMana(int value);

	void setHPBar();

	void setMana();

private:
	Mana* mana { nullptr };
	PlayerUI* ui{ nullptr };
	void push(cocos2d::Vec2 pos,int number,std::string name);

	cocos2d::Node* layer;

};

#endif