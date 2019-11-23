#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// R, G, B それぞれ 任意の浮動小数点数型 であらわされた色情報クラス
/// </summary>
class Color3F
{

public:

    /// <summary>
    /// 色の要素を表す型
    /// </summary>
    using Elem = Float;

    /// <summary>
    /// スカラー倍で使用する実数型
    /// </summary>
    using Scalar = Float;


    /// <summary>
    /// デフォルトコンストラクタ
    /// R, G, B それぞれ最大値
    /// </summary>
    Color3F() : Color3F(
        static_cast<Elem>(1),
        static_cast<Elem>(1),
        static_cast<Elem>(1)
    )
    {
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="r">
    /// Red要素
    /// </param>
    /// <param name="g">
    /// Green要素
    /// </param>
    /// <param name="b">
    /// Blue要素
    /// </param>
    constexpr Color3F(Elem r, Elem g, Elem b) noexcept
        : m_r(r)
        , m_g(g)
        , m_b(b)
    {
    }

    /// <summary>
    /// Red要素を取得
    /// </summary>
    constexpr Elem GetR() const noexcept { return m_r; }

    /// <summary>
    /// Green要素を取得
    /// </summary>
    constexpr Elem GetG() const noexcept { return m_g; }

    /// <summary>
    /// Blue要素を取得
    /// </summary>
    constexpr Elem GetB() const noexcept { return m_b; }

    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Color3F operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1による乗算結果
    /// </returns>
    constexpr Color3F operator - () const noexcept { return { -GetR(), -GetG(), -GetB() }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する色
    /// </param>
    /// <returns>
    /// 加算後の色
    /// </returns>
    constexpr Color3F operator + (Color3F const & rhs) const noexcept { return { GetR() + rhs.GetR(), GetG() + rhs.GetG(), GetB() + rhs.GetB() }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する色
    /// </param>
    /// <returns>
    /// 減算後の色
    /// </returns>
    constexpr Color3F operator - (Color3F const & rhs) const noexcept { return { GetR() - rhs.GetR(), GetG() - rhs.GetG(), GetB() - rhs.GetB() }; }

    /// <summary>
    /// アダマール積(成分毎に乗算)
    /// </summary>
    /// <param name="rhs">
    /// 乗算する色
    /// </param>
    /// <returns>
    /// 乗算後の色
    /// </returns>
    constexpr Color3F operator * (Color3F const & rhs) const noexcept { return { GetR() * rhs.GetR(), GetG() * rhs.GetG(), GetB() * rhs.GetB() }; }

    /// <summary>
    /// 逆数要素とのアダマール積(成分毎に除算)
    /// </summary>
    /// <param name="rhs">
    /// 除算する色
    /// </param>
    /// <returns>
    /// 除算後の色
    /// </returns>
    constexpr Color3F operator / (Color3F const & rhs) const noexcept { return { GetR() / rhs.GetR(), GetG() / rhs.GetG(), GetB() / rhs.GetB() }; }


    /// <summary>
    /// スカラーとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// 乗算後の色
    /// </returns>
    constexpr Color3F operator * (Scalar rhs) const noexcept { return { GetR() * rhs, GetG() * rhs, GetB() * rhs }; }

    /// <summary>
    /// スカラーとの除算演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// 除算後の色
    /// </returns>
    constexpr Color3F operator / (Scalar rhs) const noexcept { return { GetR() / rhs, GetG() / rhs, GetB() / rhs }; }


    /// <summary>
    /// 加算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する色
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Color3F & operator += (Color3F const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する色
    /// </param>
    /// <returns>
    /// 減算代入後の自身への参照
    /// </returns>
    Color3F & operator -= (Color3F const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// スカラーとの乗算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算代入後の自身への参照
    /// </returns>
    Color3F & operator *= (Scalar rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// スカラーとの除算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算代入後の自身への参照
    /// </returns>
    Color3F & operator /= (Scalar rhs) noexcept { return *this = *this / rhs; }


    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の色
    /// </param>
    /// <returns>
    /// 二つの色が等しいか
    /// </returns>
    constexpr bool operator == (Color3F const & rhs) const noexcept { return GetR() == rhs.GetR() && GetG() == rhs.GetG() && GetB() == rhs.GetB(); }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の色
    /// </param>
    /// <returns>
    /// 二つの色が等しくないか
    /// </returns>
    constexpr bool operator != (Color3F const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// リニア空間からsRGB空間に変換
    /// </summary>
    /// <param name="gammaFactor">
    /// ガンマ係数
    /// </param>
    /// <returns>
    /// sRGB空間に変換後の色
    /// </returns>
    Color3F ToGamma(Scalar gammaFactor) const
    {
        auto recipGammaFactor = Math::Recip(gammaFactor);
        return { Math::Pow(GetR(), recipGammaFactor), Math::Pow(GetG(), recipGammaFactor), Math::Pow(GetB(), recipGammaFactor) };
    }

    /// <summary>
    /// sRGB空間からリニア空間に変換
    /// </summary>
    /// <param name="gammaFactor">
    /// ガンマ係数
    /// </param>
    /// <returns>
    /// リニア空間に変換後の色
    /// </returns>
    Color3F ToLinear(Scalar gammaFactor) const
    {
        return { Math::Pow(GetR(), gammaFactor), Math::Pow(GetG(), gammaFactor), Math::Pow(GetB(), gammaFactor) };
    }

private:

    /// <summary>
    /// Red要素
    /// </summary>
    Elem m_r;

    /// <summary>
    /// Green要素
    /// </summary>
    Elem m_g;

    /// <summary>
    /// Blue要素
    /// </summary>
    Elem m_b;

};

/// <summary>
/// スカラーとの乗算演算子
/// </summary>
/// <param name="lhs">
/// 乗算するスカラー
/// </param>
/// <param name="rhs">
/// 乗算される色
/// </param>
/// <returns>
/// 乗算後の色
/// </returns>
constexpr Color3F operator * (Color3F::Scalar lhs, Color3F const & rhs) noexcept { return { rhs * lhs }; }

/// <summary>
/// スカラーとの除算演算子
/// </summary>
/// <param name="lhs">
/// 除算するスカラー
/// </param>
/// <param name="rhs">
/// 乗算される色
/// </param>
/// <returns>
/// 除算後の色
/// </returns>
constexpr Color3F operator / (Color3F::Scalar lhs, Color3F const & rhs) noexcept { return { lhs / rhs.GetR(), lhs / rhs.GetG(), lhs / rhs.GetB() }; }

/// <summary>
/// シフト演算子
/// 出力ストリームに色を渡す
/// </summary>
std::ostream & operator << (std::ostream & lhs, Color3F const & rhs);

} // namespace Math
