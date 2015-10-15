#pragma once
#include "cocos2d.h"

/*----------------------------------------------------
	 �t�@�C���� FadeScene.h
	 �쐬��     ���� ���
  �E�V�[���J�ڂ̎��Ƀt�F�[�h�C��������N���X
----------------------------------------------------*/
class FadeScene : cocos2d::Scene
{
private:
	
	typedef std::function<cocos2d::Scene*()> SceneCreateFunc;

public:

	static Scene * create(float t, SceneCreateFunc func);

	FadeScene();
	~FadeScene();

	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual void cleanup() override;

private:
	
	//������
	bool init(float t, SceneCreateFunc scene);

	//�V�[���؂�ւ�
	void hideOutShowIn(void);

	//�V�[���I������
	void finish(void);

	//�V�����V�[�����Z�b�g
	void setNewScene(float dt);

	//���̃V�[�������֐�
	SceneCreateFunc m_CreateFunc;
	
	Scene* m_OutScene;
	Scene* m_InScene;

	float m_Timer;

};


/*----------------------------------------------------
�t�@�C���� ReplaceScene.h
�쐬��     ���� ���
�E�V�[���J�ڂ�����N���X
�E�A�j���[�V�����͉��������ł��B
----------------------------------------------------*/
class ReplaceScene : cocos2d::Scene
{

private:

	typedef std::function<cocos2d::Scene*()> SceneCreateFunc;

public:

	static Scene * create(SceneCreateFunc func);

	ReplaceScene();
	~ReplaceScene();

	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual void cleanup() override;

private:

	//������
	bool init(SceneCreateFunc scene);

	//�V�[���I������
	void finish(void);

	//�V�����V�[�����Z�b�g
	void setNewScene(float dt);

	//���̃V�[�������֐�
	SceneCreateFunc m_CreateFunc;

	Scene* m_OutScene;

};
