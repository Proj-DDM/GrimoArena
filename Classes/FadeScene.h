#pragma once
#include "cocos2d.h"

/*----------------------------------------------------
	 ファイル名 FadeScene.h
	 作成者     小林 大峰
  ・シーン遷移の時にフェードインアウトをするクラス
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
	
	//初期化
	bool init(float t, SceneCreateFunc scene);

	//シーン切り替え
	void hideOutShowIn(void);

	//シーン終了処理
	void finish(void);

	//新しいシーンをセット
	void setNewScene(float dt);

	//次のシーンを作る関数
	SceneCreateFunc m_CreateFunc;
	
	Scene* m_OutScene;
	Scene* m_InScene;

	float m_Timer;

};

