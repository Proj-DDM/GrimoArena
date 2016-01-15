#ifndef _STAGE_MANAGER_H_
#define _STAGE_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>
#include <array>
#include "StageFactory.h"
#include "../../../Character/CharacterFactory.h"
#include "../../../Character/CharacterManager.h"
#include "../../../Character/Player.h"
#include "../../../Character/PlayerManager.h"

class StagePanel;

class StageManager : public cocos2d::Node {
	
#define ICONTAG   1111
#define MANATAG   1112
#define NUMBERTAG 1113
#define PHASETAG  1114

protected:	
	StageManager() = default;
	
	~StageManager();
	
public:
	
	static StageManager* create();
	
	virtual bool init() override;

	void update(float at) override;

	void touchStage();

	int onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

	void reset();

	void checkOnPanel();

	void deadChangePanel(int user, int pos);

	StagePanel* getPanel(int number);

	int touchPos(cocos2d::Point pos);

	Player* getTurnPlayer();

	const cocos2d::Color3B& getTurnPlayerColor();

	void setUI();
	std::vector < Character* > getCaras();

private:
	PanelContainer m_Container;
	CharacterFactory factory;
	CharacterManager* manager;
	PlayerManager* playerManager;
	Parameter mParam;
	CharacterID mId;
	int mTestTrun;
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer charaContainer;
	std::array<int, 25> mTestArray;
	std::array<cocos2d::Color3B, 2> playerColorArray { { cocos2d::Color3B::BLUE, cocos2d::Color3B::RED } };

public:
	int				   mCount;
	int				   touchIdx;
	bool mIsChengeColor;

};

#endif