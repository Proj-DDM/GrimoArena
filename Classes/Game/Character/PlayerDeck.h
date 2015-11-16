#ifndef _PLAYERDECK_H_
#define _PLAYERDECK_H_

#include "cocos2d.h"
#include "CharacterType.h"
#include "CharacterParameter.h"

class CharacterPanel;
class Character;



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

	Parameter getParameter()const
	{
		return nowParameter;
	}

protected:
	PlayerDeck();
	~PlayerDeck();

private:
	void add(Character* panel);
	void deckInit();

private:
	using Deck = std::vector < Character* > ;
	Deck deck;

	CharacterID nowCharacterID;
	Parameter nowParameter;
};


#endif