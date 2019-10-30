#pragma once

#include "vector-3.h"

namespace Math
{

/// <summary>
/// 4 × 4 行列
/// </summary>
class Matrix4x4;

/// <summary> クォータニオン(四元数) </summary>
class Quaternion
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// 虚部(ベクトル成分)
            /// </summary>
            Vector3 v;
            /// <summary>
            /// 実部(スカラー成分)
            /// </summary>
            Float s;
        };
        struct
        {
            /// <summary>
            /// x(i)成分
            /// </summary>
            Float x;
            /// <summary>
            /// y(j)成分
            /// </summary>
            Float y;
            /// <summary>
            /// z(k)成分
            /// </summary>
            Float z;
            /// <summary>
            /// w(a)成分
            /// </summary>
            Float w;
        };
        struct
        {
            /// <summary>
            /// i(x)成分
            /// </summary>
            Float i;
            /// <summary>
            /// j(y)成分
            /// </summary>
            Float j;
            /// <summary>
            /// k(z)成分
            /// </summary>
            Float k;
            /// <summary>
            /// a(w)成分
            /// </summary>
            Float a;
        };
        Float _[4];
    };

    /// <summary>
    /// デフォルトコンストラクタ(単位クォータニオン)
    /// </summary>
    constexpr Quaternion() noexcept : Quaternion(static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="x">
    /// x(i)成分
    /// </param>
    /// <param name="y">
    /// y(j)成分
    /// </param>
    /// <param name="z">
    /// z(k)成分
    /// </param>
    /// <param name="w">
    /// w(a)成分
    /// </param>
    constexpr Quaternion(Float x, Float y, Float z, Float w) noexcept : x(x), y(y), z(z), w(w) { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="v">
    /// 虚部(ベクトル成分)
    /// </param>
    /// <param name="s">
    /// 実部(スカラー成分)
    /// </param>
    constexpr Quaternion(Vector3 const & v, Float s) noexcept : Quaternion(v.x, v.y, v.z, s) { };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="v">
    /// 虚部(ベクトル成分)
    /// </param>
    constexpr explicit Quaternion(Vector3 const & v) noexcept : Quaternion(v, static_cast<Float>(0)) { };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="m">
    /// 回転行列
    /// </param>
    explicit Quaternion(Matrix4x4 const & m) noexcept;

    /// <summary>
    /// 単項プラス演算子
    /// </summary>
    /// <returns>
    /// +1 による乗算結果
    /// </returns>
    constexpr Quaternion const operator + () const noexcept { return *this; }

    /// <summary>
    /// 単項マイナス演算子
    /// </summary>
    /// <returns>
    /// -1 による乗算結果
    /// </returns>
    constexpr Quaternion const operator - () const noexcept { return { -x, -y, -z, -w }; }

    /// <summary>
    /// 加算演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算するクォータニオン
    /// </param>
    /// <returns>
    /// 加算後のクォータニオン
    /// </returns>
    constexpr Quaternion const operator + (Quaternion const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }

    /// <summary>
    /// 減算演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算するクォータニオン
    /// </param>
    /// <returns>
    /// 減算後のクォータニオン
    /// </returns>
    constexpr Quaternion const operator - (Quaternion const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }

    /// <summary>
    /// スカラーとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算後のクォータニオン
    /// </returns>
    constexpr Quaternion const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs, w * rhs }; }

    /// <summary>
    /// スカラーとの除算演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算後のクォータニオン
    /// </returns>
    constexpr Quaternion const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象のクォータニオン
    /// </param>
    /// <returns>
    /// 二つのクォータニオンが等しいか
    /// </returns>
    constexpr bool operator == (Quaternion const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="rhs">
    /// 比較対象のクォータニオン
    /// </param>
    /// <returns>
    /// 二つのクォータニオンが等しくないか
    /// </returns>
    constexpr bool operator != (Quaternion const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// 三次元ベクトルとの乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 回転させる三次元ベクトル
    /// </param>
    /// <returns>
    /// 回転後の三次元ベクトル
    /// </returns>
    constexpr Vector3 const operator * (Vector3 const & rhs) const noexcept { return *this * Quaternion(rhs) * Conjugate(); }

    /// <summary>
    /// クォータニオン同士の乗算演算子
    /// </summary>
    /// <param name="rhs">
    /// 合成するクォータニオン
    /// </param>
    /// <returns>
    /// 合成後のクォータニオン
    /// </returns>
    constexpr Quaternion const operator * (Quaternion const & rhs) const noexcept { return { rhs.v * s + v * rhs.s + v.Cross(rhs.v), w * rhs.w - v.Dot(rhs) }; }

    /// <summary>
    /// 加算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 加算するクォータニオン
    /// </param>
    /// <returns>
    /// 加算代入後の自身への参照
    /// </returns>
    Quaternion & operator += (Quaternion const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// 減算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 減算するクォータニオン
    /// </param>
    /// <returns>
    /// 減算代入後の自身への参照
    /// </returns>
    Quaternion & operator -= (Quaternion const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// スカラーとの乗算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 乗算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで乗算代入後の自身への参照
    /// </returns>
    Quaternion & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// スカラーとの除算代入演算子
    /// </summary>
    /// <param name="rhs">
    /// 除算するスカラー
    /// </param>
    /// <returns>
    /// スカラーで除算代入後の自身への参照
    /// </returns>
    Quaternion & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分への参照
    /// </returns>
    Float & operator [] (std::size_t index) { return _[index]; }

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい成分のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された成分
    /// </returns>
    constexpr Float operator [] (std::size_t index) const { return _[index]; }

    /// <summary>
    /// 虚数部をベクトルへ変換
    /// </summary>
    /// <returns>
    /// ベクトルとした虚数部
    /// </returns>
    constexpr operator Vector3() const noexcept { return { x, y, z }; }

    /// <summary>
    /// 共役クォータニオンを取得
    /// </summary>
    /// <returns>
    /// 共役クォータニオン
    /// </returns>
    constexpr Quaternion const Conjugate() const noexcept { return { -x, -y, -z, w }; }

    /// <summary>
    /// 逆クォータニオンを取得
    /// </summary>
    /// <returns>
    /// 逆クォータニオン
    /// </returns>
    constexpr Quaternion const Inverse() const noexcept { return Conjugate() / LengthSquared(); }

    /// <summary>
    /// 二つのクォータニオンの内積を取得
    /// </summary>
    /// <param name="rhs">
    /// 右オペランドのクォータニオン
    /// </param>
    /// <returns>
    /// 二つのクォータニオンの内積
    /// </returns>
    constexpr Float Dot(Quaternion const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

    /// <summary>
    /// 長さを取得
    /// </summary>
    /// <returns>
    /// 長さ
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// 長さの二乗を取得
    /// </summary>
    /// <returns>
    /// 長さの二乗
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// 正規化したクォータニオンを取得
    /// </summary>
    /// <returns>
    /// 正規化したクォータニオン
    /// </returns>
    constexpr Quaternion const Normalized() const noexcept { return *this / Length(); };

    /// <summary>
    /// 正規化
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// 二つのクォータニオンを線形補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つのクォータニオンの補間値
    /// </param>
    /// <returns>
    /// 二つのクォータニオンの間の線形補間されたクォータニオン
    /// </returns>
    Quaternion const Lerp(Quaternion const & other, Float t) const;

    /// <summary>
    /// 二つのクォータニオンを球面線形補間
    /// </summary>
    /// <param name="other">
    /// 終了値
    /// </param>
    /// <param name="t">
    /// 二つのクォータニオンの補間値
    /// </param>
    /// <returns>
    /// 二つのクォータニオンの間の球面線形補間されたクォータニオン
    /// </returns>
    Quaternion const Slerp(Quaternion const & other, Float t) const;

    /// <summary>
    /// 単位クォータニオン
    /// </summary>
    static Quaternion const Identity;

    /// <summary>
    /// X軸の回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// X軸の回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateX(Float angle);

    /// <summary>
    /// Y軸の回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// Y軸の回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateY(Float angle);

    /// <summary>
    /// Z軸の回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// Z軸の回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateZ(Float angle);

    /// <summary>
    /// 任意の軸の回転を表すクォータニオンを作成します。(単位ベクトルで軸指定)
    /// </summary>
    /// <param name="unitAxis">
    /// 回転軸(単位ベクトル)
    /// </param>
    /// <param name="angle">
    /// 弧度法の角度
    /// </param>
    /// <returns>
    /// 任意の軸の回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateUnitAxisAngle(Vector3 const & unitAxis, Float angle);

    /// <summary>
    /// 任意の軸の回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="axis">
    /// 回転軸(任意の長さ)
    /// </param>
    /// <param name="angle">
    /// 弧度法の角度
    /// </param>
    /// <returns>
    /// 任意の軸の回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateAxisAngle(Vector3 const & axis, Float angle);

    /// <summary>
    /// オイラー角(Z→X→Y回転)で回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="eulerAngles">
    /// オイラー角(弧度法)
    /// </param>
    /// <returns>
    /// オイラー角で指定された回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateEulerAngles(Vector3 const & eulerAngles);

    /// <summary>
    /// 指定方向を向くための回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="from">
    /// 視点座標
    /// </param>
    /// <param name="to">
    /// 注視点座標
    /// </param>
    /// <param name="up">
    /// 上方向とするベクトル
    /// </param>
    /// <returns>
    /// 指定方向を向くための回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// 指定方向を向くための回転を表すクォータニオンを作成します。(単位ベクトルで方向指定)
    /// </summary>
    /// <param name="unitDirection">
    /// 向きたい方向を表すベクトル(単位ベクトル)
    /// </param>
    /// <param name="up">
    /// 上方向とするベクトル
    /// </param>
    /// <returns>
    /// 指定方向を向くための回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateUnitDirection(Vector3 const & unitDirection, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// 指定方向を向くための回転を表すクォータニオンを作成
    /// </summary>
    /// <param name="direction">
    /// 向きたい方向を表すベクトル(任意の長さ)
    /// </param>
    /// <param name="up">
    /// 上方向とするベクトル
    /// </param>
    /// <returns>
    /// 指定方向を向くための回転を表すクォータニオン
    /// </returns>
    static Quaternion const CreateDirection(Vector3 const & direction, Vector3 const & up = Vector3::Up);
};

/// <summary>
/// 出力ストリームにクォータニオンを渡す
/// </summary>
std::ostream & operator << (std::ostream & os, Quaternion const & q);

} // namespace Math
