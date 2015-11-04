#include "CharacterIDConverter.h"

CharacterIDConverter::CharacterIDConverter()
{
}

CharacterIDConverter::~CharacterIDConverter()
{
}

void CharacterIDConverter::initialize()
{
	add(CharacterID::FireAttribute, "mon2_tati_r");
	add(CharacterID::WaterAttribute, "mon3_tati_r");
	add(CharacterID::Kamata, "mon1_tati_r");
}

void CharacterIDConverter::add(const CharacterID& id, const std::string& name )
{
	container[id] = name;
}