#include "ParameterView.h"
#include "../Character/CharacterIDConverter.h"
#include "Game/Character/PlayerJudged.h"

using namespace cocos2d;

ParameterView::ParameterView()
{
}

ParameterView::~ParameterView()
{
}

bool ParameterView::init()
{
	
	if (!Node::init()) return false;
	auto backSprite = Sprite::create();
	backSprite->setTextureRect(Rect(0, 0, 1024, 300));
	backSprite->setColor(Color3B::WHITE);
	setName("View");
	sprite = Sprite::create(); 
	sprite->setPosition(Director::getInstance()->getWinSize().width / 2 + 200, Director::getInstance()->getWinSize().height - sprite->getContentSize().height );
	

	backSprite->setPosition(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height - backSprite->getContentSize().height / 2);
	addChild(backSprite);
	addChild(sprite);
	labelInit();
	return true;
}

void ParameterView::setParameter(Parameter& parameter)
{
	if (parameter == param)return;
	//auto label = dynamic_cast<LabelTTF*>(getChildByName("HP"));
	//auto func = [&]() {label->setString("–¼‘O: " + StringUtils::toString(param)); };
	//this->param = parameter;
	//func();
	this->param = parameter;
	auto labelHP = dynamic_cast<LabelTTF*>(getChildByName("HP"));
	auto func = [&]() {labelHP->setString("HP: " + StringUtils::toString(param.hp.getHp())); };
	
	func();

	auto labelSpeed = dynamic_cast<LabelTTF*>(getChildByName("Speed"));
	auto funcSpeed = [&]() {labelSpeed->setString("Speed: " + StringUtils::toString(param.speed)); };
	funcSpeed();

	auto labelAttack = dynamic_cast<LabelTTF*>(getChildByName("Attack"));
	auto funcName = [&]() {labelAttack->setString("Attack: " + StringUtils::toString(param.attackPoint)); };
	funcName();
	
	sprite->setTexture(JudgedPlayer(param.name) + ".png");
	setVisible(true);

	
}

ParameterView* ParameterView::create()
{
	auto layer = new ParameterView();

	if (layer && layer->init()){
		layer->retain();
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return nullptr;
}

void ParameterView::labelInit()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = LabelTTF::create("Name: ", "Arial", 32);
	label->setName("name");

	label->setPosition(Vec2((origin.x + visibleSize.width / 2) - 200,
		origin.y + visibleSize.height - label->getContentSize().height- 70));
	//addChild(label);

	auto labelHP = LabelTTF::create("HP: ", "Arial", 32);
	labelHP->setName("HP");
	labelHP->setColor(Color3B::BLACK);

	labelHP->setPosition(Vec2((origin.x + visibleSize.width / 2) - 205,
		origin.y + visibleSize.height - label->getContentSize().height-110));
	addChild(labelHP);

	auto labelSpeed = LabelTTF::create("Speed: ", "Arial", 32);
	labelSpeed->setName("Speed");
	labelSpeed->setColor(Color3B::BLACK);

	labelSpeed->setPosition(Vec2((origin.x + visibleSize.width / 2) - 190,
		origin.y + visibleSize.height - label->getContentSize().height - 150));
	addChild(labelSpeed);

	auto labelAttack = LabelTTF::create("Attack: ", "Arial", 32);
	labelAttack->setName("Attack");
	labelAttack->setColor(Color3B::BLACK);


	labelAttack->setPosition(Vec2((origin.x + visibleSize.width / 2) - 190,
		origin.y + visibleSize.height - label->getContentSize().height - 190));
	addChild(labelAttack);

	auto labelSkill = LabelTTF::create("Skill: ", "Arial", 32);
	labelSkill->setName("Skill");
	labelSkill->setColor(Color3B::WHITE);

	labelSkill->setPosition(Vec2((origin.x + visibleSize.width / 2) - 200,
		origin.y + visibleSize.height - label->getContentSize().height - 240));
	addChild(labelSkill);
}