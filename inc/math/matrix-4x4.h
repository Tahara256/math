#pragma once

#include "vector-3.h"
#include "vector-4.h"

namespace Math
{

/// <summary>
/// 4 �~ 4 �s��
/// </summary>
class Matrix4x4
{

public:

    union
    {
        struct
        {
            Float m11, m12, m13, m14;
            Float m21, m22, m23, m24;
            Float m31, m32, m33, m34;
            Float m41, m42, m43, m44;
        };
        Float m[4][4];
        struct
        {
            /// <summary>
            /// ��s��
            /// </summary>
            Vector4 r1;
            /// <summary>
            /// ��s��
            /// </summary>
            Vector4 r2;
            /// <summary>
            /// �O�s��
            /// </summary>
            Vector4 r3;
            /// <summary>
            /// �l�s��
            /// </summary>
            Vector4 r4;
        };
        Vector4 r[4];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^(�P�ʍs��)
    /// </summary>
    Matrix4x4();

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Matrix4x4(
        Float m11, Float m12, Float m13, Float m14,
        Float m21, Float m22, Float m23, Float m24,
        Float m31, Float m32, Float m33, Float m34,
        Float m41, Float m42, Float m43, Float m44) noexcept;

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="r0">
    /// 1�s��
    /// </param>
    /// <param name="r1">
    /// 2�s��
    /// </param>
    /// <param name="r2">
    /// 3�s��
    /// </param>
    /// <param name="r3">
    /// 4�s��
    /// </param>
    Matrix4x4(Vector4 const & r1, Vector4 const & r2, Vector4 const & r3, Vector4 const & r4) noexcept;

    /// <summary>
    /// �R�s�[�R���X�g���N�^
    /// </summary>
    /// <param name="other">
    /// �R�s�[���̍s��
    /// </param>
    Matrix4x4(Matrix4x4 const & other);

    /// <summary>
    /// �R�s�[������Z�q
    /// </summary>
    /// <param name="other">
    /// �R�s�[���̍s��
    /// </param>
    /// <returns>
    /// ���g�ւ̎Q��
    /// </returns>
    Matrix4x4 & operator = (Matrix4x4 const & other);

    /// <summary>
    /// �O�����x�N�g���Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="other">
    /// �ϊ�����O�����x�N�g��
    /// </param>
    /// <returns>
    /// �ϊ���̎O�����x�N�g��
    /// </returns>
    Vector3 const operator * (Vector3 const & other) const;

    /// <summary>
    /// �l�����x�N�g���Ƃ̏�Z���Z�q
    /// </summary>
    /// <param name="other">
    /// �ϊ�����l�����x�N�g��
    /// </param>
    /// <returns>
    /// �ϊ���̎l�����x�N�g��
    /// </returns>
    Vector4 const operator * (Vector4 const & other) const;

    /// <summary>
    /// �s�񓯎m�̏�Z���Z�q
    /// </summary>
    /// <param name="other">
    /// ��������s��
    /// </param>
    /// <returns>
    /// ������̍s��
    /// </returns>
    Matrix4x4 const operator * (Matrix4x4 const & other) const;

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪓�������
    /// </returns>
    bool operator == (Matrix4x4 const & other) const;

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪓������Ȃ���
    /// </returns>
    bool operator != (Matrix4x4 const & other) const;

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������s�̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�s�ւ̎Q��
    /// </returns>
    Vector4 & operator [] (std::size_t index);

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������s�̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�s
    /// </returns>
    Vector4 const & operator [] (std::size_t index) const;

    /// <summary>
    /// �w�肳�ꂽ����擾
    /// </summary>
    /// <param name="index">
    /// �擾�����̃C���f�b�N�X(0 �` 3)
    /// </param>
    /// <returns>
    /// �w�肳�ꂽ��
    /// </returns>
    Vector4 const Column(std::size_t index) const;

    /// <summary>
    /// ��̍s�񂪂قړ����������擾
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪂قړ�������
    /// </returns>
    bool Approximately(Matrix4x4 const & other) const noexcept;

    /// <summary>
    /// �s�񎮂��擾
    /// </summary>
    /// <returns>
    /// �s��
    /// </returns>
    Float Determinant() const noexcept;

    /// <summary>
    /// �t�s����擾
    /// </summary>
    /// <returns>
    /// �t�s��
    /// </returns>
    Matrix4x4 const Inverse() const noexcept;

    /// <summary>
    /// �]�u�s����擾
    /// </summary>
    /// <returns>
    /// �]�u�s��
    /// </returns>
    Matrix4x4 const Transpose() const noexcept;

    /// <summary>
    /// �I�C���[�p���擾
    /// </summary>
    /// <returns>
    /// �I�C���[�p
    /// </returns>
    Vector3 const EulerAngles() const noexcept;

