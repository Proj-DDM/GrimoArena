#include "Mana.h"

#define MANATAG			1112

Mana::Mana()
{
}


Mana::~Mana()
{
}

bool Mana::init(int mana)
{
	if (!Node::init()) return false;
	int createCount { 6 };

	if (createCount < mana) createCount = mana;

	for (int i = 0; i < createCount; ++i){
		//マナ画像
		auto manaBack = Sprite::create("UI/Player/orb_null.png");
		manaBack->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 4 + manaBack->getContentSize().width * i, manaBack->getContentSize().height * 4.6));
		manaBack->setTag(MANATAG);
		this->addChild(manaBack);
	
		//マナ画像
		auto manaImage = Sprite::create("UI/Player/orb_empty.png");
		manaImage->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 4 + manaImage->getContentSize().width * i, manaImage->getContentSize().height * 4.6));
		manaImage->setTag(MANATAG);
		manaImage->setOpacity(0);
		this->addChild(manaImage);

		manaSpriteContainer.push_back(manaImage);
	}

	this->setMana(createCount);

	return true;
}

void Mana::setMana(int value)
{
	this->mana = value; 

	this->setFadeAnimation(this->mana);

}

void Mana::setFadeAnimation(int manaCount)
{

	int createCount{ 6 };

	if (createCount < manaCount) createCount = manaCount;

	if (this->manaSpriteContainer.size() < createCount)
	{ 
		for (int i = this->manaSpriteContainer.size() - 1; i < createCount; ++i){
			
			//マナ画像
			auto manaBack = Sprite::create("UI/Player/orb_null.png");
			manaBack->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 4 + manaBack->getContentSize().width * i, manaBack->getContentSize().height * 4.6));
			this->addChild(manaBack);

			//マナ画像
			auto manaImage = Sprite::create("UI/Player/orb_empty.png");
			manaImage->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 4 + manaImage->getContentSize().width * i, manaImage->getContentSize().height * 4.6));
			this->addChild(manaImage);
			manaImage->setOpacity(0);
			manaSpriteContainer.push_back(manaImage);
		}
	}

	for (int i = 0; i < createCount; ++i)
	{
		if (this->manaSpriteContainer.size() <= i) break;
	
		ActionInterval* action { nullptr };

		if (i < manaCount)
		{
			action = FadeIn::create(2);
		}
		else
		{
			action = FadeOut::create(2);
		}
		this->manaSpriteContainer.at(i)->runAction(action);
	}

}