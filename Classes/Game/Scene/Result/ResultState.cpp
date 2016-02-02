#include "ResultState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameMainScene.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Utility/Modal/ModalLayer.h"
#include "Game/Layer/UILayer.h"
#include "Utility/SceneSupport/FadeScene.h"

using namespace cocos2d;

using namespace cocos2d;

ResultState* ResultState::create(Layer* layer){

	auto obj = new ResultState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool ResultState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;

	//点数
	UserDefault* userDef = UserDefault::getInstance();

	CCLOG("A %i", userDef->getIntegerForKey("blue"));
	CCLOG("B %i", userDef->getIntegerForKey("red"));

	auto resultbg = Sprite::create("Scene/Result/background.png");
	parentLayer->addChild(resultbg);
	resultbg->setPosition(Director::getInstance()->getVisibleSize() / 2);

	auto resultrogo = Sprite::create("Scene/Result/result_logo.png");
	parentLayer->addChild(resultrogo);
	resultrogo->setPosition(resultrogo->getContentSize().width / 2, Director::getInstance()->getVisibleSize().height - resultrogo->getContentSize().height / 2);

	auto player1icon = Sprite::create("Chara/1P/player1_icon.png");
	player1icon->setScale(2, 2);
	parentLayer->addChild(player1icon);
	player1icon->setPosition(player1icon->getContentSize().width +
		player1icon->getContentSize().width / 2,
		player1icon->getContentSize().height + player1icon->getContentSize().height / 2);

	auto player2icon = Sprite::create("Chara/2P/player2_icon.png");
	player2icon->setScale(2, 2);
	parentLayer->addChild(player2icon);
	player2icon->setPosition(Director::getInstance()->getVisibleSize().width -
		(player2icon->getContentSize().width + player2icon->getContentSize().width / 2),
		player2icon->getContentSize().height + player2icon->getContentSize().height / 2);

	//1P点数
	if (userDef->getIntegerForKey("blue") - 9 >= 1) {
		int mNum = 0;
		mNum = userDef->getIntegerForKey("blue");
		mNum = mNum / 10;
		mNum = mNum % 10;
		auto rect = CCRectMake(mNum * 80, 0, 80, 128);
		auto player1num = Sprite::create("Scene/Result/num1P.png", rect);
		player1num->setPosition(player1icon->getPositionX() - 36,
			Director::getInstance()->getVisibleSize().height - player1icon->getContentSize().height * 2);
		parentLayer->addChild(player1num);
		
		mNum = userDef->getIntegerForKey("blue");
		mNum = mNum % 10;
		auto rect2 = CCRectMake(mNum * 80, 0, 80, 128);
		auto player1num2 = Sprite::create("Scene/Result/num1P.png", rect2);
		player1num2->setPosition(player1icon->getPositionX() + 36,
			Director::getInstance()->getVisibleSize().height - player1icon->getContentSize().height * 2);
		parentLayer->addChild(player1num2);
	}
	else {
		int mNum = 0;
		mNum = userDef->getIntegerForKey("blue") * 80;
		auto rect = CCRectMake(mNum, 0, 80, 128);
		auto player1num = Sprite::create("Scene/Result/num1P.png", rect);
		player1num->setPosition(player1icon->getPositionX(),
			Director::getInstance()->getVisibleSize().height - player1icon->getContentSize().height * 2);
		parentLayer->addChild(player1num);
	}

	//2P点数
	if (userDef->getIntegerForKey("red") - 9 >= 1) {
		int mNum = 0;
		mNum = userDef->getIntegerForKey("red");
		mNum = mNum / 10;
		mNum = mNum % 10;
		auto rect = CCRectMake(mNum * 80, 0, 80, 128);
		auto player2num = Sprite::create("Scene/Result/num2P.png", rect);
		player2num->setPosition(player2icon->getPositionX() - 36,
			Director::getInstance()->getVisibleSize().height - player2icon->getContentSize().height * 2);
		parentLayer->addChild(player2num);

		mNum = userDef->getIntegerForKey("red");
		mNum = mNum % 10;
		auto rect2 = CCRectMake(mNum * 80, 0, 80, 128);
		auto player2num2 = Sprite::create("Scene/Result/num2P.png", rect2);
		player2num2->setPosition(player2icon->getPositionX() + 36,
			Director::getInstance()->getVisibleSize().height - player2icon->getContentSize().height * 2);
		parentLayer->addChild(player2num2);
	}
	else {
		int mNum = 0;
		mNum = userDef->getIntegerForKey("blue") * 80;
		auto rect = CCRectMake(mNum, 0, 80, 128);
		auto player1num = Sprite::create("Scene/Result/num1P.png", rect);
		player1num->setPosition(player1icon->getPositionX(),
			Director::getInstance()->getVisibleSize().height - player1icon->getContentSize().height * 2);
		parentLayer->addChild(player1num);
	}

	auto player1point = Sprite::create("Scene/Result/blue_bar.png");
	player1point->setAnchorPoint(Vec2(0.5f, 0));
	auto scl = ScaleTo::create(2, 1, userDef->getIntegerForKey("blue"));
	player1point->runAction(scl);
	parentLayer->addChild(player1point);
	player1point->setPosition(player1icon->getPositionX(),
		player1icon->getPositionY() + player1icon->getContentSize().height + 48);

	auto player2point = Sprite::create("Scene/Result/red_bar.png");
	player2point->setAnchorPoint(Vec2(0.5f, 0));
	auto scl2 = ScaleTo::create(2, 1, userDef->getIntegerForKey("red"));
	player2point->runAction(scl2);
	parentLayer->addChild(player2point);
	player2point->setPosition(player2icon->getPositionX(),
		player2icon->getPositionY() + player2icon->getContentSize().height + 48);

	auto player1name = Sprite::create("Scene/Result/1P_turn.png");
	parentLayer->addChild(player1name);
	player1name->setPosition(player1icon->getPositionX(), player1icon->getPositionY() + player1name->getContentSize().height + 12);

	auto player2name = Sprite::create("Scene/Result/2P_turn.png");
	parentLayer->addChild(player2name);
	player2name->setPosition(player2icon->getPositionX(), player2icon->getPositionY() + player2name->getContentSize().height + 12);

	mCount = 0;



	if (userDef->getIntegerForKey("blue") > userDef->getIntegerForKey("red")) {
		auto win = Sprite::create("Scene/Result/win.png");
		parentLayer->addChild(win);
		win->setPosition(player1icon->getPositionX(), player1icon->getPositionY() - 100);
		auto lose = Sprite::create("Scene/Result/lose.png");
		parentLayer->addChild(lose);
		lose->setPosition(player2icon->getPositionX(), player2icon->getPositionY() - 100);
	}
	else {
		auto win = Sprite::create("Scene/Result/win.png");
		parentLayer->addChild(win);
		win->setPosition(player2icon->getPositionX(), player2icon->getPositionY() - 100);
		auto lose = Sprite::create("Scene/Result/lose.png");
		parentLayer->addChild(lose);
		lose->setPosition(player1icon->getPositionX(), player1icon->getPositionY() - 100);
	}

	return true;
}

