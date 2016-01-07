#ifndef MANA_H
#define MANA_H

//---------------------
// 　　Mana.h
// 作成者　小林 大峰
//
// 使い魔召喚のための魔力を管理するクラス
//

#include "cocos2d.h"

USING_NS_CC;

class Mana : public Node
{

public:
	//インスタンスメソッド
	CREATE_FUNC_PARAM1(Mana,int);

	using ManaSpriteContainer = std::vector<Sprite*>;

	//クラス変数
private:

	int mana;

	ManaSpriteContainer manaSpriteContainer;
	//クラスメソッド
public:

	Mana();
	~Mana();

	bool init(int);

	void setMana(int value);

	void setFadeAnimation(int manaCount);

};

#endif