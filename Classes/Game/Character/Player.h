#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
/************************************************

 Player.h
 作成者:小林勇輝

*************************************************/
class Player : public Character
{
public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//初期化
	bool init(const cocos2d::Vec2& position)override;

	//インスタンスの生成
	static Player* create(const cocos2d::Vec2& position);


private:
	
};

#endif