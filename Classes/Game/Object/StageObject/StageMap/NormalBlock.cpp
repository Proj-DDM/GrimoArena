#include "NormalBlock.h"
#include "../ObjectType.h"

using namespace cocos2d;

NormalBlock::NormalBlock()
	: mBlockData( BlockData() )
{

}

NormalBlock::~NormalBlock()
{
	//this->disableCollision( this->getName() );
}

NormalBlock* NormalBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new NormalBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool NormalBlock::init( const std::string& nodeName, const BlockData& data )
{
	if ( !Sprite::initWithFile( data.pointTextureName + ".png" ) )
	{
		return false;
	}
	
	mBlockData = data;
	
	this->setName( nodeName );
	
	return true;
}