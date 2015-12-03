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

	S_STATUS update(float at) override;					//更新

	void main(float at) override;						//メイン更新

	void start(float at) override;						//シークエンス初め

	void end(float at) override;						//シークエンス終わり

	void onEndSequence() override;					    //シークエンス終了ボタンが押されたとき

	void isTouch(cocos2d::Vec2 touchPos);				//フィールドへのタッチ処理

	void move(const cocos2d::Vec2& touchPos);					//プレイヤーの移動

	void onPushYesButton();

	void onPushNoButton();

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

private:

	Player* mTurnPlayer;

	MOVE_STATUS isPlayerMove { TOUCH };

	cocos2d::Vec2 touchPos;

};

#endif