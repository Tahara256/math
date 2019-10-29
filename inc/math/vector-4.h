#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// 四次元ベクトルクラス(浮動小数点数型)
/// </summary>
class Vector4
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// x 成分
            /// </summary>
            Float x;
            /// <summary>
            /// y 成分
            /// </summary>
            Float y;
            /// <summary>
            /// z 成分
            /// </summary>
            Float z;
            /// <summary>
            /// w 成分
            /// </summary>
            Float w;
        };
        Float _[4];
    };

    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    constexpr Vector4() noexcept : Vector4(static_cast<Float>(0)) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="x">
    /// x 成分
    /// </param>
    /// <param name="y">
    /// y 成分
    /// </param>
    /// <param name="z">
    /// z 成分
    /// </param>
    /// <param name="w">
    /// w 成分
    /// </param>
    constexpr Vector4(Float x, Float y, Float z, Float w) noexcept : x(x), y(y), z(z), w(w) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="value">
    /// xyzw 成分全てに割り当てる値
    /// </param>
    constexpr explicit Vector4(Float value) noexcept : Vector4(value, value, value, value) { }

    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Vector4 const operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1による乗算結果
    /// </returns>
    constexpr Vector4 const operator - () const noexcept { return { -x, -y, -z, -w }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する四次元ベクトル
    /// </param>
    /// <returns>
    /// 加算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator + (Vector4 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する四次元ベクトル
    /// </param>
    /// <returns>
    /// 減算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator - (Vector4 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }

    /// <summary>
    /// アダマール積(成分毎に乗算)
    /// </summary>
    /// <param name="rhs">
    /// 乗算する四次元ベクトル
    /// </param>
    /// <returns>
    /// 乗算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator * (Vector4 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w }; }

    /// <summary>
    /// 逆数要素とのアダマール積(成分毎に除算)
    /// </summary>
    /// <param name="rhs">
    /// 除算する四次元ベクトル 
    /// </param>
    /// <returns>
    /// 除算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator / (Vector4 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w }; }

    /// <summary>
    /// スカラーとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// 乗算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs, w * rhs }; }

    /// <summary>
    /// スカラーとの除算演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// 除算後の四次元ベクトル
    /// </returns>
    constexpr Vector4 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の四次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの四次元ベクトルが等しいか
    /// </returns>
    constexpr bool operator == (Vector4 const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の四次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの四次元ベクトルが等しくないか
    /// </returns>
    constexpr bool operator != (Vector4 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// 加算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する四次元ベクトル
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Vector4 & operator += (Vector4 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する四次元ベクトル
    /// </param>
    /// <returns>
    /// 減算代入後の自身への参照
    /// </returns>
    Vector4 & operator -= (Vector4 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// スカラーとの乗算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算代入後の自身への参照
    /// </returns>
    Vector4 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// スカラーとの除算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算代入後の自身への参照
    /// </returns>
    Vector4 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分への参照
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// 二つの四次元ベクトルがほぼ等しいかを取得
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の四次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの四次元ベクトルがほぼ等しいか
    /// </returns>
    constexpr bool Approximately(Vector4 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y) && Math::Approximately(z, rhs.z) && Math::Approximately(w, rhs.w); }

    /// <summary>
    /// 二つの四次元ベクトルの内積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドの四次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの四次元ベクトルの内積
    /// </returns>
    constexpr Float Dot(Vector4 const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

    /// <summary>
    /// 四次元ベクトルの長さを取得
    /// </summary>
    /// <returns>
    /// 四次元ベクトルの長さ
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// 四次元ベクトルの長さの二乗を取得
    /// </summary>
    /// <returns>
    /// 四次元ベクトルの長さの二乗
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// もう一方の四次元ベクトルとの距離を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の四次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の四次元ベクトルとの距離
    /// </returns>
    constexpr Float Distance(Vector4 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// もう一方の四次元ベクトルとの距離の二乗を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の四次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の四次元ベクトルとの距離の二乗
    /// </returns>
    constexpr Float DistanceSquared(Vector4 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// 正規化した四次元ベクトルを取得
    /// </summary>
    /// <returns>
    /// 正規化した四次元ベクトル
    /// </returns>
    constexpr Vector4 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector4(); }

    /// <summary>
    /// 正規化
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// { 0, 0, 0, 0 }
    /// </summary>
    static Vector4 const Zero;

    /// <summary>
    /// { 1, 1, 1, 1 }
    /// </summary>
    static Vector4 const One;

    /// <summary>
    /// { 1, 0, 0, 0 }
    /// </summary>
    static Vector4 const UnitX;

    /// <summary>
    /// { 0, 1, 0, 0 }
    /// </summary>
    static Vector4 const UnitY;

    /// <summary>
    /// { 0, 0, 1, 0 }
    /// </summary>
    static Vector4 const UnitZ;

    /// <summary>
    /// { 0, 0, 0, 1 }
    /// </summary>
    static Vector4 const UnitW;
};

/// <summary>
/// スカラーとの乗算演算子
/// </summary>
/// <param name="lhs">
/// 乗算するスカラー
/// </param>
/// <param name="rhs">
/// 乗算される四次元ベクトル
/// </param>
/// <returns>
/// 乗算後の四次元ベクトル
/// </returns>
constexpr Vector4 const operator * (Float lhs, Vector4 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// 出力ストリームに四次元ベクトルを渡す
/// </summary>
std::ostream & operator << (std::ostream & os, Vector4 const & v);

} // namespace Math
