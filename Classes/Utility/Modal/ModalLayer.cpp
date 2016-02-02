#include "ModalLayer.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

USING_NS_CC;

ModalLayer* ModalLayer::create(EventListener* listener){

	return ModalLayer::create(listener, "Scene/Main/Window.png", "Scene/Main/Ok.png", "Scene/Main/No.png");
}

ModalLayer* ModalLayer::create(EventListener* listener, const std::string& window, const std::string& okButton, const std::string& NoButton){

	auto obj = new ModalLayer();

	if (obj && obj->init(listener, window, okButton, NoButton)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;

}

bool ModalLayer::init(EventListener* listener, const std::string& windowImage, const std::string& okButton, const std::string& NoButton)
{
	if (!Layer::init()){
		return false;
	}

	auto onTouchBegan = CC_CALLBACK_2(ModalLayer::onTouchBegan, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, nullptr, nullptr);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto window = cocos2d::Sprite::create(windowImage);

	window->setPosition(cocos2d::Director::getInstance()->getWinSize() / 2);

	this->addChild(window);

	MenuItemImage* yes = MenuItemImage::create(okButton, okButton, CC_CALLBACK_1(ModalLayer::onYesButton, this));
	yes->setPosition(Vec2(150, 500));

	MenuItemImage* no = MenuItemImage::create(NoButton, NoButton, CC_CALLBACK_1(ModalLayer::onNoButton, this));
	no->setPosition(Vec2(550, 500));

	Menu* menu = Menu::create(yes,no, nullptr);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

	//this->addButton(window, okButton, okButton, CC_CALLBACK_1(ModalLayer::onYesButton, this), YES);

	//this->addButton(window, NoButton, NoButton, CC_CALLBACK_1(ModalLayer::onNoButton, this), NO);

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

		CC_SAFE_RELEASE(this->listner);

	}), nullptr);

	this->runAction(sequence);
}

void ModalLayer::addButton(cocos2d::Node* window, const std::string& normalImage, const std::string& selectImage, const cocos2d::ccMenuCallback& callback, ModalLayer::BUTTONTYPE type){

	MenuItemImage* item = MenuItemImage::create(normalImage, selectImage,callback);

	Menu* menu = Menu::create(item, nullptr);
	menu->setPosition(Point::ZERO);
	auto point = buttonAddPoint(item->getContentSize(),window->getContentSize(), type);

	item->setPosition(point);
	
	this->addChild(menu);
}

const Vec2& ModalLayer::buttonAddPoint(const Size& contentSize,const Size& windowSize, ModalLayer::BUTTONTYPE type){

	switch (type)
	{
	case ModalLayer::YES:
		return Vec2(150, 500);
	case ModalLayer::NO:
		return Vec2(550, 500);
	case ModalLayer::CLOSE:
		return Vec2(windowSize.width - contentSize.width, windowSize.height - contentSize.height);
	case ModalLayer::SIZE:
		break;
	default:
		break;
	}	
	return nullptr;
}