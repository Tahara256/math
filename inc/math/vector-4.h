#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// �l�����x�N�g���N���X(���������_���^)
/// </summary>
class Vector4
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// x ����
            /// </summary>
            Float x;
            /// <summary>
            /// y ����
            /// </summary>
            Float y;
            /// <summary>
            /// z ����
            /// </summary>
            Float z;
            /// <summary>
            /// w ����
            /// </summary>
            Float w;
        };
        Float _[4];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    constexpr Vector4() noexcept : Vector4(static_cast<Float>(0)) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="x">
    /// x ����
    /// </param>
    /// <param name="y">
    /// y ����
    /// </param>
    /// <param name="z">
    /// z ����
    /// </param>
    /// <param name="w">
    /// w ����
    /// </param>
    constexpr Vector4(Float x, Float y, Float z, Float w) noexcept : x(x), y(y), z(z), w(w) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="value">
    /// xyzw �����S�ĂɊ��蓖�Ă�l
    /// </param>
    constexpr explicit Vector4(Float value) noexcept : Vector4(value, value, value, value) { }

    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Vector4 const operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1�ɂ���Z����
    /// </returns>
    constexpr Vector4 const operator - () const noexcept { return { -x, -y, -z, -w }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����l�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator + (Vector4 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����l�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator - (Vector4 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }

    /// <summary>
    /// �A�_�}�[����(�������ɏ�Z)
    /// </summary>
    /// <param name="rhs">
    /// ��Z����l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator * (Vector4 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w }; }

    /// <summary>
    /// �t���v�f�Ƃ̃A�_�}�[����(�������ɏ��Z)
    /// </summary>
    /// <param name="rhs">
    /// ���Z����l�����x�N�g�� 
    /// </param>
    /// <returns>
    /// ���Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator / (Vector4 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w }; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// ��Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs, w * rhs }; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// ���Z��̎l�����x�N�g��
    /// </returns>
    constexpr Vector4 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎l�����x�N�g������������
    /// </returns>
    constexpr bool operator == (Vector4 const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎l�����x�N�g�����������Ȃ���
    /// </returns>
    constexpr bool operator != (Vector4 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����l�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector4 & operator += (Vector4 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����l�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector4 & operator -= (Vector4 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector4 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector4 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�����ւ̎Q��
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ����
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// ��̎l�����x�N�g�����قړ����������擾
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎l�����x�N�g�����قړ�������
    /// </returns>
    constexpr bool Approximately(Vector4 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y) && Math::Approximately(z, rhs.z) && Math::Approximately(w, rhs.w); }

    /// <summary>
    /// ��̎l�����x�N�g���̓��ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎l�����x�N�g���̓���
    /// </returns>
    constexpr Float Dot(Vector4 const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

    /// <summary>
    /// �l�����x�N�g���̒������擾
    /// </summary>
    /// <returns>
    /// �l�����x�N�g���̒���
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// �l�����x�N�g���̒����̓����擾
    /// </summary>
    /// <returns>
    /// �l�����x�N�g���̒����̓��
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// ��������̎l�����x�N�g���Ƃ̋������擾
    /// </summary>
    /// <param name="other">
    /// ��������̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��������̎l�����x�N�g���Ƃ̋���
    /// </returns>
    constexpr Float Distance(Vector4 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// ��������̎l�����x�N�g���Ƃ̋����̓����擾
    /// </summary>
    /// <param name="other">
    /// ��������̎l�����x�N�g��
    /// </param>
    /// <returns>
    /// ��������̎l�����x�N�g���Ƃ̋����̓��
    /// </returns>
    constexpr Float DistanceSquared(Vector4 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// ���K�������l�����x�N�g�����擾
    /// </summary>
    /// <returns>
    /// ���K�������l�����x�N�g��
    /// </returns>
    constexpr Vector4 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector4(); }

    /// <summary>
    /// ���K��
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
/// �X�J���[�Ƃ̏�Z���Z�q
/// </summary>
/// <param name="lhs">
/// ��Z����X�J���[
/// </param>
/// <param name="rhs">
/// ��Z�����l�����x�N�g��
/// </param>
/// <returns>
/// ��Z��̎l�����x�N�g��
/// </returns>
constexpr Vector4 const operator * (Float lhs, Vector4 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// �o�̓X�g���[���Ɏl�����x�N�g����n��
/// </summary>
std::ostream & operator << (std::ostream & os, Vector4 const & v);

} // namespace Math
