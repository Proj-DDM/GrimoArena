#ifndef IPANEL_H
#define IPANEL_H

#include "cocos2d.h"

typedef enum {
	
} PANEL;

class IPanel {
public:
	virtual ~IPanel() = default;
	virtual void createPanel() = 0;
protected:
	IPanel();
};

#endif