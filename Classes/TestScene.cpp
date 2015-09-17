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
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool TestScene::init(){
	return true;
}

bool TestScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	return true;

}