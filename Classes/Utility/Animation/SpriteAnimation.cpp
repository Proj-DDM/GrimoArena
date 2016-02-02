#include "SpriteAnimation.h"
#include <string>

using namespace Util;
USING_NS_CC;

SpriteAnimation::SpriteAnimation(const std::string& path){
	mResourcePath = path;
}


Sprite* SpriteAnimation::create(const std::string& spriteName, const int count, const float delay, const bool restart, const bool repeat){
	
	std::string textureName = spriteName;

	firstSprite = Sprite::create(mResourcePath + textureName + "1.png");
	firstSprite->setName(spriteName);

	auto animation = Animation::create();
	for (int i = 2; i <= count; ++i){
		animation->addSpriteFrameWithFile(mResourcePath + textureName + StringUtils::toString(i) + ".png");
	}
	animation->setRestoreOriginalFrame(restart);
	animation->setDelayPerUnit(delay);
	Animate* animate = Animate::create(animation);
	animate->setTag(1122);
	//繰り返すなら
	if (repeat){
		RepeatForever* repeatTrue = RepeatForever::create(animate);
		firstSprite->runAction(repeatTrue);
	} else {

		firstSprite->runAction(animate);
	}
	
	return firstSprite;
}

Animate* SpriteAnimation::createAnim(const std::string& spriteName, const int count, const float delay, const bool restart){

	std::string textureName = spriteName;

	firstSprite = Sprite::create(mResourcePath + textureName + "1.png");
	firstSprite->setName(spriteName);

	auto animation = Animation::create();
	for (int i = 2; i <= count; ++i){
		animation->addSpriteFrameWithFile(mResourcePath + StringUtils::toString(i) + ".png");
	}
	animation->setRestoreOriginalFrame(restart);
	animation->setDelayPerUnit(delay);
	Animate* animate = Animate::create(animation);
	animate->setTag(1122);
	//繰り返すなら
	return animate;
}

void SpriteAnimation::setResourcesPath(const std::string& path){
	mResourcePath = path;
}