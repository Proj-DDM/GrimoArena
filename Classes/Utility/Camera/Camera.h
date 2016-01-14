#ifndef CUSTOMCAMERA_H
#define CUSTOMCAMERA_H

#include  "cocos2d.h"

USING_NS_CC;

#include "Utility/Template/Singleton.h"
#include "Utility/Action/Follow/CustomFollow.h"

class CustomCamera : public Singleton<CustomCamera>
{
public:

	~CustomCamera() = default;

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

	const Vec2& getLayerPos() { return this->layer->getPosition(); };

private:
	Node* target{ nullptr };
	Layer* layer{ nullptr };
	CustomAction::CustomFollow* follow{ nullptr };
	ActionCamera* camera{ nullptr };
	Vec3 followTargetEye{ Vec3::ZERO };
	Vec2 followTargetPos{ Vec2::ZERO };

	CustomCamera() = default;

	friend class Singleton< CustomCamera >;
};

#endif //end_of Camera.h