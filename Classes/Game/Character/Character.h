#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "CharacterParameter.h"
#include "CharacterType.h"
#include <vector>
#include "CharactorCore.h"
#include "Skill.h"
#include "Utility/FileIO/SkillReader.h"

class Character : public cocos2d::Node
{
public:
	Character( const Parameter& param );
	Character();
	~Character();
	virtual bool init(const cocos2d::Vec2& position);
	Parameter& getParameter();		//キャラのパラメータ
	CharacterState& getState();

	Character* create(const Parameter& param, const cocos2d::Vec2& position);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	bool onTouchCheck(const cocos2d::Vec2& touchPoint);

	void checkSkillRange(const cocos2d::Vec2& position, const Skill::Status& status, CharacterUser player);

	void setOpacity(int alpha);

	CharacterID getCharacterID() const
	{
		return id;
	}

	CharacterUser getCharacterUser() const
	{
		return user;
	}

	bool IsTouch()const
	{
		return isTouch;
	}

	cocos2d::Sprite* getSprite(){ return this->sprite; };
	Skill getSkillParameter() { return skill; };

	void read();

protected:
	Parameter parameter;
	cocos2d::Sprite* sprite;
	CharacterID id;
	CharacterUser user;
	CharacterState state;
	Skill skill;
	bool isTouch;
	Parameter parameterOrigin;
};


#endif