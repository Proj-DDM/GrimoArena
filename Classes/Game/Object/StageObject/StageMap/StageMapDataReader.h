#ifndef _STAGE_MAP_DATA_READER_H_
#define _STAGE_MAP_DATA_READER_H_

#include "cocos2d.h"

struct StageMapData;

class StageMapDateReader : public cocos2d::Node {
protected:
	StageMapDateReader() = default;
	~StageMapDateReader() = default;

public:
	typedef std::vector< StageMapData > StageMapReadData;
public:
	static StageMapDateReader* create();
	StageMapReadData read(const std::string& fileName);
};

#endif