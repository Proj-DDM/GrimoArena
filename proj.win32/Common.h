#ifndef COMMON_H
#define COMMON_H

#include "cocos2d.h"

USING_NS_CC;

//名前空間をつけることによって 読みづらくなるのを回避する為
#define NS_BEGIN(_type_) namespace _type_ {
#define NS_END }


//生成マクロ 引数１ついれる場合
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

//生成マクロ 引数2ついれる場合
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