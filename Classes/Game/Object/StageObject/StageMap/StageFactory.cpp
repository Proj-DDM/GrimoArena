#include "StageFactory.h"
#include "StagePanel.h"

namespace {
#define MAXSTAGEX 9
#define MAXSTAGEY 11
}

using namespace cocos2d;

StageFactory::StageFactory(){}

StageFactory::~StageFactory(){}

void StageFactory::createPanel(PanelContainer* container,cocos2d::Node* node) {

	Vec2 createPosCount(0,0);
	//ècâ°ñáêîÅ@ÇªÇÃÇ§ÇøäOïîÇ©ÇÁ
	Vec2 createSize(MAXSTAGEX, MAXSTAGEY);
	Vec2 createPos(0,0);
	int panelSize = PANELSIZE;
	int createCount = createSize.x * createSize.y;
	int changeCount = 0;
	int count = 0;

	for (int i = 0; i < createCount; ++i) {
		auto panel = StagePanel::create("StagePanel" + std::to_string(i));
		panel->setContentSize(Size(panelSize, panelSize));
		panel->setCameraMask((int)CameraFlag::USER1);
		node->addChild(panel);
		container->push_back(panel);


		if (changeCount == createSize.x) {
			++createPosCount.y;
			changeCount = 0;
		}
		createPosCount.x = i % (int)createSize.x;
		++changeCount;
		++count;

		createPos.x = createPosCount.x * panelSize + 16;
		createPos.y = createPosCount.y * panelSize + 350;
		panel->setPosition(Vec2(
			createPos.x + panelSize, createPos.y + panelSize));

		CCLOG("%i", i);

	}
	Sprite* background = Sprite::create("Scene/Main/stage_base1.png");
	background->setCameraMask((int)CameraFlag::USER1);
	background->setPosition(Vec2(16 + background->getContentSize().width / 2 - 60, 350 + background->getContentSize().height / 2 - 40));

	Sprite* backBase = Sprite::create("Scene/Main/stage_base2.png");
	backBase->setCameraMask((int)CameraFlag::USER1);
	backBase->setPosition(Vec2(16 + backBase->getContentSize().width / 2 - 484, 350 + backBase->getContentSize().height / 2 - 364));

	Sprite* backBara = Sprite::create("Scene/Main/leave.png");
	backBara->setCameraMask((int)CameraFlag::USER1);
	backBara->setPosition(Vec2(16 + backBara->getContentSize().width / 2 - 686, 350 + backBara->getContentSize().height / 2 - 556));

	background->setOpacity(100);

	node->addChild(backBase);
	node->addChild(background);
	node->addChild(backBara);
	
}
