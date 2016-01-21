#include "SequenceManager.h"

#define MAXTURN 6

SequenceManager::SequenceManager():m_Turn(1)
{
}


SequenceManager::~SequenceManager()
{
}

//�C���X�^���X������
SequenceManager* SequenceManager::GetInstance()
{
	static SequenceManager instance;
	return &instance;
}

//������
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

//�X�V
bool SequenceManager::update(float at){

	currentSequence = m_SequenceStack.top();

	if (currentSequence->update(at) == S_NULL){
		
		if (currentSequence != NULL){
			delete currentSequence;
			m_SequenceStack.pop();
			currentSequence = NULL;
		}
		// �X�^�b�N�ɐςނ��Ƃ��\�񂳂ꂽ�V�[��
		if (NULL != nextSequence)
		{
			// �X�^�b�N��ς�
			m_SequenceStack.push(nextSequence);

			nextSequence = NULL;
		}
	}

	return (m_Turn >= MAXTURN);

}

//�V�[�P���X�ǉ��i�g�����ƂȂ����ȁH�j
void SequenceManager::push(ISequence* sequence){
	m_SequenceStack.push(sequence);
}

//�V�[�P���X�̉��
void SequenceManager::pop(){
	
	delete	currentSequence;
	m_SequenceStack.pop();
}

//���̃^�[����
void SequenceManager::addTurn(){
	m_Turn++;
}

//���̃V�[���̗\��
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

//���
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

//�^�b�`����
bool SequenceManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	if (!currentSequence) return false;

	return currentSequence->onTouchBegan(touch, event);
 
}

//�^�b�`�I���
bool SequenceManager::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	
	if (!currentSequence) return false;

	return currentSequence->onTouchEnded(touch, event);

}

TURN_PLAYER SequenceManager::getTurnPlayer() const{
	return m_TrunPlayer;
}

//�I���{�^��
void SequenceManager::setEndSequence(){
	currentSequence->onEndSequence();
	if (m_TrunPlayer == PLAYER1) m_TrunPlayer = PLAYER2;
	else m_TrunPlayer = PLAYER1;
}