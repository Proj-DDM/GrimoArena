#ifndef _CLONE_FACTORY_H_
#define _CLONE_FACTORY_H_

#include <map>

/**
 *	@class	：	CloneFactory
 *	@brief	：	汎用クローン工場クラス
 *				KEY			: 要素に紐付けるキー
 *				PRODUCT		: コンテナに格納する要素
 *				RELEASE		: 解放に使用するクラス
 *	@author	：	利川聖太
 */
template< typename KEY, typename PRODUCT, typename RELEASE >
class CloneFactory
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	CloneFactory() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~CloneFactory();
	
	/**
	 *	@brief	要素の追加
	 *	@param	key		要素に紐付けるキー
	 *	@param	product	コンテナに格納する要素
	 */
	void addProduct( KEY key, PRODUCT* product );
	
	/**
	 *	@brief	要素の生成
	 *	@param	key		取り出す要素のキー
	 *	@return	PRODUCT	要素のインスタンス
	 */
	PRODUCT* createProduct( KEY key );
	
private:
	
	// 型定義
	typedef std::map< KEY, PRODUCT* >	ProductContainer;
	
	// メンバ変数の宣言
	ProductContainer	mProductContainer;
};

// 実装ヘッダ
#include "CloneFactoryImpl.h"

#endif