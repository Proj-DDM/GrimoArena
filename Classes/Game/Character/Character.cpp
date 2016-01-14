#include "Character.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
using namespace cocos2d;
#include "Utility/Camera/Camera.h"

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
	Point touchPoint = touch->getLocation();	//タッチ座標の取得
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

void Character::setOpacity(int alpha)
{
	sprite->setOpacity(alpha);
}
