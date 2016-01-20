#include "CharacterIDConverter.h"

CharacterIDConverter::CharacterIDConverter()
{
}

CharacterIDConverter::~CharacterIDConverter()
{
}

void CharacterIDConverter::initialize()
{
	add(CharacterID::Aster,				"mon7_icon_g");
	add(CharacterID::Cerberus,			"mon3_icon_r");
	add(CharacterID::Zombie,			"mon2_icon_r");
	add(CharacterID::Cockatrice,		"mon8_icon_b");
	add(CharacterID::Cyan,				"mon4_icon_b");
	add(CharacterID::DryArd,			"mon5_icon_g");
	add(CharacterID::Emerald,			"mon1_icon_g");
	add(CharacterID::Eta,				"mon6_icon_g");
	add(CharacterID::Fee,				"mon6_icon_r");
	add(CharacterID::Fenrir,			"mon3_icon_b");
	add(CharacterID::FreezingZombie,	"mon2_icon_b");
	add(CharacterID::Griffon,			"mon8_icon_g");
	add(CharacterID::Kelvin,			"mon5_icon_b");
	add(CharacterID::Levy,				"mon7_icon_b");
	add(CharacterID::Lilith,			"mon7_icon_r");
	add(CharacterID::Mint,				"mon1_icon_g");
	add(CharacterID::Myu,				"mon6_icon_b");
	add(CharacterID::Orthros,			"mon3_icon_g");
	add(CharacterID::Phoenix,			"mon8_icon_r");
	add(CharacterID::RottenwoodZombie,	"mon2_icon_g");
	add(CharacterID::Rouge,				"mon4_icon_r");
	add(CharacterID::Ruby,				"mon1_icon_r");
	add(CharacterID::Sapphire,			"mon1_icon_b");
	add(CharacterID::Vect,				"mon5_icon_r");
}

void CharacterIDConverter::add(const CharacterID& id, const std::string& name )
{
	container[id] = name;
}