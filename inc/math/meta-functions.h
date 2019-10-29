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
/// ƒ^ƒvƒ‹Œ^‚Ì—v‘fŒ^‚ª‘S‚Ä“¯‚¶Œ^‚©‚ğ’è‹`‚·‚é\‘¢‘Ì
/// </summary>
template <class TTuple>
struct IsSameTuple : IsSameTupleImpl<std::tuple_size_v<TTuple> -1, TTuple> { };

/// <summary>
/// ƒ^ƒvƒ‹Œ^‚Ì—v‘fŒ^‚ª‘S‚Ä“¯‚¶Œ^‚©‚ğæ“¾
/// </summary>
template <class TTuple>
constexpr bool IsSameTupleValue = IsSameTuple<TTuple>::value;

/// <summary>
/// ‘S‚Ä‚ÌŒ^ˆø”‚ª“¯‚¶Œ^‚©‚ğ’è‹`‚·‚é\‘¢‘Ì
/// </summary>
template <class ... Types>
struct IsSameType : IsSameTuple<std::tuple<Types...>> { };

/// <summary>
/// ‘S‚Ä‚ÌŒ^ˆø”‚ª“¯‚¶Œ^‚©‚ğæ“¾
/// </summary>
template <class ... Types>
constexpr bool IsSameTypeValue = IsSameType<Types...>::value;

} // namespace MetaFunctions

} // namespace Math
