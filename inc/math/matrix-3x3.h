#pragma once

#include "vector-3.h"

namespace Math
{

/// <summary>
/// 3 × 3 行列
/// </summary>
class Matrix3x3
{

public:

    union
    {
        struct
        {
            Float m11, m12, m13;
            Float m21, m22, m23;
            Float m31, m32, m33;
        };
        Float m[3][3];
        struct
        {
            /// <summary>
            /// 一行目
            /// </summary>
            Vector3 r1;
            /// <summary>
            /// 二行目
            /// </summary>
            Vector3 r2;
            /// <summary>
            /// 三行目
            /// </summary>
            Vector3 r3;
        };
        Vector3 r[3];
    };

    /// <summary>
    /// デフォルトコンストラクタ(単位行列)
    /// </summary>
    Matrix3x3();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Matrix3x3(
        Float m11, Float m12, Float m13,
        Float m21, Float m22, Float m23,
        Float m31, Float m32, Float m33) noexcept;

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
    Matrix3x3(Vector3 const & r1, Vector3 const & r2, Vector3 const & r3) noexcept;

    /// <summary>
    /// コピーコンストラクタ
    /// </summary>
    /// <param name="other">
    /// コピー元の行列
    /// </param>
    Matrix3x3(Matrix3x3 const & other);

    /// <summary>
    /// コピー代入演算子
    /// </summary>
    /// <param name="other">
    /// コピー元の行列
    /// </param>
    /// <returns>
    /// 自身への参照
    /// </returns>
    Matrix3x3 & operator = (Matrix3x3 const & other);

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
    /// 行列同士の乗算演算子
    /// </summary>
    /// <param name="other">
    /// 合成する行列
    /// </param>
    /// <returns>
    /// 合成後の行列
    /// </returns>
    Matrix3x3 const operator * (Matrix3x3 const & other) const;

    /// <summary>
    /// 等価演算子
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列が等しいか
    /// </returns>
    bool operator == (Matrix3x3 const & other) const;

    /// <summary>
    /// 非等価演算子
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列が等しくないか
    /// </returns>
    bool operator != (Matrix3x3 const & other) const;

    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい行のインデックス(0 ～ 2)
    /// </param>
    /// <returns>
    /// インデックスで指定された行への参照
    /// </returns>
    Vector3 & operator [] (std::size_t index);

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい行のインデックス(0 ～ 2)
    /// </param>
    /// <returns>
    /// インデックスで指定された行
    /// </returns>
    Vector3 const & operator [] (std::size_t index) const;

    /// <summary>
    /// 指定された列を取得
    /// </summary>
    /// <param name="index">
    /// 取得する列のインデックス(0 ～ 2)
    /// </param>
    /// <returns>
    /// 指定された列
    /// </returns>
    Vector3 const Column(std::size_t index) const;

    /// <summary>
    /// 二つの行列がほぼ等しいかを取得
    /// </summary>
    /// <param name="other">
    /// 比較対象の行列
    /// </param>
    /// <returns>
    /// 二つの行列がほぼ等しいか
    /// </returns>
    bool Approximately(Matrix3x3 const & other) const noexcept;

    /// <summary>
    /// 行列式を取得
    /// </summary>
    /// <returns>
    /// 行列式
    /// </returns>
    Float Determinant() const noexcept;

    /// <summary>
    /// 転置行列を取得
    /// </summary>
    /// <returns>
    /// 転置行列
    /// </returns>
    Matrix3x3 const Transpose() const noexcept;

    /// <summary>
    /// 単位行列
    /// </summary>
    static Matrix3x3 const Identity;

    /// <summary>
    /// 零行列
    /// </summary>
    static Matrix3x3 const Zero;

};

} // namespace Math
