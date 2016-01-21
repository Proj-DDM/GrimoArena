#ifndef BATTLESEQUENCE_H
#define BATTLESEQUENCE_H

#include "ISequence.h"
#include <vector>
#include <algorithm>
#include "../../../Character/CharacterFactory.h"
#include "../../../Character/CharacterManager.h"

class BattelSequence : public ISequence
{
public:
	BattelSequence(StageManager* stageManager);
	~BattelSequence();

	typedef std::function<void(int i)> test_FUNC;

	S_STATUS update(float at) override;					//�X�V

	void main(float at) override;						//���C���X�V

	void start(float at) override;						//�V�[�N�G���X����

	void end(float at) override;						//�V�[�N�G���X�I���

	void onEndSequence() override;

	void deadCheck();
	void actionMain(int id);
	void checkPos(int pos);
	void attackPos(int pos);
	void move(int id, int user);

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
private:
	cocos2d::Sprite* sprite;
	cocos2d::Animate* anime;
	bool isAnime;
	int mCount;
	int mCharaPos;
	int charauser;
	int mAttackParam;
	int attackpanel;
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container;
	std::array<int, 25> mAttackArray;
	cocos2d::Vec2 mBaseLine;
	cocos2d::Vec2 mCharaLine;
	cocos2d::Vec2 mPanelLine;
};

#endif