#include "BlockDataReader.h"
#include "BlockData.h"
#include "Utility/FileIO/PlistReader.h"

BlockDataReader* BlockDataReader::create()
{
	auto inst = new BlockDataReader();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

BlockDataReader::ReadData BlockDataReader::read( const std::string& fileName )
{
	PlistReader	reader;
	ReadData	readData;
	
	auto valueMap = reader.read( fileName );
	
	for ( auto& map : valueMap )
	{
		BlockData data;
		data.pointTextureName	= map.at( "pointTextureName" ).asString();
		data.panelState			= map.at( "panelState" ).asInt();
		data.panelType			= map.at( "panelType" ).asInt();
		readData.push_back( data );
	}
	
	return readData;
}