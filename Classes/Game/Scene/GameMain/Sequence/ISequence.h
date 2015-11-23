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

	virtual S_STATUS update(float at) = 0;			//更新
	
	virtual void main(float at) = 0;				//メイン更新

	virtual void start(float at) = 0;				//シークエンス初め

	virtual void end(float at) = 0;					//シークエンス終わり

	virtual void onEndSequence() = 0;			    //シークエンス終了設定

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	virtual bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

protected:

	void(ISequence::*updateFunc[S_STATUS::S_NULL])(float at);        //更新用関数ポインタ

	S_STATUS mState;												 //シークエンスの状態
	StageManager* mStageManager;								     //各オブジェクトの管理者

};

#endif