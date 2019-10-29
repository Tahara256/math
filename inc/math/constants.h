#pragma once

#include <limits>
#include "integer-types.h"

namespace Math
{

/// <summary>
/// ��(�~����)
/// </summary>
template <class TFloat>
constexpr TFloat Pi = static_cast<TFloat>(3.14159265358979323846);

/// <summary>
/// 2��
/// </summary>
template <class TFloat>
constexpr TFloat TwoPi = Pi<TFloat> * static_cast<TFloat>(2);

/// <summary>
/// (1/2)��
/// </summary>
template <class TFloat>
constexpr TFloat HalfPi = Pi<TFloat> / static_cast<TFloat>(2);

/// <summary>
/// (1/3)��
/// </summary>
template <class TFloat>
constexpr TFloat OneThirdPi = Pi<TFloat> / static_cast<TFloat>(3);

/// <summary>
/// (1/4)��
/// </summary>
template <class TFloat>
constexpr TFloat QuaterPi = Pi<TFloat> / static_cast<TFloat>(4);


/// <summary>
/// �ʓx�@����x���@�֕ϊ�����W��
/// </summary>
template <class TFloat>
constexpr TFloat ToDegreesConstant = static_cast<TFloat>(180) / Pi<TFloat>;

/// <summary>
/// �x���@����ʓx�@�֕ϊ�����W��
/// </summary>
template <class TFloat>
constexpr TFloat ToRadiansConstant = Pi<TFloat> / static_cast<TFloat>(180);

} // namespace Math
