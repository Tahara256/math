#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// 三次元ベクトルクラス(浮動小数点数型)
/// </summary>
class Vector3
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
        };
        Float _[3];
    };

    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    constexpr Vector3() noexcept : Vector3(static_cast<Float>(0)) { }

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
    constexpr Vector3(Float x, Float y, Float z) noexcept : x(x), y(y), z(z) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="value">
    /// xyz 成分全てに割り当てる値
    /// </param>
    constexpr explicit Vector3(Float value) noexcept : Vector3(value, value, value) { }

    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Vector3 const operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1による乗算結果
    /// </returns>
    constexpr Vector3 const operator - () const noexcept { return { -x, -y, -z }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 加算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator + (Vector3 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 減算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator - (Vector3 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z }; }

    /// <summary>
    /// アダマール積(成分毎に乗算)
    /// </summary>
    /// <param name="rhs">
    /// 乗算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 乗算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator * (Vector3 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y, z * rhs.z }; }

    /// <summary>
    /// 逆数要素とのアダマール積(成分毎に除算)
    /// </summary>
    /// <param name="rhs">
    /// 除算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 除算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator / (Vector3 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y, z / rhs.z }; }

    /// <summary>
    /// スカラーとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// 乗算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs }; }

    /// <summary>
    /// スカラーとの除算演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// 除算後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs }; }

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の三次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルが等しいか
    /// </returns>
    constexpr bool operator == (Vector3 const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z; }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の三次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルが等しくないか
    /// </returns>
    constexpr bool operator != (Vector3 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// 加算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Vector3 & operator += (Vector3 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算する三次元ベクトル
    /// </param>
    /// <returns>
    /// 減算代入後の自身への参照
    /// </returns>
    Vector3 & operator -= (Vector3 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// スカラーとの乗算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算代入後の自身への参照
    /// </returns>
    Vector3 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// スカラーとの除算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算代入後の自身への参照
    /// </returns>
    Vector3 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 2)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分への参照
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 2)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// 二つの三次元ベクトルがほぼ等しいかを取得
    /// </summary>
    /// <param name="rhs">
    /// 比較対象の三次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルがほぼ等しいか
    /// </returns>
    constexpr bool Approximately(Vector3 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y) && Math::Approximately(z, rhs.z); }

    /// <summary>
    /// 二つの三次元ベクトルの内積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドの三次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルの内積
    /// </returns>
    constexpr Float Dot(Vector3 const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z; }

    /// <summary>
    /// 二つの三次元ベクトルの外積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドの三次元ベクトル
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルの外積
    /// </returns>
    constexpr Vector3 const Cross(Vector3 const & rhs) const noexcept { return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x }; }

    /// <summary>
    /// 三次元ベクトルの長さを取得
    /// </summary>
    /// <returns>
    /// 三次元ベクトルの長さ
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// 三次元ベクトルの長さの二乗を取得
    /// </summary>
    /// <returns>
    /// 三次元ベクトルの長さの二乗
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// もう一方の三次元ベクトルとの距離を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の三次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の三次元ベクトルとの距離
    /// </returns>
    constexpr Float Distance(Vector3 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// もう一方の三次元ベクトルとの距離の二乗を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の三次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の三次元ベクトルとの距離の二乗
    /// </returns>
    constexpr Float DistanceSquared(Vector3 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// もう一方の三次元ベクトルとのなす角(符号なし)を取得
    /// </summary>
    /// <param name="other">
    /// もう一方の三次元ベクトル
    /// </param>
    /// <returns>
    /// もう一方の三次元ベクトルとのなす角(符号なし)
    /// </returns>
    Float Angle(Vector3 const & other) const { return Math::Acos(Normalized().Dot(other.Normalized())); }

    /// <summary>
    /// 法線を基準に反射した三次元ベクトルを取得
    /// </summary>
    /// <param name="normal">
    /// 法線ベクトル
    /// </param>
    /// <returns>
    /// 法線を基準に反射した三次元ベクトル
    /// </returns>
    constexpr Vector3 const Reflect(Vector3 const & normal) const noexcept { return ReflectUnitNormal(normal.Normalized()); }

    /// <summary>
    /// 正規化された法線を基準に反射した三次元ベクトルを取得
    /// </summary>
    /// <param name="unitNormal">
    /// 正規化された法線ベクトル
    /// </param>
    /// <returns>
    /// 正規化された法線を基準に反射した三次元ベクトル
    /// </returns>
    constexpr Vector3 const ReflectUnitNormal(Vector3 const & unitNormal) const noexcept { return *this + unitNormal * static_cast<Float>(2) * Dot(-unitNormal); }

    /// <summary>
    /// 正規化した三次元ベクトルを取得
    /// </summary>
    /// <returns>
    /// 正規化した三次元ベクトル
    /// </returns>
    constexpr Vector3 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector3(); }

    /// <summary>
    /// 正規化
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// 二つの三次元ベクトルを線形補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つの三次元ベクトルの補間値
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルの間の線形補間された三次元ベクトル
    /// </returns>
    constexpr Vector3 const Lerp(Vector3 const & other, Float t) const noexcept { return { Math::Lerp(x, other.x, t), Math::Lerp(y, other.y, t), Math::Lerp(z, other.z, t) }; }

    /// <summary>
    /// 二つの三次元ベクトルをHermite補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つの三次元ベクトルの補間値
    /// </param>
    /// <returns>
    /// 二つの三次元ベクトルの間のHermite補間された三次元ベクトル
    /// </returns>
    constexpr Vector3 const SmoothStep(Vector3 const & other, Float t) const noexcept { return { Math::Smoothstep(x, other.x, t), Math::Smoothstep(y, other.y, t), Math::Smoothstep(z, other.z, t) }; }

    /// <summary>
    /// 小さいほうの要素を持つ三次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の三次元ベクトル
    /// </param>
    /// <returns>
    /// 小さいほうの要素を持つ三次元ベクトル
    /// </returns>
    constexpr Vector3 const Min(Vector3 const & other) const noexcept { return { Math::Min(x, other.x), Math::Min(y, other.y), Math::Min(z, other.z) }; }

    /// <summary>
    /// 大きいほうの要素を持つ三次元ベクトルを取得
    /// </summary>
    /// <param name="other">
    /// もう一方の三次元ベクトル
    /// </param>
    /// <returns>
    /// 大きいほうの要素を持つ三次元ベクトル
    /// </returns>
    constexpr Vector3 const Max(Vector3 const & other) const noexcept { return { Math::Max(x, other.x), Math::Max(y, other.y), Math::Max(z, other.z) }; }

    /// <summary>
    /// 下限と上限の範囲に収めた三次元ベクトルを取得
    /// </summary>
    /// <param name="min">
    /// 収める範囲の下限
    /// </param>
    /// <param name="max">
    /// 収める範囲の上限
    /// </param>
    /// <returns>
    /// 下限と上限の範囲に収めた三次元ベクトル
    /// </returns>
    constexpr Vector3 const Clamp(Vector3 const & min, Vector3 const & max) const noexcept { return min.Max(max.Min(*this)); }

    /// <summary>
    /// 目的地への三次元距離ベクトルを取得
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <returns>
    /// 目的地への三次元ベクトル
    /// </returns>
    constexpr Vector3 const To(Vector3 const & target) const noexcept { return target - *this; }

    /// <summary>
    /// 目的地への三次元単位ベクトルを取得
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <returns>
    /// 目的地への三次元単位ベクトル
    /// </returns>
    constexpr Vector3 const Direction(Vector3 const & target) const noexcept { return To(target).Normalized(); }

    /// <summary>
    /// 目的地へ移動させた座標を取得(目的地を通り過ぎない)
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <param name="speed">
    /// 最大速度
    /// </param>
    /// <returns>
    /// 目的地へ移動させた座標
    /// </returns>
    constexpr Vector3 const MovedTowards(Vector3 const & target, Float speed) const noexcept { return *this + Direction(target) * Math::Min(Distance(target), speed); }

    /// <summary>
    /// 目的地へ移動(目的地を通り過ぎない)
    /// </summary>
    /// <param name="target">
    /// 目的地
    /// </param>
    /// <param name="speed">
    /// 最大速度
    /// </param>
    void MoveTowards(Vector3 const & target, Float speed) noexcept { *this = MovedTowards(target, speed); }

    /// <summary>
    /// 各要素を弧度法から度数法へ変換した三次元ベクトルを取得
    /// </summary>
    /// <returns>
    /// 各要素を弧度法から度数法へ変換した三次元ベクトル
    /// </returns>
    constexpr Vector3 const ToDegrees() const noexcept { return { Math::ToDegrees(x), Math::ToDegrees(y), Math::ToDegrees(z) }; }

    /// <summary>
    /// 各要素を度数法から弧度法へ変換した三次元ベクトルを取得
    /// </summary>
    /// <returns>
    /// 各要素を度数法から弧度法へ変換した三次元ベクトル
    /// </returns>
    constexpr Vector3 const ToRadians() const noexcept { return { Math::ToRadians(x), Math::ToRadians(y), Math::ToRadians(z) }; }

    /// <summary>
    /// 零ベクトルかを取得
    /// </summary>
    /// <returns>
    /// 零ベクトルか
    /// </returns>
    constexpr bool IsZero() const noexcept { return x == static_cast<Float>(0) && y == static_cast<Float>(0); }

    /// <summary>
    /// { x, x, x }
    /// </summary>
    constexpr Vector3 const xxx() const noexcept { return { x, x, x }; }

    /// <summary>
    /// { x, x, y }
    /// </summary>
    constexpr Vector3 const xxy() const noexcept { return { x, x, y }; }

    /// <summary>
    /// { x, x, z }
    /// </summary>
    constexpr Vector3 const xxz() const noexcept { return { x, x, z }; }

    /// <summary> 
    /// { x, y, x }
    /// </summary>
    constexpr Vector3 const xyx() const noexcept { return { x, y, x }; }

    /// <summary> 
    /// { x, y, y }
    /// </summary>
    constexpr Vector3 const xyy() const noexcept { return { x, y, y }; }

    /// <summary>
    /// { x, y, z }
    /// </summary>
    constexpr Vector3 const xyz() const noexcept { return { x, y, z }; }

    /// <summary>
    /// { x, z, x }
    /// </summary>
    constexpr Vector3 const xzx() const noexcept { return { x, z, x }; }

    /// <summary>
    /// { x, z, y }
    /// </summary>
    constexpr Vector3 const xzy() const noexcept { return { x, z, y }; }

    /// <summary>
    /// { x, z, z }
    /// </summary>
    constexpr Vector3 const xzz() const noexcept { return { x, z, z }; }

    /// <summary>
    /// { y, x, x }
    /// </summary>
    constexpr Vector3 const yxx() const noexcept { return { y, x, x }; }

    /// <summary>
    /// { y, x, y }
    /// </summary>
    constexpr Vector3 const yxy() const noexcept { return { y, x, y }; }

    /// <summary>
    /// { y, x, z }
    /// </summary>
    constexpr Vector3 const yxz() const noexcept { return { y, x, z }; }

    /// <summary>
    /// { y, y, x }
    /// </summary>
    constexpr Vector3 const yyx() const noexcept { return { y, y, x }; }

    /// <summary>
    /// { y, y, y }
    /// </summary>
    constexpr Vector3 const yyy() const noexcept { return { y, y, y }; }

    /// <summary>
    /// { y, y, z }
    /// </summary>
    constexpr Vector3 const yyz() const noexcept { return { y, y, z }; }

    /// <summary>
    /// { y, z, x }
    /// </summary>
    constexpr Vector3 const yzx() const noexcept { return { y, z, x }; }

    /// <summary>
    /// { y, z, y }
    /// </summary>
    constexpr Vector3 const yzy() const noexcept { return { y, z, y }; }

    /// <summary>
    /// { y, z, z }
    /// </summary>
    constexpr Vector3 const yzz() const noexcept { return { y, z, z }; }

    /// <summary>
    /// { z, x, x }
    /// </summary>
    constexpr Vector3 const zxx() const noexcept { return { z, x, x }; }

    /// <summary>
    /// { z, x, y }
    /// </summary>
    constexpr Vector3 const zxy() const noexcept { return { z, x, y }; }

    /// <summary>
    /// { z, x, z }
    /// </summary>
    constexpr Vector3 const zxz() const noexcept { return { z, x, z }; }

    /// <summary>
    /// { z, y, x }
    /// </summary>
    constexpr Vector3 const zyx() const noexcept { return { z, y, x }; }

    /// <summary>
    /// { z, y, y }
    /// </summary>
    constexpr Vector3 const zyy() const noexcept { return { z, y, y }; }

    /// <summary>
    /// { z, y, z }
    /// </summary>
    constexpr Vector3 const zyz() const noexcept { return { z, y, z }; }

    /// <summary>
    /// { z, z, x }
    /// </summary>
    constexpr Vector3 const zzx() const noexcept { return { z, z, x }; }

    /// <summary>
    /// { z, z, y }
    /// </summary>
    constexpr Vector3 const zzy() const noexcept { return { z, z, y }; }

    /// <summary>
    /// { z, z, z }
    /// </summary>
    constexpr Vector3 const zzz() const noexcept { return { z, z, z }; }

    /// <summary>
    /// {  0,  0,  0 }
    /// </summary>
    static Vector3 const Zero;

    /// <summary>
    /// {  1,  1,  1 }
    /// </summary>
    static Vector3 const One;

    /// <summary>
    /// {  1,  0,  0 }
    /// </summary>
    static Vector3 const UnitX;

    /// <summary>
    /// {  0,  1,  0 }
    /// </summary>
    static Vector3 const UnitY;

    /// <summary>
    /// {  0,  0,  1 }
    /// </summary>
    static Vector3 const UnitZ;

    /// <summary>
    /// { -1,  0,  0 }
    /// </summary>
    static Vector3 const Left;

    /// <summary>
    /// {  1,  0,  0 }
    /// </summary>
    static Vector3 const Right;

    /// <summary>
    /// {  0, -1,  0 }
    /// </summary>
    static Vector3 const Down;

    /// <summary>
    /// {  0,  1,  0 }
    /// </summary>
    static Vector3 const Up;

    /// <summary>
    /// {  0,  0, -1 }
    /// </summary>
    static Vector3 const Back;

    /// <summary>
    /// {  0,  0,  1 }
    /// </summary>
    static Vector3 const Forward;

};

/// <summary>
/// スカラーとの乗算演算子
/// </summary>
/// <param name="lhs">
/// 乗算するスカラー
/// </param>
/// <param name="rhs">
/// 乗算される三次元ベクトル
/// </param>
/// <returns>
/// 乗算後の三次元ベクトル
/// </returns>
constexpr Vector3 const operator * (Float lhs, Vector3 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// 出力ストリームに三次元ベクトルを渡す
/// </summary>
std::ostream & operator << (std::ostream & os, Vector3 const & v);

} // namespace Math
