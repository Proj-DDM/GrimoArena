#include "CharacterFactory.h"
#include "Character.h"
#include "SampleKamata.h"
#include "../Test/SampleHashigo.h"
#include "SampleHige.h"
#include "../../Utility/FileIO/CharaReader.h"

namespace{
	void assignment(int* a, int* b){

		for (int i = 0; i < 25; ++i){
			a[i] = b[i];
		}

	}

}


CharacterFactory::CharacterFactory()
{
}

CharacterFactory::~CharacterFactory()
{
	container.clear();
}

void CharacterFactory::init()
{
	CharaReader read;
	data = read.read("Plist/charalist.plist");//Plist‚©‚ç‚Ìƒf[ƒ^“Ç‚Ýž‚Ý
	converter.initialize();
	add(CharacterID::FireAttribute,  [](const Parameter& param, const cocos2d::Vec2& position){ return Kamata::create(param, position); });
	add(CharacterID::WaterAttribute, [](const Parameter& param, const cocos2d::Vec2& position){ return Hige::create(param, position); });
	add(CharacterID::Kamata,		 [](const Parameter& param, const cocos2d::Vec2& position){ return Hashigo::create(param, position); });
}

void CharacterFactory::add(CharacterID id, Function func)
{
	container[id] = func;
}

Character* CharacterFactory::create(CharacterID id, const cocos2d::Vec2& position, int pos)
{
	std::string name;
	name = converter.getCharacterName(id);
	Parameter parameter;
	for (auto& charadata : data)
	{
		if (charadata.textureName != name)continue;
		
		parameter.name = charadata.textureName;
		parameter.hp = charadata.hp;
		parameter.speed = charadata.speed;
		parameter.cost = charadata.cost;
		parameter.attackPoint = charadata.attack;
		parameter.attribute = charadata.attribute;
		parameter.move = charadata.move;
		parameter.position = pos;
		assignment(parameter.vect, charadata.vect);
		break;
	}

	return container[id](parameter,position);
}