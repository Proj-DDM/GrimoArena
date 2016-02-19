#include "BattleSequence.h"
#include "SequenceManager.h"
#include "EndSequence.h"
#include <array>
#include <math.h>
#include "Game\Object\StageObject\StageMap/StageManager.h"
#include "Utility/Particle/SimpleParticle.h"
#include "Utility/Animation/SpriteAnimation.h"

#define MAX_ARRAY 24

namespace 
{
	std::vector < Character* > Mysort(std::vector < Character* > contener)
	{
		std::vector < Character* > sortContener;

		for(Character* chara : contener)
		{
			sortContener.push_back(chara);
			if (sortContener.size() == 1) continue;

			for (int i = 0; i < sortContener.size(); ++i)
			{
				if (sortContener.at(i)->getParameter().speed < sortContener.back()->getParameter().speed)
				{
					Character* sortChara;
					std::swap(sortChara, sortContener.back());

					for (int y = sortContener.size() - 1; i < y; --y)
					{
						sortContener.at(y) = std::move(sortContener.at(y - 1));
					}
					sortContener.at(i) = std::move(sortChara);

					continue;
				}
			}
		}


		return sortContener;
	}
}

BattelSequence::BattelSequence(StageManager* stageManager) :ISequence(stageManager)
{
	mState = S_START;
}

BattelSequence::~BattelSequence(){
}

S_STATUS BattelSequence::update(float at){

	if (mState < S_NULL){
		(this->*updateFunc[mState])(at);
	}

	return mState;
}

void BattelSequence::start(float at){
	container = mStageManager->getCaras();
	container = Mysort(container);
	mStageManager->allCheck(0);
	mAttackArray = { 0, 0, 0, 0, 0,
					 0, 1, 1, 1, 0,
					 0, 1, 2, 1, 0,
					 0, 1, 1, 1, 0,
					 0, 0, 0, 0, 0 };
	mCount = 0;
	mStageManager->setUI(BATTLE_SEQUENCE);
	mState = S_MAIN;
}

void BattelSequence::main(float at){
	int charaPos = 0;
	static int i = 0;
	++i;
	//deadCheck();
	for (int i = 0; i < container.size(); ++i) {
		if (container.at(i)->getParameter().hp.isDead() == true) {
			auto act = RemoveSelf::create();
			container[i]->runAction(act);
		}
	}
	if (i % 60 == 0) {
		if (container[mCount]->getParameter().hp.isDead()) {
			if (container.at(mCount)->getState() != CharacterState::Dead) {
				container.at(mCount)->getState() = CharacterState::Dead;
				CCLOG("dead : %i", mCount);
			}
		}
		charaPos = container.at(mCount)->getParameter().position;
		mAttackParam = container.at(mCount)->getParameter().attackPoint;
		if (container.at(mCount)->getCharacterUser() == CharacterUser::Player1) {
			charauser = 1;
		}
		else {
			charauser = 2;
		}

		//攻撃範囲変換
		for (int i = 0; i < mAttackArray.size(); ++i) {
			if (mAttackArray[i] == 2){
				mCharaLine.x = i % 5;
				mCharaLine.y = i / 5;
				mBaseLine.x = mCharaLine.x;
				mBaseLine.y = mCharaLine.y;
				mCharaLine.x = 0;
				mCharaLine.y = 0;
			}
		}
		if (container.at(mCount)->getState() != CharacterState::Dead) {
			container.at(mCount)->getState() = CharacterState::MoveWait;
		}
		move(mCount, charauser);
		charaPos = container.at(mCount)->getParameter().position;
		mStageManager->checkOnPanel();

		if (container.at(mCount)->getState() != CharacterState::Dead) {
			CCLOG("attack : %i", mCount);
			attackPos(charaPos);
		}
		++mCount;
	}
	
	if (mCount == container.size()) {
		mState = S_END;
	}
}

void  BattelSequence::deadCheck() {
	for (int i = 0; i < container.size(); ++i) {
		if (container.at(i)->getParameter().hp.isDead()) {
			if (container.at(i)->getState() != CharacterState::Dead) {
				container.at(i)->getState() = CharacterState::Dead;
				CCLOG("dead : %i", i);
				int pos = 0;
				pos = container.at(i)->getParameter().position;

				std::array<int, 25> charavect{};
				for (int k = 0; k < 25; ++k) {
					charavect[k] = container.at(i)->getParameter().vect[k];
				}

				mStageManager->deadChangePanel(charauser + 2, pos, charavect);
			}
		}
		//mStageManager->checkOnPanel();
	}
}

