#include "StageMapDataReader.h"
#include "StageMapData.h"
#include "Utility/FileIO/PlistReader.h"

StageMapDateReader* StageMapDateReader::create() {
	auto inst = new StageMapDateReader();

	if (inst && inst->init()) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

StageMapDateReader::StageMapReadData StageMapDateReader::read(const std::string& fileName) {
	PlistReader reader;
	StageMapReadData readData;

	auto valueMap = reader.read(fileName);

	for (auto& map : valueMap) {
		StageMapData data;
		data.splitX = map.at("splitX").asInt();
		data.splitY = map.at("splitY").asInt();
		readData.push_back(data);
	}

	return readData;
}