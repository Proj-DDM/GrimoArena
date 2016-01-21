
#ifndef PLAYER_UI_H
#define PLAYER_UI_H

#include "cocos2d.h"
#include "Utility/Common.h"

class PlayerUI : public Node
{
public:
	PlayerUI();
	~PlayerUI();

	CREATE_FUNC(PlayerUI);

	void setHPBar(int hp);
	bool init();

private:
	Sprite* icon{ nullptr };
	Sprite* hp{ nullptr };
	Sprite* hpFrame{ nullptr };


};

#endif