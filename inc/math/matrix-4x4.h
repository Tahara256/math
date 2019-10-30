#pragma once

#include "vector-3.h"
#include "vector-4.h"

namespace Math
{

/// <summary>
/// 4 × 4 行列
/// </summary>
class Matrix4x4
{

public:

    union
    {
        struct
        {
            Float m11, m12, m13, m14;
            Float m21, m22, m23, m24;
            Float m31, m32, m33, m34;
            Float m41, m42, m43, m44;
        };
        Float m[4][4];
        struct
        {
            /// <summary>
            /// 一行目
            /// </summary>
            Vector4 r1;
            /// <summary>
            /// 二行目
            /// </summary>
            Vector4 r2;
            /// <summary>
            /// 三行目
            /// </summary>
            Vector4 r3;
            /// <summary>
            /// 四行目
            /// </summary>
            Vector4 r4;
        };
        Vector4 r[4];
    };

    /// <summary>
    /// デフォルトコンストラクタ(単位行列)
    /// </summary>
    Matrix4x4();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Matrix4x4(
        Float m11, Float m12, Float m13, Float m14,
        Float m21, Float m22, Float m23, Float m24,
        Float m31, Float m32, Float m33, Float m34,
        Float m41, Float m42, Float m43, Float m44) noexcept;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="r0">
    /// 1行目
    /// </param>
    /// <param name="r1">
    /// 2行目
    /// </param>
    /// <param name="r2">
    /// 3行目
    /// </param>
    /// <param name="r3">
    /// 4行目
    /// </param>
    Matrix4x4(Vector4 const & r1, Vector4 const & r2, Vector4 const & r3, Vector4 const & r4) noexcept;

    /// <summary>
    /// コピーコンストラクタ
    /// </summary>
    /// <param name="other">
    /// コピー元の行列
    /// </param>
    Matrix4x4(Matrix4x4 const & other);

    /// <summary>
    /// コピー代入演算子
    /// </summary>
    /// <param name="other">
    /// コピー元の行列
    /// </param>
    /// <returns>
    /// 自身への参照
    /// </returns>
    Matrix4x4 & operator = (Matrix4x4 const & other);

    /// <summary>
    /// 三次元ベクトルとの乗算演算子
    /// </summary>
    /// <param name="other">
    /// 変換する三次元ベクトル
    /// </param>
    /// <returns>
    /// 変換後の三次元ベクトル
    /// </returns>
    Vector3 const operator * (Vector3 const & other) const;

    /// <summary>
    /// 四次元ベクトルとの乗算演算子
    /// </summary>
    /// <param name="other">
    /// 変換する四次元ベクトル
    /// </param>
    /// <returns>
    /// 変換後の四次元ベクトル
    /// </returns>
    Vector4 const operator * (Vector4 const & other) const;

    /// <summary>
    /// 行列同士の乗算演算子
    /// </summary>
    /// <param name="other">
    /// 合成する行列
    /// </param>
    /// <returns>
    /// 合成後の行列
    /// </returns>
    Matrix4x4 const operator * (Matrix4x4 const & other) const;

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列が等しいか
    /// </returns>
    bool operator == (Matrix4x4 const & other) const;

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列が等しくないか
    /// </returns>
    bool operator != (Matrix4x4 const & other) const;

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい行のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された行への参照
    /// </returns>
    Vector4 & operator [] (std::size_t index);

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい行のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された行
    /// </returns>
    Vector4 const & operator [] (std::size_t index) const;

    /// <summary>
    /// 指定された列を取得
    /// </summary>
    /// <param name="index">
    /// 取得する列のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// 指定された列
    /// </returns>
    Vector4 const Column(std::size_t index) const;

    /// <summary>
    /// 二つの行列がほぼ等しいかを取得
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列がほぼ等しいか
    /// </returns>
    bool Approximately(Matrix4x4 const & other) const noexcept;

    /// <summary>
    /// 行列式を取得
    /// </summary>
    /// <returns>
    /// 行列式
    /// </returns>
    Float Determinant() const noexcept;

    /// <summary>
    /// 逆行列を取得
    /// </summary>
    /// <returns>
    /// 逆行列
    /// </returns>
    Matrix4x4 const Inverse() const noexcept;

    /// <summary>
    /// 転置行列を取得
    /// </summary>
    /// <returns>
    /// 転置行列
    /// </returns>
    Matrix4x4 const Transpose() const noexcept;

