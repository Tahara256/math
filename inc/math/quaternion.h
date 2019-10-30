#pragma once

#include "vector-3.h"

namespace Math
{

/// <summary>
/// 4 �~ 4 �s��
/// </summary>
class Matrix4x4;

/// <summary> �N�H�[�^�j�I��(�l����) </summary>
class Quaternion
{

public:

    union
    {
        struct
        {
            /// <summary>
            /// ����(�x�N�g������)
            /// </summary>
            Vector3 v;
            /// <summary>
            /// ����(�X�J���[����)
            /// </summary>
            Float s;
        };
        struct
        {
            /// <summary>
            /// x(i)����
            /// </summary>
            Float x;
            /// <summary>
            /// y(j)����
            /// </summary>
            Float y;
            /// <summary>
            /// z(k)����
            /// </summary>
            Float z;
            /// <summary>
            /// w(a)����
            /// </summary>
            Float w;
        };
        struct
        {
            /// <summary>
            /// i(x)����
            /// </summary>
            Float i;
            /// <summary>
            /// j(y)����
            /// </summary>
            Float j;
            /// <summary>
            /// k(z)����
            /// </summary>
            Float k;
            /// <summary>
            /// a(w)����
            /// </summary>
            Float a;
        };
        Float _[4];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^(�P�ʃN�H�[�^�j�I��)
    /// </summary>
    constexpr Quaternion() noexcept : Quaternion(static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="x">
    /// x(i)����
    /// </param>
    /// <param name="y">
    /// y(j)����
    /// </param>
    /// <param name="z">
    /// z(k)����
    /// </param>
    /// <param name="w">
    /// w(a)����
    /// </param>
    constexpr Quaternion(Float x, Float y, Float z, Float w) noexcept : x(x), y(y), z(z), w(w) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="v">
    /// ����(�x�N�g������)
    /// </param>
    /// <param name="s">
    /// ����(�X�J���[����)
    /// </param>
    constexpr Quaternion(Vector3 const & v, Float s) noexcept : Quaternion(v.x, v.y, v.z, s) { };

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="v">
    /// ����(�x�N�g������)
    /// </param>
    constexpr explicit Quaternion(Vector3 const & v) noexcept : Quaternion(v, static_cast<Float>(0)) { };

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="m">
    /// ��]�s��
    /// </param>
    explicit Quaternion(Matrix4x4 const & m) noexcept;

    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Quaternion const operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1 �ɂ���Z����
    /// </returns>
    constexpr Quaternion const operator - () const noexcept { return { -x, -y, -z, -w }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ���Z��̃N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const operator + (Quaternion const & rhs) const noexcept { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ���Z��̃N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const operator - (Quaternion const & rhs) const noexcept { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z��̃N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const operator * (Float rhs) const noexcept { return { x * rhs, y * rhs, z * rhs, w * rhs }; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z��̃N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const operator / (Float rhs) const noexcept { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̃N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ��̃N�H�[�^�j�I������������
    /// </returns>
    constexpr bool operator == (Quaternion const & rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̃N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ��̃N�H�[�^�j�I�����������Ȃ���
    /// </returns>
    constexpr bool operator != (Quaternion const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary>
    /// �O�����x�N�g���Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��]������O�����x�N�g��
    /// </param>
    /// <returns>
    /// ��]��̎O�����x�N�g��
    /// </returns>
    constexpr Vector3 const operator * (Vector3 const & rhs) const noexcept { return *this * Quaternion(rhs) * Conjugate(); }

    /// <summary>
    /// �N�H�[�^�j�I�����m�̏�Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��������N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ������̃N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const operator * (Quaternion const & rhs) const noexcept { return { rhs.v * s + v * rhs.s + v.Cross(rhs.v), w * rhs.w - v.Dot(rhs) }; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Quaternion & operator += (Quaternion const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Quaternion & operator -= (Quaternion const & rhs) noexcept { return *this = *this - rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏�Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ�Z�����̎��g�ւ̎Q��
    /// </returns>
    Quaternion & operator *= (Float rhs) noexcept { return *this = *this * rhs; }

    /// <summary>
    /// �X�J���[�Ƃ̏��Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����X�J���[
    /// </param>
    /// <returns>
    /// �X�J���[�ŏ��Z�����̎��g�ւ̎Q��
    /// </returns>
    Quaternion & operator /= (Float rhs) noexcept { return *this = *this / rhs; }

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�����ւ̎Q��
    /// </returns>
    Float & operator [] (std::size_t index) { return _[index]; }

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�����������̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ����
    /// </returns>
    constexpr Float operator [] (std::size_t index) const { return _[index]; }

    /// <summary>
    /// ���������x�N�g���֕ϊ�
    /// </summary>
    /// <returns>
    /// �x�N�g���Ƃ���������
    /// </returns>
    constexpr operator Vector3() const noexcept { return { x, y, z }; }

    /// <summary>
    /// �����N�H�[�^�j�I�����擾
    /// </summary>
    /// <returns>
    /// �����N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const Conjugate() const noexcept { return { -x, -y, -z, w }; }

    /// <summary>
    /// �t�N�H�[�^�j�I�����擾
    /// </summary>
    /// <returns>
    /// �t�N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const Inverse() const noexcept { return Conjugate() / LengthSquared(); }

    /// <summary>
    /// ��̃N�H�[�^�j�I���̓��ς��擾
    /// </summary>
    /// <param name="rhs">
    /// �E�I�y�����h�̃N�H�[�^�j�I��
    /// </param>
    /// <returns>
    /// ��̃N�H�[�^�j�I���̓���
    /// </returns>
    constexpr Float Dot(Quaternion const & rhs) const noexcept { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

    /// <summary>
    /// �������擾
    /// </summary>
    /// <returns>
    /// ����
    /// </returns>
    constexpr Float Length() const noexcept { return Math::Sqrt(LengthSquared()); }

    /// <summary>
    /// �����̓����擾
    /// </summary>
    /// <returns>
    /// �����̓��
    /// </returns>
    constexpr Float LengthSquared() const noexcept { return Dot(*this); }

    /// <summary>
    /// ���K�������N�H�[�^�j�I�����擾
    /// </summary>
    /// <returns>
    /// ���K�������N�H�[�^�j�I��
    /// </returns>
    constexpr Quaternion const Normalized() const noexcept { return *this / Length(); };

    /// <summary>
    /// ���K��
    /// </summary>
    void Normalize() noexcept { *this = Normalized(); }

    /// <summary>
    /// ��̃N�H�[�^�j�I������`���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̃N�H�[�^�j�I���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̃N�H�[�^�j�I���̊Ԃ̐��`��Ԃ��ꂽ�N�H�[�^�j�I��
    /// </returns>
    Quaternion const Lerp(Quaternion const & other, Float t) const;

    /// <summary>
    /// ��̃N�H�[�^�j�I�������ʐ��`���
    /// </summary>
    /// <param name="other">
    /// �I���l
    /// </param>
    /// <param name="t">
    /// ��̃N�H�[�^�j�I���̕�Ԓl
    /// </param>
    /// <returns>
    /// ��̃N�H�[�^�j�I���̊Ԃ̋��ʐ��`��Ԃ��ꂽ�N�H�[�^�j�I��
    /// </returns>
    Quaternion const Slerp(Quaternion const & other, Float t) const;

    /// <summary>
    /// �P�ʃN�H�[�^�j�I��
    /// </summary>
    static Quaternion const Identity;

    /// <summary>
    /// X���̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// X���̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateX(Float angle);

    /// <summary>
    /// Y���̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// Y���̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateY(Float angle);

    /// <summary>
    /// Z���̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// Z���̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateZ(Float angle);

    /// <summary>
    /// �C�ӂ̎��̉�]��\���N�H�[�^�j�I�����쐬���܂��B(�P�ʃx�N�g���Ŏ��w��)
    /// </summary>
    /// <param name="unitAxis">
    /// ��]��(�P�ʃx�N�g��)
    /// </param>
    /// <param name="angle">
    /// �ʓx�@�̊p�x
    /// </param>
    /// <returns>
    /// �C�ӂ̎��̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateUnitAxisAngle(Vector3 const & unitAxis, Float angle);

    /// <summary>
    /// �C�ӂ̎��̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="axis">
    /// ��]��(�C�ӂ̒���)
    /// </param>
    /// <param name="angle">
    /// �ʓx�@�̊p�x
    /// </param>
    /// <returns>
    /// �C�ӂ̎��̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateAxisAngle(Vector3 const & axis, Float angle);

    /// <summary>
    /// �I�C���[�p(Z��X��Y��])�ŉ�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="eulerAngles">
    /// �I�C���[�p(�ʓx�@)
    /// </param>
    /// <returns>
    /// �I�C���[�p�Ŏw�肳�ꂽ��]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateEulerAngles(Vector3 const & eulerAngles);

    /// <summary>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="from">
    /// ���_���W
    /// </param>
    /// <param name="to">
    /// �����_���W
    /// </param>
    /// <param name="up">
    /// ������Ƃ���x�N�g��
    /// </param>
    /// <returns>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I�����쐬���܂��B(�P�ʃx�N�g���ŕ����w��)
    /// </summary>
    /// <param name="unitDirection">
    /// ��������������\���x�N�g��(�P�ʃx�N�g��)
    /// </param>
    /// <param name="up">
    /// ������Ƃ���x�N�g��
    /// </param>
    /// <returns>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateUnitDirection(Vector3 const & unitDirection, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I�����쐬
    /// </summary>
    /// <param name="direction">
    /// ��������������\���x�N�g��(�C�ӂ̒���)
    /// </param>
    /// <param name="up">
    /// ������Ƃ���x�N�g��
    /// </param>
    /// <returns>
    /// �w��������������߂̉�]��\���N�H�[�^�j�I��
    /// </returns>
    static Quaternion const CreateDirection(Vector3 const & direction, Vector3 const & up = Vector3::Up);
};

/// <summary>
/// �o�̓X�g���[���ɃN�H�[�^�j�I����n��
/// </summary>
std::ostream & operator << (std::ostream & os, Quaternion const & q);

} // namespace Math
