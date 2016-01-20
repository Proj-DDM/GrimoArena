#include "CharacterFactory.h"
#include "Character.h"
#include "../../Utility/FileIO/CharaReader.h"
#include "Zombie.h"
#include "Aster.h"
#include "Cerberus.h"
#include "Cockatrice.h"
#include "Cyan.h"
#include "DryArd.h"
#include "Eta.h"
#include "Emerald.h"
#include "Fee.h"
#include "Fenrir.h"
#include "FreezingZombie.h"
#include "Griffon.h"
#include "Kelvin.h"
#include "Levy.h"
#include "Lilith.h"
#include "Mint.h"
#include "Myu.h"
#include "Orthros.h"
#include "Phoenix.h"
#include "RottenwoodZombie.h"
#include "Rouge.h"
#include "Ruby.h"
#include "Vect.h"
#include "Sapphire.h"


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
	add(CharacterID::Aster,  [](const Parameter& param, const cocos2d::Vec2& position){ return Aster::create(param, position); });
	add(CharacterID::Cerberus, [](const Parameter& param, const cocos2d::Vec2& position){ return Cerberus::create(param, position); });
	add(CharacterID::Cockatrice,		 [](const Parameter& param, const cocos2d::Vec2& position){ return Cockatrice::create(param, position); });
	add(CharacterID::Cyan, [](const Parameter& param, const cocos2d::Vec2& position) { return Cyan::create(param, position); });
	add(CharacterID::DryArd, [](const Parameter& param, const cocos2d::Vec2& position) { return DryArd::create(param, position); });
	add(CharacterID::Emerald, [](const Parameter& param, const cocos2d::Vec2& position) { return Emerald::create(param, position); });
	add(CharacterID::Eta, [](const Parameter& param, const cocos2d::Vec2& position) { return Eta::create(param, position); });
	add(CharacterID::Fee, [](const Parameter& param, const cocos2d::Vec2& position) { return Fee::create(param, position); });
	add(CharacterID::Fenrir, [](const Parameter& param, const cocos2d::Vec2& position) { return Fenrir::create(param, position); });
	add(CharacterID::FreezingZombie, [](const Parameter& param, const cocos2d::Vec2& position) { return FreezingZombie::create(param, position); });
	add(CharacterID::Griffon, [](const Parameter& param, const cocos2d::Vec2& position) { return Griffon::create(param, position); });
	add(CharacterID::Kelvin, [](const Parameter& param, const cocos2d::Vec2& position) { return Kelvin::create(param, position); });
	add(CharacterID::Lilith, [](const Parameter& param, const cocos2d::Vec2& position) { return Lilith::create(param, position); });
	add(CharacterID::Mint, [](const Parameter& param, const cocos2d::Vec2& position) { return Mint::create(param, position); });
	add(CharacterID::Myu, [](const Parameter& param, const cocos2d::Vec2& position) { return Myu::create(param, position); });
	add(CharacterID::Orthros, [](const Parameter& param, const cocos2d::Vec2& position) { return Orthros::create(param, position); });
	add(CharacterID::Phoenix, [](const Parameter& param, const cocos2d::Vec2& position) { return Phoenix::create(param, position); });
	add(CharacterID::RottenwoodZombie, [](const Parameter& param, const cocos2d::Vec2& position) { return RotternWoodZombie::create(param, position); });
	add(CharacterID::Rouge, [](const Parameter& param, const cocos2d::Vec2& position) { return Rouge::create(param, position); });
	add(CharacterID::Ruby, [](const Parameter& param, const cocos2d::Vec2& position) { return Ruby::create(param, position); });
	add(CharacterID::Sapphire, [](const Parameter& param, const cocos2d::Vec2& position) { return Sapphire::create(param, position); });
	add(CharacterID::Levy, [](const Parameter& param, const cocos2d::Vec2& position) { return Levy::create(param, position); });
	add(CharacterID::Vect, [](const Parameter& param, const cocos2d::Vec2& position) { return Vect::create(param, position); });
	add(CharacterID::Zombie, [](const Parameter& param, const cocos2d::Vec2& position) { return Zombie::create(param, position); });
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