#ifndef _TESTSCENE_H_
#define _TESTSCENE_H_

#include "cocos2d.h"

#include "../Character/CharacterFactory.h"
#include "../Character/CharacterManager.h"

class TestScene : public cocos2d::Layer
{
protected:
	/********************************
	コンストラクタ
	*********************************/
	TestScene();

	/********************************
	デストラクタ
	*********************************/
	~TestScene();


public:
	/********************************
	初期化
	*********************************/
	virtual bool init() override;

	/*********************************
	更新
	**********************************/
	virtual void update(float deltaTime)override;

	/**********************************
	シーンの作成
	**********************************/
	static TestScene* create();

	/*************************************
	タッチ始め
	***************************************/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*************************************
	タッチ終わり
	***************************************/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	CharacterFactory factory;
	CharacterManager* manager;
};


#endif