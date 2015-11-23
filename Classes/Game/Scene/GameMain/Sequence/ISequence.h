#ifndef ISEQUENCE_H
#define ISEQUENCE_H

#include "cocos2d.h"

class StageManager;
enum S_STATUS{
	S_START = 0,
	S_MAIN,
	S_END,
	S_NULL
};

class ISequence {

public:

	ISequence(StageManager* stageManager) : mState(S_START),mStageManager(stageManager){

		updateFunc[0] = &ISequence::start;
		updateFunc[1] = &ISequence::main;
		updateFunc[2] = &ISequence::end;

	}

	virtual S_STATUS update(float at) = 0;			//�X�V
	
	virtual void main(float at) = 0;				//���C���X�V

	virtual void start(float at) = 0;				//�V�[�N�G���X����

	virtual void end(float at) = 0;					//�V�[�N�G���X�I���

	virtual void onEndSequence() = 0;			    //�V�[�N�G���X�I���ݒ�

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	virtual bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

protected:

	void(ISequence::*updateFunc[S_STATUS::S_NULL])(float at);        //�X�V�p�֐��|�C���^

	S_STATUS mState;												 //�V�[�N�G���X�̏��
	StageManager* mStageManager;								     //�e�I�u�W�F�N�g�̊Ǘ���

};

#endif