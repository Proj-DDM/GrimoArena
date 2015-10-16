#include "StageFactory.h"
#include "StagePanel.h"

using namespace cocos2d;

StageFactory::StageFactory(){}

StageFactory::~StageFactory(){}

void StageFactory::createPanel(Node* parentNode) {

	Vec2 createPosCount(0,0);
	//縦横枚数　そのうち外部から
	Vec2 createSize(10, 10);
	Vec2 createPos(0,0);
	int panelSize = 32;
	int createCount = createSize.x * createSize.y;
	int changeCount = 0;
	int count = 0;

	for (int i = 0; i < createCount; ++i) {
		auto panel = StagePanel::create("StagePanel" + std::to_string(i));
		parentNode->addChild(panel);
		//ビルボード
		/*auto camera = new cocos2d::ActionCamera();

		camera->autorelease();
		camera->setTarget(block);
		auto eye = camera->getEye();
		eye.y = 0.00000003;
		camera->setEye(eye);*/

		if (changeCount == createSize.x) {
			++createPosCount.y;
			changeCount = 0;
		}
		createPosCount.x = i % (int)createSize.x;
		++changeCount;
		++count;

		createPos.x = createPosCount.x * panelSize;
		createPos.y = createPosCount.y * panelSize;
		panel->setPosition(Vec2(
			createPos.x + panelSize, createPos.y + panelSize));

		CCLOG("%i", i);
	}
}
