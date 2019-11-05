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
/// タプル型の要素型が全て同じ型かを定義する構造体
/// </summary>
template <class TTuple>
struct IsSameTuple : IsSameTupleImpl<std::tuple_size_v<TTuple> -1, TTuple> { };

/// <summary>
/// タプル型の要素型が全て同じ型かを取得
/// </summary>
template <class TTuple>
constexpr bool IsSameTupleValue = IsSameTuple<TTuple>::value;

/// <summary>
/// 全ての型引数が同じ型かを定義する構造体
/// </summary>
template <class ... Types>
struct IsSameType : IsSameTuple<std::tuple<Types...>> { };

/// <summary>
/// 全ての型引数が同じ型かを取得
/// </summary>
template <class ... Types>
constexpr bool IsSameTypeValue = IsSameType<Types...>::value;

/// <summary>
/// コンパイルを遅らせたいfalse static_assert()等で使用
/// </summary>
template <class T>
constexpr bool FalseValue = false;

} // namespace MetaFunctions

} // namespace Math
