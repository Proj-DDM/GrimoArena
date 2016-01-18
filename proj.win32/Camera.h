#ifndef CUSTOMCAMERA_H
#define CUSTOMCAMERA_H

#include  "cocos2d.h"

USING_NS_CC;

#include "Utility/Template/Singleton.h"
//#include "Utility/Action/Follow/CustomFollow.h"

class CustomCamera : public Singleton<CustomCamera>
{
public:

	~CustomCamera();

	void createCamera();

	void setTargetLayer(Layer* layer);

	void setFollowTarget(Node* node);

	void startLayer();

	void stopLayer();

	void removeTarget();

	void removeTargetLayer();

	void stopFollwTarget();

	void againFollowTaget();

	void setEye(const Vec3& eye);

	void moveEye(const Vec3& eye);

	void setPosition(const Vec3& position);

private:
	Node* target{ nullptr };
	Layer* layer;
	//CustomAction::CustomFollow* follow{ nullptr };
	ActionCamera* camera{ nullptr };

	CustomCamera();

	friend class Singleton< CustomCamera >;
};

#endif //end_of Camera.h