    /// <summary>
    /// �P�ʍs��
    /// </summary>
    static Matrix4x4 const Identity;

    /// <summary>
    /// ��s��
    /// </summary>
    static Matrix4x4 const Zero;

    /// <summary>
    /// �g��k���s����쐬
    /// </summary>
    /// <param name="scale">
    /// �g��k��
    /// </param>
    /// <returns>
    /// �g��k���s��
    /// </returns>
    static Matrix4x4 const CreateScale(Float scale);

    /// <summary>
    /// �g��k���s����쐬
    /// </summary>
    /// <param name="scale">
    /// XYZ�̂��ꂼ��̎��ɑ΂��Ă̊g��k��
    /// </param>
    /// <returns>
    /// �g��k���s��
    /// </returns>
    static Matrix4x4 const CreateScale(Vector3 const & scale);

    /// <summary>
    /// X���̉�]�s����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// X���̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationX(Float angle);

    /// <summary>
    /// Y���̉�]�s����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// Y���̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationY(Float angle);

    /// <summary>
    /// Z���̉�]�s����쐬
    /// </summary>
    /// <param name="angle">
    /// ��]�p�x(�ʓx�@)
    /// </param>
    /// <returns>
    /// Z���̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationZ(Float angle);

    /// <summary>
    /// �C�ӎ��̉�]�s����쐬(�P�ʃx�N�g���Ŏ��w��)
    /// </summary>
    /// <param name="unitAxis">
    /// ��]��(�P�ʃx�N�g��)
    /// </param>
    /// <param name="angle">
    /// �ʓx�@�̊p�x
    /// </param>
    /// <returns>
    /// �C�ӎ��̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationUnitAxisAngle(Vector3 const & unitAxis, Float angle);

    /// <summary>
    /// �C�ӎ��̉�]�s����쐬
    /// </summary>
    /// <param name="axis">
    /// ��]��(�C�ӂ̒���)
    /// </param>
    /// <param name="angle">
    /// �ʓx�@�̊p�x
    /// </param>
    /// <returns>
    /// �C�ӎ��̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationAxisAngle(Vector3 const & axis, Float angle);

    /// <summary>
    /// �I�C���[�p(Z��X��Y��])�ŉ�]�s����쐬
    /// </summary>
    /// <param name="eulerAngles">
    /// �I�C���[�p
    /// </param>
    /// <returns>
    /// ��]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationEulerAngles(Vector3 const & eulerAngles);

    /// <summary>
    /// �w��������������߂̉�]�s����쐬
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
    /// �w��������������߂̉�]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// �����x�N�g�������]�s����쐬(�P�ʃx�N�g���ŕ����w��)
    /// </summary>
    /// <param name="unitDirection">
    /// �����x�N�g��(�P�ʃx�N�g��)
    /// </param>
    /// <param name="up">
    /// ������Ƃ���x�N�g��
    /// </param>
    /// <returns>
    /// ��]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationUnitDirection(Vector3 const & unitDirection, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// �����x�N�g�������]�s����쐬
    /// </summary>
    /// <param name="direction">
    /// �����x�N�g��(�C�ӂ̒���)
    /// </param>
    /// <param name="up">
    /// ������Ƃ���x�N�g��
    /// </param>
    /// <returns>
    /// ��]�s��
    /// </returns>
    static Matrix4x4 const CreateRotationDirection(Vector3 const & direction, Vector3 const & up = Vector3::Up);

    /// <summary>
    /// ���W���畽�s�ړ��s����쐬
    /// </summary>
    /// <param name="position">
    /// ���W
    /// </param>
    /// <returns>
    /// ���W����쐬�����ύX�ړ��s��
    /// </returns>
    static Matrix4x4 const CreateTranslation(Vector3 const & position);

    /// <summary>
    /// �p�[�X�y�N�e�B�u�̃v���W�F�N�V�����s����쐬
    /// </summary>
    /// <param name="fovAngleY">
    /// Y�����̎���p
    /// </param>
    /// <param name="aspect">
    /// �A�X�y�N�g��
    /// </param>
    /// <param name="nearZ">
    /// �߂��̃r���[�v���[��
    /// </param>
    /// <param name="farZ">
    /// �����̃r���[�v���[��
    /// </param>
    /// <returns>
    /// �p�[�X�y�N�e�B�u�̃v���W�F�N�V�����s��
    /// </returns>
    static Matrix4x4 const CreatePerspective(Float fovAngleY, Float aspect, Float nearZ, Float farZ);

};

/// <summary>
/// �o�̓X�g���[���� 4 �~ 4 �s���n��
/// </summary>
std::ostream & operator << (std::ostream & os, Matrix4x4 const & m);

} // namespace Math
