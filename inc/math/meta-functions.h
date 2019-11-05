#pragma once

#include <type_traits>
#include <tuple>
#include "integer-types.h"

namespace Math
{

namespace MetaFunctions
{

template <std::size_t Index, class Tuple>
struct IsSameTupleImpl : std::conjunction<std::is_same<std::tuple_element_t<0, Tuple>, std::tuple_element_t<Index, Tuple>>, IsSameTupleImpl<Index - 1, Tuple>> { };

template <class TTuple>
struct IsSameTupleImpl<0, TTuple> : std::true_type { };

/// <summary>
/// �^�v���^�̗v�f�^���S�ē����^�����`����\����
/// </summary>
template <class TTuple>
struct IsSameTuple : IsSameTupleImpl<std::tuple_size_v<TTuple> -1, TTuple> { };

/// <summary>
/// �^�v���^�̗v�f�^���S�ē����^�����擾
/// </summary>
template <class TTuple>
constexpr bool IsSameTupleValue = IsSameTuple<TTuple>::value;

/// <summary>
/// �S�Ă̌^�����������^�����`����\����
/// </summary>
template <class ... Types>
struct IsSameType : IsSameTuple<std::tuple<Types...>> { };

/// <summary>
/// �S�Ă̌^�����������^�����擾
/// </summary>
template <class ... Types>
constexpr bool IsSameTypeValue = IsSameType<Types...>::value;

/// <summary>
/// �R���p�C����x�点����false static_assert()���Ŏg�p
/// </summary>
template <class T>
constexpr bool FalseValue = false;

} // namespace MetaFunctions

} // namespace Math
