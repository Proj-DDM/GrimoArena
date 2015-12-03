#ifndef _PARAMETERVIEW_H_
#define _PARAMETERVIEW_H_

#include "cocos2d.h"
#include "ParameterPtr.h"


class ParameterView : public cocos2d::Node
{
public:
	ParameterView();
	~ParameterView();
	bool init()override;
	void setParameter(ParameterPtr ptr);

private:
	ParameterPtr param;
};



#endif