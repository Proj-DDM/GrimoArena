#include "FadeScene.h"

USING_NS_CC;

const unsigned int kSceneFade = 0xFADEFADE;

FadeScene::FadeScene() : m_InScene(nullptr)
{

}


FadeScene::~FadeScene()
{
	CC_SAFE_DELETE(m_InScene);

}


Scene* FadeScene::create(float t, SceneCreateFunc func){

	FadeScene * pScene = new FadeScene();
	if (pScene && pScene->init(t, func))
	{
		pScene->autorelease();
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return nullptr;

}

bool FadeScene::init(float t, SceneCreateFunc func){

	if (Scene::init())
	{
		m_Timer = t;

		// retain
		m_OutScene = cocos2d::Director::getInstance()->getRunningScene();
		if (m_OutScene == nullptr)
		{
			m_OutScene = Scene::create();
		}
		m_OutScene->retain();

		m_CreateFunc = func;

		/*auto onTouchBegan = cocos2d::CC_CALLBACK_2(FadeScene::onTouchBegan, this);
		
		ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);
*/
		return true;
	}
	else
	{
		return false;
	}

}

void FadeScene::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
	Scene::draw(renderer, transform, flags);

	if (m_OutScene) {
		m_OutScene->visit(renderer, transform, flags);
	}

//	if (m_InScene){
//		m_InScene->visit(renderer, transform, flags);
//	}
}

void FadeScene::onEnter(){
	
	Scene::onEnter();

	m_OutScene->onExitTransitionDidStart();

	_eventDispatcher->setEnabled(false);

	LayerColor* l = LayerColor::create(Color4B(0,0,0,0));

	addChild(l, 2, kSceneFade);
	Node* f = getChildByTag(kSceneFade);

	ActionInterval* a = (ActionInterval *)Sequence::create
		(
		FadeIn::create(m_Timer / 2),
//		CallFunc::create(CC_CALLBACK_0(FadeScene::hideOutShowIn, this)),
//		FadeOut::create(m_Timer / 2),
		CallFunc::create(CC_CALLBACK_0(FadeScene::finish, this)),

		nullptr
		);

	f->runAction(a);
}

void FadeScene::hideOutShowIn(){
	m_OutScene->onExit();
	m_OutScene->cleanup();

	CC_SAFE_DELETE(m_OutScene);
	m_InScene =  m_CreateFunc();
	m_InScene->retain();

}
void FadeScene::finish(){
	


	m_OutScene->onExit();
	m_OutScene->cleanup();

	CC_SAFE_DELETE(m_OutScene);

	this->schedule(CC_SCHEDULE_SELECTOR(FadeScene::setNewScene), 0);
	
}


void FadeScene::setNewScene(float dt){

	CC_UNUSED_PARAM(dt);

	this->unschedule(CC_SCHEDULE_SELECTOR(FadeScene::setNewScene));

	Director::getInstance()->replaceScene(m_CreateFunc());
}

void FadeScene::onExit(){
	Scene::onExit();

	// enable events while transitions
	_eventDispatcher->setEnabled(true);
	
	// _inScene should not receive the onEnter callback
	// only the onEnterTransitionDidFinish
	//m_InScene->onEnterTransitionDidFinish();

	this->removeChildByTag(kSceneFade, false);

}

void FadeScene::cleanup(){
	Scene::cleanup();
}


ReplaceScene::ReplaceScene() 
{

}


ReplaceScene::~ReplaceScene()
{
	
}


Scene* ReplaceScene::create(SceneCreateFunc func){

	ReplaceScene * pScene = new ReplaceScene();
	if (pScene && pScene->init(func))
	{
		pScene->autorelease();
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return nullptr;

}

bool ReplaceScene::init(SceneCreateFunc func){

	if (Scene::init())
	{
		// retain
		m_OutScene = cocos2d::Director::getInstance()->getRunningScene();
		if (m_OutScene == nullptr)
		{
			m_OutScene = Scene::create();
		}
		m_OutScene->retain();

		m_CreateFunc = func;

		return true;
	}
	else
	{
		return false;
	}

}

void ReplaceScene::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
	Scene::draw(renderer, transform, flags);
}

void ReplaceScene::onEnter(){

	Scene::onEnter();

	m_OutScene->onExitTransitionDidStart();

	_eventDispatcher->setEnabled(false);
	
	finish();
}

void ReplaceScene::finish(){

	m_OutScene->onExit();
	m_OutScene->cleanup();

	CC_SAFE_DELETE(m_OutScene);

	this->schedule(CC_SCHEDULE_SELECTOR(ReplaceScene::setNewScene), 0);
}


void ReplaceScene::setNewScene(float dt){

	CC_UNUSED_PARAM(dt);

	this->unschedule(CC_SCHEDULE_SELECTOR(ReplaceScene::setNewScene));

	Director::getInstance()->replaceScene(m_CreateFunc());
}

void ReplaceScene::onExit(){
	Scene::onExit();

	_eventDispatcher->setEnabled(true);
}

void ReplaceScene::cleanup(){
	Scene::cleanup();
}

