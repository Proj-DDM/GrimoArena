#include "StageMapFactory.h"
#include "StageMapDataReader.h"

#include <string>

using namespace cocos2d;

void StageMapFactory::createStageMap( Node* parentNode, const std::string& fileName ) {
	auto reader = StageMapDateReader::create();
	auto readData = reader->read(fileName);

	int count = 0;
}