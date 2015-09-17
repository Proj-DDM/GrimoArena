#pragma once

#include "cocos2d.h"

class TestScene : cocos2d::Layer
{
public:

	static TestScene* create();

	TestScene();
	~TestScene();

	bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
};

