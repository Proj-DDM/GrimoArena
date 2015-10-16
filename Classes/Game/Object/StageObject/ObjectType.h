#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

enum class ObjectType : int {
	OBJECT_BLOCK_RED		= 1 << 0,
	OBJECT_BLOCK_BLUE		= 1 << 1,
	OBJECT_ALL			= INT_MAX,	// 0xFFFFFFFFの代用品
	};
	
namespace converter {
	static int toInt( ObjectType type ) {
		return static_cast< int >( type );
	}
	
	static ObjectType toObjectType(int bit) {
		return static_cast< ObjectType >( bit );
	}
};
	
#endif