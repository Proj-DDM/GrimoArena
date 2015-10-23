#include "CharacterManager.h"
#include "Character.h"

CharacterManager::CharacterManager()
{
	container.clear();
}

CharacterManager::~CharacterManager()
{
	//保持しているキャラクターをすべて削除
	CharacterContainer::iterator i = container.begin();
	while (i != container.end())
	{
		CC_SAFE_RELEASE(*i);
		++i;
	}
}

bool CharacterManager::init()
{
	return true;
}

void CharacterManager::update()
{

}


void CharacterManager::add(Character* character)
{
	addChild(character);
	container.push_back(character);
}

CharacterManager* CharacterManager::create()
{
	auto instance = new CharacterManager();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}