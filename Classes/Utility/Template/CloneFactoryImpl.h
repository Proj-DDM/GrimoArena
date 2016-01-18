#ifndef _CLONE_FACTORY_IMPL_H_
#define _CLONE_FACTORY_IMPL_H_

#include "CloneFactory.h"

template< typename KEY, typename PRODUCT, typename RELEASE >
CloneFactory< KEY, PRODUCT, RELEASE >::~CloneFactory()
{
	auto itor	= mProductContainer.begin();
	auto end	= mProductContainer.end();
	
	for ( ; itor != end; ++itor )
	{
		RELEASE();
	}
	
	mProductContainer.clear();
}

template< typename KEY, typename PRODUCT, typename RELEASE >
void CloneFactory< KEY, PRODUCT, RELEASE >::addProduct( KEY key, PRODUCT* product )
{
	mProductContainer[ key ] = product;
}

template< typename KEY, typename PRODUCT, typename RELEASE >
PRODUCT* CloneFactory< KEY, PRODUCT, RELEASE >::createProduct( KEY key )
{
	// clone関数( プロトタイプパターン )を実装していることが前提です。
	return mProductContainer[ key ]->clone();
}

#endif