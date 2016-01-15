#include "SimpleParticle.h"

// インスタンスの生成
ParticleSystemQuad* SimpleParticle::create( const std::string& particleName, const Vec2& createPos )
{
	// plistFileからパーティクルシステムを生成します
	auto filePath	= "Particle2dx/Normal/" + particleName + ".plist";
	auto particle	= ParticleSystemQuad::create( filePath );
	
	// 各パラメータを設定します
	particle->setAutoRemoveOnFinish( true );
	particle->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	particle->setPosition( createPos );

	// インスタンスを返却します
	return particle;
}