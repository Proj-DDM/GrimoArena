#ifndef _CHARACTERIDCONVERTER_H_
#define _CHARACTERIDCONVERTER_H_

#include <unordered_map>
#include <string>
#include "CharacterType.h"
#include "Utility/EnumHash.h"

class CharacterIDConverter
{
public:
	CharacterIDConverter();
	~CharacterIDConverter();
	void initialize();

	void add(const CharacterID& id, const std::string& name);

	std::string& getCharacterName(const CharacterID& id)
	{
		return container[id];
	}

private:
	using IDContainer = std::unordered_map <CharacterID, std::string, EnumHash>;
	IDContainer container;
};



#endif