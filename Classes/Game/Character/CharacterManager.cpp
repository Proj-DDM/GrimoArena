#include "CharacterManager.h"
#include "Character.h"

#define MAX_ARRAY  25

using namespace cocos2d;

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

void CharacterManager::update(test_FUNC func)
{
	static int i = 0;
	i++;
	//コールバックで移動先のパネルの色を変えます
	if (i % 60 == 0){
		std::for_each(container.begin(), container.end(), [func](Character* obj){
			obj->setPositionY(obj->getPositionY() + 120);
			
			cocos2d::Vec2 pos = obj->getPosition() - cocos2d::Vec2(0,19);
			int number = (((int)obj->getPositionX() - 32) / 120)  + (((int)obj->getPositionY() - 160) / 120 * 9);
			func(number);
		});

	}
}

void CharacterManager::add(Character* character)
{
	addChild(character);
	container.push_back(character);
}

std::array<int, MAX_ARRAY> CharacterManager::getContainer(int id) {
	
	std::array<int, MAX_ARRAY> charavect{};

	if (container.empty() || container.size() < id ) return charavect;
	
	for (int i = 0; i < MAX_ARRAY; ++i) {
		//charavect[i] = container[id]->getParameter().vect[i];
		CCLOG("%i", (int)container[0]->getParameter().vect[i]);
	}
	return charavect;
	//charavect;
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

bool CharacterManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (container.empty())return false;
	for (auto& panel : container)
	{
		if (panel->onTouchBegan(touch, event))
		{
			parameter = panel->getParameter();
			return true;
		}
	}
	return false;
}