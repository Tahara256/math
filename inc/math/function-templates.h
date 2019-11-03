#pragma once

#include <cmath>
#include "constants.h"
#include "meta-functions.h"
#include "function-templates-impl/sqlt-impl.h"

/* 数学関数 templates */
namespace Math
{

/// <summary>
/// 値が 0 かを取得
/// </summary>
template <class T>
constexpr bool IsZero(T value) noexcept
{
    return value == static_cast<T>(0);
}

/// <summary>
/// 値が 正の値 かを取得
/// </summary>
template <class T>
constexpr bool IsPlus(T value) noexcept
{
    return value >= static_cast<T>(0);
}

/// <summary>
/// 値が 負の値 かを取得
/// </summary>
template <class T>
constexpr bool IsMinus(T value) noexcept
{
    return value < static_cast<T>(0);
}

/// <summary>
/// 絶対値を取得
/// </summary>
template <class T>
constexpr T Abs(T value) noexcept
{
    return value < static_cast<T>(0) ? -value : value;
}

/// <summary>
/// 指定された値が、0 未満の場合は -1 、0 の場合は 0、0 より大きい場合は 1 をそれぞれ取得
/// </summary>
/// <param name="value">
/// 符号を取得する値
/// </param>
/// <returns>
/// 0 未満の場合は -1 、0 の場合は 0、0 より大きい場合は 1
/// </returns>
template <class T>
constexpr T Sign(T value) noexcept
{
    return value ? (value > static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(-1)) : static_cast<T>(0);
}

/// <summary>
/// 二つの値を比較して、どちらの値が大きいかに基づいて 0 または 1 を取得
/// </summary>
/// <param name="value1">
/// 比較する最初の値
/// </param>
/// <param name="value2">
/// 比較する2番目の値
/// </param>
/// <returns>
/// value1 が value2 以上の場合は 1、それ以外の場合は 0
/// </returns>
template <class T>
constexpr T Step(T value1, T value2) noexcept
{
    return value1 > value2 ? static_cast<T>(0) : static_cast<T>(1);
}

/// <summary>
/// value が範囲内にあるかを取得
/// </summary>
template <class T>
constexpr bool InRange(T value, T min, T max) noexcept
{
    return min <= value && value <= max;
}

/// <summary>
/// value が[0, 1]の範囲内にあるかを取得
/// </summary>
template <class T>
constexpr bool InRange01(T value) noexcept
{
    return InRange(value, static_cast<T>(0), static_cast<T>(1));
}

/// <summary>
/// 最小値を取得
/// </summary>
template <class Head, class ... Tail>
constexpr Head Min(Head head, Tail ... tail) noexcept
{
    static_assert(MetaFunctions::IsSameTypeValue<Head, Tail...>, "Template parameters must be same type.");
    auto result = head;
    using Swallow = std::initializer_list<int>;
    void(Swallow{ (void(result = result < tail ? result : tail), 0)... });
    return result;
}

/// <summary>
/// 最大値を取得
/// </summary>
template <class Head, class ... Tail>
constexpr Head Max(Head head, Tail ... tail) noexcept
{
    static_assert(MetaFunctions::IsSameTypeValue<Head, Tail...>, "Template parameters must be same type.");
    auto result = head;
    using Swallow = std::initializer_list<int>;
    void(Swallow{ (void(result = result > tail ? result : tail), 0)... });
    return result;
}

/// <summary>
/// value を min と max の間に押し込んだ値を取得
/// </summary>
template <class T>
constexpr T Clamp(T value, T min, T max) noexcept
{
    return Min(Max(value, min), max);
}

/// <summary>
/// 任意の値を [0, 1] の区間に押し込む
/// </summary>
/// <param name="value">
/// [0, 1] で押し込む値
/// </param>
/// <returns>
/// [0, 1] の区間に押し込んだ値
/// </returns>
template <class TFloat>
constexpr TFloat Saturate(TFloat value) noexcept
{
    return Clamp(value, static_cast<TFloat>(0), static_cast<TFloat>(1));
}

/// <summary>
/// ある範囲内の値を異なる範囲内の値に変換
/// </summary>
/// <param name="value">
/// 範囲を変更する入力値
/// </param>
/// <param name="inMin">
/// 入力最小値
/// </param>
/// <param name="inMax">
/// 入力最大値
/// </param>
/// <param name="outMin">
/// 出力最小値
/// </param>
/// <param name="outMax">
/// 出力最大値
/// </param>
/// <returns>
/// ある範囲内の値を異なる範囲内の値に変換した値
/// </returns>
template <class TFloat>
constexpr TFloat Remap(TFloat value, TFloat inMin, TFloat inMax, TFloat outMin, TFloat outMax) noexcept
{
    return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
}

/// <summary>
/// 弧度法から度数法へ変換した値を取得
/// </summary>
/// <param name="radians">
/// 弧度法の角度
/// </param>
/// <returns>
/// 度数法の角度
/// </returns>
template <class TFloat>
constexpr TFloat ToDegrees(TFloat radians)
{
    return radians * Math::ToDegreesConstant<TFloat>;
}

/// <summary>
/// 度数法から弧度法へ変換した値を取得
/// </summary>
/// <param name="degrees">
/// 度数法の角度
/// </param>
/// <returns>
/// 弧度法の角度
/// </returns>
template <class TFloat>
constexpr TFloat ToRadians(TFloat degrees)
{
    return degrees * Math::ToRadiansConstant<TFloat>;
}

/// <summary>
/// b の e 乗を取得
/// </summary>
/// <param name="b">
/// 基数
/// </param>
/// <param name="e">
/// 指数
/// </param>
/// <returns>
/// b の e 乗
/// </returns>
template <class TFloat>
TFloat Pow(TFloat b, TFloat e)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::pow(b, e);
}

