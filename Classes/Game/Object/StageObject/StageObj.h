#ifndef STAGEOBJ_H
#define STAGEOBJ_H

#include "cocos2d.h"
#include "Utility/CocosAssistant/SpriteCreator.h"

class StageObj : public cocos2d::Node{
public:

	virtual ~StageObj(){
		if(mSprite->getReferenceCount() <= 0){
			mSprite->release();
		}
	};

	virtual void update(float deltatime) = 0;


	/*----------------------------------------------------
	|	ポジションのセット（スプライトのポジションを変更します）
	|	const cocos2d::Vec2 &position　位置
	-----------------------------------------------------*/
	void setPosition(const cocos2d::Vec2 &position) override{ mSprite->setPosition(position); }
	
	/*----------------------------------------------------
	|	ポジションの取得（スプライトのポジションを取得）
	|	const cocos2d::Vec2 &position　位置
	-----------------------------------------------------*/
	const cocos2d::Vec2& getPosition() const override		{ return mSprite->getPosition(); }

	/*----------------------------------------------------
	|	スプライトの高さを変更
	|	const cocos2d::Vec2 　位置
	-----------------------------------------------------*/
	void setPositionY(float positionY) override				{ mSprite->setPositionY(positionY); }

	/*----------------------------------------------------
	|	スプライトの高さを取得
	|	float　高さ
	-----------------------------------------------------*/
	float getPositionY(void) const override					{ return mSprite->getPositionY(); }

	/*----------------------------------------------------
	|	スプライトのサイズを取得
	|	const cocos2d::Rect& スプライトのサイズ
	-----------------------------------------------------*/
	cocos2d::Rect getBoundingBox() const override			{ return mSprite->getBoundingBox(); }


protected:

	cocos2d::Sprite* mSprite;
};

#endif