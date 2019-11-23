#pragma once

#include <iostream>
#include <array>
#include "integer-types.h"

namespace Math
{

class Color3B;
class Color3F;

/// <summary>
/// R, G, B, A ���ꂼ�� 8bit �����ł���킳�ꂽ�F���N���X
/// </summary>
class Color4B
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
        return std::numeric_limits<Math::Color4B::Elem>::max();
    }


    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// R, G, B, A ���ꂼ��ő�l
    /// </summary>
    Color4B();

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
    /// <param name="a">
    /// Alpha�v�f
    /// </param>
    Color4B(Elem r, Elem g, Elem b, Elem a = GetElemMax());

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="rgb">
    /// Red�v�f, Green�v�f, Blue�v�f
    /// </param>
    /// <param name="a">
    /// Alpha�v�f
    /// </param>
    explicit Color4B(Color3B const & rgb, Elem a = GetElemMax());


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
    /// Alpha�v�f���擾
    /// </summary>
    Elem GetA() const;


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
    /// Alpha�v�f��ݒ�
    /// </summary>
    /// <param name="a">
    /// �ݒ肷��Alpha�l[0, 255]
    /// </param>
    void SetA(Elem a);


    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������v�f�̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�v�f�ւ̎Q��
    /// </returns>
    Elem & operator [] (std::size_t index) noexcept;

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������v�f�̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�v�f
    /// </returns>
    Elem operator [] (std::size_t index) const noexcept;


    /// <summary>
    /// ���������_���^�̐F���N���X�ɕϊ�
    /// </summary>
    Color3F ToColor3F() const noexcept;


private:

    union
    {
        struct
        {
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

            /// <summary>
            /// Alpha�v�f
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
/// �V�t�g���Z�q
/// �o�̓X�g���[���ɐF�N���X��n��
/// </summary>
std::ostream & operator << (std::ostream & lhs, Color4B const & rhs);

} // namespace Math
