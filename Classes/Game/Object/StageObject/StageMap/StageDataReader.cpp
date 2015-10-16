#include "StageDataReader.h"
#include "PanelData.h"
#include "Utility/FileIO/PlistReader.h"

StageDataReader* StageDataReader::create() {
	auto inst = new StageDataReader();
	
	if ( inst && inst->init() ) {
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

StageDataReader::ReadData StageDataReader::read(const std::string& fileName) {
	PlistReader	reader;
	ReadData	readData;
	
	auto valueMap = reader.read( fileName );
	
	for ( auto& map : valueMap ) {
		PanelData data;
		data.panelState			= map.at( "panelState" ).asInt();
		data.panelType			= map.at( "panelType" ).asInt();
		readData.push_back( data );
	}
	
	return readData;
}