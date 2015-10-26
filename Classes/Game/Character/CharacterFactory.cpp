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
	//•ÛŽ‚µ‚Ä‚¢‚é»•i‚ð‚·‚×‚Äíœ
	Container::iterator i = container.begin();
	while (i != container.end())
	{
		CC_SAFE_RELEASE(i->second);
		++i;
	}
}

void CharacterFactory::init()
{
	add(CharacterID::FireAttribute , Kamata::create());
	add(CharacterID::WaterAttribute, Hashigo::create());
	add(CharacterID::Kamata        , Hige::create());
}

void CharacterFactory::add(CharacterID id, Character* instance)
{
	container[id] = instance;
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

	return container[id]->clone(parameter,position);
}