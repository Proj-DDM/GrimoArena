#include "CharacterManager.h"
#include "Character.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#include "Utility/Camera/Camera.h"

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

void CharacterManager::update(float dt)
{
	for (int i = 0; i < container.size(); ++i) {
		if (container[i]->getParameter().hp.isDead())
		{
			auto act = RemoveSelf::create();
			//container[i]->removeFromParent();
			container[i]->runAction(act);
		}

	}
}

void CharacterManager::add(Character* character)
{
	addChild(character);
	character->setCameraMask((int)CameraFlag::USER1);
	container.push_back(character);
}

std::array<int, MAX_ARRAY> CharacterManager::getContainer(int id) {
	
	std::array<int, MAX_ARRAY> charavect{};

	//if (container.empty() || container.size() < id ) return charavect;
	
	for (int i = 0; i < MAX_ARRAY; ++i) {
		charavect[i] = getParameter().vect[i];
		CCLOG("%i", (int)container[0]->getParameter().vect[i]);
	}
	return charavect;
}

std::vector < Character* > CharacterManager::getCaras() {
	return container;
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
		auto convertTouchPos = gremo::Camera::getInstance().convertTouchPosition(touch);

		if (panel->onTouchCheck(convertTouchPos))
		{
			parameter = panel->getParameter();
			return true;
		}
	}
	return false;
}