#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include "cocos2d.h"

#include <vector>
#include <string>


namespace Util{

/*-----------------------------------------------------
		cocos2dxのAnimationクラスを使用した
		パラパラアニメーション作成クラス
		ファイル名　SpriteAnimation.h
		作成者　小林　大峰
-----------------------------------------------------*/	
class SpriteAnimation{
public:
	SpriteAnimation(const std::string& path);
	~SpriteAnimation() = default;

	/*--------------------------------------------------------------------------------
		生成関数
		string spriteName 画像の名前
		int	   count	　フレーム数
		float  delay      切り替え間隔
		bool   restart	　一番初めの画像に戻すか
		bool   repeat	　繰り返すか？
	--------------------------------------------------------------------------------*/
	cocos2d::Sprite* create(const std::string& spriteName, const int count, const float delay, const bool restart, const bool repeat);

	cocos2d::Animate* createAnim(const std::string& spriteName, const int count, const float delay, const bool restart);
	

	/*------------------------------------------------------------
		リソースフォルダのパスを変更する
		const std::string& path リソースパス
	-------------------------------------------------------------*/
	void setResourcesPath(const std::string& path);
private:
	std::string mResourcePath;
	cocos2d::Sprite* firstSprite;
};
}

#endif