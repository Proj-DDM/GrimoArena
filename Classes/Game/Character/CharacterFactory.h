#ifndef _CHARACTERFACTORY_H_
#define _CHARACTERFACTORY_H_

#include "CharacterType.h"
#include "CharacterParameter.h"
#include <map>
#include "cocos2d.h"

class Character;

class CharacterFactory
{
public:
	CharacterFactory();
	~CharacterFactory();
	
	void init();
	void add(CharacterID id, Character* instance);
	Character* create(CharacterID id, const Parameter& param, const cocos2d::Vec2& position);

private:
	using Container = std::map < CharacterID, Character* >;
	Container container;
};

#endif