#pragma once

namespace Math
{

/// <summary>
/// 二次元ベクトルクラス(整数型)
/// </summary>
template <class TInt>
class Point2
{

public:

    /// <summary>
    /// 各要素を表す型
    /// </summary>
    using Elem = TInt;


    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    constexpr Point2() noexcept : Point2(static_cast<Elem>(0)) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="x">
    /// x 成分
    /// </param>
    /// <param name="y">
    /// y 成分
    /// </param>
    constexpr Point2(Elem x, Elem y) noexcept : m_x(x), m_y(y) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="value">
    /// x 成分と y 成分に割り当てる値
    /// </param>
    constexpr Point2(Elem value) noexcept : Point2(value, value) { }


    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Point2 const operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1 による乗算結果
    /// </returns>
    constexpr Point2 const operator - () const noexcept { return { -GetX(), -GetY() }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 加算後の二次元ベクトル
    /// </returns>
    constexpr Point2 const operator + (Point2 const & rhs) const noexcept { return { GetX() + rhs.GetX(), GetY() + rhs.GetY() }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 減算後の二次元ベクトル
    /// </returns>
    constexpr Point2 const operator - (Point2 const & rhs) const noexcept { return { GetX() - rhs.GetX(), GetY() - rhs.GetY() }; }

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルが等しいか
    /// </returns>
    constexpr bool operator == (Point2 const & rhs) const noexcept { return GetX() == rhs.GetX() && GetY() == rhs.GetY(); }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルが等しくないか
    /// </returns>
    constexpr bool operator != (Point2 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary> 加算代入演算子 </summary>
    /// <param name="rhs">
    /// 加算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Point2 & operator += (Point2 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 減算代入演算子
    /// </returns>
    Point2 & operator -= (Point2 const & rhs) noexcept { return *this = *this - rhs; }


    /// <summary>
    /// X座標を取得
    /// </summary>
    constexpr Elem GetX() const noexcept { return m_x; }

    /// <summary>
    /// Y座標を取得
    /// </summary>
    constexpr Elem GetY() const noexcept { return m_y; }


    /// <summary>
    /// X座標を設定
    /// </summary>
    /// <param name="x">
    /// 設定するX座標
    /// </param>
    void SetX(Elem x) noexcept { m_x = x; }

    /// <summary>
    /// Y座標を設定
    /// </summary>
    /// <param name="y">
    /// 設定するY座標
    /// </param>
    void SetY(Elem y) noexcept { m_y = y; }


    /// <summary>
    /// 小さいほうの要素を持つ二次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// 小さいほうの要素を持つ二次元ベクトル
    /// </returns>
    constexpr Point2 Min(Point2 const & other) const noexcept { return { Math::Min(GetX(), other.GetX()), Math::Min(GetY(), other.GetY()) }; }

    /// <summary>
    /// 大きいほうの要素を持つ二次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// 大きいほうの要素を持つ二次元ベクトル
    /// </returns>
    constexpr Point2 Max(Point2 const & other) const noexcept { return { Math::Max(GetX(), other.GetX()), Math::Max(GetY(), other.GetY()) }; }

    /// <summary>
    /// 下限と上限の範囲に収めた二次元ベクトルを取得
    /// </summary>
    /// <param name="min">
    /// 収める範囲の下限
    /// </param>
    /// <param name="max">
    /// 収める範囲の上限
    /// </param>
    /// <returns>
    /// 下限と上限の範囲に収めた二次元ベクトル
    /// </returns>
    constexpr Point2 Clamp(Point2 const & min, Point2 const & max) const noexcept { return min.Max(max.Min(*this)); }

    /// <summary>
    /// 下限と上限の範囲内かを取得
    /// </summary>
    /// <param name="min">
    /// 範囲の下限
    /// </param>
    /// <param name="max">
    /// 範囲の上限
    /// </param>
    /// <returns>
    /// 下限と上限の範囲内か
    /// </returns>
    constexpr bool InRange(Point2 const & min, Point2 const & max) const noexcept { return Math::InRange(GetX(), min.GetX(), max.GetX()) && Math::InRange(GetY(), min.GetY(), max.GetY()); }

private:

    /// <summary>
    /// x 成分
    /// </summary>
    Elem m_x;

    /// <summary>
    /// y 成分
    /// </summary>
    Elem m_y;

};

} // namespace Math
