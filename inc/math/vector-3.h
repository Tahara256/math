#pragma once

#include <iostream>
#include "use-type.h"
#include "function-templates.h"

namespace Math
{

/// <summary>
/// �O�����x�N�g���N���X(���������_���^)
/// </summary>
class Vector3
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
        };
        Float _[3];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    constexpr Vector3() noexcept : Vector3(static_cast<Float>(0)) { }

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
    constexpr Vector3(Float x, Float y, Float z) noexcept : x(x), y(y), z(z) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="value">
    /// xyz �����S�ĂɊ��蓖�Ă�l
    /// </param>
    constexpr explicit Vector3(Float value) noexcept : Vector3(value, value, value) { }

    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Vector3 const operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1�ɂ���Z����
    /// </returns>
    constexpr Vector3 const operator - () const noexcept { return { -x, -y, -z }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator + (Vector3 const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator - (Vector3 const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z }; }

    /// <summary>
    /// �A�_�}�[����(�������ɏ�Z)
    /// </summary>
    /// <param name="rhs">
    /// ��Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator * (Vector3 const & rhs) const noexcept { return { x * rhs.x, y * rhs.y, z * rhs.z }; }

    /// <summary>
    /// �t���v�f�Ƃ̃A�_�}�[����(�������ɏ��Z)
    /// </summary>
    /// <param name="rhs">
    /// ���Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator / (Vector3 const & rhs) const noexcept { return { x / rhs.x, y / rhs.y, z / rhs.z }; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// ��Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs }; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// ���Z��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs }; }

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g������������
    /// </returns>
    constexpr bool operator == (Vector3 const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z; }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g�����������Ȃ���
    /// </returns>
    constexpr bool operator != (Vector3 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector3 & operator += (Vector3 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����O�����x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector3 & operator -= (Vector3 const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector3 & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z�����̎��g�ւ̎Q��
    /// </returns>
    Vector3 & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 2)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�����ւ̎Q��
    /// </returns>
    Float & operator [] (std::size_t index) noexcept { return _[index]; }

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 2)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ����
    /// </returns>
    constexpr Float operator [] (std::size_t index) const noexcept { return _[index]; }

    /// <summary>
    /// ��̎O�����x�N�g�����قړ����������擾
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g�����قړ�������
    /// </returns>
    constexpr bool Approximately(Vector3 const & rhs) const noexcept { return Math::Approximately(x, rhs.x) && Math::Approximately(y, rhs.y) && Math::Approximately(z, rhs.z); }

    /// <summary>
    /// ��̎O�����x�N�g���̓��ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g���̓���
    /// </returns>
    constexpr Float Dot(Vector3 const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z; }

    /// <summary>
    /// ��̎O�����x�N�g���̊O�ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g���̊O��
    /// </returns>
    constexpr Vector3 const Cross(Vector3 const & rhs) const noexcept { return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x }; }

    /// <summary>
    /// �O�����x�N�g���̒������擾
    /// </summary>
    /// <returns>
    /// �O�����x�N�g���̒���
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// �O�����x�N�g���̒����̓����擾
    /// </summary>
    /// <returns>
    /// �O�����x�N�g���̒����̓��
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// ��������̎O�����x�N�g���Ƃ̋������擾
    /// </summary>
    /// <param name="other">
    /// ��������̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��������̎O�����x�N�g���Ƃ̋���
    /// </returns>
    constexpr Float Distance(Vector3 const & other) const noexcept { return (*this - other).Length(); }

    /// <summary>
    /// ��������̎O�����x�N�g���Ƃ̋����̓����擾
    /// </summary>
    /// <param name="other">
    /// ��������̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��������̎O�����x�N�g���Ƃ̋����̓��
    /// </returns>
    constexpr Float DistanceSquared(Vector3 const & other) const noexcept { return (*this - other).LengthSquared(); }

    /// <summary>
    /// ��������̎O�����x�N�g���Ƃ̂Ȃ��p(�����Ȃ�)���擾
    /// </summary>
    /// <param name="other">
    /// ��������̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��������̎O�����x�N�g���Ƃ̂Ȃ��p(�����Ȃ�)
    /// </returns>
    Float Angle(Vector3 const & other) const { return Math::Acos(Normalized().Dot(other.Normalized())); }

    /// <summary>
    /// �@������ɔ��˂����O�����x�N�g�����擾
    /// </summary>
    /// <param name="normal">
    /// �@���x�N�g��
    /// </param>
    /// <returns>
    /// �@������ɔ��˂����O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Reflect(Vector3 const & normal) const noexcept { return ReflectUnitNormal(normal.Normalized()); }

    /// <summary>
    /// ���K�����ꂽ�@������ɔ��˂����O�����x�N�g�����擾
    /// </summary>
    /// <param name="unitNormal">
    /// ���K�����ꂽ�@���x�N�g��
    /// </param>
    /// <returns>
    /// ���K�����ꂽ�@������ɔ��˂����O�����x�N�g��
    /// </returns>
    constexpr Vector3 const ReflectUnitNormal(Vector3 const & unitNormal) const noexcept { return *this + unitNormal * static_cast<Float>(2) * Dot(-unitNormal); }

    /// <summary>
    /// ���K�������O�����x�N�g�����擾
    /// </summary>
    /// <returns>
    /// ���K�������O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Normalized() const noexcept { auto l = Length(); return l ? (*this / Length()) : Vector3(); }

    /// <summary>
    /// ���K��
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// ��̎O�����x�N�g������`���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̎O�����x�N�g���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g���̊Ԃ̐��`��Ԃ��ꂽ�O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Lerp(Vector3 const & other, Float t) const noexcept { return { Math::Lerp(x, other.x, t), Math::Lerp(y, other.y, t), Math::Lerp(z, other.z, t) }; }

    /// <summary>
    /// ��̎O�����x�N�g����Hermite���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̎O�����x�N�g���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̎O�����x�N�g���̊Ԃ�Hermite��Ԃ��ꂽ�O�����x�N�g��
    /// </returns>
    constexpr Vector3 const SmoothStep(Vector3 const & other, Float t) const noexcept { return { Math::Smoothstep(x, other.x, t), Math::Smoothstep(y, other.y, t), Math::Smoothstep(z, other.z, t) }; }

    /// <summary>
    /// �������ق��̗v�f�����O�����x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// �������ق��̗v�f�����O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Min(Vector3 const & other) const noexcept { return { Math::Min(x, other.x), Math::Min(y, other.y), Math::Min(z, other.z) }; }

    /// <summary>
    /// �傫���ق��̗v�f�����O�����x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̎O�����x�N�g��
    /// </param>
    /// <returns>
    /// �傫���ق��̗v�f�����O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Max(Vector3 const & other) const noexcept { return { Math::Max(x, other.x), Math::Max(y, other.y), Math::Max(z, other.z) }; }

    /// <summary>
    /// �����Ə���͈̔͂Ɏ��߂��O�����x�N�g�����擾
    /// </summary>
    /// <param name="min">
    /// ���߂�͈͂̉���
    /// </param>
    /// <param name="max">
    /// ���߂�͈͂̏��
    /// </param>
    /// <returns>
    /// �����Ə���͈̔͂Ɏ��߂��O�����x�N�g��
    /// </returns>
    constexpr Vector3 const Clamp(Vector3 const & min, Vector3 const & max) const noexcept { return min.Max(max.Min(*this)); }

    /// <summary>
    /// �ړI�n�ւ̎O���������x�N�g�����擾
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <returns>
    /// �ړI�n�ւ̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const To(Vector3 const & target) const noexcept { return target - *this; }

    /// <summary>
    /// �ړI�n�ւ̎O�����P�ʃx�N�g�����擾
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <returns>
    /// �ړI�n�ւ̎O�����P�ʃx�N�g��
    /// </returns>
    constexpr Vector3 const Direction(Vector3 const & target) const noexcept { return To(target).Normalized(); }

    /// <summary>
    /// �ړI�n�ֈړ����������W���擾(�ړI�n��ʂ�߂��Ȃ�)
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <param name="speed">
    /// �ő呬�x
    /// </param>
    /// <returns>
    /// �ړI�n�ֈړ����������W
    /// </returns>
    constexpr Vector3 const MovedTowards(Vector3 const & target, Float speed) const noexcept { return *this + Direction(target) * Math::Min(Distance(target), speed); }

    /// <summary>
    /// �ړI�n�ֈړ�(�ړI�n��ʂ�߂��Ȃ�)
    /// </summary>
    /// <param name="target">
    /// �ړI�n
    /// </param>
    /// <param name="speed">
    /// �ő呬�x
    /// </param>
    void MoveTowards(Vector3 const & target, Float speed) noexcept { *this = MovedTowards(target, speed); }

    /// <summary>
    /// �e�v�f���ʓx�@����x���@�֕ϊ������O�����x�N�g�����擾
    /// </summary>
    /// <returns>
    /// �e�v�f���ʓx�@����x���@�֕ϊ������O�����x�N�g��
    /// </returns>
    constexpr Vector3 const ToDegrees() const noexcept { return { Math::ToDegrees(x), Math::ToDegrees(y), Math::ToDegrees(z) }; }

    /// <summary>
    /// �e�v�f��x���@����ʓx�@�֕ϊ������O�����x�N�g�����擾
    /// </summary>
    /// <returns>
    /// �e�v�f��x���@����ʓx�@�֕ϊ������O�����x�N�g��
    /// </returns>
    constexpr Vector3 const ToRadians() const noexcept { return { Math::ToRadians(x), Math::ToRadians(y), Math::ToRadians(z) }; }

    /// <summary>
    /// ��x�N�g�������擾
    /// </summary>
    /// <returns>
    /// ��x�N�g����
    /// </returns>
    constexpr bool IsZero() const noexcept { return x == static_cast<Float>(0) && y == static_cast<Float>(0); }

    /// <summary>
    /// { x, x, x }
    /// </summary>
    constexpr Vector3 const xxx() const noexcept { return { x, x, x }; }

    /// <summary>
    /// { x, x, y }
    /// </summary>
    constexpr Vector3 const xxy() const noexcept { return { x, x, y }; }

    /// <summary>
    /// { x, x, z }
    /// </summary>
    constexpr Vector3 const xxz() const noexcept { return { x, x, z }; }

    /// <summary> 
    /// { x, y, x }
    /// </summary>
    constexpr Vector3 const xyx() const noexcept { return { x, y, x }; }

    /// <summary> 
    /// { x, y, y }
    /// </summary>
    constexpr Vector3 const xyy() const noexcept { return { x, y, y }; }

    /// <summary>
    /// { x, y, z }
    /// </summary>
    constexpr Vector3 const xyz() const noexcept { return { x, y, z }; }

    /// <summary>
    /// { x, z, x }
    /// </summary>
    constexpr Vector3 const xzx() const noexcept { return { x, z, x }; }

    /// <summary>
    /// { x, z, y }
    /// </summary>
    constexpr Vector3 const xzy() const noexcept { return { x, z, y }; }

    /// <summary>
    /// { x, z, z }
    /// </summary>
    constexpr Vector3 const xzz() const noexcept { return { x, z, z }; }

    /// <summary>
    /// { y, x, x }
    /// </summary>
    constexpr Vector3 const yxx() const noexcept { return { y, x, x }; }

    /// <summary>
    /// { y, x, y }
    /// </summary>
    constexpr Vector3 const yxy() const noexcept { return { y, x, y }; }

    /// <summary>
    /// { y, x, z }
    /// </summary>
    constexpr Vector3 const yxz() const noexcept { return { y, x, z }; }

    /// <summary>
    /// { y, y, x }
    /// </summary>
    constexpr Vector3 const yyx() const noexcept { return { y, y, x }; }

    /// <summary>
    /// { y, y, y }
    /// </summary>
    constexpr Vector3 const yyy() const noexcept { return { y, y, y }; }

    /// <summary>
    /// { y, y, z }
    /// </summary>
    constexpr Vector3 const yyz() const noexcept { return { y, y, z }; }

    /// <summary>
    /// { y, z, x }
    /// </summary>
    constexpr Vector3 const yzx() const noexcept { return { y, z, x }; }

    /// <summary>
    /// { y, z, y }
    /// </summary>
    constexpr Vector3 const yzy() const noexcept { return { y, z, y }; }

    /// <summary>
    /// { y, z, z }
    /// </summary>
    constexpr Vector3 const yzz() const noexcept { return { y, z, z }; }

    /// <summary>
    /// { z, x, x }
    /// </summary>
    constexpr Vector3 const zxx() const noexcept { return { z, x, x }; }

    /// <summary>
    /// { z, x, y }
    /// </summary>
    constexpr Vector3 const zxy() const noexcept { return { z, x, y }; }

    /// <summary>
    /// { z, x, z }
    /// </summary>
    constexpr Vector3 const zxz() const noexcept { return { z, x, z }; }

    /// <summary>
    /// { z, y, x }
    /// </summary>
    constexpr Vector3 const zyx() const noexcept { return { z, y, x }; }

    /// <summary>
    /// { z, y, y }
    /// </summary>
    constexpr Vector3 const zyy() const noexcept { return { z, y, y }; }

    /// <summary>
    /// { z, y, z }
    /// </summary>
    constexpr Vector3 const zyz() const noexcept { return { z, y, z }; }

    /// <summary>
    /// { z, z, x }
    /// </summary>
    constexpr Vector3 const zzx() const noexcept { return { z, z, x }; }

    /// <summary>
    /// { z, z, y }
    /// </summary>
    constexpr Vector3 const zzy() const noexcept { return { z, z, y }; }

    /// <summary>
    /// { z, z, z }
    /// </summary>
    constexpr Vector3 const zzz() const noexcept { return { z, z, z }; }

    /// <summary>
    /// {  0,  0,  0 }
    /// </summary>
    static Vector3 const Zero;

    /// <summary>
    /// {  1,  1,  1 }
    /// </summary>
    static Vector3 const One;

    /// <summary>
    /// {  1,  0,  0 }
    /// </summary>
    static Vector3 const UnitX;

    /// <summary>
    /// {  0,  1,  0 }
    /// </summary>
    static Vector3 const UnitY;

    /// <summary>
    /// {  0,  0,  1 }
    /// </summary>
    static Vector3 const UnitZ;

    /// <summary>
    /// { -1,  0,  0 }
    /// </summary>
    static Vector3 const Left;

    /// <summary>
    /// {  1,  0,  0 }
    /// </summary>
    static Vector3 const Right;

    /// <summary>
    /// {  0, -1,  0 }
    /// </summary>
    static Vector3 const Down;

    /// <summary>
    /// {  0,  1,  0 }
    /// </summary>
    static Vector3 const Up;

    /// <summary>
    /// {  0,  0, -1 }
    /// </summary>
    static Vector3 const Back;

    /// <summary>
    /// {  0,  0,  1 }
    /// </summary>
    static Vector3 const Forward;

};

/// <summary>
/// �X�J���[�Ƃ̏�Z���Z�q
/// </summary>
/// <param name="lhs">
/// ��Z����X�J���[
/// </param>
/// <param name="rhs">
/// ��Z�����O�����x�N�g��
/// </param>
/// <returns>
/// ��Z��̎O�����x�N�g��
/// </returns>
constexpr Vector3 const operator * (Float lhs, Vector3 const & rhs) noexcept { return rhs * lhs; }

/// <summary>
/// �o�̓X�g���[���ɎO�����x�N�g����n��
/// </summary>
std::ostream & operator << (std::ostream & os, Vector3 const & v);

} // namespace Math
