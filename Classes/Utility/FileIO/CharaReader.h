#ifndef CHARAREDER_H
#define CHARAREDER_H

#include <vector>
#include "CharaData.h"

struct CharaData;

class CharaReader
{
public:
	CharaReader() = default;
	~CharaReader() = default;

	typedef std::vector< CharaData > ReadData;

	static ReadData read(const std::string& fileName);
};

#endif