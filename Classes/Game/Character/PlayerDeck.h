#ifndef _PLAYERDECK_H_
#define _PLAYERDECK_H_

#include "cocos2d.h"
#include "CharacterType.h"

class CharacterPanel;


class PlayerDeck : public cocos2d::Node
{
public:
	static PlayerDeck* create();
	bool init()override;
	void update(float deltaTime);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	CharacterID getCharacterID()const
	{
		return nowCharacterID;
	}

protected:
	PlayerDeck();
	~PlayerDeck();

private:
	void add(CharacterPanel* panel, float positionX);
	void deckInit();

private:
	using Deck = std::vector < CharacterPanel* > ;
	Deck deck;

	CharacterID nowCharacterID;
};


#endif