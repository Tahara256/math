#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// 二次元ベクトルクラス(浮動小数点数型)
/// </summary>
class Vector2
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// x成分
            /// </summary>
            Float x;
            /// <summary>
            /// y成分
            /// </summary>
            Float y;
        };
        struct
        {
            /// <summary>
            /// u成分
            /// </summary>
            Float u;
            /// <summary>
            /// rhs成分
            /// </summary>
            Float v;
        };
        struct
        {
            /// <summary>
            /// 幅
            /// </summary>
            Float width;
            /// <summary>
            /// 高さ
            /// </summary>
            Float height;
        };
        Float _[3];
    };

    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    constexpr Vector2() noexcept : Vector2(static_cast<Float>(0)) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="x">
    /// x 成分
    /// </param>
    /// <param name="y">
    /// y 成分
    /// </param>
    constexpr Vector2(Float x, Float y) noexcept : x(x), y(y) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="value">
    /// x 成分と y 成分に割り当てる値
    /// </param>
    constexpr explicit Vector2(Float value) noexcept : Vector2(value, value) { }

    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Vector2 const operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1 による乗算結果
    /// </returns>
    constexpr Vector2 const operator - () const noexcept { return { -x, -y }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 加算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator + (Vector2 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 減算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator - (Vector2 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y }; }

    /// <summary>
    /// アダマール積(成分毎に乗算)
    /// </summary>
    /// <param name="rhs">
    /// 乗算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 乗算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator * (Vector2 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y }; }

    /// <summary>
    /// 逆数要素とのアダマール積(成分毎に除算)
    /// </summary>
    /// <param name="rhs">
    /// 除算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 除算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator / (Vector2 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y }; }

    /// <summary>
    /// スカラーとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// 乗算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs }; }

    /// <summary>
    /// スカラーとの除算演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// 除算後の二次元ベクトル
    /// </returns>
    constexpr Vector2 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs }; }

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルが等しいか
    /// </returns>
    constexpr bool operator == (Vector2 const & rhs) const noexcept { return x == rhs.x && y == rhs.y; }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルが等しくないか
    /// </returns>
    constexpr bool operator != (Vector2 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// 加算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Vector2 & operator += (Vector2 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する二次元ベクトル
    /// </param>
    /// <returns>
    /// 減算代入演算子
    /// </returns>
    Vector2 & operator -= (Vector2 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// スカラーとの乗算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算代入後の自身への参照
    /// </returns>
    Vector2 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// スカラーとの除算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算代入後の自身への参照
    /// </returns>
    Vector2 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 1)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分への参照
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 1)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// 二つの二次元ベクトルがほぼ等しいかを取得
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルがほぼ等しいか
    /// </returns>
    constexpr bool Approximately(Vector2 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y); }

    /// <summary>
    /// 二つの二次元ベクトルの内積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドの二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルの内積
    /// </returns>
    constexpr Float Dot(Vector2 const & rhs) const noexcept { return x * rhs.x + y * rhs.y; }

    /// <summary>
    /// 二つの二次元ベクトルの外積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドの二次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルの外積
    /// </returns>
    constexpr Float Cross(Vector2 const & rhs) const noexcept { return x * rhs.y - y * rhs.x; }

    /// <summary>
    /// 二次元ベクトルの長さを取得
    /// </summary>
    /// <returns>
    /// 二次元ベクトルの長さ
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// 二次元ベクトルの長さの二乗を取得
    /// </summary>
    /// <returns>
    /// 二次元ベクトルの長さの二乗
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// もう一方の二次元ベクトルとの距離を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の二次元ベクトルとの距離
    /// </returns>
    constexpr Float Distance(Vector2 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// もう一方の二次元ベクトルとの距離の二乗を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の二次元ベクトルとの距離の二乗
    /// </returns>
    constexpr Float DistanceSquared(Vector2 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// もう一方の二次元ベクトルとのなす角(符号なし)を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の二次元ベクトルとのなす角(符号なし)
    /// </returns>
    Float Angle(Vector2 const & other) const { return Math::Acos(Normalized().Dot(other.Normalized())); }

    /// <summary>
    /// 法線を基準に反射した二次元ベクトルを取得
    /// </summary>
    /// <param name="normal">
    /// 法線ベクトル
    /// </param>
    /// <returns>
    /// 法線を基準に反射した二次元ベクトル
    /// </returns>
    constexpr Vector2 const Reflect(Vector2 const & normal) const noexcept { auto n = normal.Normalized(); return *this + n * 2 * Dot(-n); }

    /// <summary>
    /// 正規化した二次元ベクトルを取得
    /// </summary>
    /// <returns>
    /// 正規化した二次元ベクトル
    /// </returns>
    constexpr Vector2 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector2(); }

    /// <summary>
    /// 正規化
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// 二つの二次元ベクトルを線形補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つの二次元ベクトルの補間値
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルの間の線形補間された二次元ベクトル
    /// </returns>
    constexpr Vector2 const Lerp(Vector2 const & other, Float t) const noexcept { return { Math::Lerp(x, other.x, t), Math::Lerp(y, other.y, t) }; }

    /// <summary>
    /// 二つの二次元ベクトルをHermite補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つの二次元ベクトルの補間値
    /// </param>
    /// <returns>
    /// 二つの二次元ベクトルの間のHermite補間された二次元ベクトル
    /// </returns>
    constexpr Vector2 const SmoothStep(Vector2 const & other, Float t) const noexcept { return { Math::Smoothstep(x, other.x, t), Math::Smoothstep(y, other.y, t) }; }

    /// <summary>
    /// 小さいほうの要素を持つ二次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// 小さいほうの要素を持つ二次元ベクトル
    /// </returns>
    constexpr Vector2 const Min(Vector2 const & other) const { return { Math::Min(x, other.x), Math::Min(y, other.y) }; }

    /// <summary>
    /// 大きいほうの要素を持つ二次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の二次元ベクトル
    /// </param>
    /// <returns>
    /// 大きいほうの要素を持つ二次元ベクトル
    /// </returns>
    constexpr Vector2 const Max(Vector2 const & other) const { return { Math::Max(x, other.x), Math::Max(y, other.y) }; }

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
    constexpr Vector2 const Clamp(Vector2 const & min, Vector2 const & max) const { return min.Max(max.Min(*this)); }

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
    constexpr bool InRange(Vector2 const & min, Vector2 const & max) const { return Math::InRange(x, min.x, max.x) && Math::InRange(y, min.y, max.y); }

    /// <summary>
    /// 目的地への三次元距離ベクトルを取得
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <returns>
    /// 目的地への三次元ベクトル
    /// </returns>
    constexpr Vector2 const To(Vector2 const & target) const noexcept { return target - *this; }

    /// <summary>
    /// 目的地への三次元単位ベクトルを取得
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <returns>
    /// 目的地への三次元単位ベクトル
    /// </returns>
    constexpr Vector2 const Direction(Vector2 const & target) const noexcept { return To(target).Normalized(); }

    /// <summary>
    /// 目的地へ移動(目的地を通り過ぎない)
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <param name="speed">
    /// 最大速度
    /// </param>
    void MoveTowards(Vector2 const & target, float speed) noexcept { *this += Direction(target) * Math::Min(speed, Distance(target)); }

    /// <summary>
    /// アスペクト比を取得
    /// </summary>
    /// <returns>
    /// アスペクト比
    /// </returns>
    constexpr Float Aspect() const noexcept { return width / height; }

    /// <summary>
    /// 零ベクトルかを取得
    /// </summary>
    /// <returns>
    /// 零ベクトルか
    /// </returns>
    constexpr bool IsZero() const noexcept { return x == static_cast<Float>(0) && y == static_cast<Float>(0); }

    /// <summary>
    /// { x, x }
    /// </summary>
    constexpr Vector2 const xx() const noexcept { return { x, x }; }

    /// <summary>
    /// { x, y }
    /// </summary>
    constexpr Vector2 const xy() const noexcept { return { x, y }; }

    /// <summary>
    /// { y, x }
    /// </summary>
    constexpr Vector2 const yx() const noexcept { return { y, x }; }

    /// <summary>
    /// { y, y }
    /// </summary>
    constexpr Vector2 const yy() const noexcept { return { y, y }; }

    /// <summary>
    /// {  0,  0 }
    /// </summary>
    static Vector2 const Zero;

    /// <summary>
    /// {  1,  1 }
    /// </summary>
    static Vector2 const One;

    /// <summary>
    /// {  1,  0 }
    /// </summary>
    static Vector2 const UnitX;

    /// <summary>
    /// {  0,  1 }
    /// </summary>
    static Vector2 const UnitY;

    /// <summary>
    /// { -1,  0 }
    /// </summary>
    static Vector2 const Left;

    /// <summary>
    /// {  1,  0 }
    /// </summary>
    static Vector2 const Right;

    /// <summary>
    /// {  0, -1 }
    /// </summary>
    static Vector2 const Up;

    /// <summary>
    /// {  0,  1 }
    /// </summary>
    static Vector2 const Down;

};

/// <summary>
/// スカラーとの乗算演算子
/// </summary>
/// <param name="lhs">
/// 乗算するスカラー
/// </param>
/// <param name="rhs">
/// 乗算される二次元ベクトル
/// </param>
/// <returns>
/// 乗算後の二次元ベクトル
/// </returns>
constexpr Vector2 const operator * (Float lhs, Vector2 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// 出力ストリームに二次元ベクトルを渡す
/// </summary>
std::ostream & operator << (std::ostream & os, Vector2 const & v);

} // namespace Math
