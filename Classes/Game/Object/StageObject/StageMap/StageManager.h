﻿#ifndef _STAGE_MANAGER_H_
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
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"

USING_NS_CC;

class StagePanel;


class StageManager : public cocos2d::Node {
	
protected:	
	StageManager() = default;
	
	~StageManager();
	
public:
	
	static StageManager* create(Layer* layer);
	
	virtual bool init(Layer* layer);

	void update(float at) override;

	void touchStage();

	int onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

	void reset();

	void checkOnPanel();

	void deadChangePanel(int user, int pos, std::array<int, 25> array);

	StagePanel* getPanel(int number);

	int touchPos(cocos2d::Point pos);

	Player* getTurnPlayer();

	const cocos2d::Color3B& getTurnPlayerColor();

	void setUI(GAMESEQUENCE sequence);

	std::vector < Character* > getCaras();
	bool summon(const CharacterID& id, const Vec2& position, int panelNumber);

private:
	using CharacterContainer = std::vector < Character* >;

	Layer* uiLayer;
	PanelContainer m_Container;
	CharacterFactory factory;
	CharacterManager* manager;
	PlayerManager* playerManager;
	Parameter mParam;
	CharacterID mId;
	int mTestTrun;
	CharacterContainer charaContainer;
	std::array<int, 25> mTestArray;
	std::array<cocos2d::Color3B, 2> playerColorArray { { cocos2d::Color3B::BLUE, cocos2d::Color3B::RED } };


public:
	int				   mCount;
	int				   touchIdx;
	bool mIsChengeColor;

};

#endif