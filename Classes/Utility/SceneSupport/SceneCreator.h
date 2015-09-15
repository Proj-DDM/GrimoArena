#ifndef _SCENE_CREATOR_H_
#define _SCENE_CREATOR_H_

#include "cocos2d.h"

/**
 *	@class	：	SceneCreator
 *	@brief	：	シーンの生成を補助するクラス
 *	@author	：	利川聖太
 */
class SceneCreator
{
	
public:
	
	/**
	 *	@brief	シーンの生成
	 *	@param	childLayer	子ノードにするレイヤ
	 *	@return	Scene		シーンのインスタンス
	 */
	static cocos2d::Scene* createScene( cocos2d::Layer* childLayer );
	
	/**
	 *	@brief	物理空間を所有したシーンの生成
	 *	@param	childLayer	子ノードにするレイヤ
	 *	@param	gravity		物理空間に与える重力
	 *	@param	speed		物理演算が行われる速度
	 *						増加させることで、高速に動作するオブジェクトの「コリジョン抜け」を防ぐことができます。( デフォルトでは1.0秒 )
	 *	@param	isDebug		物理空間内のデバッグ描画を行うか否か( デフォルトでは行わない )
	 *	@return	Scene		シーンのインスタンス
	 */
	static cocos2d::Scene* createPhysicsScene( cocos2d::Layer* childLayer, const cocos2d::Vect& gravity, float speed = 1.f, bool isDebug = false );
};

#endif