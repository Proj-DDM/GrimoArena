#ifndef _STAGE_PANEL_H_
#define _STAGE_PANEL_H_

#include "cocos2d.h"
#include "PanelData.h"


#define PANELSIZE 120


enum class ObjectType : int;

namespace {
}

class StagePanel : public cocos2d::Sprite {

	enum SEARCHTYPE
	{
		NORMAL,
		TARGET,
		CHECKEND,

	};

protected:
	
	StagePanel();
	
public:
	~StagePanel();
	
	static StagePanel* create(const std::string& nodeName);
	
	bool init( const std::string& nodeName );

	void createPanel();
	void touch(cocos2d::Point);
	void chengeColor();

	void setTouchPos();

	const cocos2d::Color3B getColor();

public:
	bool mIsChengeColor;
	Sprite* sprite;

};

#endif