#include "SceneCreator.h"

using namespace cocos2d;

Scene* SceneCreator::createScene( Layer* childLayer )
{
	auto scene = Scene::create();
	scene->addChild( childLayer );
	
	return scene;
}

Scene* SceneCreator::createPhysicsScene( Layer* childLayer, const Vect& gravity, float speed, bool isDebug )
{
	auto scene	= Scene::createWithPhysics();
	auto world	= scene->getPhysicsWorld();
	
	world->setGravity( gravity );
	world->setSpeed( speed );
	
	if ( isDebug )
	{
		world->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
	}
	
	scene->addChild( childLayer );
	
	return scene;
}