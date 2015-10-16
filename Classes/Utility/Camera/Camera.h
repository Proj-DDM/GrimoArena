#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "cocos2d.h"

class Camera {
public:
	Camera();
	~Camera();
public:
	void changeCameraAngle(cocos2d::Touch touch, cocos2d::Event* event);
public:
	cocos2d::ActionCamera* cameara;
};

#endif