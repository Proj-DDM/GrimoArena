#ifndef _CHARACTERMANAGER_H_
#define _CHARACTERMANAGER_H_

#include "cocos2d.h"
#include "Player.h"
#include <array>

#include "CharacterParameter.h"

class Character;

class CharacterManager : public cocos2d::Node
{
public:
	typedef std::function<void(int i)> test_FUNC;

	CharacterManager();
	~CharacterManager();
	bool init()override;
	void update(float dt);
	void add(Character* character);
	void findPara(int id);
	static CharacterManager* create();
	std::array<int, 25> getContainer(int id);

	std::vector < Character* > getCaras();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
	Parameter& getParameter()
	{
		return parameter;
	}

private:
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container;
	Player* player;
	Parameter parameter;

};

#endif