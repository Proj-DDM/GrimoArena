#ifndef _HIGEPANEL_H_
#define _HIGEPANEL_H_

#include "../Character/CharacterPanel.h"

class HigePanel : public CharacterPanel
{
public:
	HigePanel();
	~HigePanel();
	static HigePanel* create();
	virtual bool init()override;

private:

};

#endif