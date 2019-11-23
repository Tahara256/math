#pragma once

#include <iostream>
#include <array>
#include "integer-types.h"

namespace Math
{

class Color3B;
class Color3F;

/// <summary>
/// R, G, B, A それぞれ 8bit 整数であらわされた色情報クラス
/// </summary>
class Color4B
{

public:

    /// <summary>
    /// 色の要素を表す型
    /// </summary>
    using Elem = U8;

    /// <summary>
    /// 色の要素の最大値を取得
    /// </summary>
    constexpr static Elem GetElemMax()
    {
        return std::numeric_limits<Math::Color4B::Elem>::max();
    }


    /// <summary>
    /// デフォルトコンストラクタ
    /// R, G, B, A それぞれ最大値
    /// </summary>
    Color4B();

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
    /// <param name="a">
    /// Alpha要素
    /// </param>
    Color4B(Elem r, Elem g, Elem b, Elem a = GetElemMax());

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="rgb">
    /// Red要素, Green要素, Blue要素
    /// </param>
    /// <param name="a">
    /// Alpha要素
    /// </param>
    explicit Color4B(Color3B const & rgb, Elem a = GetElemMax());


    /// <summary>
    /// Red要素を取得
    /// </summary>
    Elem GetR() const;

    /// <summary>
    /// Green要素を取得
    /// </summary>
    Elem GetG() const;

    /// <summary>
    /// Blue要素を取得
    /// </summary>
    Elem GetB() const;

    /// <summary>
    /// Alpha要素を取得
    /// </summary>
    Elem GetA() const;


    /// <summary>
    /// Red要素を設定
    /// </summary>
    /// <param name="r">
    /// 設定するRed値[0, 255]
    /// </param>
    void SetR(Elem r);

    /// <summary>
    /// Green要素を設定
    /// </summary>
    /// <param name="g">
    /// 設定するGreen値[0, 255]
    /// </param>
    void SetG(Elem g);

    /// <summary>
    /// Blue要素を設定
    /// </summary>
    /// <param name="b">
    /// 設定するBlue値[0, 255]
    /// </param>
    void SetB(Elem b);

    /// <summary>
    /// Alpha要素を設定
    /// </summary>
    /// <param name="a">
    /// 設定するAlpha値[0, 255]
    /// </param>
    void SetA(Elem a);


    /// <summary>
    /// 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい要素のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された要素への参照
    /// </returns>
    Elem & operator [] (std::size_t index) noexcept;

    /// <summary>
    /// const 添字演算子
    /// </summary>
    /// <param name="index">
    /// 取得したい要素のインデックス(0 ～ 3)
    /// </param>
    /// <returns>
    /// インデックスで指定された要素
    /// </returns>
    Elem operator [] (std::size_t index) const noexcept;


    /// <summary>
    /// 浮動小数点数型の色情報クラスに変換
    /// </summary>
    Color3F ToColor3F() const noexcept;


private:

    union
    {
        struct
        {
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

            /// <summary>
            /// Alpha要素
            /// </summary>
            Elem m_a;
        };
        struct
        {
            std::array<Elem, 4> _;
        };
    };

};

/// <summary>
/// シフト演算子
/// 出力ストリームに色クラスを渡す
/// </summary>
std::ostream & operator << (std::ostream & lhs, Color4B const & rhs);

} // namespace Math
