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

USING_NS_CC;

class StagePanel;

class StageManager : public cocos2d::Node {
	
#define ICONTAG			1111
#define NUMBERTAG		1113
#define PHASETAG		1114
#define ICONBACK		1115
#define PLAYER_HP_FRAME 1116
#define PLAYER_HP_BACK  1117
#define HP_FRAME_BACK   1118

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

	void changeColor(cocos2d::Node* node);

	void focusPanel(cocos2d::Node* node);

	StagePanel* getPanel(int number);

	int touchPos(cocos2d::Point pos);

	Player* getTurnPlayer();

	const cocos2d::Color3B& getTurnPlayerColor();

	void setUI();

	bool summon(const CharacterID& id, const Vec2& position);

private:
	PanelContainer m_Container;
	CharacterFactory factory;
	CharacterManager* manager;
	PlayerManager* playerManager;
	Parameter mParam;
	CharacterID mId;
	int mTestTrun;
	std::array<int, 25> mTestArray;
	std::array<cocos2d::Color3B, 2> playerColorArray { { cocos2d::Color3B::BLUE, cocos2d::Color3B::RED } };

public:
	int				   mCount;
	int				   touchIdx;
	bool mIsChengeColor;

};

#endif