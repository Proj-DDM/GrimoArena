#ifndef _SIMPLE_PARTICLE_H_
#define _SIMPLE_PARTICLE_H_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

/**
	@class	：	SimpleParticle
	@brief	：	パーティクルの簡単なラップクラス
	@author	：	利川聖太
 */
class SimpleParticle : public ParticleSystemQuad
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	SimpleParticle() = default;
	
	/**
		@brief	デストラクタ
	 */
	~SimpleParticle() = default;
	
	/**
		@brief	インスタンスの生成
	 
		@param	particleName	パーティクルの名前( ファイルパス, 拡張子不要 )
		@param	createPos		パーティクルを生成する座標
	 */
	static ParticleSystemQuad* create( const std::string& particleName, const Vec2& createPos );
};

#endif