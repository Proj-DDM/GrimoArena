#ifndef DELETE_CONTAINER_H
#define DELETE_CONTAINER_H

#include "cocos2d.h"

namespace Delete{
	
	template< typename VALUE >
	static void cleanVector(std::vector<VALUE*>& vector){

		auto itor = vector.begin();
		auto end = vector.end();

		for (; itor != end; ++itor)
		{
			vector.erase(itor);
		}

		vector.clear();

	}
}
#endif