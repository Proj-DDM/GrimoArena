#ifndef SKILLFIELD_H
#define	SKILLFIELD_H

#include "cocos2d.h"
#include <array>

namespace
{
	struct Status
	{
		int damage{ 0 };
		int attack{ 0 };
		int 
	};
}


class SkillField
{

//•Ï”
private:
	std::array<float, 50> skillField { };
	
public:
	SkillField(std::array<float, 50> skillField)
	{
		this->skillField = skillField;
	}

	~SkillField();

	const std::array<float, 50>& getArray() { return skillField; }

};

#endif