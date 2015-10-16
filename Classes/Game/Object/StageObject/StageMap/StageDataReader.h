#ifndef _STAGE_DATA_READER_H_
#define _STAGE_DATA_READER_H_

#include "cocos2d.h"

struct PanelData;

class StageDataReader : public cocos2d::Node {
	
protected:
	
	StageDataReader() = default;
	
	~StageDataReader() = default;
	
public:
	
	typedef std::vector< PanelData > ReadData;
	
public:
	
	static StageDataReader* create();
	
	ReadData read( const std::string& fileName );
};

#endif