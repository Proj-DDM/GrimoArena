#include "SkillReader.h"
#include "PlistReader.h"
#include <iostream>

namespace{

	struct vec2
	{
		int count;
		int value;

		vec2(int x, int y){
			count = 0;
			value = 0;
		}
		vec2(){

		}
	};

	int pushData(int number, vec2 values, Skill::Status* data){
		if (0 < values.count){

			for (int k = 0; k < values.count; ++k){
				data->skillField[number + k] = values.value;
			}

			return values.count + number;
		}
		return number;
	}


	void thawing(cocos2d::ValueMap map, Skill::Status* data){

		std::string checkValue = "xyz";

		std::string vectStr = map.at("vect").asString();

		int number = 0;
		int count = 0;
		int value = 0;
		int strCount = 0;
		vec2 values(0, 0);

		for (int i = 0; i < vectStr.length(); ++i){

			for (int k = 0; k < 3; ++k){
				if (vectStr[i] == checkValue[k]){
					std::string countStr = vectStr.substr(i - strCount, strCount);

					values.count = std::atoi(countStr.c_str());
					values.value = k;

					strCount = 0;
					continue;
				}
			}
			number = pushData(number, values, data);
			if (values.count == 0){
				strCount++;
			}
			values.count = 0;
		}
	}
}


Skill::Status SkillReader::read(const std::string& charaName)
{
	PlistReader reader;
	Skill::Status data;

	auto valueMap = reader.read("plist/skilllist.plist");

	for (auto& map : valueMap)
	{
		if (!std::strstr(charaName.c_str(), map.at("TextureName").asString().c_str())) continue;

		data.damage = map.at("damage").asInt();
		data.attack = map.at("attack").asInt();
		data.speed = map.at("speed").asInt();
		data.moveY = map.at("moveY").asInt();
		data.hp = map.at("hp").asInt();
		
		thawing(map, &data);
		
		return data;
	}

	return data;

}