#include "SequenceManager.h"


SequenceManager::SequenceManager():m_Turn(1)
{
}


SequenceManager::~SequenceManager()
{
}


void SequenceManager::update(float at){

	auto sequence = m_SequenceQueue.front();

	if (sequence->update(at) == S_NULL){
		pop();
	}
}

void SequenceManager::pop(){
	
	delete m_SequenceQueue.front();
	m_SequenceQueue.pop();
}