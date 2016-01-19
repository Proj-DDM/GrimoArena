#include "Camera.h"

NS_BEGIN(gremo)

namespace
{
	#define CAMERAS	Director::getInstance()->getRunningScene()->getCameras()
	#define POSITIONZ -300
}

void Camera::setLookAt(const Vec2& eye)
{
	auto setPoint = Vec3(eye.x, eye.y, POSITIONZ);

	this->camera->setPosition3D(setPoint);

	this->lookAt = setPoint;
}

void Camera::moveLookAt(const Vec2& eye)
{
	auto movePoint = Vec3(this->lookAt.x + eye.x, this->lookAt.y + eye.y, POSITIONZ);

	this->camera->setPosition3D(movePoint);

	this->lookAt = movePoint;
}

void Camera::movePosition(const Vec2& position)
{
	auto cameraPos = this->getCameraPosition();
	this->camera->setPosition3D(Vec3(cameraPos.x + position.x, cameraPos.y + position.y, POSITIONZ));

	this->moveLookAt(position);
}

void Camera::setPosition(const Vec2& position)
{
	this->camera->setPosition3D(Vec3(position.x, position.y, POSITIONZ));

	this->setLookAt(position);
}

const Vec2& Camera::getCameraPosition()
{
	auto position = this->camera->getPosition3D();

	return Vec2(position.x, position.y);
};

const Vec2& Camera::convertTouchPosition(Touch* touch)
{
	return this->camera->convertTouchToNodeSpace(touch);
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