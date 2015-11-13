#ifndef _STAGE_FACTORY_H_
#define _STAGE_FACTORY_H_

struct PanelData;
#include "PanelCore.h"


class StageFactory {

public:

	StageFactory();
	~StageFactory();

	//ƒRƒ“ƒeƒi

	void createPanel(PanelContainer* container, cocos2d::Node* node);

	static StageFactory* create();
};

#endif