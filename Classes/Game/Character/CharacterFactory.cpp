#include "CharacterFactory.h"
#include "Character.h"
#include "SampleKamata.h"
#include "../Test/SampleHashigo.h"
#include "SampleHige.h"
#include "../../Utility/FileIO/CharaReader.h"

CharacterFactory::CharacterFactory()
{
}

CharacterFactory::~CharacterFactory()
{
	container.clear();
}

void CharacterFactory::init()
{
	add(CharacterID::FireAttribute,  [](const Parameter& param, const cocos2d::Vec2& position){ return Kamata::create(param, position); });
	add(CharacterID::WaterAttribute, [](const Parameter& param, const cocos2d::Vec2& position){ return Hashigo::create(param, position); });
	add(CharacterID::Kamata,		 [](const Parameter& param, const cocos2d::Vec2& position){ return Hige::create(param, position); });
}

void CharacterFactory::add(CharacterID id, Function func)
{
	container[id] = func;
}

Character* CharacterFactory::create(CharacterID id, const Parameter& param, const cocos2d::Vec2& position)
{
	std::string name;
	switch (id)
	{
	case CharacterID::FireAttribute:
			name = "mon2_tati_r";
			break;
	case CharacterID::WaterAttribute:
		name = "mon3_tati_r";
		break;
	case CharacterID::Kamata:
		name = "mon1_tati_r";
		break;
	default:
		break;
	}
	CharaReader read;
	data = read.read("charalist.plist");
	Parameter parameter;
	for (auto& charadata : data)
	{
		if (charadata.textureName != name)continue;
		
		parameter.hp = charadata.hp;
		parameter.speed = charadata.speed;
		parameter.cost = charadata.cost;
		parameter.attackPoint = charadata.attack;
		parameter.attribute = charadata.attribute;
		parameter.move = charadata.move;
		break;
	}

	return container[id](parameter,position);
}