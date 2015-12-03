#ifndef _PARAMETERVIEW_H_
#define _PARAMETERVIEW_H_

#include "cocos2d.h"
#include "../Character/CharacterParameter.h"

class ParameterView : public cocos2d::Node
{
public:
	ParameterView();
	~ParameterView();
	bool init()override;
	void setParameter(Parameter ptr);
	static ParameterView* create();
private:
	void labelInit();
private:
	Parameter param;
	cocos2d::Sprite* sprite;
};



#endif