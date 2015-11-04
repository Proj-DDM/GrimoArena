#ifndef _CHARACTERFACTORY_H_
#define _CHARACTERFACTORY_H_

#include "CharacterType.h"
#include "CharacterParameter.h"
#include <map>
#include "cocos2d.h"
#include "../../Utility/FileIO/CharaData.h"
#include <unordered_map>

class Character;

class CharacterFactory
{
private:
	using Function = std::function < Character*(const Parameter& param, const cocos2d::Vec2& position) >;
	using Container = std::unordered_map < CharacterID, Function >;
	using Charadata = std::vector<CharaData>;

public:
	CharacterFactory();
	~CharacterFactory();
	
	void init();
	void add(CharacterID id, Function);
	Character* create(CharacterID id, const Parameter& param, const cocos2d::Vec2& position);

private:
	Container container;
	Charadata data;
};

#endif