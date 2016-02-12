#include "Character.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
using namespace cocos2d;
#include "Utility/Camera/Camera.h"
#include "Utility/Animation/SpriteAnimation.h"

Character::Character(const Parameter& param)
:parameter(param), isTouch(false)
{
	state = CharacterState::MoveWait;
	if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER1) {
		this->user = CharacterUser::Player1;
	} else if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER2){
		this->user = CharacterUser::Player2;
	}
	
}

Character::Character() : parameter(0,0,0)
{
}

Character::~Character()
{
}

bool Character::init(const cocos2d::Vec2& position)
{
	return true;
}

Character* Character::create(const Parameter& param, const cocos2d::Vec2& position)
{
	auto chara = new Character(param);
	if (chara && chara->init(position)){
		chara->retain();
		chara->autorelease();
		return chara;
	}

	CC_SAFE_DELETE(chara);
	return nullptr;
}


Parameter& Character::getParameter(){

	return this->parameter;
}

CharacterState& Character::getState() {
	return this->state;
}

bool Character::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto target = sprite;
	auto touchPoint = gremo::Camera::getInstance().convertTouchPosition(touch);	//タッチ座標の取得
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(touchPoint))
	{
		sprite->setColor(Color3B::RED);
		isTouch = true;
		return true;
	}
	sprite->setColor(Color3B::WHITE);
	isTouch = false;
	return false;
}

void Character::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

bool Character::onTouchCheck(const Vec2& touchPoint)
{
	auto target = sprite;
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(touchPoint))
	{
		sprite->setColor(Color3B::RED);
		isTouch = true;
		return true;
	}
	sprite->setColor(Color3B::WHITE);
	isTouch = false;
	return false;
}

void Character::checkSkillRange(const cocos2d::Vec2& position, const Skill::Status& status, CharacterUser player)
{
	auto target = sprite;
	Rect rect = target->getBoundingBox();

	if (!rect.containsPoint(position)) return;
	
	this->parameterOrigin = this->parameter;

	std::string name = "";
	int flameCount = 0;

	if (player != this->getCharacterUser() &&  status.damage)
	{
		this->parameter.hp -= status.damage;
		name = "fire_";
		flameCount = 8;
	}

	if (player == this->getCharacterUser() && status.hp)
	{
		this->parameter.hp += status.hp;
		name = "hart_";
		flameCount = 20;
	}

	this->parameter.attackPoint += status.attack;
	if (this->parameter.attackPoint < 0) this->parameter.attackPoint = 0;
	this->parameter.move.y += status.moveY;
	this->parameter.speed += status.speed;

	if (player == this->getCharacterUser() && 0 < status.attack || 0 < status.moveY || 0 < status.speed)
	{
		name = "up_";
		flameCount = 10;
	}

	if (player != this->getCharacterUser() &&  status.attack < 0 || status.moveY < 0 || status.speed < 0)
	{
		name = "down_";
		flameCount = 10;
	}

	if (name == "") return;

	auto sprite = Sprite::create();
	this->getParent()->addChild(sprite);
	sprite->setPosition(Point(
		this->getSprite()->getPositionX() + this->getPositionX(),
		this->getSprite()->getPositionY() + this->getPositionY()));
	sprite->setTextureRect(Rect(0, 0, 120, 120));
	sprite->setCameraMask((int)CameraFlag::USER1);

	auto func = CallFunc::create([sprite]() {
		sprite->removeFromParentAndCleanup(true);
	});

	Util::SpriteAnimation spriteAnimetion("Effect/");
	auto anime =  spriteAnimetion.createAnim(name, flameCount, 0.08f, false);

	auto seq = Sequence::create(anime, func, NULL);
	sprite->runAction(seq);

}

void Character::setOpacity(int alpha)
{
	sprite->setOpacity(alpha);
}

void Character::read()
{
	SkillReader reder;

	auto status = reder.read(parameter.name);
	this->skill.setStatus(status);

}