#ifndef OPERATIONSEQUENCE_H
#define OPERATIONSEQUENCE_H

#include "ISequence.h"

class OperationSequence : public ISequence
{
public:
	OperationSequence(StageManager* stageManager);
	~OperationSequence();

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