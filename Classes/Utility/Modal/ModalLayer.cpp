#include "ModalLayer.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

USING_NS_CC;

ModalLayer* ModalLayer::create(EventListener* listener){

	auto obj = new ModalLayer();

	if (obj && obj->init(listener)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool ModalLayer::init(EventListener* listener)
{
	if (!Layer::init()){
		return false;
	}

	auto onTouchBegan = CC_CALLBACK_2(ModalLayer::onTouchBegan, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, nullptr, nullptr);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto window = cocos2d::Sprite::create("Window.png");

	window->setPosition(cocos2d::Director::getInstance()->getWinSize() / 2);

	this->addChild(window);

	this->addButton(window, "Ok.png", "Ok.png", CC_CALLBACK_1(ModalLayer::onYesButton, this), YES);

	this->addButton(window, "No.png", "No.png", CC_CALLBACK_1(ModalLayer::onNoButton,this),NO);

	this->listner = listener;
	
	CC_SAFE_RETAIN(this->listner);

	return true;
}

bool ModalLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	
	return true;
}

void ModalLayer::onYesButton(Ref* ref){
	onSelectButton(this->listner->onButtonYes);
}

void ModalLayer::onNoButton(Ref* ref){
	onSelectButton(this->listner->onButtonNo);
}

void ModalLayer::onSelectButton(std::function<void()> func)
{
	auto sequence = cocos2d::Sequence::create(cocos2d::CallFunc::create([this,func]()
	{
		if (this->listner && func) func();
	}),
	cocos2d::CallFunc::create([this]()
	{
		this->removeFromParentAndCleanup(true);

		Director* director = Director::getInstance();

		this->getEventDispatcher()->removeEventListenersForTarget(this);

		CC_SAFE_RETAIN(this->listner);

	}), nullptr);

	this->runAction(sequence);
}

void ModalLayer::addButton(cocos2d::Node* window, const std::string& normalImage, const std::string& selectImage, const cocos2d::ccMenuCallback& callback, ModalLayer::BUTTONTYPE type){

	MenuItemImage* item = MenuItemImage::create(normalImage, selectImage,callback);

	Menu* menu = Menu::create(item, NULL);

	auto point = buttonAddPoint(item->getContentSize(),window->getContentSize(), type);

	menu->setPosition(point);
	
	window->addChild(menu);
}

const Point& ModalLayer::buttonAddPoint(const Size& contentSize,const Size& windowSize, ModalLayer::BUTTONTYPE type){

	switch (type)
	{
	case ModalLayer::YES:
		return Point(contentSize.width / 1.5f, contentSize.height / 2);
	case ModalLayer::NO:
		return Point(contentSize.width * 2, contentSize.height / 2);
	case ModalLayer::CLOSE:
		return Point(windowSize.width - contentSize.width, windowSize.height - contentSize.height);
	case ModalLayer::SIZE:
		break;
	default:
		break;
	}	
	return nullptr;
}