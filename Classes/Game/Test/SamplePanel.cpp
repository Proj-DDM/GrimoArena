#include "SamplePanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
using namespace cocos2d;

KamataPanel::KamataPanel()
{
}

KamataPanel::~KamataPanel()
{
}

bool KamataPanel::init()
{
	charaID = CharacterID::WaterAttribute;
	mSprite = Sprite::create("chara_02.png");
	//mSprite->setScale(0.025f);
	auto onTouchBegan = CC_CALLBACK_2(KamataPanel::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(KamataPanel::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, nullptr, onTouchEnd, nullptr);
	addChild(mSprite);
	return true;
}

KamataPanel* KamataPanel::create()
{
	auto instance = new KamataPanel();

	if (instance && instance->init()){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}