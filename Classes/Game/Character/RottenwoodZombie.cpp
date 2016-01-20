#include "RottenwoodZombie.h"
#include "PlayerJudged.h"

RotternWoodZombie::RotternWoodZombie(const Parameter & param) : Character(param)
{
}

RotternWoodZombie::RotternWoodZombie()
{
}

RotternWoodZombie::~RotternWoodZombie()
{
}

bool RotternWoodZombie::init(const cocos2d::Vec2 & position)
{
	std::string name = JudgedPlayer("mon2_icon_g") + ".png";
	sprite = cocos2d::Sprite::create(name);
	id = CharacterID::RottenwoodZombie;
	sprite->setPosition(position);
	this->addChild(sprite);

	return true;
}

RotternWoodZombie * RotternWoodZombie::create(const Parameter & param, const cocos2d::Vec2 & position)
{
	auto chara = new RotternWoodZombie(param);

	if (chara && chara->init(position)) {
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}
