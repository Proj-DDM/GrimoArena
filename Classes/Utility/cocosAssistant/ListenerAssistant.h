#ifndef _LISTENER_ASSISTANT_H_
#define _LISTENER_ASSISTANT_H_

#include "cocos2d.h"

/**
 *	@class	：	ListenerAssistant
 *	@brief	：	リスナの登録を補助するクラス
 *				引数の関数ラッパについて...
 *				ラムダ式				=> 直接渡すことができます。
 *				メンバ関数( マクロ )	=> バインドする必要があります。 例 : CC_CALLBACK_X( Hoge::XXX, this );
 *				メンバ関数( 直打ち )	=> バインドする必要があります。 例 : std::bind( &Hoge::XXX, this, _1, _2, ... );
 *	@author	：	利川聖太
 */
class ListenerAssistant
{
	
private:
	
	// 型定義
	typedef std::vector< cocos2d::Touch* >												TouchVector;
	typedef std::function< bool( cocos2d::Touch*, cocos2d::Event* ) >					SingleTouchBeganFunc;
	typedef std::function< void( cocos2d::Touch*, cocos2d::Event* ) >					SingleTouchFunc;
	typedef std::function< void( const TouchVector&, cocos2d::Event* ) >				MultiTouchFunc;
	typedef std::function< void( cocos2d::EventKeyboard::KeyCode, cocos2d::Event* ) >	KeyboardFunc;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ListenerAssistant() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ListenerAssistant() = default;
	
public:
	
	/**
	 *	@brief	シングルタッチリスナの登録
	 *	@param	target				リスナを登録するターゲット
	 *	@param	isSwallowTouches	優先度が高いイベントのみ実行するのか否か
	 *	@param	began				タッチ開始時に呼び出される関数ラッパ
	 *	@param	moved				タッチ移動時に呼び出される関数ラッパ
	 *	@param	ended				タッチ終了時に呼び出される関数ラッパ
	 *	@param	cancelled			タッチキャンセル時( システムエラーやバックグラウンド移動時など )に呼び出される関数ラッパ
	 */
	static void setupSingleTouchListener( cocos2d::Node*		target,
										  bool					isSwallowTouches,
										  SingleTouchBeganFunc	began,
										  SingleTouchFunc		moved		= nullptr,
										  SingleTouchFunc		ended		= nullptr,
										  SingleTouchFunc		cancelled	= nullptr );

	/**
	 *	@brief	マルチタッチリスナの登録
	 *	@param	target		リスナを登録するターゲット
	 *	@param	began		タッチ開始時に呼び出される関数ラッパ
	 *	@param	moved		タッチ移動時に呼び出される関数ラッパ
	 *	@param	ended		タッチ終了時に呼び出される関数ラッパ
	 *	@param	cancelled	タッチキャンセル時( システムエラーやバックグラウンド移動時など )に呼び出される関数ラッパ
	 */
	static void setupMultiTouchListener( cocos2d::Node*	target,
										 MultiTouchFunc	began,
										 MultiTouchFunc	moved		= nullptr,
										 MultiTouchFunc	ended		= nullptr,
										 MultiTouchFunc	cancelled	= nullptr );
	
	/**
	 *	@brief	キーボードリスナの登録
	 *	@param	target		リスナを登録するターゲット
	 *	@param	pressed		キーボードが押された時に呼ばれる関数ラッパ
	 *	@param	released	キーボードが離された時に呼ばれる関数ラッパ
	 */
	static void setupKeyboardListener( cocos2d::Node* target, KeyboardFunc pressed, KeyboardFunc released );
};

#endif