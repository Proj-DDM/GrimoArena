#ifndef BATTLESEQUENCE_H
#define BATTLESEQUENCE_H

#include "ISequence.h"

class BattelSequence : public ISequence
{
public:
	BattelSequence(StageManager* stageManager);
	~BattelSequence();

	S_STATUS update(float at) override;					//更新

	void main(float at) override;						//メイン更新

	void start(float at) override;						//シークエンス初め

	void end(float at) override;						//シークエンス終わり

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

};

#endif