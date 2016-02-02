#include "UILayer.h"
#include "../../Utility/cocosAssistant/ListenerAssistant.h"
#include "../Character/PlayerDeck.h"
#include "../Character/CharacterPanel.h"
#include "../UI/ParameterView.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"

using namespace cocos2d;

namespace
{
	
}

UILayer::UILayer()
{

}

UILayer::~UILayer()
{
	CC_SAFE_RELEASE(this->listner);
}

bool UILayer::init()
{

	auto onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(UILayer::onTouchEnded, this);
	auto onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);

	ListenerAssistant::setupSingleTouchListener(this, false, onTouchBegan, onTouchMoved, onTouchEnd, nullptr);
	playerDeck = PlayerDeck::create();
	this->addChild(playerDeck);
	this->schedule(schedule_selector(UILayer::update));
	this->scheduleUpdate();
	view = ParameterView::create();
	addChild(view);
	view->setVisible(false);
	setTag(1);

	auto size = cocos2d::Director::getInstance()->getVisibleSize();
	
	auto uiTopSprite = Sprite::create("Scene/Main/main_topui.png");
	uiTopSprite->setPosition(Vec2(size.width / 2, size.height - uiTopSprite->getContentSize().height / 2));
	this->addChild(uiTopSprite);

	this->roundTexture = Sprite::create("Scene/Main/round_1.png");
	this->roundTexture->setPosition(Vec2(size.width / 2, size.height - this->roundTexture->getContentSize().height / 2));
	this->roundTexture->setOpacity(0);
	this->roundTexture->runAction(FadeIn::create(0.5f));
	this->addChild(this->roundTexture);
	
	this->phaseTexture = Sprite::create("Scene/Main/1P_turn.png");
	this->phaseTexture->setPosition(Vec2(this->phaseTexture->getContentSize().width / 2 - 50, size.height - this->phaseTexture->getContentSize().height / 2 - 20));
	this->addChild(this->phaseTexture);

	return true;
}

void UILayer::update(float deltaTime)
{
	playerDeck->update(deltaTime);
}

bool UILayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	//auto touch = getParent()->getChildByName("");
	if (!playerDeck->onTouchBegan(touch, event))
	{
		view->setVisible(false);
		return false;
	}
	
	return true;
}

void UILayer::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	playerDeck->onTouchMoved(touch,event);
}

void UILayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	playerDeck->onTouchEnded(touch, event);
}

