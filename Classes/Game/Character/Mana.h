#ifndef MANA_H
#define MANA_H

//---------------------
// �@�@Mana.h
// �쐬�ҁ@���� ���
//
// �g���������̂��߂̖��͂��Ǘ�����N���X
//

#include "cocos2d.h"

USING_NS_CC;

class Mana : public Node
{

public:
	//�C���X�^���X���\�b�h
	CREATE_FUNC_PARAM1(Mana,int);

	using ManaSpriteContainer = std::vector<Sprite*>;

	//�N���X�ϐ�
private:

	int mana;

	ManaSpriteContainer manaSpriteContainer;
	//�N���X���\�b�h
public:

	Mana();
	~Mana();

	bool init(int);

	void setMana(int value);

	void setFadeAnimation(int manaCount);

};

#endif