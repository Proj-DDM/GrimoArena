#ifndef _CHARACTERMANAGER_H_
#define _CHARACTERMANAGER_H_

#include "cocos2d.h"

class Character;

class CharacterManager : public cocos2d::Node
{
public:
	typedef std::function<void(int i)> test_FUNC;

	CharacterManager();
	~CharacterManager();
	bool init()override;
	void update(test_FUNC func);
	void add(Character* character);
	static CharacterManager* create();

private:
	using CharacterContainer = std::vector < Character* > ;
	CharacterContainer container;
};



#endif