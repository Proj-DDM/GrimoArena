#include "CharacterFactory.h"
#include "Character.h"
#include "SampleKamata.h"
#include "../Test/SampleHashigo.h"

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
	add(CharacterID::FireAttribute, Kamata::create());
	add(CharacterID::WaterAttribute, Hashigo::create());
}

void CharacterFactory::add(CharacterID id, Character* instance)
{
	container[id] = instance;
}

Character* CharacterFactory::create(CharacterID id, const Parameter& param, const cocos2d::Vec2& position)
{
	return container[id]->clone(param,position);
}