#include "IPanel.h"

using namespace cocos2d;

IPanel::IPanel() {
	createPanel();
}

void IPanel::createPanel() {

	Vec2 createPos;
	Vec2 createPosCount;

	auto sprite = Sprite::create();
	sprite->setTextureRect(Rect(0, 0, 50, 50));
	sprite->setColor(Color3B::WHITE);

	createPos.x = createPosCount.x * sprite->getContentSize().width;
	createPos.y = createPosCount.y * sprite->getContentSize().height;

	auto panel = MenuItemSprite::create
		(sprite, sprite, [sprite](Ref* pSender) {
			sprite->setColor(Color3B::RED);
		}
	);

	auto pMenu = Menu::create(panel, NULL);
	pMenu->setPosition(Vec2(
		createPos.x + sprite->getContentSize().width / 2,
		createPos.y + sprite->getContentSize().height / 2));
}