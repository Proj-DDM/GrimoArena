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
	static Player* create(const cocos2d::Vec2& position, int number);

	void setPosition(const cocos2d::Vec2& position);

	const cocos2d::Vec2& getPosition() const override;

	cocos2d::Rect getBoundingBox() const override;

	void mathMana(const int value);

	const int getMana() { return this->mana; }

	cocos2d::Sprite* setIcon(std::string textureName);

private:

	int mana { 0 };

	cocos2d::Sprite* icon;
	
};

#endif