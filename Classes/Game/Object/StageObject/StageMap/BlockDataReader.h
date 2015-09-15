#ifndef _BLOCK_DATA_READER_H_
#define _BLOCK_DATA_READER_H_

#include "cocos2d.h"

struct BlockData;

class BlockDataReader : public cocos2d::Node
{
	
protected:
	
	BlockDataReader() = default;
	
	~BlockDataReader() = default;
	
public:
	
	typedef std::vector< BlockData > ReadData;
	
public:
	
	static BlockDataReader* create();
	
	ReadData read( const std::string& fileName );
};

#endif