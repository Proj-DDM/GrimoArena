#ifndef _TESTSCENE_H_
#define _TESTSCENE_H_

#include "cocos2d.h"

#include "../Character/CharacterFactory.h"
#include "../Character/CharacterManager.h"

class TestScene : public cocos2d::Layer
{
protected:
	/********************************
	�R���X�g���N�^
	*********************************/
	TestScene();

	/********************************
	�f�X�g���N�^
	*********************************/
	~TestScene();


public:
	/********************************
	������
	*********************************/
	virtual bool init() override;

	/*********************************
	�X�V
	**********************************/
	virtual void update(float deltaTime)override;

	/**********************************
	�V�[���̍쐬
	**********************************/
	static TestScene* create();

	/*************************************
	�^�b�`�n��
	***************************************/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*************************************
	�^�b�`�I���
	***************************************/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	CharacterFactory factory;
	CharacterManager* manager;
};


#endif