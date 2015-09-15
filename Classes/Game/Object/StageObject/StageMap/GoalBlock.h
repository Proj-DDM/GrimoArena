#ifndef _GOAL_BLOCK_H_
#define _GOAL_BLOCK_H_

#include "cocos2d.h"
#include "BlockData.h"

enum class ObjectType : int;

class GoalBlock : public cocos2d::Sprite
{
	
protected:
	
	GoalBlock();
	
	~GoalBlock();
	
public:
	
	static GoalBlock* create( const std::string& nodeName, const BlockData& data );
	
	bool init( const std::string& nodeName, const BlockData& data );
	
private:
	
	BlockData	mBlockData;
};

#endif