#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// �񎟌��x�N�g���N���X(���������_���^)
/// </summary>
class Vector2
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// x����
            /// </summary>
            Float x;
            /// <summary>
            /// y����
            /// </summary>
            Float y;
        };
        struct
        {
            /// <summary>
            /// u����
            /// </summary>
            Float u;
            /// <summary>
            /// rhs����
            /// </summary>
            Float v;
        };
        struct
        {
            /// <summary>
            /// ��
            /// </summary>
            Float width;
            /// <summary>
            /// ����
            /// </summary>
            Float height;
        };
        Float _[3];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    constexpr Vector2() noexcept : Vector2(static_cast<Float>(0)) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="x">
    /// x ����
    /// </param>
    /// <param name="y">
    /// y ����
    /// </param>
    constexpr Vector2(Float x, Float y) noexcept : x(x), y(y) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="value">
    /// x ������ y �����Ɋ��蓖�Ă�l
    /// </param>
    constexpr explicit Vector2(Float value) noexcept : Vector2(value, value) { }

    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Vector2 const operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1 �ɂ���Z����
    /// </returns>
    constexpr Vector2 const operator - () const noexcept { return { -x, -y }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator + (Vector2 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator - (Vector2 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y }; }

    /// <summary>
    /// �A�_�}�[����(�������ɏ�Z)
    /// </summary>
    /// <param name="rhs">
    /// ��Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator * (Vector2 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y }; }

    /// <summary>
    /// �t���v�f�Ƃ̃A�_�}�[����(�������ɏ��Z)
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator / (Vector2 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y }; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// ��Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs }; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs }; }

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g������������
    /// </returns>
    constexpr bool operator == (Vector2 const & rhs) const noexcept { return x == rhs.x && y == rhs.y; }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g�����������Ȃ���
    /// </returns>
    constexpr bool operator != (Vector2 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector2 & operator += (Vector2 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z������Z�q
    /// </returns>
    Vector2 & operator -= (Vector2 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector2 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector2 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 1)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�����ւ̎Q��
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 1)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ����
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// ��̓񎟌��x�N�g�����قړ����������擾
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g�����قړ�������
    /// </returns>
    constexpr bool Approximately(Vector2 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y); }

    /// <summary>
    /// ��̓񎟌��x�N�g���̓��ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g���̓���
    /// </returns>
    constexpr Float Dot(Vector2 const & rhs) const noexcept { return x * rhs.x + y * rhs.y; }

    /// <summary>
    /// ��̓񎟌��x�N�g���̊O�ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g���̊O��
    /// </returns>
    constexpr Float Cross(Vector2 const & rhs) const noexcept { return x * rhs.y - y * rhs.x; }

    /// <summary>
    /// �񎟌��x�N�g���̒������擾
    /// </summary>
    /// <returns>
    /// �񎟌��x�N�g���̒���
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// �񎟌��x�N�g���̒����̓����擾
    /// </summary>
    /// <returns>
    /// �񎟌��x�N�g���̒����̓��
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// ��������̓񎟌��x�N�g���Ƃ̋������擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��������̓񎟌��x�N�g���Ƃ̋���
    /// </returns>
    constexpr Float Distance(Vector2 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// ��������̓񎟌��x�N�g���Ƃ̋����̓����擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��������̓񎟌��x�N�g���Ƃ̋����̓��
    /// </returns>
    constexpr Float DistanceSquared(Vector2 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// ��������̓񎟌��x�N�g���Ƃ̂Ȃ��p(�����Ȃ�)���擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��������̓񎟌��x�N�g���Ƃ̂Ȃ��p(�����Ȃ�)
    /// </returns>
    Float Angle(Vector2 const & other) const { return Math::Acos(Normalized().Dot(other.Normalized())); }

    /// <summary>
    /// �@������ɔ��˂����񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="normal">
    /// �@���x�N�g��
    /// </param>
    /// <returns>
    /// �@������ɔ��˂����񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Reflect(Vector2 const & normal) const noexcept { auto n = normal.Normalized(); return *this + n * 2 * Dot(-n); }

    /// <summary>
    /// ���K�������񎟌��x�N�g�����擾
    /// </summary>
    /// <returns>
    /// ���K�������񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector2(); }

    /// <summary>
    /// ���K��
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// ��̓񎟌��x�N�g������`���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̓񎟌��x�N�g���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g���̊Ԃ̐��`��Ԃ��ꂽ�񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Lerp(Vector2 const & other, Float t) const noexcept { return { Math::Lerp(x, other.x, t), Math::Lerp(y, other.y, t) }; }

    /// <summary>
    /// ��̓񎟌��x�N�g����Hermite���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̓񎟌��x�N�g���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g���̊Ԃ�Hermite��Ԃ��ꂽ�񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const SmoothStep(Vector2 const & other, Float t) const noexcept { return { Math::Smoothstep(x, other.x, t), Math::Smoothstep(y, other.y, t) }; }

    /// <summary>
    /// �������ق��̗v�f�����񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// �������ق��̗v�f�����񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Min(Vector2 const & other) const { return { Math::Min(x, other.x), Math::Min(y, other.y) }; }

    /// <summary>
    /// �傫���ق��̗v�f�����񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// �傫���ق��̗v�f�����񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Max(Vector2 const & other) const { return { Math::Max(x, other.x), Math::Max(y, other.y) }; }

    /// <summary>
    /// �����Ə���͈̔͂Ɏ��߂��񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="min">
    /// ���߂�͈͂̉���
    /// </param>
    /// <param name="max">
    /// ���߂�͈͂̏��
    /// </param>
    /// <returns>
    /// �����Ə���͈̔͂Ɏ��߂��񎟌��x�N�g��
    /// </returns>
    constexpr Vector2 const Clamp(Vector2 const & min, Vector2 const & max) const { return min.Max(max.Min(*this)); }

    /// <summary>
    /// �����Ə���͈͓̔������擾
    /// </summary>
    /// <param name="min">
    /// �͈͂̉���
    /// </param>
    /// <param name="max">
    /// �͈͂̏��
    /// </param>
    /// <returns>
    /// �����Ə���͈͓̔���
    /// </returns>
    constexpr bool InRange(Vector2 const & min, Vector2 const & max) const { return Math::InRange(x, min.x, max.x) && Math::InRange(y, min.y, max.y); }

    /// <summary>
    /// �ړI�n�ւ̎O���������x�N�g�����擾
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <returns>
    /// �ړI�n�ւ̎O�����x�N�g��
    /// </returns>
    constexpr Vector2 const To(Vector2 const & target) const noexcept { return target - *this; }

    /// <summary>
    /// �ړI�n�ւ̎O�����P�ʃx�N�g�����擾
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <returns>
    /// �ړI�n�ւ̎O�����P�ʃx�N�g��
    /// </returns>
    constexpr Vector2 const Direction(Vector2 const & target) const noexcept { return To(target).Normalized(); }

    /// <summary>
    /// �ړI�n�ֈړ�(�ړI�n��ʂ�߂��Ȃ�)
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <param name="speed">
    /// �ő呬�x
    /// </param>
    void MoveTowards(Vector2 const & target, float speed) noexcept { *this += Direction(target) * Math::Min(speed, Distance(target)); }

    /// <summary>
    /// �A�X�y�N�g����擾
    /// </summary>
    /// <returns>
    /// �A�X�y�N�g��
    /// </returns>
    constexpr Float Aspect() const noexcept { return width / height; }

    /// <summary>
    /// ��x�N�g�������擾
    /// </summary>
    /// <returns>
    /// ��x�N�g����
    /// </returns>
    constexpr bool IsZero() const noexcept { return x == static_cast<Float>(0) && y == static_cast<Float>(0); }

    /// <summary>
    /// { x, x }
    /// </summary>
    constexpr Vector2 const xx() const noexcept { return { x, x }; }

    /// <summary>
    /// { x, y }
    /// </summary>
    constexpr Vector2 const xy() const noexcept { return { x, y }; }

    /// <summary>
    /// { y, x }
    /// </summary>
    constexpr Vector2 const yx() const noexcept { return { y, x }; }

    /// <summary>
    /// { y, y }
    /// </summary>
    constexpr Vector2 const yy() const noexcept { return { y, y }; }

    /// <summary>
    /// {  0,  0 }
    /// </summary>
    static Vector2 const Zero;

    /// <summary>
    /// {  1,  1 }
    /// </summary>
    static Vector2 const One;

    /// <summary>
    /// {  1,  0 }
    /// </summary>
    static Vector2 const UnitX;

    /// <summary>
    /// {  0,  1 }
    /// </summary>
    static Vector2 const UnitY;

    /// <summary>
    /// { -1,  0 }
    /// </summary>
    static Vector2 const Left;

    /// <summary>
    /// {  1,  0 }
    /// </summary>
    static Vector2 const Right;

    /// <summary>
    /// {  0, -1 }
    /// </summary>
    static Vector2 const Up;

    /// <summary>
    /// {  0,  1 }
    /// </summary>
    static Vector2 const Down;

};

/// <summary>
/// �X�J���[�Ƃ̏�Z���Z�q
/// </summary>
/// <param name="lhs">
/// ��Z����X�J���[
/// </param>
/// <param name="rhs">
/// ��Z�����񎟌��x�N�g��
/// </param>
/// <returns>
/// ��Z��̓񎟌��x�N�g��
/// </returns>
constexpr Vector2 const operator * (Float lhs, Vector2 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// �o�̓X�g���[���ɓ񎟌��x�N�g����n��
/// </summary>
std::ostream & operator << (std::ostream & os, Vector2 const & v);

} // namespace Math
