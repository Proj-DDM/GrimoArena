#include "PlistReader.h"

using namespace cocos2d;

PlistReader::ReadDataVector PlistReader::read( const std::string& filePath ) const
{
	auto fileUtils	= FileUtils::getInstance();
	auto plistName	= fileUtils->fullPathForFilename( filePath );
	
	ReadDataVector readDataVector;
	
	// プロパティリストファイルの構造として、
	// 配列要素の中に連想配列要素があるので、まずは配列要素を取得します。
	ValueVector array = fileUtils->getValueVectorFromFile( plistName.c_str() );
	
	for ( auto map : array )
	{
		// 配列要素の中の連想配列要素を取得します。
		auto dictionaryData = map.asValueMap();
		
		readDataVector.push_back( dictionaryData );
	}
	
	return readDataVector;
}