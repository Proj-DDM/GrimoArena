#ifndef _SPRITECREATOR_H_
#define _SPRITECREATOR_H_

//インクルード
#include "cocos2d.h"

/***************************************

キャラクタースプライト作成の補助

作成者: 小林勇輝

****************************************/
class SpriteCreator
{
public:
	/***********************************************
	スプライトの作成
	filePath: 画像ファイルのある場所と画像名
	************************************************/
	static cocos2d::Sprite* create(const std::string& filePath);

	/***********************************************
	円形の当たり判定の物理挙動をもったスプライト作成
	filePath: 画像ファイルのある場所と画像名
	radius: 当たり判定の半径
	************************************************/
	static cocos2d::Sprite* createPhysicsCircle(const std::string& filePath, float radius);

	/***********************************************
	四角形の当たり判定の物理挙動をもったスプライト作成
	filePath: 画像ファイルのある場所と画像名
	size: 当たり判定の四角形のサイズ
	************************************************/
	static cocos2d::Sprite* createPhysicsBox(const std::string& filePath, cocos2d::Size size);

private:

};



#endif