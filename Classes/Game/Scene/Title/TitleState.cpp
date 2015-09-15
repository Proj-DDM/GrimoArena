#include "TitleState.h"
#include "Utility/SceneSupport/SceneCreator.h"

using namespace cocos2d;

TitleState::TitleState() :
mTitleState(true),
mNumber(0),
mState(0)
{
}


/*-----------------------------------------------------
 -------デストラクタ
 -----------------------------------------------------*/
TitleState::~TitleState()
{}

/*-----------------------------------------------------
 -------シーン作成
 -----------------------------------------------------*/
TitleState* TitleState::create(Layer* layer)
{

	auto obj = new TitleState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

/*-----------------------------------------------------
 -------初期化
 -----------------------------------------------------*/
bool TitleState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;
	mTestTouch = false;
    
    mTitleSpriteLayer = TitleSpriteLayer::create();
    layer->addChild(mTitleSpriteLayer);
  
    
	
	UserDefault* useDef = UserDefault::getInstance();
	useDef->setIntegerForKey("selectStage", mNumber);
	useDef->flush();

	mPlayer = Player::create("Helper1_1.png", ObjectType::OBJECT_PLAYER_RED, 2);
	mPlayer->setName("Player");
	mPlayer->setPosition(Vec2(0, 0));
	mTitleSpriteLayer->addChild(mPlayer);


	auto lis = PhysicsListener::create();
	layer->addChild(lis);

	mBlockManager = BlockManager::create();
	mBlockManager->setName("Blocks");

    
	mTitleSpriteLayer->addChild(mBlockManager);
    
     
    mTitleActionLayer = TitleActionLayer::create();
    layer->addChild(mTitleActionLayer);

	return true;
}

/*-----------------------------------------------------
  -------更新
 -----------------------------------------------------*/
void TitleState::update(float at){
	(this->*updateFunc[mSceneState])(at);
	
	animeUpdate(at);
    //シーン遷移
    sceneChange();

}


/*-----------------------------------------------------
 -------フェードイン
 -----------------------------------------------------*/
void TitleState::fadeIn(float at){
		mSceneState = MAIN;
}

/*-----------------------------------------------------
 -------シーンメイン
 -----------------------------------------------------*/
void TitleState::sceneMain(float at){(this->*mainFunc[mUpdateState])(at);}

/*-----------------------------------------------------
 -------フェードアウト
 -----------------------------------------------------*/
void TitleState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
}

/*-----------------------------------------------------
 -------シーンメイン（スタート）
 -----------------------------------------------------*/
void TitleState::mainStart(float at){mUpdateState = UPDATELOOP;}

/*-----------------------------------------------------
 -------シーンメイン（ループ）
 -----------------------------------------------------*/
void TitleState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}


}

/*-----------------------------------------------------
 -------シーン遷移
 -----------------------------------------------------*/
void TitleState::sceneChange(){
    
   // int mState = mTitleActionLayer->getSelectCount();
    
    switch (mState)
    {
        case 0:
            break;
         
        //初めから//////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
        {
            //初期化
          //  mTitleActionLayer->initSelectCount();
			mState = 0;
            
            UserDefault* useDef  = UserDefault::getInstance();
            useDef->setIntegerForKey("selectStage",1);
			useDef->setIntegerForKey("selectGimmick", 1);
			
            useDef->flush();
            
            //ゲーム生成
			auto nextScene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 5.0f);
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
        
        //ステージセレクト////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
        {
            //初期化
            //mTitleActionLayer->initSelectCount();

			mState = 0;
            //ステージセレクト
            auto nextScene = SceneCreator::createScene(StageSelectScene::create());
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
            
        //クレジット////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3:
        {
            //mTitleActionLayer->initSelectCount();

			mState = 0;
            
            //クレジット
            auto nextScene = SceneCreator::createScene(CreditScene::create());
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
    }
}


/*-----------------------------------------------------
 -------シーンメイン（エンド）
 -----------------------------------------------------*/
void TitleState::mainEnd(float at){
	mUpdateState =UPDATESTART;
	mSceneState = FADEOUT;
}

void TitleState::animeUpdate(float at){
	if (!mTitleSpriteLayer->getChildByName("Player")) return;

	mPlayer->update(at);

	if (mPlayer->jumpCount() >= 5 || mPlayer->getState() == DEAD){
		remove();
		mNumber = (mNumber - 1) % -3;
		reset();
		return;
	}

	if (mPlayer->getState() == JUMP) return;

	mPlayer->jump(mBlockManager->getBlockPos(mPlayer->jumpCount()));
}

bool TitleState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;

	//状態管理
	if (!mTitleState) return false;
	
    
	cocos2d::MenuItemImage* buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_Start.png",
		"Texture/GamePlay/GameScene/Title/Title_Start.png",
		[=](Ref* sender){mState = 1;});
	buttonImage->setPosition(Director::getInstance()->getVisibleSize().width/2, 300);

	
	auto start = Menu::create(buttonImage, nullptr);
	start->setPosition(Vec2::ZERO);
	mTitleSpriteLayer->addChild(start);



	cocos2d::MenuItemImage* buttonImage2 = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
		"Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
		[=](Ref* sender){mState = 2; });
	buttonImage2->setPosition(Director::getInstance()->getVisibleSize().width / 2, 200);
	auto stageSelect = Menu::create(buttonImage2, nullptr);
	stageSelect->setPosition(Vec2::ZERO);
	mTitleSpriteLayer->addChild(stageSelect);



	cocos2d::MenuItemImage* buttonImage3 = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_Credit.png",
		"Texture/GamePlay/GameScene/Title/Title_Credit.png",
		[=](Ref* sender){mState = 3; });
	buttonImage3->setPosition(Director::getInstance()->getVisibleSize().width/2, 100);
	auto end = Menu::create(buttonImage3, nullptr);
	end->setPosition(Vec2::ZERO);
	mTitleSpriteLayer->addChild(end);
    
 
    
    //アクションの停止
    auto touchLogo = mTitleSpriteLayer->getChildByName("TouchLogo");
    touchLogo->stopAllActions();
    touchLogo->setOpacity(0);
    
    //mTitleActionLayer->CreateButton();

    mTitleState = false;

	return true;
}


void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}

void TitleState::remove(){
	mTitleSpriteLayer->removeChildByName("Player");
}

void TitleState::reset(){

	if (mNumber == -1){
		mPlayer = Player::create("Helper2_1.png", ObjectType::OBJECT_PLAYER_BLUE, 2);
		mPlayer->setName("Player");
		mPlayer->setPosition(Vec2(0, 0));
		mTitleSpriteLayer->addChild(mPlayer);
	}
	else{
		mPlayer = Player::create("Helper1_1.png", ObjectType::OBJECT_PLAYER_RED, 2);
		mPlayer->setName("Player");
		mPlayer->setPosition(Vec2(0, 0));
		mTitleSpriteLayer->addChild(mPlayer);
	}

	UserDefault* useDef = UserDefault::getInstance();
	useDef->setIntegerForKey("selectStage", mNumber);
	useDef->flush();

	mBlockManager->reset();
}