#include "SequenceManager.h"

#define MAXTURN 6

SequenceManager::SequenceManager():m_Turn(1)
{
}


SequenceManager::~SequenceManager()
{
}

//インスタンス初期化
SequenceManager* SequenceManager::GetInstance()
{
	static SequenceManager instance;
	return &instance;
}

//初期化
void SequenceManager::init(){
	while (!m_SequenceStack.empty())
	{
		currentSequence = m_SequenceStack.top();
		delete currentSequence;
		currentSequence = NULL;
		m_SequenceStack.pop();
	}

	m_Turn = 1;
}

//更新
bool SequenceManager::update(float at){

	currentSequence = m_SequenceStack.top();

	if (currentSequence->update(at) == S_NULL){
		
		if (currentSequence != NULL){
			delete currentSequence;
			m_SequenceStack.pop();
			currentSequence = NULL;
		}
		// スタックに積むことが予約されたシーン
		if (NULL != nextSequence)
		{
			// スタックを積む
			m_SequenceStack.push(nextSequence);

			nextSequence = NULL;
		}
	}

	return (m_Turn >= MAXTURN);

}

//シーケンス追加（使うことないかな？）
void SequenceManager::push(ISequence* sequence){
	m_SequenceStack.push(sequence);
}

//シーケンスの解放
void SequenceManager::pop(){
	
	delete	currentSequence;
	m_SequenceStack.pop();
}

//次のターンへ
void SequenceManager::addTurn(){
	m_Turn++;
}

//次のシーンの予約
void SequenceManager::nextScene(ISequence* sequence){

	/*while (!m_SequenceStack.empty())
	{
		currentSequence = m_SequenceStack.top();
		delete currentSequence;
		currentSequence = NULL;
		m_SequenceStack.pop();
	}

	m_SequenceStack.push(sequence);*/

	if (m_SequenceStack.empty()){
		m_SequenceStack.push(sequence);
		return;
	}

	if (nextSequence){
		delete nextSequence;
	}

	nextSequence = sequence;

}

//解放
void SequenceManager::Release(){
	while (!m_SequenceStack.empty())
	{
		ISequence* ptr = m_SequenceStack.top();
		delete ptr;
		ptr = NULL;
		m_SequenceStack.pop();
	}
	if (NULL != nextSequence)
	{
		delete nextSequence;
	}
}

//タッチ初め
bool SequenceManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	if (!currentSequence) return false;

	return currentSequence->onTouchBegan(touch, event);
 
}

//タッチ終わり
bool SequenceManager::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	
	if (!currentSequence) return false;

	return currentSequence->onTouchEnded(touch, event);

}

TURN_PLAYER SequenceManager::getTurnPlayer() const{
	return m_TrunPlayer;
}

//終了ボタン
void SequenceManager::setEndSequence(){
	currentSequence->onEndSequence();
	if (m_TrunPlayer == PLAYER1) m_TrunPlayer = PLAYER2;
	else m_TrunPlayer = PLAYER1;
}