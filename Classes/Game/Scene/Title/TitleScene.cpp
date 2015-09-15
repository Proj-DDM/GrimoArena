#include "TitleScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
	mState->release();
    ply->release();
}

TitleScene* TitleScene::create(){
	auto obj = new TitleScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool TitleScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = TitleState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(TitleScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);
    
    auto node = Node::create();
    auto func = cocos2d::CallFunc::create([&]() {
		ply = ADX2Player::create("Sound/ADX2/WorkUnit_BackMusic/CueSheet_0.acb");
        ply->play(0);
        ply->retain();
    });
    auto delay = cocos2d::DelayTime::create(1.8f);
    auto seq = cocos2d::Sequence::create(delay, func, nullptr);
    node->runAction(seq);
    this->addChild(node);
    

	this->scheduleUpdate();

	return true;
}

void TitleScene::update(float at){
	mState->update(at);
}


bool TitleScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}


void TitleScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}