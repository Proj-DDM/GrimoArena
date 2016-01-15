#ifndef _CHARACTERREMOVE_H_
#define _CHARACTERREMOVE_H_

#include "Character.h"

class CharacterRemove
{
public:
	bool operator () (Character* chara)
	{
		if (chara->getParameter().hp.isDead())
		{
			if (chara->getReferenceCount() != 0)
			{
				CC_SAFE_RELEASE(chara);
				return true;
			}
		}
		return false;
	}

private:

};

#endif