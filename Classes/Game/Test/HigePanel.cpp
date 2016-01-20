#include "HigePanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
using namespace cocos2d;

HigePanel::HigePanel()
{
}

HigePanel::~HigePanel()
{
}

bool HigePanel::init()
{
	//charaID = CharacterID::Kamata;
	mSprite = Sprite::create("chara_03.png");
	//mSprite->setScale(0.025f);
	addChild(mSprite);
	return true;
}

HigePanel* HigePanel::create()
{
	auto instance = new HigePanel();

	if (instance && instance->init()){
		instance->retain();
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}