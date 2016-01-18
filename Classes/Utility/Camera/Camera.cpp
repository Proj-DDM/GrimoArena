#include "Camera.h"

void CustomCamera::createCamera()
{
	if (this->camera) return;

	this->camera = new ActionCamera();
}

void CustomCamera::setTargetLayer(Layer* layer)
{
	if (this->layer) this->removeTargetLayer();

	this->layer = layer;

	this->startLayer();
}

void CustomCamera::startLayer()
{
	this->followTargetEye = Vec3::ZERO;

	this->camera->startWithTarget(this->layer);

}

void CustomCamera::stopLayer()
{
	this->camera->stop();
	delete this->camera;
	this->camera = new ActionCamera();
	this->layer->stopAllActions();
}

void CustomCamera::setFollowTarget(Node* node)
{
	this->layer->stopAllActions();

	this->follow = CustomAction::CustomFollow::create(node);

	this->layer->runAction(this->follow);

	this->target = node;
	
	this->moveEye(-this->followTargetEye);

}

void CustomCamera::removeTarget()
{
	this->layer->stopAction(this->follow);
	this->target = nullptr;

}

void CustomCamera::removeTargetLayer()
{
	this->camera->stop();
	this->layer->stopAllActions();
	this->layer = nullptr;

}

void CustomCamera::stopFollwTarget()
{
	this->layer->stopAction(this->follow);
	this->follow = nullptr;
}

void CustomCamera::againFollowTaget()
{
	this->camera->setEye(this->followTargetEye);

	this->follow = CustomAction::CustomFollow::create(this->target);

	this->layer->runAction(this->follow);

}

void CustomCamera::setEye(const Vec3& eye)
{
	this->camera->setEye(eye);

	this->camera->setCenter(Vec3(this->camera->getEye().x, this->camera->getEye().y, 0));
}

void CustomCamera::moveEye(const Vec3& eye){

	this->followTargetEye += eye;

	this->camera->setEye(Vec3(this->camera->getEye().x + eye.x, this->camera->getEye().y + eye.y, 10));

	this->camera->setCenter(Vec3(this->camera->getEye().x, this->camera->getEye().y,0));
}