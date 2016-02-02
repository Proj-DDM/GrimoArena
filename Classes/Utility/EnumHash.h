#ifndef _ENUM_HASH_H_
#define _ENUM_HASH_H_

#include <cstddef>
#include <type_traits>
#include <functional>

/*------------------------------------------------------------*/
//	@struct		：	EnumHash
//	@brief		：	unordered_map用のHash
//	@author		：	利川聖太
/*------------------------------------------------------------*/
struct EnumHash
{
	/**
	*	@brief	関数オブジェクト
	*	@param	t		enum classの値
	*	@return	size_t	要素数
	*/
	template< typename T >
	std::size_t operator () (T x) const
	{
		// enum型以外の場合はエラーを発生させる。
		static_assert(std::is_enum< T >::value, "enum型以外は使用できません。");
		using BaseType = typename std::underlying_type< T >::type;

		return static_cast< BaseType >(x);
	}
};

#endif