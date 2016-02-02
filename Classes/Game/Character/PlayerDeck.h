#ifndef _PLAYERDECK_H_
#define _PLAYERDECK_H_

#include "cocos2d.h"
#include "CharacterType.h"
#include "Game/UI/ParameterView.h"
#include "CharacterParameter.h"
#include <array>

class CharacterPanel;
class Character;



class PlayerDeck : public cocos2d::Node
{
public:
	static PlayerDeck* create();
	bool init()override;
	void update(float deltaTime);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	CharacterID getCharacterID()const
	{
		return nowCharacterID;
	}

	Parameter getParameter()const
	{
		return nowParameter;
	}

	bool getIsSummons()const
	{
		return isSummons;
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
	bool isSummons;
};


#endif