#include "CharacterPanel.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"

using namespace cocos2d;

CharacterPanel::CharacterPanel() :isTouch(false)
{
}

CharacterPanel::~CharacterPanel()
{
}

bool CharacterPanel::init(){
	charaID = CharacterID::FireAttribute;
	mSprite = Sprite::create("chara_01.png");
	//mSprite->setScale(0.025f);
	auto onTouchBegan = CC_CALLBACK_2(CharacterPanel::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(CharacterPanel::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, nullptr, onTouchEnd, nullptr);
	addChild(mSprite);
	return true;
}

CharacterPanel* CharacterPanel::create()
{
	auto layer = new CharacterPanel();

	if (layer && layer->init()){
		layer->retain();
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool CharacterPanel::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto target = mSprite;
	Point touchPoint = touch->getLocation();	//�^�b�`���W�̎擾
	Rect rect = target->getBoundingBox();

	if (rect.containsPoint(touchPoint))
	{
		mSprite->setColor(Color3B::RED);
		isTouch = true;
		return true;
	}
	mSprite->setColor(Color3B::WHITE);
	isTouch = false;
	return false;
}

void CharacterPanel::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

CharacterID CharacterPanel::getCharacterID()const
{
	return charaID;
}