void BattelSequence::actionMain(int id) {
	int charaPos = 0; //パネル座標変換用変数
	int mCount = 0; //今行動できるキャラ
	//メイン処理
	//死んでたらスルー
	deadCheck();
	if (container.at(mCount)->getState() == CharacterState::Dead) {
		++mCount;
	}
	charaPos = container.at(mCount)->getParameter().position;
	mAttackParam = container.at(mCount)->getParameter().attackPoint;
}

void BattelSequence::move(int id, int user) {
	CCLOG("move : %i", id);
	if (container.at(id)->getState() != CharacterState::MoveWait) return;
	
	int moveCount = 0;
	int charaPosY = 0;
	int moveVelocity = 0;
	int correctionCount = 0;
	int stopCount = 0;
	int absCount = 0;
	moveCount = container.at(id)->getParameter().move.y;
	charaPosY = container.at(id)->getPositionY();
	if (container.at(id)->getCharacterUser() == CharacterUser::Player2) {
		moveCount = -1 * moveCount;
	}
	moveVelocity = charaPosY + moveCount * PANELSIZE;
	correctionCount = container.at(id)->getParameter().move.y * 9;
	if (container.at(id)->getCharacterUser() == CharacterUser::Player2) {
		correctionCount = -1 * correctionCount;
	}
	if (container.at(id)->getParameter().move.y >= 2) {
		stopCount = container.at(id)->getParameter().position + 
			correctionCount / container.at(id)->getParameter().move.y;
	}
	for (int i = 0; i < container.size(); ++i) {
		if (container.at(id)->getParameter().position + correctionCount == container.at(i)->getParameter().position ||
			stopCount == container.at(i)->getParameter().position) {
			container.at(id)->getState() = CharacterState::MoveEnd;
			return;
		}
	}
	//画像移動
	//適当な範囲制限
	if (moveVelocity > 0 || moveVelocity < 1500) {
		auto sprite = (Sprite*)container.at(id)->getSprite();
		auto move = MoveTo::create(0.3f, Vec2(
			container.at(id)->getSprite()->getPositionX(),
			container.at(id)->getSprite()->getPositionY() + moveVelocity));
		auto easemove = EaseInOut::create(move, 10);
		sprite->runAction(easemove);
		//container.at(id)->setPositionY(moveVelocity);
	}
	//キャラクターパラメーターの位置の値を画像位置と同期
	//CCLOG("%i", std::abs(moveCount));
	if (container.at(id)->getCharacterUser() == CharacterUser::Player2) {
		moveCount = moveCount * -1;
	}
	absCount = std::abs(moveCount);
	if (moveCount > 1) {
		for (int i = 0; i < moveCount; ++i) {
			if (container.at(id)->getCharacterUser() == CharacterUser::Player2) {
				container.at(id)->getParameter().position -= 9;
			} else {
				container.at(id)->getParameter().position += 9;
			}
			mStageManager->checkOnPanel();
		}
	} else {
		container.at(id)->getParameter().position += correctionCount;
	}
	container.at(id)->getState() = CharacterState::MoveEnd;
}

void BattelSequence::attackPos(int pos) {

	mPanelLine = cocos2d::Vec2(0, 0);

	attackpanel = pos;
	for (int i = 0; i < mAttackArray.size(); ++i){

		if (mAttackArray[i] >= 1){
			mPanelLine.x = i % 5 - mBaseLine.x;
			mPanelLine.y = (MAX_ARRAY - i) / 5 - mBaseLine.y;

			int test_x = pos % 9 + mPanelLine.x;

			if (test_x >= 0 && test_x < 9){
				attackpanel = pos + mPanelLine.x + mPanelLine.y * 9;

				checkPos(attackpanel);
			}
		}
	}
}

