#ifndef _PLAYERJUDGED_H_
#define _PLAYERJUDGED_H_

#include "../Scene/GameMain/Sequence/SequenceManager.h"

namespace{
	std::string JudgedPlayer(const std::string& name)
	{
		//TURN_PLAYER turn = SequenceManager::GetInstance()->getTurnPlayer();
		TURN_PLAYER turn = TURN_PLAYER::PLAYER1;
		std::string spriteName;
		switch (turn)
		{
		case TURN_PLAYER::PLAYER1:
			spriteName = name;
			spriteName = "Chara/1P/" + spriteName;
			return spriteName;
			break;

		case TURN_PLAYER::PLAYER2:
					
			spriteName = name;
			spriteName = "Chara/2P/" + spriteName + "_2";
			return spriteName;
			break;
		default:
			spriteName = nullptr;
			return name;
			break;
		}
		return name;
	}
}

#endif
