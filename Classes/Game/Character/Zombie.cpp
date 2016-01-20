#include "Zombie.h"
#include "../Scene/GameMain/Sequence/SequenceManager.h"
#include "PlayerJudged.h"
using namespace cocos2d;

Zombie::Zombie(const Parameter & param) : Character(param)
{
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

bool Zombie::init(const cocos2d::Vec2 & position)
{
	//int player = SequenceManager::GetInstance()->getTurnPlayer();
	std::string name = JudgedPlayer("mon2_icon_r") + ".png";
	sprite = Sprite::create(name);
	id = CharacterID::Zombie;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

Zombie * Zombie::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new Zombie(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
