#include "RedBlock.h"
#include "../ObjectType.h"

using namespace cocos2d;

RedBlock::RedBlock()
	: mIsChanged( false )
{
	
}

RedBlock::~RedBlock()
{
}

RedBlock* RedBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new RedBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool RedBlock::init( const std::string& nodeName, const BlockData& data )
{
	if ( !Sprite::initWithFile( data.pointTextureName + ".png" ) )
	{
		return false;
	}
	
	this->setName( nodeName );
	CreatePanel();
	return true;
}

void RedBlock::CreatePanel() {

	Vec2 createPosCount;
	Vec2 createPos;

	auto sprite = Sprite::create();
	sprite->setTextureRect(Rect(0, 0, 64, 64));
	sprite->setColor(Color3B::WHITE);

	createPos.x = createPosCount.x * sprite->getContentSize().width;
	createPos.y = createPosCount.y * sprite->getContentSize().height;

	auto panel = MenuItemSprite::create
		(sprite, sprite, [sprite](Ref* pSender) {
		sprite->setColor(Color3B::RED);
	}
	);

	auto pMenu = Menu::create(panel, NULL);
	pMenu->setPosition(Vec2(
		createPos.x + sprite->getContentSize().width / 2,
		createPos.y + sprite->getContentSize().height / 2));
	this->addChild(pMenu);
}

bool RedBlock::isChange() const
{
	return mIsChanged;
}