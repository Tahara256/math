#pragma once

#include "use-type.h"

namespace Math
{

/// <summary>
/// 矩形の大きさを表すクラス
/// </summary>
template <class T>
class RectSize
{

public:

    /// <summary>
    /// 幅と高さの大きさを表す型
    /// </summary>
    using Elem = T;


    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="width">
    /// 幅
    /// </param>
    /// <param name="height">
    /// 高さ
    /// </param>
    constexpr RectSize(Elem width, Elem height) noexcept : m_width(width), m_height(height) { }


    /// <summary>
    /// 幅を取得
    /// </summary>
    constexpr Elem GetWidth() const noexcept { return m_width; }

    /// <summary>
    /// 高さを取得
    /// </summary>
    constexpr Elem GetHeight() const noexcept { return m_height; }


    /// <summary>
    /// 幅を設定
    /// </summary>
    /// <param name="width">
    /// 幅
    /// </param>
    void SetWidth(Elem width) noexcept { m_width = width; }

    /// <summary>
    /// 高さを設定
    /// </summary>
    /// <param name="height">
    /// 高さ
    /// </param>
    void SetHeight(Elem height) noexcept { m_height = height; }


    /// <summary>
    /// アスペクト比を取得
    /// </summary>
    /// <returns>
    /// アスペクト比
    /// </returns>
    constexpr Float GetAspect() const noexcept { return static_cast<Float>(GetWidth()) / GetHeight(); }

private:

    /// <summary>
    /// 幅
    /// </summary>
    Elem m_width;

    /// <summary>
    /// 高さ
    /// </summary>
    Elem m_height;

};

} // namespace Math
