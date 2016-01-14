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
}

void CustomCamera::startLayer()
{
	this->camera->startWithTarget(this->layer);
}

void CustomCamera::stopLayer()
{
	this->camera->stop();
}

void CustomCamera::setFollowTarget(Node* node)
{
	/*this->follow = CustomAction::CustomFollow::create(node);

	this->layer->runAction(this->follow);

	this->target = node;*/
}

void CustomCamera::removeTarget()
{
	/*this->follow->stop();
	this->target = nullptr;*/

}

void CustomCamera::removeTargetLayer()
{
	this->camera->stop();
	this->layer = nullptr;
}

void CustomCamera::stopFollwTarget()
{
	/*this->follow->stop();
	this->follow = nullptr;*/
}

void CustomCamera::againFollowTaget()
{
	/*this->follow = CustomAction::CustomFollow::create(this->target);

	this->layer->runAction(this->follow);*/
}

void CustomCamera::setEye(const Vec3& eye)
{
	this->camera->setEye(eye);
}

void CustomCamera::moveEye(const Vec3& eye){

	this->camera->setEye(this->camera->getEye() + eye);

	this->camera->setCenter(this->camera->getEye());
}