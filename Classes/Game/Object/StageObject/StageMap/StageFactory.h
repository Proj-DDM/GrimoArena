#ifndef _STAGE_FACTORY_H_
#define _STAGE_FACTORY_H_

#include "cocos2d.h"

struct PanelData;

class StageFactory {
	
public:

	StageFactory();
	~StageFactory();
public:
public:
	void createPanel( cocos2d::Node* parentNode);

	static StageFactory* create();
};

#endif