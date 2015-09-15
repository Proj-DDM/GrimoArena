#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}


TestScene* TestScene::create(){
	auto obj = new TestScene();

	if (obj && obj->init()){
		obj->auto
	}
}