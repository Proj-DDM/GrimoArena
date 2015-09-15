#include "BlockManager.h"
#include "BlockDataReader.h"
#include "BlockFactory.h"

using namespace cocos2d;

BlockManager* BlockManager::create()
{
	auto inst = new BlockManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool BlockManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}

	mBlockNode = Node::create();
	mBlockNode->setName("BlockNode");
	this->addChild( mBlockNode );
    
    auto userDef = UserDefault::getInstance();
    
    int  selectStage  = userDef -> getIntegerForKey("selectStage");
    std::string stage = "Plist/Stage1.plist";

	auto fac = std::make_shared< BlockFactory >();
	fac->createBlock( mBlockNode, stage);

	return true;
}

void BlockManager::onTouchBegan(cocos2d::Point pos) {}

void BlockManager::onTouchMove(cocos2d::Point pos) {}

void BlockManager::onTouchEnd(cocos2d::Point pos) {}

Vec2 BlockManager::getGoalPos(){
    return mBlockNode->getChildren().back()->getPosition();
}

Vec2 BlockManager::getBlockPos(int value) const {
	if (value >= mBlockNode->getChildrenCount()) {
		return mBlockNode->getChildren().back()->getPosition();
	}

	return mBlockNode->getChildren().at(value)->getPosition();
}

void BlockManager::reset(){
	removeChildByName("BlockNode");

	mBlockNode = Node::create();
	mBlockNode->setName("BlockNode");
	this->addChild(mBlockNode);

	auto userDef = UserDefault::getInstance();
	int  selectStage = userDef->getIntegerForKey("selectStage");
	std::string stage = "Plist/Stage" + std::to_string(selectStage) + ".plist";

	auto fac = std::make_shared< BlockFactory >();
	fac->createBlock(mBlockNode, stage);
}