/// <summary>
/// b の 2 乗を取得
/// </summary>
/// <param name="b">
/// 基数
/// </param>
/// <returns>
/// b の 2 乗
/// </returns>
template <class T>
constexpr T Pow2(T b) noexcept
{
    return b * b;
}

/// <summary>
/// b の 3 乗を取得
/// </summary>
/// <param name="b">
/// 基数
/// </param>
/// <returns>
/// b の 3 乗
/// </returns>
template <class T>
constexpr T Pow3(T b) noexcept
{
    return b * b * b;
}

/// <summary>
/// b の 4 乗を取得
/// </summary>
/// <param name="b">
/// 基数
/// </param>
/// <returns>
/// b の 4 乗
/// </returns>
template <class T>
constexpr T Pow4(T b) noexcept
{
    return b * b * b * b;
}

/// <summary>
/// b の 5 乗を取得
/// </summary>
/// <param name="b">
/// 基数
/// </param>
/// <returns>
/// b の 5 乗
/// </returns>
template <class T>
constexpr T Pow5(T b) noexcept
{
    return b * b * b * b * b;
}

/// <summary>
/// 仮数部と指数部から浮動小数点数を取得
/// </summary>
/// <param name="x">
/// 仮数部
/// </param>
/// <param name="exp">
/// 指数部
/// </param>
/// <returns>
/// 浮動小数点数
/// </returns>
template <class TFloat>
TFloat Ldexp(TFloat x, I32 exp) noexcept
{
    return std::ldexp(x, exp);
}

/// <summary>
/// 値が無限大かを取得
/// </summary>
/// <param name="value">
/// 無限大かを取得する値
/// </param>
/// <returns>
/// 値が無限大か
/// </returns>
template <class THasInf>
constexpr bool IsInf(THasInf value) noexcept
{
    static_assert(std::numeric_limits<THasInf>::has_infinity, "Type can not has infinity.");
    return std::numeric_limits<THasInf>::infinity() == Abs(value);
}

/// <summary>
/// 二つの値がほぼ等しいかを取得
/// </summary>
/// <param name="value1">
/// 比較する最初の値
/// </param>
/// <param name="value2">
/// 比較する2番目の値
/// </param>
/// <returns>
/// 二つの値の差がイプシロン内だったら true 、そうでなかったら false
/// </returns>
template <class TFloat>
constexpr bool Approximately(TFloat value1, TFloat value2) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Abs(value1 - value2) < std::numeric_limits<TFloat>::epsilon();
}

/// <summary>
/// 小数部を切り捨てた値を取得
/// </summary>
/// <param name="value">
/// 小数部を切り捨てる値
/// </param>
/// <returns>
/// 小数部を切り捨てた値
/// </returns>
template <class TFloat>
constexpr TFloat Trunc(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return static_cast<TFloat>(static_cast<I32>(value));
}

/// <summary>
/// 剰余を取得
/// </summary>
/// <param name="value1">
/// 被除数
/// </param>
/// <param name="value2">
/// 除数
/// </param>
/// <returns>
/// 剰余
/// </returns>
template <class TFloat>
constexpr TFloat Mod(TFloat value1, TFloat value2) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return value1 - Trunc(value1 / value2) * value2;
}

/// <summary>
/// 指定された値の小数部を取得
/// </summary>
/// <param name="value">
/// 小数部を取り出す値
/// </param>
/// <returns>
/// value の小数部
/// </returns>
template <class TFloat>
constexpr TFloat Frac(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Abs(Mod(value, static_cast<TFloat>(1)));
}

/// <summary>
/// 指定された値以下の最大の整数部を取得
/// </summary>
/// <param name="value">
/// 整数部を取得する値
/// </param>
/// <returns>
/// 指定された値以下の最大の整数部
/// </returns>
template <class TFloat>
constexpr TFloat Floor(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return value - Frac(value);
}

