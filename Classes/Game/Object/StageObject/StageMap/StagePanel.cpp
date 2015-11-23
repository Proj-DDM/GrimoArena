#include "StagePanel.h"
#include "../ObjectType.h"

using namespace cocos2d;

StagePanel::StagePanel() { }

StagePanel::~StagePanel() { }

StagePanel* StagePanel::create(const std::string& nodeName) {
	auto inst = new StagePanel();
	
	if ( inst && inst->init( nodeName ) ) {
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool StagePanel::init(const std::string& nodeName) {
	if ( !Sprite::init() ) {
		return false;
	}

	auto Listener = EventListenerTouchOneByOne::create();

	this->setName( nodeName );
	createPanel();
	return true;
}

void StagePanel::createPanel() {

	sprite = Sprite::create();
	sprite->setTextureRect(Rect(0, 0, 64, 64));
	sprite->setColor(Color3B::WHITE);
	sprite->setName(this->getName());
	sprite->setOpacity(50);

	this->addChild(sprite);
}

void StagePanel::touch(Point touchPos) {
	//auto sprite = (Sprite*)this->getChildByName(this->getName());
	//bool isTouch = false;
}

void StagePanel::chengeColor() {
	//auto sprite = (Sprite*)this->getChildByName(this->getName());
	sprite->setColor(Color3B::BLUE);
	CCLOG("F‚Ì•ÏX‚ªŽÀs‚³‚ê‚Ü‚µ‚½");
}

void StagePanel::setTouchPos(){
}


const Color3B& StagePanel::getColor(void) const {
	return sprite->getColor();
}