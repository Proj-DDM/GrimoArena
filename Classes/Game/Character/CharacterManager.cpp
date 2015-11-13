#include "CharacterManager.h"
#include "Character.h"

CharacterManager::CharacterManager()
{
	container.clear();
}

CharacterManager::~CharacterManager()
{
	//�ێ����Ă���L�����N�^�[�����ׂč폜
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
	//�R�[���o�b�N�ňړ���̃p�l���̐F��ς��܂�
	if (i % 60 == 0){
		std::for_each(container.begin(), container.end(), [func](Character* obj){
			obj->setPositionY(obj->getPositionY() + 64);
			
			cocos2d::Vec2 pos = obj->getPosition() - cocos2d::Vec2(0,19);
			int number = (((int)obj->getPositionX() - 32) / 64)  + (((int)obj->getPositionY() - 160) / 64 * 9);
			func(number);
		});

	}
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