#include "SpriteCreator.h"

using namespace cocos2d;

Sprite* SpriteCreator::create(const std::string& filePath)
{
	Sprite* sprite = Sprite::create(filePath);
	return sprite;
}

Sprite* SpriteCreator::createPhysicsCircle(const std::string& filePath,float radius)
{
	//スプライトを生成
	Sprite* sprite = Sprite::create(filePath);
	//物理挙動の生成
	PhysicsBody* body = PhysicsBody::createCircle(radius);
	//キャラの重さを設定
	body->setMass(1.0f);
	//スプライトに物理挙動をセット
	sprite->setPhysicsBody(body);

	return sprite;
}

Sprite* SpriteCreator::createPhysicsBox(const std::string& filePath, cocos2d::Size size)
{
	//スプライトを生成
	Sprite* sprite = Sprite::create(filePath);
	//物理挙動の生成
	PhysicsBody* body = PhysicsBody::createBox(size);
	//キャラの重さを設定
	body->setMass(1.0f);
	body->setDynamic(true);
	//スプライトに物理挙動をセット
	sprite->setPhysicsBody(body);

	return sprite;
}