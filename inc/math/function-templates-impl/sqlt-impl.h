#pragma once

namespace Math
{

namespace Impl
{

/// <summary>
/// 再帰で「バビロニアの平方根」を使用して平方根を求める
/// </summary>
/// <param name="value">
/// 平方根を取得したい値
/// </param>
/// <param name="previous">
/// 平方根になるべく近い値(このパラメータが再帰ごとに平方根に近づく)
/// </param>
/// <returns>
/// 平方根
/// </returns>
template <class TFloat>
constexpr TFloat RecursiveBabylonianMethod(TFloat value, TFloat previous) noexcept
{
    auto const result = ((previous + value / previous) / static_cast<TFloat>(2));
    return result == previous ? result : RecursiveBabylonianMethod(value, result);
}

} // namespace Impl

} // namespace Math
