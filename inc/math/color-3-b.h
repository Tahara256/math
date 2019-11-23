#pragma once

#include <string>
#include "color-3-f.h"

namespace Math
{

/// <summary>
/// R, G, B ���ꂼ�� 8bit �����ł���킳�ꂽ�F���N���X
/// </summary>
class Color3B
{

public:

    /// <summary>
    /// �F�̗v�f��\���^
    /// </summary>
    using Elem = U8;

    /// <summary>
    /// �F�̗v�f�̍ő�l���擾
    /// </summary>
    constexpr static Elem GetElemMax()
    {
        return std::numeric_limits<Math::Color3B::Elem>::max();
    }


    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// R, G, B ���ꂼ��ő�l
    /// </summary>
    Color3B();

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="r">
    /// Red�v�f
    /// </param>
    /// <param name="g">
    /// Green�v�f
    /// </param>
    /// <param name="b">
    /// Blue�v�f
    /// </param>
    Color3B(Elem r, Elem g, Elem b);


    /// <summary>
    /// Red�v�f���擾
    /// </summary>
    Elem GetR() const;

    /// <summary>
    /// Green�v�f���擾
    /// </summary>
    Elem GetG() const;

    /// <summary>
    /// Blue�v�f���擾
    /// </summary>
    Elem GetB() const;


    /// <summary>
    /// Red�v�f��ݒ�
    /// </summary>
    /// <param name="r">
    /// �ݒ肷��Red�l[0, 255]
    /// </param>
    void SetR(Elem r);

    /// <summary>
    /// Green�v�f��ݒ�
    /// </summary>
    /// <param name="g">
    /// �ݒ肷��Green�l[0, 255]
    /// </param>
    void SetG(Elem g);

    /// <summary>
    /// Blue�v�f��ݒ�
    /// </summary>
    /// <param name="b">
    /// �ݒ肷��Blue�l[0, 255]
    /// </param>
    void SetB(Elem b);


    /// <summary>
    /// ���������_���^�̐F���N���X�ɕϊ�
    /// </summary>
    Math::Color3F ToColor3F() const noexcept;

private:

    /// <summary>
    /// Red�v�f
    /// </summary>
    Elem m_r;

    /// <summary>
    /// Green�v�f
    /// </summary>
    Elem m_g;

    /// <summary>
    /// Blue�v�f
    /// </summary>
    Elem m_b;

public:

    static Color3B const Black;
    static Color3B const Dimgray;
    static Color3B const Gray;
    static Color3B const Darkgray;
    static Color3B const Silver;
    static Color3B const Lightgrey;
    static Color3B const Gainsboro;
    static Color3B const Whitesmoke;
    static Color3B const White;
    static Color3B const Snow;
    static Color3B const Ghostwhite;
    static Color3B const Floralwhite;
    static Color3B const Linen;
    static Color3B const Antiquewhite;
    static Color3B const Papayawhip;
    static Color3B const Blanchedalmond;
    static Color3B const Bisque;
    static Color3B const Moccasin;
    static Color3B const Navajowhite;
    static Color3B const Peachpuff;
    static Color3B const Mistyrose;
    static Color3B const Lavenderblush;
    static Color3B const Seashell;
    static Color3B const Oldlace;
    static Color3B const Ivory;
    static Color3B const Honeydew;
    static Color3B const Mintcream;
    static Color3B const Azure;
    static Color3B const Aliceblue;
    static Color3B const Lavender;
    static Color3B const Lightsteelblue;
    static Color3B const Lightslategray;
    static Color3B const Slategray;
    static Color3B const Steelblue;
    static Color3B const Royalblue;
    static Color3B const Midnightblue;
    static Color3B const Navy;
    static Color3B const Darkblue;
    static Color3B const Mediumblue;
    static Color3B const Blue;
    static Color3B const Dodgerblue;
    static Color3B const Cornflowerblue;
    static Color3B const Deepskyblue;
    static Color3B const Lightskyblue;
    static Color3B const Skyblue;
    static Color3B const Lightblue;
    static Color3B const Powderblue;
    static Color3B const Paleturquoise;
    static Color3B const Lightcyan;
    static Color3B const Cyan;
    static Color3B const Aqua;
    static Color3B const Turquoise;
    static Color3B const Mediumturquoise;
    static Color3B const Darkturquoise;
    static Color3B const Lightseagreen;
    static Color3B const Cadetblue;
    static Color3B const Darkcyan;
    static Color3B const Teal;
    static Color3B const Darkslategray;
    static Color3B const Darkgreen;
    static Color3B const Green;
    static Color3B const Forestgreen;
    static Color3B const Seagreen;
    static Color3B const Mediumseagreen;
    static Color3B const Mediumaquamarine;
    static Color3B const Darkseagreen;
    static Color3B const Aquamarine;
    static Color3B const Palegreen;
    static Color3B const Lightgreen;
    static Color3B const Springgreen;
    static Color3B const Mediumspringgreen;
    static Color3B const Lawngreen;
    static Color3B const Chartreuse;
    static Color3B const Greenyellow;
    static Color3B const Lime;
    static Color3B const Limegreen;
    static Color3B const Yellowgreen;
    static Color3B const Darkolivegreen;
    static Color3B const Olivedrab;
    static Color3B const Olive;
    static Color3B const Darkkhaki;
    static Color3B const Palegoldenrod;
    static Color3B const Cornsilk;
    static Color3B const Beige;
    static Color3B const Lightyellow;
    static Color3B const Lightgoldenrodyellow;
    static Color3B const Lemonchiffon;
    static Color3B const Wheat;
    static Color3B const Burlywood;
    static Color3B const Tan;
    static Color3B const Khaki;
    static Color3B const Yellow;
    static Color3B const Gold;
    static Color3B const Orange;
    static Color3B const Sandybrown;
    static Color3B const Darkorange;
    static Color3B const Goldenrod;
    static Color3B const Peru;
    static Color3B const Darkgoldenrod;
    static Color3B const Chocolate;
    static Color3B const Sienna;
    static Color3B const Saddlebrown;
    static Color3B const Maroon;
    static Color3B const Darkred;
    static Color3B const Brown;
    static Color3B const Firebrick;
    static Color3B const Indianred;
    static Color3B const Rosybrown;
    static Color3B const Darksalmon;
    static Color3B const Lightcoral;
    static Color3B const Salmon;
    static Color3B const Lightsalmon;
    static Color3B const Coral;
    static Color3B const Tomato;
    static Color3B const Orangered;
    static Color3B const Red;
    static Color3B const Crimson;
    static Color3B const Mediumvioletred;
    static Color3B const Deeppink;
    static Color3B const Hotpink;
    static Color3B const Palevioletred;
    static Color3B const Pink;
    static Color3B const Lightpink;
    static Color3B const Thistle;
    static Color3B const Magenta;
    static Color3B const Fuchsia;
    static Color3B const Violet;
    static Color3B const Plum;
    static Color3B const Orchid;
    static Color3B const Mediumorchid;
    static Color3B const Darkorchid;
    static Color3B const Darkviolet;
    static Color3B const Darkmagenta;
    static Color3B const Purple;
    static Color3B const Indigo;
    static Color3B const Darkslateblue;
    static Color3B const Blueviolet;
    static Color3B const Mediumpurple;
    static Color3B const Slateblue;
    static Color3B const Mediumslateblue;

};

/// <summary>
/// �V�t�g���Z�q
/// �o�̓X�g���[���ɐF�N���X��n��
/// </summary>
std::ostream & operator << (std::ostream & lhs, Color3B const & rhs);

} // namespace Math
