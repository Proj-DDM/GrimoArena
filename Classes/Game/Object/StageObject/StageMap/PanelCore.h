#ifndef PANEL_CORE_H_
#define PANEL_CORE_H_


#include<vector>
#include "StagePanel.h"
#include "cocos2d.h"

using PanelContainer = std::vector<StagePanel*>;

enum PLAYERINITPOS {
	P1POS = 4,
	P2POS = 94,
};

namespace PanelCore{

	static	bool isCreate(int number){
		return (number != P1POS && number != P2POS);
	}

}


#endif