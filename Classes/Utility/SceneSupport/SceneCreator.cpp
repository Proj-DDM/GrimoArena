#include "SceneCreator.h"

using namespace cocos2d;

Scene* SceneCreator::createScene( Layer* childLayer )
{
	auto scene = Scene::create();

	const Size& s{ Director::getInstance()->getVisibleSize() };
	Camera* camera { Camera::createOrthographic(s.width / 3, s.height / 3, -300.0f, 1000.f) };
	camera->setCameraFlag(CameraFlag::USER1);
	scene->addChild(camera);

	scene->addChild( childLayer );
	return scene;
}

Scene* SceneCreator::createScene(Layer* childLayer,Layer* uiLayer)
{
	auto scene = Scene::create();
	
	const Size& s{ Director::getInstance()->getVisibleSize() };
	Camera* camera{ Camera::createOrthographic(s.width , s.height , -600.0f, 1000.f) };
	camera->setCameraFlag(CameraFlag::USER1);
	scene->addChild(camera);
	
	scene->addChild( childLayer );
	scene->addChild( uiLayer );

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