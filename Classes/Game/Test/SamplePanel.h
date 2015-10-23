#ifndef _SAMPLEPANEL_H_
#define _SAMPLEPANEL_H_

#include "../Character/CharacterPanel.h"

class KamataPanel : public CharacterPanel
{
public:
	KamataPanel();
	~KamataPanel();
	static KamataPanel* create();
	virtual bool init()override;

private:

};

#endif