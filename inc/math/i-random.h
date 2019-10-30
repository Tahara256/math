#pragma once

#include "use-type.h"

namespace Math
{

/// <summary>
/// 一様分布乱数取得インタフェース
/// </summary>
class IRandom
{

public:

    virtual ~IRandom() = default;

    /// <summary>
    /// [  0,   1] の区間のランダムな 浮動小数点数型 の値を取得
    /// </summary>
    virtual Float Range() = 0;

    /// <summary>
    /// [  0, max] の区間のランダムな 浮動小数点数型 の値を取得
    /// </summary>
    virtual Float Range(Float max) = 0;

    /// <summary>
    /// [min, max] の区間のランダムな 浮動小数点数型 の値を取得
    /// </summary>
    virtual Float Range(Float min, Float max) = 0;

};

} // namespace Math
