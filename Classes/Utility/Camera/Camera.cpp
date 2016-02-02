#include "Camera.h"
#include "Utility/Math/MyMath.h"

NS_BEGIN(gremo)

namespace
{
	#define CAMERAS	Director::getInstance()->getRunningScene()->getCameras()
	#define POSITIONZ -300
}

void Camera::setLookAt(const Vec2& eye)
{
	auto setPoint = Vec3(eye.x, eye.y, POSITIONZ);

	this->camera->lookAt(setPoint);

	this->lookAt = setPoint;
}

void Camera::moveLookAt(const Vec2& eye)
{
	auto movePoint = Vec3(this->lookAt.x + eye.x, this->lookAt.y + eye.y, POSITIONZ);

	this->camera->lookAt(movePoint);

	this->lookAt = movePoint;
}

void Camera::movePosition(const Vec2& position)
{
	auto cameraPos = this->getCameraPosition();
	
	auto clampPos = Vec2(MyMath::clamp(cameraPos.x + position.x, -220.f, 800.f), clampf(cameraPos.y + position.y, -200, 800));
	if (clampPos.x <= -220.f  || clampPos.x == 800.f) return;
	this->camera->setPosition3D(Vec3(cameraPos.x + position.x, clampPos.y, POSITIONZ));
	
	this->moveLookAt(position);
}

void Camera::setPosition(const Vec2& position)
{
	auto centor = position - Director::getInstance()->getVisibleSize() / 2;

	this->camera->setPosition3D(Vec3(centor.x, centor.y, POSITIONZ));

	this->setLookAt(centor);
}

const Vec2 Camera::getCameraPosition()
{
	Vec3 position = this->camera->getPosition3D();

	return Vec2(position.x, position.y);
};

const Vec2 Camera::convertTouchPosition(Touch* touch)
{
	Vec2 visibleBottomLeft = this->getCameraPosition();

	return visibleBottomLeft + touch->getLocation();
}

void Camera::setUseCamera(const CameraFlag& flag)
{
	auto scene = Director::getInstance()->getRunningScene();
	auto test = scene->getCameras();

	for (cocos2d::Camera* camera : CAMERAS)
	{
		if (camera->getCameraFlag() == flag)
		{
			this->camera = camera;
		}
	}
}

NS_END