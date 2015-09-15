#ifndef _STAGE_MAP_MANAGER_H_
#define _StAGE_MAP_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>

class StageMap;

class StageMapManager : public cocos2d::Node {
protected:
	StageMapManager() = default;
	~StageMapManager() = default;
public:
	static StageMapManager* create();
	virtual bool init() override;
private:
	cocos2d::Node* mStageMapNode;
	typedef std::vector<StageMap*> StageMapList;

	StageMapList mStageMapList;
};

#endif