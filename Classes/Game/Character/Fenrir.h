#ifndef _FENRIR_H_
#define _FENRIR_H_

#include "Character.h"

class Fenrir : public Character
{
public:
	Fenrir(const Parameter& param);
	Fenrir();
	~Fenrir();
	bool init(const cocos2d::Vec2& position)override;
	static Fenrir* create(const Parameter& param, const cocos2d::Vec2& position);
	//static Hige* create(const cocos2d::Vec2& position);
private:

};


#endif