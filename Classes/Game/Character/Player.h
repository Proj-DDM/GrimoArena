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
	bool init(const cocos2d::Vec2& position)override;

	//�C���X�^���X�̐���
	static Player* create(const cocos2d::Vec2& position);


private:
	
};

#endif