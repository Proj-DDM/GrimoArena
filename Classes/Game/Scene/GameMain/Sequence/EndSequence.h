#ifndef ENDSEQUENCE_H
#define ENDSEQUENCE_H

#include "ISequence.h"

class EndSequence : public ISequence
{
public:
	EndSequence(StageManager* stageManager);
	~EndSequence();

	S_STATUS update(float at) override;					//�X�V

	void main(float at) override;						//���C���X�V

	void start(float at) override;						//�V�[�N�G���X����

	void end(float at) override;						//�V�[�N�G���X�I���

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

};

#endif