void BattelSequence::checkPos(int pos) {
	mPanelLine = cocos2d::Vec2(0, 0);

	attackpanel = pos;


	for (int i = 0; i < container.size(); ++i) {
		//攻撃範囲
		if (attackpanel == container.at(i)->getParameter().position) {
			if (charauser == 1) {
				if (container.at(i)->getCharacterUser() == CharacterUser::Player1) return;
				container.at(i)->getParameter().hp.operator-=(mAttackParam);
				
				auto sprite = Sprite::create();
				mStageManager->addChild(sprite);
				sprite->setPosition(Point(
					container.at(i)->getSprite()->getPositionX() + (int)container.at(i)->getPositionX(),
					container.at(i)->getSprite()->getPositionY() + (int)container.at(i)->getPositionY()));
				CCLOG("X %i", (int)container.at(i)->getSprite()->getPositionX());
				CCLOG("Y %i", (int)container.at(i)->getSprite()->getPositionY());
				sprite->setTextureRect(Rect(0, 0, 120, 120));
				sprite->setCameraMask((int)CameraFlag::USER1);
				Util::SpriteAnimation spriteAnimetion("Effect/");
				//
				if (container.at(mCount)->getParameter().attribute == 1000) {
					anime = spriteAnimetion.createAnim("fire_", 8, 0.08f, true);
				}
				if (container.at(mCount)->getParameter().attribute == 1001) {
					anime = spriteAnimetion.createAnim("water_", 8, 0.08f, true);
				}
				if (container.at(mCount)->getParameter().attribute == 1010) {
					anime = spriteAnimetion.createAnim("wood_", 8, 0.08f, true);
				}
				auto func = CallFunc::create([sprite]() {
					sprite->removeFromParentAndCleanup(true);
				});
				auto seq = Sequence::create(anime, func, NULL);
				sprite->runAction(seq);

				CCLOG("Player1Attack for %i", i);
				if (container.at(i)->getParameter().hp.isDead() == true) {
					int pos;
					pos = container.at(i)->getParameter().position;

					std::array<int, 25> charavect{};
					for (int k = 0; k < 25; ++k) {
						charavect[k] = container.at(i)->getParameter().vect[k];
					}

					mStageManager->deadChangePanel(charauser + 2, pos, charavect);
					//キャラの削除
				}
			}
			if (charauser == 2) {
				if (container.at(i)->getCharacterUser() == CharacterUser::Player2) return;
				container.at(i)->getParameter().hp.operator-=(mAttackParam);

				auto sprite = Sprite::create();
				mStageManager->addChild(sprite);
				sprite->setPosition(Point(
					container.at(i)->getSprite()->getPositionX() + (int)container.at(i)->getPositionX(),
					container.at(i)->getSprite()->getPositionY() + (int)container.at(i)->getPositionY()));
				CCLOG("X %i", (int)container.at(i)->getSprite()->getPositionX());
				CCLOG("Y %i", (int)container.at(i)->getSprite()->getPositionY());
				sprite->setTextureRect(Rect(0, 0, 120, 120));
				sprite->setCameraMask((int)CameraFlag::USER1);
				Util::SpriteAnimation spriteAnimetion("Effect/");
				//
				if (container.at(mCount)->getParameter().attribute == 1000) {
					anime = spriteAnimetion.createAnim("fire_", 8, 0.08f, true);
				}
				if (container.at(mCount)->getParameter().attribute == 1001) {
					anime = spriteAnimetion.createAnim("water_", 8, 0.08f, true);
				}
				if (container.at(mCount)->getParameter().attribute == 1010) {
					anime = spriteAnimetion.createAnim("wood_", 8, 0.08f, true);
				}
				auto func = CallFunc::create([sprite]() {
					sprite->removeFromParentAndCleanup(true);
				});
				auto seq = Sequence::create(anime, func, NULL);
				sprite->runAction(seq);

				CCLOG("Player2Attack for %i", i);
				if (container.at(i)->getParameter().hp.isDead() == true) {
					int pos;
					pos = container.at(i)->getParameter().position;

					std::array<int, 25> charavect{};
					for (int k = 0; k < 25; ++k) {
						charavect[k] = container.at(i)->getParameter().vect[k];
					}

					mStageManager->deadChangePanel(charauser + 2, pos, charavect);
					//キャラの削除
				}
			}
		}
	}
}

void BattelSequence::end(float at){
	
	SequenceManager::GetInstance()->nextScene(new EndSequence(mStageManager));
	mState = S_NULL;
}

bool BattelSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touch,event);

	return true;
}

bool BattelSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}

void BattelSequence::onEndSequence(){

}