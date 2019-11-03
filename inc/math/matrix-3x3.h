#pragma once

#include "vector-3.h"

namespace Math
{

/// <summary>
/// 3 �~ 3 �s��
/// </summary>
class Matrix3x3
{

public:

    union
    {
        struct
        {
            Float m11, m12, m13;
            Float m21, m22, m23;
            Float m31, m32, m33;
        };
        Float m[3][3];
        struct
        {
            /// <summary>
            /// ��s��
            /// </summary>
            Vector3 r1;
            /// <summary>
            /// ��s��
            /// </summary>
            Vector3 r2;
            /// <summary>
            /// �O�s��
            /// </summary>
            Vector3 r3;
        };
        Vector3 r[3];
    };

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^(�P�ʍs��)
    /// </summary>
    Matrix3x3();

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Matrix3x3(
        Float m11, Float m12, Float m13,
        Float m21, Float m22, Float m23,
        Float m31, Float m32, Float m33) noexcept;

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
    Matrix3x3(Vector3 const & r1, Vector3 const & r2, Vector3 const & r3) noexcept;

    /// <summary>
    /// �R�s�[�R���X�g���N�^
    /// </summary>
    /// <param name="other">
    /// �R�s�[���̍s��
    /// </param>
    Matrix3x3(Matrix3x3 const & other);

    /// <summary>
    /// �R�s�[������Z�q
    /// </summary>
    /// <param name="other">
    /// �R�s�[���̍s��
    /// </param>
    /// <returns>
    /// ���g�ւ̎Q��
    /// </returns>
    Matrix3x3 & operator = (Matrix3x3 const & other);

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
    /// �s�񓯎m�̏�Z���Z�q
    /// </summary>
    /// <param name="other">
    /// ��������s��
    /// </param>
    /// <returns>
    /// ������̍s��
    /// </returns>
    Matrix3x3 const operator * (Matrix3x3 const & other) const;

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪓�������
    /// </returns>
    bool operator == (Matrix3x3 const & other) const;

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪓������Ȃ���
    /// </returns>
    bool operator != (Matrix3x3 const & other) const;

    /// <summary>
    /// �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������s�̃C���f�b�N�X(0 �` 2)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�s�ւ̎Q��
    /// </returns>
    Vector3 & operator [] (std::size_t index);

    /// <summary>
    /// const �Y�����Z�q
    /// </summary>
    /// <param name="index">
    /// �擾�������s�̃C���f�b�N�X(0 �` 2)
    /// </param>
    /// <returns>
    /// �C���f�b�N�X�Ŏw�肳�ꂽ�s
    /// </returns>
    Vector3 const & operator [] (std::size_t index) const;

    /// <summary>
    /// �w�肳�ꂽ����擾
    /// </summary>
    /// <param name="index">
    /// �擾�����̃C���f�b�N�X(0 �` 2)
    /// </param>
    /// <returns>
    /// �w�肳�ꂽ��
    /// </returns>
    Vector3 const Column(std::size_t index) const;

    /// <summary>
    /// ��̍s�񂪂قړ����������擾
    /// </summary>
    /// <param name="other">
    /// ��r�Ώۂ̍s��
    /// </param>
    /// <returns>
    /// ��̍s�񂪂قړ�������
    /// </returns>
    bool Approximately(Matrix3x3 const & other) const noexcept;

    /// <summary>
    /// �s�񎮂��擾
    /// </summary>
    /// <returns>
    /// �s��
    /// </returns>
    Float Determinant() const noexcept;

    /// <summary>
    /// �]�u�s����擾
    /// </summary>
    /// <returns>
    /// �]�u�s��
    /// </returns>
    Matrix3x3 const Transpose() const noexcept;

    /// <summary>
    /// �P�ʍs��
    /// </summary>
    static Matrix3x3 const Identity;

    /// <summary>
    /// ��s��
    /// </summary>
    static Matrix3x3 const Zero;

};

} // namespace Math
