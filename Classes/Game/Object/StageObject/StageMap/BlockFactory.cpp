#include "BlockFactory.h"
#include "BlockDataReader.h"
#include "RedBlock.h"
#include "GoalBlock.h"
#include "NormalBlock.h"

using namespace cocos2d;

BlockFactory::BlockFactory(){}

BlockFactory::~BlockFactory(){}

void BlockFactory::createBlock( Node* parentNode, const std::string& fileName )
{
	auto reader		= BlockDataReader::create();
	auto readData	= reader->read( fileName );
	
	int count = 0;
	Vec2 createPosCount;
	Vec2 createSize(11, 10);
	Vec2 createPos(Vec2(0,0));
	int createCount = createSize.x * createSize.y;
	int changeCount = 0;

	for (auto& data : readData){
		for (int i = 0; i <= createCount; ++i) {
			auto block = RedBlock::create("RedBlock" + std::to_string(count), data);
			parentNode->addChild(block);
			//ビルボード
			/*auto camera = new cocos2d::ActionCamera();

			camera->autorelease();
			camera->setTarget(block);
			auto eye = camera->getEye();
			eye.y = 0.00000003;
			camera->setEye(eye);*/

			createPos.x = createPosCount.x * 64;
			createPos.y = createPosCount.y * 64;

			block->setPosition(Vec2(
				createPos.x + 64, createPos.y + 64));

			if (changeCount == createSize.x) {
				++createPosCount.y;
				changeCount = 0;
			}
			createPosCount.x = i % (int)createSize.x;
			++changeCount;
		}
	}
}
