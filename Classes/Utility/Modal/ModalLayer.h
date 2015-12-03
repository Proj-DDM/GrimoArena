#ifndef MODALLAYER_H
#define MODALLAYER_H

#include "cocos2d.h"

class ModalLayer : public cocos2d::Layer{

	enum BUTTONTYPE{ //ボタンタイプ
		YES,
		NO,
		CLOSE,
		SIZE
	};

	class EventListener;
private:
	void onYesButton(cocos2d::Ref* ref);	//Yesボタンが押されたとき 

	void onNoButton(cocos2d::Ref* ref);		//Noボタンが押されたとき

	void onSelectButton(std::function<void()> func);	//ボタンが選択されたあとのコールバック

	//ボタンの追加
	void addButton(cocos2d::Node* node, const std::string& normalImage, const std::string& selectImage, const cocos2d::ccMenuCallback& callback, BUTTONTYPE type);

	//追加するボタンのポイント
	//場所はボタンのタイプによって変更する。
	const cocos2d::Point& buttonAddPoint(const cocos2d::Size& contentSize, const cocos2d::Size& windowSize, BUTTONTYPE type);

	EventListener* listner;	 //イベントリスナー

public:

	//生成
	static ModalLayer* create(EventListener* listener);

	//初期化
	virtual bool init(EventListener* listener);

	//画面がタッチされた時
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event); 

public:
	class EventListener :public cocos2d::Ref{

	public:
		CREATE_FUNC(EventListener);
		EventListener(){};
		bool init(){ return true; }

		std::function<void()> onButtonYes { nullptr };
		std::function<void()> onButtonNo { nullptr };
	};

};


#endif