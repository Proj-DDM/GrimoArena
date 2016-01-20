#ifndef _ROUGE_H_
#define _ROUGE_H_

#include "Character.h"

class Rouge : public Character
{
public:
	Rouge(const Parameter& param);
	Rouge();
	~Rouge();
	bool init(const cocos2d::Vec2& position)override;
	static Rouge* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif