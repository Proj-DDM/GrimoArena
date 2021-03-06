#ifndef ENDSEQUENCE_H
#define ENDSEQUENCE_H

#include "ISequence.h"

class EndSequence : public ISequence
{
public:
	EndSequence(StageManager* stageManager);
	~EndSequence();

	S_STATUS update(float at) override;					//更新

	void main(float at) override;						//メイン更新

	void start(float at) override;						//シークエンス初め

	void end(float at) override;						//シークエンス終わり

	void onEndSequence() override;

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