#ifndef SKILLFIELD_H
#define	SKILLFIELD_H

#include "cocos2d.h"
#include <array>

class Skill
{
public:
//�X�L���X�e�[�^�X
	struct Status
	{
		int damage{ 0 };   //�_���[�W�X�L��
		int attack{ 0 };   //�U���̓A�b�v
		int speed{ 0 };    //�ړ����x�A�b�v
		int moveY{ 0 };    //�ړ��ʃA�b�v
		int hp{ 0 };       //�̗͉�
		std::array<int, 50> skillField;


		Status(){};
	};

//�ϐ�
private:
	Status status;


public:
	Skill(){};

	~Skill(){};

	std::array<int, 50>& getArray() { return status.skillField; }

	const Status getStatus() { return this->status; }

	void setStatus(Status status) { this->status = status; }
};

#endif