void ResultState::update(float at){

	if (mSceneState < SCENEEND){
		(this->*updateFunc[mSceneState])(at);
	}
}

void ResultState::fadeIn(float at){

	mSceneState = MAIN;
}

void ResultState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void ResultState::fadeOut(float at){
	mSceneState = SCENEEND;

	ModalLayer::EventListener* listener = ModalLayer::EventListener::create();
	listener->onButtonYes = CC_CALLBACK_0(ResultState::onPushYesButton, this);
	listener->onButtonNo = CC_CALLBACK_0(ResultState::onPushNoButton, this);

	auto modalLayer = ModalLayer::create(listener, "mouitid.png", "un.png", "iya.png");
	auto isScene = cocos2d::Director::getInstance()->getRunningScene();

	isScene->addChild(modalLayer);
}

void ResultState::mainStart(float at){
	
	mUpdateState = UPDATELOOP;
}

void ResultState::mainLoop(float at){

	
}

void ResultState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool ResultState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	mUpdateState = UPDATEEND;
	return true;
}

void ResultState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){


}

void ResultState::onPushYesButton(){

	auto uiLayer = UILayer::create();

	//シーン切り替え
	auto func = []()
	{
		auto uiLayer = UILayer::create();
		return SceneCreator::createScene(GameMainScene::create(uiLayer), uiLayer);
	};

	auto scene = FadeScene::create(1.5f, func);

	Director::getInstance()->replaceScene(scene);

}

void ResultState::onPushNoButton(){

	//シーン切り替え
	auto func = []()
	{
		auto uiLayer = UILayer::create();
		return SceneCreator::createScene(GameMainScene::create(uiLayer), uiLayer);
	};

	auto scene = FadeScene::create(1.5f, func);

	Director::getInstance()->replaceScene(scene);

}