#ifndef _CHARACTERTABLE_H_
#define _CHARACTERTABLE_H_

#include "cocos2d.h"
#include "../../Character/Character.h"
#include "../../Character/CharacterType.h"

class CharacterTable : public cocos2d::Node
{
public:
	CharacterTable();
	~CharacterTable();
	bool init();
	void update(float deltaTime);
	void add(Character* chara);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	bool getIsSummons()const
	{
		return isSummons;
	}

	CharacterID getCharacterID()const
	{
		return nowCharacterID;
	}
	static CharacterTable* create();

private:
	using CharacterContainer = std::vector<Character*>;
	CharacterContainer container;
	bool isSummons;
	CharacterID nowCharacterID;
};

#endif