/// <summary>
/// 指定された値以上の最小の整数値を取得
/// </summary>
/// <param name="value">
/// 指定する値
/// </param>
/// <returns>
/// 指定された値以上の最小の整数値
/// </returns>
template <class TFloat>
constexpr TFloat Ceil(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Floor(value) + static_cast<TFloat>(1);
}

/// <summary>
/// 指定された値に最も近い整数を取得(四捨五入)
/// </summary>
/// <param name="value">
/// 指定する値
/// </param>
/// <returns>
/// 指定された値に最も近い整数
/// </returns>
template <class TFloat>
constexpr TFloat Round(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Floor(value + static_cast<TFloat>(0.5));
}

/// <summary>
/// 角度 f のサインを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のサイン
/// </returns>
template <class TFloat>
TFloat Sin(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::sin(f);
}

/// <summary>
/// 角度 f のコサインを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のコサイン
/// </returns>
template <class TFloat>
TFloat Cos(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::cos(f);
}

/// <summary>
/// 角度 f のタンジェントを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のコサイン
/// </returns>
template <class TFloat>
TFloat Tan(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::tan(f);
}

/// <summary>
/// 角度 f のコセカントを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のコセカント
/// </returns>
template <class TFloat>
TFloat Csc(TFloat f)
{
    return static_cast<TFloat>(1) / Sin(f);
}

/// <summary>
/// 角度 f のセカントを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のセカント
/// </returns>
template <class TFloat>
TFloat Sec(TFloat f)
{
    return static_cast<TFloat>(1) / Cos(f);
}

/// <summary>
/// 角度 f のコタンジェントを取得
/// </summary>
/// <param name="f">
/// 弧度法の入力角度
/// </param>
/// <returns>
/// 角度 f のコタンジェント
/// </returns>
template <class TFloat>
TFloat Cot(TFloat f)
{
    return static_cast<TFloat>(1) / Tan(f);
}

/// <summary>
/// サインが f になる弧度法の角度を取得
/// </summary>
/// <param name="f">
/// 角度を求めたいサイン
/// </param>
/// <returns>
/// サインが f になる弧度法の角度
/// </returns>
template <class TFloat>
TFloat Asin(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::asin(f);
}

/// <summary>
/// コサインが f になる弧度法の角度を取得
/// </summary>
/// <param name="f">
/// 角度を求めたいコサイン
/// </param>
/// <returns>
/// コサインが f になる弧度法の角度
/// </returns>
template <class TFloat>
TFloat Acos(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::acos(f);
}

/// <summary>
/// タンジェントが f になる弧度法の角度を取得
/// </summary>
/// <param name="f">
/// 角度を求めたいタンジェント
/// </param>
/// <returns>
/// タンジェントが f になる弧度法の角度
/// </returns>
template <class TFloat>
TFloat Atan(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::atan(f);
}

/// <summary>
/// タンジェントが y / x になる弧度法の角度を取得
/// </summary>
/// <param name="y">
/// y / x の y
/// </param>
/// <param name="x">
/// y / x の x
/// </param>
/// <returns>
/// タンジェントが y / x になる弧度法の角度
/// </returns>
template <class TFloat>
TFloat Atan2(TFloat y, TFloat x)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::atan2(y, x);
}

/// <summary>
/// 任意の値の平方根を取得
/// </summary>
/// <param name="value">
/// 平方根を取得したい値
/// </param>
/// <returns>
/// 平方根
/// </returns>
template <class TFloat>
constexpr TFloat Sqrt(TFloat value) noexcept
{
    return (IsInf(value) || IsZero(value)) ? value : IsPlus(value) ? Impl::RecursiveBabylonianMethod(value, value / static_cast<TFloat>(2)) : NAN;
}

/// <summary>
/// 任意の値のの立方根を取得
/// </summary>
/// <param name="value">
/// 立方根を取得したい値
/// </param>
/// <returns>
/// 立方根
/// </returns>
template <class TFloat>
TFloat Cbrt(TFloat value)
{
    return std::cbrt(value);
}

/// <summary>
/// 線形補間
/// </summary>
template <class TFloat>
constexpr TFloat Lerp(TFloat value1, TFloat value2, TFloat amount) noexcept
{
    return value1 + (value2 - value1) * amount;
}

/// <summary>
/// Hermite補間
/// </summary>
template <class TFloat>
constexpr TFloat Smoothstep(TFloat value1, TFloat value2, TFloat amount) noexcept
{
    return Lerp(value1, value2, amount * amount * (static_cast<TFloat>(3) - static_cast<TFloat>(2) * amount));
}

} // namespace Math
