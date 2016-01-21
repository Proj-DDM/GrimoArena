#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
/************************************************

 Player.h
 �쐬��:���їE�P

*************************************************/
class Player : public Character
{
public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//������
	bool init(const cocos2d::Vec2& position, const std::string& name);

	//�C���X�^���X�̐���
	static Player* create(const cocos2d::Vec2& position, int number, const std::string& name);

	void setPosition(const cocos2d::Vec2& position);

	const cocos2d::Vec2& getPosition() const override;

	cocos2d::Rect getBoundingBox() const override;

	void mathMana(const int value);

	const int getMana() { return this->mana; }

	cocos2d::Sprite* setIcon(std::string textureName);

	const int getPanelNumber() { return this->panelNumber; };

private:

	int mana { 0 };
	int panelNumber { -1 };
	cocos2d::Sprite* icon;
	
};

#endif