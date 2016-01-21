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
	bool init(const cocos2d::Vec2& position, const std::string& name);

	//インスタンスの生成
	static Player* create(const cocos2d::Vec2& position, int number, const std::string& name);

	void setPosition(const cocos2d::Vec2& position);

	const cocos2d::Vec2& getPosition() const override;

	cocos2d::Rect getBoundingBox() const override;

	void mathMana(const int value);

	const int getMana() { return this->mana; }

	cocos2d::Sprite* setIcon(std::string textureName);

	const int getPanelNumber() { return this->panelNumber; };

private:

	int mana { 0 };
	int panelNumber { -1 };
	cocos2d::Sprite* icon;
	
};

#endif