    /// <summary>
    /// オイラー角を取得
    /// </summary>
    /// <returns>
    /// オイラー角
    /// </returns>
    Vector3 const EulerAngles() const noexcept;

    /// <summary>
    /// 単位行列
    /// </summary>
    static Matrix4x4 const Identity;

    /// <summary>
    /// 零行列
    /// </summary>
    static Matrix4x4 const Zero;

    /// <summary>
    /// 拡大縮小行列を作成
    /// </summary>
    /// <param name="scale">
    /// 拡大縮小
    /// </param>
    /// <returns>
    /// 拡大縮小行列
    /// </returns>
    static Matrix4x4 const CreateScale(Float scale);

    /// <summary>
    /// 拡大縮小行列を作成
    /// </summary>
    /// <param name="scale">
    /// XYZのそれぞれの軸に対しての拡大縮小
    /// </param>
    /// <returns>
    /// 拡大縮小行列
    /// </returns>
    static Matrix4x4 const CreateScale(Vector3 const & scale);

    /// <summary>
    /// X軸の回転行列を作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// X軸の回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationX(Float angle);

    /// <summary>
    /// Y軸の回転行列を作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// Y軸の回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationY(Float angle);

    /// <summary>
    /// Z軸の回転行列を作成
    /// </summary>
    /// <param name="angle">
    /// 回転角度(弧度法)
    /// </param>
    /// <returns>
    /// Z軸の回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationZ(Float angle);

    /// <summary>
    /// 任意軸の回転行列を作成(単位ベクトルで軸指定)
    /// </summary>
    /// <param name="unitAxis">
    /// 回転軸(単位ベクトル)
    /// </param>
    /// <param name="angle">
    /// 弧度法の角度
    /// </param>
    /// <returns>
    /// 任意軸の回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationUnitAxisAngle(Vector3 const & unitAxis, Float angle);

    /// <summary>
    /// 任意軸の回転行列を作成
    /// </summary>
    /// <param name="axis">
    /// 回転軸(任意の長さ)
    /// </param>
    /// <param name="angle">
    /// 弧度法の角度
    /// </param>
    /// <returns>
    /// 任意軸の回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationAxisAngle(Vector3 const & axis, Float angle);

    /// <summary>
    /// オイラー角(Z→X→Y回転)で回転行列を作成
    /// </summary>
    /// <param name="eulerAngles">
    /// オイラー角
    /// </param>
    /// <returns>
    /// 回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationEulerAngles(Vector3 const & eulerAngles);

    /// <summary>
    /// 指定方向を向くための回転行列を作成
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
    /// 指定方向を向くための回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// 方向ベクトルから回転行列を作成(単位ベクトルで方向指定)
    /// </summary>
    /// <param name="unitDirection">
    /// 方向ベクトル(単位ベクトル)
    /// </param>
    /// <param name="up">
    /// 上方向とするベクトル
    /// </param>
    /// <returns>
    /// 回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationUnitDirection(Vector3 const & unitDirection, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// 方向ベクトルから回転行列を作成
    /// </summary>
    /// <param name="direction">
    /// 方向ベクトル(任意の長さ)
    /// </param>
    /// <param name="up">
    /// 上方向とするベクトル
    /// </param>
    /// <returns>
    /// 回転行列
    /// </returns>
    static Matrix4x4 const CreateRotationDirection(Vector3 const & direction, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// 座標から平行移動行列を作成
    /// </summary>
    /// <param name="position">
    /// 座標
    /// </param>
    /// <returns>
    /// 座標から作成した変更移動行列
    /// </returns>
    static Matrix4x4 const CreateTranslation(Vector3 const & position);

    /// <summary>
    /// パースペクティブのプロジェクション行列を作成
    /// </summary>
    /// <param name="fovAngleY">
    /// Y方向の視野角
    /// </param>
    /// <param name="aspect">
    /// アスペクト比
    /// </param>
    /// <param name="nearZ">
    /// 近くのビュープレーン
    /// </param>
    /// <param name="farZ">
    /// 遠くのビュープレーン
    /// </param>
    /// <returns>
    /// パースペクティブのプロジェクション行列
    /// </returns>
    static Matrix4x4 const CreatePerspective(Float fovAngleY, Float aspect, Float nearZ, Float farZ);

};

/// <summary>
/// 出力ストリームに 4 × 4 行列を渡す
/// </summary>
std::ostream & operator << (std::ostream & os, Matrix4x4 const & m);

} // namespace Math