UILayer* UILayer::create()
{
	auto layer = new UILayer();

	if (layer && layer->init()){
		layer->retain();
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool UILayer::isSummon() const
{
	return this->playerDeck->getIsSummons();
}

void UILayer::createMenuButton(EventListene* listener)
{
	buttons.clear();

	this->listner = listener;

	auto size = cocos2d::Director::getInstance()->getVisibleSize();

	auto menuButton = cocos2d::MenuItemImage::create("Scene/Main/button_menu.png", "Scene/Main/button_menu.png", CC_CALLBACK_0(UILayer::onMenuButton, this));
	menuButton->setPosition(cocos2d::Vec2(size.width - menuButton->getContentSize().width / 2 + 50, size.height - menuButton->getContentSize().height / 2));

	auto endButton = cocos2d::MenuItemImage::create("Scene/Main/menu_turnend.png", "Scene/Main/menu_turnend_t.png", CC_CALLBACK_0(UILayer::onEndButton, this));
	endButton->setPosition(cocos2d::Vec2(size.width + endButton->getContentSize().width, menuButton->getPositionY() - endButton->getContentSize().height));

	auto viewButton = cocos2d::MenuItemImage::create("Scene/Main/camera01.png", "Scene/Main/camera02.png", CC_CALLBACK_0(UILayer::onViewButton, this));
	viewButton->setPosition(cocos2d::Vec2(size.width + viewButton->getContentSize().width, endButton->getPositionY() - viewButton->getContentSize().height));
	auto viewMenu = cocos2d::Menu::create(viewButton, menuButton, endButton, nullptr);
	viewMenu->setPosition(cocos2d::Point::ZERO);
	this->addChild(viewMenu);

	this->buttons[BUTTONTYPE::MENU] = menuButton;
	this->buttons[BUTTONTYPE::TURNEND] = endButton;
	this->buttons[BUTTONTYPE::VIEW] = viewButton;

	CC_SAFE_RETAIN(this->listner);
}

//���j���[�����
void UILayer::closeMenu()
{
	if(!this->isMenuEnable) return;

	this->isMenuEnable = false;

	auto move = [](Node* target, float animationTime, const Vec2& position)
	{
		target->stopAllActions();
		target->runAction(MoveTo::create(animationTime, position));
	};

	auto viewSize = Director::getInstance()->getVisibleSize();
	float textureSizeWidth = buttons.at(TURNEND)->getContentSize().width / 2;

	buttons.at(MENU)->runAction(FadeIn::create(0.05f));

	move(buttons.at(VIEW),   0.1f, Vec2(viewSize.width + textureSizeWidth, buttons.at(VIEW)->getPositionY()));
	move(buttons.at(TURNEND),0.2f, Vec2(viewSize.width + textureSizeWidth, buttons.at(TURNEND)->getPositionY()));

}

//���j���[�{�^��
void UILayer::onMenuButton()
{
	auto move = [](Node* target,float animationTime,  const Vec2& position)
	{
		target->stopAllActions();
		target->runAction(MoveTo::create(animationTime, position));
	};

	auto viewSize = Director::getInstance()->getVisibleSize();
	float textureSizeWidth = buttons.at(TURNEND)->getContentSize().width / 2;

	if (!this->isMenuEnable)
	{
		move(buttons.at(TURNEND), 0.1f, Vec2(viewSize.width - textureSizeWidth, buttons.at(TURNEND)->getPositionY()));
		move(buttons.at(VIEW)   , 0.2f, Vec2(viewSize.width - textureSizeWidth , buttons.at(VIEW)->getPositionY()));

		buttons.at(MENU)->runAction(FadeOut::create(0.05f));

		this->isMenuEnable = true;

		return;
	}

	this->closeMenu();
}

void UILayer::onEndButton()
{
	this->listner->onEndButton();
	this->closeMenu();
}

void UILayer::onGiveUpButton()
{
	this->listner->onGiveUpButton();
	this->closeMenu();
}

void UILayer::onBackButton()
{
	this->listner->onBackButton();
	this->closeMenu();
}

void UILayer::onViewButton()
{
	this->listner->onViewButton();
	this->closeMenu();
}

//���E���h�X�v���C�g�؂�ւ�
void UILayer::setRoundSprite()
{
	if (6 < SequenceManager::GetInstance()->getRoundCount()) return;

	if (!this->roundTexture) this->roundTexture = Sprite::create("Scene/Main/round_" + StringUtils::toString(SequenceManager::GetInstance()->getRoundCount()) + ".png");

	this->roundTexture->setOpacity(0);
	this->roundTexture->runAction(FadeIn::create(0.5f));

	this->roundTexture->setTexture("Scene/Main/round_" + StringUtils::toString(SequenceManager::GetInstance()->getRoundCount()) + ".png");
}

//�t�F�C�Y�X�v���C�g�؂�ւ�
void UILayer::setPhaseSprite(PHASETYPE phase)
{

	switch (phase)
	{
	case UILayer::PHASETYPE::P1:
		this->phaseTexture->setTexture("Scene/Main/1P_turn.png");
		break;
	case UILayer::PHASETYPE::P2:
		this->phaseTexture->setTexture("Scene/Main/2P_turn.png");
		break;
	case UILayer::PHASETYPE::AI:
		this->phaseTexture->setTexture("Scene/Main/AI_turn.png");

		break;
	default:
		break;
	}

	this->phaseTexture->setOpacity(0);
	this->phaseTexture->runAction(FadeIn::create(0.5f));

}

