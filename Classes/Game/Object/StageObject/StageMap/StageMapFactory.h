#ifndef _STAGE_MAP_FACTORY_
#define _STAGE_MAP_FACTORY_

#include "cocos2d.h"

class StageMapFactory {
public:
	void createStageMap(cocos2d::Node* parrentNode, const std::string& fileName );
};

#endif