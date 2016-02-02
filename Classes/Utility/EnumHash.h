#ifndef _ENUM_HASH_H_
#define _ENUM_HASH_H_

#include <cstddef>
#include <type_traits>
#include <functional>

/*------------------------------------------------------------*/
//	@struct		�F	EnumHash
//	@brief		�F	unordered_map�p��Hash
//	@author		�F	���쐹��
/*------------------------------------------------------------*/
struct EnumHash
{
	/**
	*	@brief	�֐��I�u�W�F�N�g
	*	@param	t		enum class�̒l
	*	@return	size_t	�v�f��
	*/
	template< typename T >
	std::size_t operator () (T x) const
	{
		// enum�^�ȊO�̏ꍇ�̓G���[�𔭐�������B
		static_assert(std::is_enum< T >::value, "enum�^�ȊO�͎g�p�ł��܂���B");
		using BaseType = typename std::underlying_type< T >::type;

		return static_cast< BaseType >(x);
	}
};

#endif