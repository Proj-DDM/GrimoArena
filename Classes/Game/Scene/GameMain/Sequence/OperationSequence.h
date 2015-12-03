#ifndef OPERATIONSEQUENCE_H
#define OPERATIONSEQUENCE_H

#include "ISequence.h"

class Player;

class OperationSequence : public ISequence
{
	enum MOVE_STATUS{
		TOUCH,
		MOVE,
		MOVE_END,
		NULL_MOVE
	};


public:
	OperationSequence(StageManager* stageManager);
	~OperationSequence();

	S_STATUS update(float at) override;					//�X�V

	void main(float at) override;						//���C���X�V

	void start(float at) override;						//�V�[�N�G���X����

	void end(float at) override;						//�V�[�N�G���X�I���

	void onEndSequence() override;					    //�V�[�N�G���X�I���{�^���������ꂽ�Ƃ�

	void isTouch(cocos2d::Vec2 touchPos);				//�t�B�[���h�ւ̃^�b�`����

	void move(const cocos2d::Vec2& touchPos);					//�v���C���[�̈ړ�

	void onPushYesButton();

	void onPushNoButton();

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

private:

	Player* mTurnPlayer;

	MOVE_STATUS isPlayerMove { TOUCH };

	cocos2d::Vec2 touchPos;

};

#endif