#ifndef _UILAYER_H_
#define _UILAYER_H_

#include "cocos2d.h"

class PlayerDeck;
class ParameterView;
USING_NS_CC;

class UILayer:public cocos2d::Layer
{
	enum BUTTONTYPE
	{
		MENU,
		TURNEND,
		VIEW,
		BACK,
		GIVEUP
	};

public:

public:
	class EventListene :public cocos2d::Ref{

	public:
		CREATE_FUNC(EventListene);
		EventListene(){};
		bool init(){ return true; }

		std::function<void()> onEndButton{ nullptr };
		std::function<void()> onGiveUpButton{ nullptr };
		std::function<void()> onBackButton{ nullptr };
		std::function<void()> onViewButton{ nullptr };
	};

	enum class PHASETYPE
	{
		P1,
		P2,
		AI,

		SIZE
	};

public:
	
	static UILayer* create();

	virtual bool init()override;

	bool isSummon() const;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void update(float deltaTime)override;

	void createMenuButton(EventListene* listener);

	//メニューを閉じる
	void closeMenu();

	//メニューボタン
	void onMenuButton();

	//終了ボタン
	void onEndButton();

	//降参ボタン
	void onGiveUpButton();

	//一つ前に戻るボタン
	void onBackButton();

	//カメラ切り替えボタン
	void onViewButton();

	//ラウンドスプライト切り替え
	void setRoundSprite();
	
	//フェイズスプライト切り替え
	void setPhaseSprite(PHASETYPE phase);

	void setDeck(int i);

protected:
	UILayer();
	~UILayer();

private:
	PlayerDeck* playerDeck;
	ParameterView* view;

	bool isMenuEnable{ false };
	std::map<BUTTONTYPE,cocos2d::MenuItemImage*> buttons;
	Sprite* phaseTexture;
	Sprite* roundTexture;

	EventListene* listner;	 //イベントリスナー

};


#endif
