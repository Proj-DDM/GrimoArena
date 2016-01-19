#ifndef CUSTOMCAMERA_H
#define CUSTOMCAMERA_H

#include  "cocos2d.h"

USING_NS_CC;

#include "Utility/Template/Singleton.h"
#include "Utility/Action/Follow/CustomFollow.h"
#include "Utility/Common.h"

NS_BEGIN(gremo)

class Camera : public Singleton<Camera>
{
public:

	~Camera() = default;

	void setLookAt(const Vec2& eye);

	void moveLookAt(const Vec2& eye);

	void movePosition(const Vec2& position);
	
	void setPosition(const Vec2& position);

	const Vec2& getCameraPosition();

	const Vec2& convertTouchPosition(Touch* touch);

	void setUseCamera(const CameraFlag& flag);

private:
	Camera() = default;
	Vec3 lookAt{ Vec3::ZERO };
	cocos2d::Camera* camera{ nullptr };
	friend class Singleton< Camera >;
};

NS_END

#endif //end_of Camera.h