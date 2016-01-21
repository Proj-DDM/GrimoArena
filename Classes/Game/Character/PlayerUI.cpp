#include "PlayerUI.h"

namespace
{
#define HP_WIDTH 510.f / 500.f 
}
PlayerUI::PlayerUI()
{
}


PlayerUI::~PlayerUI()
{
}

bool PlayerUI::init()
{
	if (!Node::init()) return false;

	//アイコン背景
	auto iconBack = Sprite::create("Scene/Main/UI_playerFrame.png");
	iconBack->setPosition(Vec2(iconBack->getContentSize().width / 2.8f, iconBack->getContentSize().height * 1.25));
	this->addChild(iconBack);

	//アイコン
	this->icon = cocos2d::Sprite::create("Scene/Main/core.png");
	this->icon->setPosition(Vec2(this->icon->getContentSize().width / 1.85, this->icon->getContentSize().height * 2.1));
	this->addChild(this->icon);

	//HPフレーム
	this->hpFrame = Sprite::create("Scene/Main/hp_frame.png");
	this->hpFrame->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, this->hpFrame->getContentSize().height * 3.6));
	this->addChild(this->hpFrame);

	//HPバー
	this->hp = Sprite::create("Scene/Main/p_player.png");
	this->hp->setPosition(Vec2(hpFrame->getPositionX() + 50 , hpFrame->getPositionY()));
	this->addChild(this->hp);

	return true;
}

void PlayerUI::setHPBar(int hp)
{
	this->hp->setTextureRect(Rect(0, 0, HP_WIDTH * hp, this->hp->getContentSize().height));
	this->hp->setPosition(Vec2(hpFrame->getPositionX() + 50 - 255 + this->hp->getContentSize().width / 2, hpFrame->getPositionY()));
}