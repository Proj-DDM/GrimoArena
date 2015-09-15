#ifndef _BLOCK_MANAGER_H_
#define _BLOCK_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>

class BlockManager : public cocos2d::Node
{
	
protected:
	
	BlockManager() = default;
	
	~BlockManager() = default;
	
public:
	
	static BlockManager* create();
	
	virtual bool init() override;

	void onTouchBegan(cocos2d::Point pos);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);
    
    cocos2d::Vec2 getGoalPos();
    
	cocos2d::Vec2 getBlockPos(int value) const;

	void reset();

private:
	cocos2d::Node*	mBlockNode;
};

#endif