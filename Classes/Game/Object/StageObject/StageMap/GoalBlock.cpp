#include "GoalBlock.h"
#include "../ObjectType.h"

using namespace cocos2d;

GoalBlock::GoalBlock()
	: mBlockData( BlockData() )
{
	
}

GoalBlock::~GoalBlock()
{
}

GoalBlock* GoalBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new GoalBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool GoalBlock::init( const std::string& nodeName, const BlockData& data )
{
	if ( !Sprite::initWithFile( data.pointTextureName + ".png" ) )
	{
		return false;
	}
	
	mBlockData = data;
	
	this->setName( nodeName );
	
	return true;
}
