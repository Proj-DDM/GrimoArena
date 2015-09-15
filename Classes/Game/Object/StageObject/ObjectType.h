#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

enum class ObjectType : int
{
	OBJECT_BLOCK_RED		= 1 << 0,
	OBJECT_BLOCK_BLUE		= 1 << 1,
	OBJECT_PLAYER_RED		= 1 << 2,
	OBJECT_PLAYER_BLUE		= 1 << 3,
	OBJECT_BLOCK_NORMAL		= 1 << 4,
	OBJECT_BLOCK_GOAL		= 1 << 5,
	OBJECT_GIMMICK_FERMATA	= 1 << 6,
	OBJECT_GIMMICK_REST		= 1 << 7, 
	OBJECT_ALL			= INT_MAX,	// 0xFFFFFFFFの代用品
	};
	
namespace converter
{
	static int toInt( ObjectType type )
	{
		return static_cast< int >( type );
	}
	
	static ObjectType toObjectType(int bit)
	{
		return static_cast< ObjectType >( bit );
	}
};
	
#endif