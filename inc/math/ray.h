#pragma once

#include <math-lib.h>

namespace Math
{

/// <summary>
/// レイ(光線)クラス
/// </summary>
class Ray
{

public:

    /// <summary>
    /// レイの原点と方向を示すベクトルの型
    /// </summary>
    using Vector = Math::Vector3;

    /// <summary>
    /// スカラー倍で使用する実数型
    /// </summary>
    using Scalar = decltype(Math::Vector3::x);


    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    Ray() noexcept;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="origin">
    /// レイの原点
    /// </param>
    /// <param name="direction">
    /// レイの方向
    /// </param>
    Ray(Vector origin, Vector direction) noexcept;


    /// <summary>
    /// レイの原点を取得
    /// </summary>
    /// <returns>
    /// レイの原点
    /// </returns>
    Vector GetOrigin() const noexcept;

    /// <summary>
    /// レイの方向(単位ベクトル)を取得
    /// </summary>
    /// <returns>
    /// レイの方向(単位ベクトル)
    /// </returns>
    Vector GetDirection() const noexcept;


    /// <summary>
    /// レイの原点設定
    /// </summary>
    /// <param name="origin">
    /// レイの原点
    /// </param>
    void SetOrigin(Vector const & origin) noexcept;

    /// <summary>
    /// レイの方向(単位ベクトル)を設定
    /// </summary>
    /// <param name="direction">
    /// レイの方向(単位ベクトル)
    /// </param>
    void SetDirection(Vector const & direction) noexcept;


    /// <summary>
    /// 始点から方向に任意の距離だけ進んだ点を取得
    /// </summary>
    /// <param name="distance">
    /// 始点からの距離
    /// </param>
    /// <returns>
    /// 始点から方向に任意の距離だけ進んだ点
    /// </returns>
    Vector Point(Scalar distance) const noexcept;

    /// <summary>
    /// 任意の距離だけ進めたレイを取得
    /// </summary>
    /// <param name="distance">
    /// 進める距離
    /// </param>
    /// <returns>
    /// 任意の距離だけ進めたレイ
    /// </returns>
    Ray MovedForward(Scalar distance) const noexcept;

    /// <summary>
    /// 任意の距離だけレイを進める
    /// </summary>
    /// <param name="distance">
    /// 進める距離
    /// </param>
    void MoveForward(Scalar distance) noexcept;

private:

    /// <summary>
    /// レイの原点
    /// </summary>
    Vector m_origin;

    /// <summary>
    /// レイの方向(単位ベクトル)
    /// </summary>
    Vector m_direction;

};

} // namespace Math
