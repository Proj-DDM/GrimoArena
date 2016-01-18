#ifndef COMMON_H
#define COMMON_H

#include "cocos2d.h"

USING_NS_CC;

//���O��Ԃ����邱�Ƃɂ���� �ǂ݂Â炭�Ȃ�̂���������
#define NS_BEGIN(_type_) namespace _type_ {
#define NS_END }


//�����}�N�� �����P�����ꍇ
#define CREATE_FUNC_PARAM1(__TYPE__,__PARAM__) \
	static __TYPE__* create(__PARAM__ param) \
{ \
	__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
	if (pRet && pRet->init(param)) \
	{ \
	pRet->autorelease(); \
	return pRet; \
	} \
	else \
	{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
	} \
}

//�����}�N�� ����2�����ꍇ
#define CREATE_FUNC_PARAM2(__TYPE__,__PARAM__,__PARAM2__) \
	static __TYPE__* create(__PARAM__ param,__PARAM2__ param2 ) \
{ \
	__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
	if (pRet && pRet->init(param,param2)) \
	{ \
	pRet->autorelease(); \
	return pRet; \
	} \
	else \
	{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
	} \
}


#endif