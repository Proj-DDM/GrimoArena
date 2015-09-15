#include "StageMapManager.h"
#include "StageMapDataReader.h"
#include "StageMapFactory.h"

using namespace cocos2d;

StageMapManager* StageMapManager::create() {
	auto inst = new StageMapManager();

	if (inst && inst->init()) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

bool StageMapManager::init() {
	if (!Node::init()) {
		return false;
	}

	mStageMapNode = Node::create();
	this->addChild(mStageMapNode);

	std::string stagemap = "Plist/Stage/Stagemap.plist";

	auto fac = std::make_shared< StageMapFactory >();
	fac->createStageMap(mStageMapNode, stagemap);
	return true;
}