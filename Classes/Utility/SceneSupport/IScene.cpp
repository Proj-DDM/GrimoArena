#include "IScene.h"

USING_NS_CC;

IScene::IScene() :mSceneState(FADEIN)
{
	updateFunc[0] = &IScene::fadeIn;
	updateFunc[1] = &IScene::sceneMain;
	updateFunc[2] = &IScene::fadeOut;

	mainFunc[0] = &IScene::mainStart;
	mainFunc[1] = &IScene::mainLoop;
	mainFunc[2] = &IScene::mainEnd;

}
