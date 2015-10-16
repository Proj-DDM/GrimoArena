#ifndef _STAGE_PANEL_H_
#define _STAGE_PANEL_H_

#include "cocos2d.h"
#include "PanelData.h"

enum class ObjectType : int;

namespace {
}

class StagePanel : public cocos2d::Sprite {
	
protected:
	
	StagePanel();
	
	~StagePanel();
	
public:
	
	static StagePanel* create(const std::string& nodeName);
	
	bool init( const std::string& nodeName );

	void createPanel();
	void touch(cocos2d::Point);
	void chengeColor();
public:
	bool mIsChengeColor;
};

#endif