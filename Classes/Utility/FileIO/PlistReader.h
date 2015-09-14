#ifndef _PLIST_READER_H_
#define _PLIST_READER_H_

#include "cocos2d.h"

/**
 *	@class	：	PlistReader
 *	@brief	：	プロパティリストファイル読み込みクラス
 *	@author	：	利川聖太
 */
class PlistReader
{
	
public:
	
	// 型定義
	typedef std::vector< cocos2d::ValueMap >	ReadDataVector;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PlistReader() = default;

	/**
	 *	@brief	デストラクタ
	 */
	~PlistReader() = default;
	
	/**
	 *	@brief	プロパティリストファイルの読み込み
	 *			配列要素内に連想配列要素があるフォーマットに対応しています。
	 *	@param	filePath		ファイルのパス
	 *	@return	ReadDataVector	読み込んだデータを格納したベクタ
	 */
	ReadDataVector read( const std::string& filePath ) const;
};

#endif