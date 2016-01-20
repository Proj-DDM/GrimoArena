#ifndef _EDITSTAGEMANAGER_H_
#define _EDITSTAGEMANAGER_H_

#include "cocos2d.h"

#include "../Object/StageObject/StageMap/StageFactory.h"
#include "../Character/CharacterFactory.h"
#include "../Character/CharacterManager.h"
#include "../Character/Player.h"
#include "../Character/PlayerManager.h"

class EditStageManager:public cocos2d::Node
{
public:
	EditStageManager();
	~EditStageManager();

	static EditStageManager* create();

	virtual bool init() override;

	void update(float at) override;

	void touchStage();

	int onTouchBegan(cocos2d::Point pos);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

	void reset();

	void changeColor(cocos2d::Node* node);

	void focusPanel(cocos2d::Node* node);

	StagePanel* getPanel(int number);

	int touchPos(cocos2d::Point pos);

private:
	PanelContainer m_Container;
	CharacterFactory factory;
	CharacterManager* manager;
	CharacterID mId;
	int mTestTrun;
	std::array<int, 25> mTestArray;

public:
	int				   mCount;
	int				   touchIdx;
	bool mIsChengeColor;
};

#endif
