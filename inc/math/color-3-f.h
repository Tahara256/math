#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// R, G, B ���ꂼ�� �C�ӂ̕��������_���^ �ł���킳�ꂽ�F���N���X
/// </summary>
class Color3F
{

public:

    /// <summary>
    /// �F�̗v�f��\���^
    /// </summary>
    using Elem = Float;

    /// <summary>
    /// �X�J���[�{�Ŏg�p��������^
    /// </summary>
    using Scalar = Float;


    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// R, G, B ���ꂼ��ő�l
    /// </summary>
    Color3F() : Color3F(
        static_cast<Elem>(1),
        static_cast<Elem>(1),
        static_cast<Elem>(1)
    )
    {
    }

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
    constexpr Color3F(Elem r, Elem g, Elem b) noexcept
        : m_r(r)
        , m_g(g)
        , m_b(b)
    {
    }

    /// <summary>
    /// Red�v�f���擾
    /// </summary>
    constexpr Elem GetR() const noexcept { return m_r; }

    /// <summary>
    /// Green�v�f���擾
    /// </summary>
    constexpr Elem GetG() const noexcept { return m_g; }

    /// <summary>
    /// Blue�v�f���擾
    /// </summary>
    constexpr Elem GetB() const noexcept { return m_b; }

    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Color3F operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1�ɂ���Z����
    /// </returns>
    constexpr Color3F operator - () const noexcept { return { -GetR(), -GetG(), -GetB() }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����F
    /// </param>
    /// <returns>
    /// ���Z��̐F
    /// </returns>
    constexpr Color3F operator + (Color3F const & rhs) const noexcept { return { GetR() + rhs.GetR(), GetG() + rhs.GetG(), GetB() + rhs.GetB() }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����F
    /// </param>
    /// <returns>
    /// ���Z��̐F
    /// </returns>
    constexpr Color3F operator - (Color3F const & rhs) const noexcept { return { GetR() - rhs.GetR(), GetG() - rhs.GetG(), GetB() - rhs.GetB() }; }

    /// <summary>
    /// �A�_�}�[����(�������ɏ�Z)
    /// </summary>
    /// <param name="rhs">
    /// ��Z����F
    /// </param>
    /// <returns>
    /// ��Z��̐F
    /// </returns>
    constexpr Color3F operator * (Color3F const & rhs) const noexcept { return { GetR() * rhs.GetR(), GetG() * rhs.GetG(), GetB() * rhs.GetB() }; }

    /// <summary>
    /// �t���v�f�Ƃ̃A�_�}�[����(�������ɏ��Z)
    /// </summary>
    /// <param name="rhs">
    /// ���Z����F
    /// </param>
    /// <returns>
    /// ���Z��̐F
    /// </returns>
    constexpr Color3F operator / (Color3F const & rhs) const noexcept { return { GetR() / rhs.GetR(), GetG() / rhs.GetG(), GetB() / rhs.GetB() }; }


    /// <summary>
    /// �X�J���[�Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// ��Z��̐F
    /// </returns>
    constexpr Color3F operator * (Scalar rhs) const noexcept { return { GetR() * rhs, GetG() * rhs, GetB() * rhs }; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// ���Z��̐F
    /// </returns>
    constexpr Color3F operator / (Scalar rhs) const noexcept { return { GetR() / rhs, GetG() / rhs, GetB() / rhs }; }


    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����F
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Color3F & operator += (Color3F const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����F
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Color3F & operator -= (Color3F const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z�����̎��g�ւ̎Q��
    /// </returns>
    Color3F & operator *= (Scalar rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z�����̎��g�ւ̎Q��
    /// </returns>
    Color3F & operator /= (Scalar rhs) noexcept { return *this = *this / rhs; }


    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̐F
    /// </param>
    /// <returns>
    /// ��̐F����������
    /// </returns>
    constexpr bool operator == (Color3F const & rhs) const noexcept { return GetR() == rhs.GetR() && GetG() == rhs.GetG() && GetB() == rhs.GetB(); }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̐F
    /// </param>
    /// <returns>
    /// ��̐F���������Ȃ���
    /// </returns>
    constexpr bool operator != (Color3F const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// ���j�A��Ԃ���sRGB��Ԃɕϊ�
    /// </summary>
    /// <param name="gammaFactor">
    /// �K���}�W��
    /// </param>
    /// <returns>
    /// sRGB��Ԃɕϊ���̐F
    /// </returns>
    Color3F ToGamma(Scalar gammaFactor) const
    {
        auto recipGammaFactor = Math::Recip(gammaFactor);
        return { Math::Pow(GetR(), recipGammaFactor), Math::Pow(GetG(), recipGammaFactor), Math::Pow(GetB(), recipGammaFactor) };
    }

    /// <summary>
    /// sRGB��Ԃ��烊�j�A��Ԃɕϊ�
    /// </summary>
    /// <param name="gammaFactor">
    /// �K���}�W��
    /// </param>
    /// <returns>
    /// ���j�A��Ԃɕϊ���̐F
    /// </returns>
    Color3F ToLinear(Scalar gammaFactor) const
    {
        return { Math::Pow(GetR(), gammaFactor), Math::Pow(GetG(), gammaFactor), Math::Pow(GetB(), gammaFactor) };
    }

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

};

/// <summary>
/// �X�J���[�Ƃ̏�Z���Z�q
/// </summary>
/// <param name="lhs">
/// ��Z����X�J���[
/// </param>
/// <param name="rhs">
/// ��Z�����F
/// </param>
/// <returns>
/// ��Z��̐F
/// </returns>
constexpr Color3F operator * (Color3F::Scalar lhs, Color3F const & rhs) noexcept { return { rhs * lhs }; }

/// <summary>
/// �X�J���[�Ƃ̏��Z���Z�q
/// </summary>
/// <param name="lhs">
/// ���Z����X�J���[
/// </param>
/// <param name="rhs">
/// ��Z�����F
/// </param>
/// <returns>
/// ���Z��̐F
/// </returns>
constexpr Color3F operator / (Color3F::Scalar lhs, Color3F const & rhs) noexcept { return { lhs / rhs.GetR(), lhs / rhs.GetG(), lhs / rhs.GetB() }; }

/// <summary>
/// �V�t�g���Z�q
/// �o�̓X�g���[���ɐF��n��
/// </summary>
std::ostream & operator << (std::ostream & lhs, Color3F const & rhs);

} // namespace Math
