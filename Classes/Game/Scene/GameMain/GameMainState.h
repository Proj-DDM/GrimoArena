﻿#ifndef GAMEMAINSTATE_H
#define GAMEMAINSTATE_H

#include "cocos2d.h"
#include "Utility/SceneSupport/IScene.h"
#include "Game/Object/StageObject/StageMap/StageManager.h"


class GameMainState : public IScene {
public:
	/*-------------------------------------------------------------------
	|	・コンストラクタ
	-------------------------------------------------------------------*/
	GameMainState() = default;

	/*-------------------------------------------------------------------
	|	・デストラクタ
	-------------------------------------------------------------------*/
	~GameMainState() {};

	/*-------------------------------------------------------------------
	|	・レイヤーの生成
	-------------------------------------------------------------------*/
	static GameMainState* create(cocos2d::Layer* layer, cocos2d::Layer* uiLayer);

	/*-------------------------------------------------------------------
	|	・初期化
	--------------------------------------------------------------------*/
	bool init(cocos2d::Layer* layer, cocos2d::Layer* uiLayer) override;

	/*-------------------------------------------------------------------
	|	・描画開始時
	--------------------------------------------------------------------*/
	void onEnter();

	/*--------------------------------------------------------------------
	|	・更新
	|　 float at	１フレームにかかる時間
	--------------------------------------------------------------------*/
	void update(float at) override;

	/*--------------------------------------------------------------------
	|	・シーン始め
	-------------------------------------------------------------------*/
	void fadeIn(float at) override;


	/*------------------------------------------------------------------
	|	・ゲームメイン更新
	-------------------------------------------------------------------*/
	void sceneMain(float at) override;

	/*------------------------------------------------------------------
	|	・シーン終了
	------------------------------------------------------------------*/
	void fadeOut(float at)   override;

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・シークエンス終了ボタン
	----------------------------------------------------------------------*/
	void onEndButton();

	//カメラ切り替え
	void onViewButton();

private:
	/*------------------------------------------------------------------
	|	メインループ始め
	-------------------------------------------------------------------*/
	void mainStart(float at) override;

	/*------------------------------------------------------------------
	|	ゲームメイン更新
	-------------------------------------------------------------------*/
	void mainLoop(float at)  override;

	/*------------------------------------------------------------------
	|	メインループ終了
	------------------------------------------------------------------*/
	void mainEnd(float at)   override;


	void cameraControl(cocos2d::Touch* touch, cocos2d::Event* user_event);


private:
	StageManager* mStageManager;
	cocos2d::ActionCamera* camera;
	int mCount;
	cocos2d::Vec2  movePos;
	bool    isView{ false };
};

#endif