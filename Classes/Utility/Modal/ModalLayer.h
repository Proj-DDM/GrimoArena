#ifndef MODALLAYER_H
#define MODALLAYER_H

#include "cocos2d.h"

class ModalLayer : public cocos2d::Layer{

	enum BUTTONTYPE{ //�{�^���^�C�v
		YES,
		NO,
		CLOSE,
		SIZE
	};

	class EventListener;
private:
	void onYesButton(cocos2d::Ref* ref);	//Yes�{�^���������ꂽ�Ƃ� 

	void onNoButton(cocos2d::Ref* ref);		//No�{�^���������ꂽ�Ƃ�

	void onSelectButton(std::function<void()> func);	//�{�^�����I�����ꂽ���Ƃ̃R�[���o�b�N

	//�{�^���̒ǉ�
	void addButton(cocos2d::Node* node, const std::string& normalImage, const std::string& selectImage, const cocos2d::ccMenuCallback& callback, BUTTONTYPE type);

	//�ǉ�����{�^���̃|�C���g
	//�ꏊ�̓{�^���̃^�C�v�ɂ���ĕύX����B
	const cocos2d::Point& buttonAddPoint(const cocos2d::Size& contentSize, const cocos2d::Size& windowSize, BUTTONTYPE type);

	EventListener* listner;	 //�C�x���g���X�i�[

public:

	//����
	static ModalLayer* create(EventListener* listener);

	//������
	virtual bool init(EventListener* listener);

	//��ʂ��^�b�`���ꂽ��
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event); 

public:
	class EventListener :public cocos2d::Ref{

	public:
		CREATE_FUNC(EventListener);
		EventListener(){};
		bool init(){ return true; }

		std::function<void()> onButtonYes { nullptr };
		std::function<void()> onButtonNo { nullptr };
	};

};


#endif