#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <memory>

/**
 *	@class	：	Singleton
 *	@brief	：	シングルトンのテンプレートクラス
 *	@author	：	利川聖太
 */
template< typename T >
class Singleton
{
	
public:
	
	/**
	 *	@brief	インスタンスの取得
	 */
	static T& getInstance()
	{
		static typename T::InstancePtr instance( new T() );
		return *instance;
	}
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Singleton() = default;
	
private:
	
	// 型定義
	typedef std::unique_ptr< T > InstancePtr;
	
private:
	
	/**
	 *	@brief	コピーコンストラクタ, ムーブコンストラクタ, 代入演算子の削除
	 */
	Singleton( const Singleton& )				= delete;
	Singleton( Singleton&& )					= delete;
	Singleton& operator = ( const Singleton& )	= delete;
	Singleton& operator = ( Singleton&& )		= delete;
};

#endif