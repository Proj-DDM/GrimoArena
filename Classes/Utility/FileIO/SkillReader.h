#ifndef SKILLREADER_H
#define SKILLREADER_H

#include "Game/Character/Skill.h"

#include <vector>

class SkillReader
{
public:
	SkillReader() = default;
	~SkillReader() = default;

	typedef std::vector< Skill::Status > ReadData;

	static Skill::Status read(const std::string& charaName);
};

#endif