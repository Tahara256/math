#pragma once

#include <math-lib.h>

namespace Math
{

/// <summary>
/// ���C(����)�N���X
/// </summary>
class Ray
{

public:

    /// <summary>
    /// ���C�̌��_�ƕ����������x�N�g���̌^
    /// </summary>
    using Vector = Math::Vector3;

    /// <summary>
    /// �X�J���[�{�Ŏg�p��������^
    /// </summary>
    using Scalar = decltype(Math::Vector3::x);


    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    Ray() noexcept;

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="origin">
    /// ���C�̌��_
    /// </param>
    /// <param name="direction">
    /// ���C�̕���
    /// </param>
    Ray(Vector origin, Vector direction) noexcept;


    /// <summary>
    /// ���C�̌��_���擾
    /// </summary>
    /// <returns>
    /// ���C�̌��_
    /// </returns>
    Vector GetOrigin() const noexcept;

    /// <summary>
    /// ���C�̕���(�P�ʃx�N�g��)���擾
    /// </summary>
    /// <returns>
    /// ���C�̕���(�P�ʃx�N�g��)
    /// </returns>
    Vector GetDirection() const noexcept;


    /// <summary>
    /// ���C�̌��_�ݒ�
    /// </summary>
    /// <param name="origin">
    /// ���C�̌��_
    /// </param>
    void SetOrigin(Vector const & origin) noexcept;

    /// <summary>
    /// ���C�̕���(�P�ʃx�N�g��)��ݒ�
    /// </summary>
    /// <param name="direction">
    /// ���C�̕���(�P�ʃx�N�g��)
    /// </param>
    void SetDirection(Vector const & direction) noexcept;


    /// <summary>
    /// �n�_��������ɔC�ӂ̋��������i�񂾓_���擾
    /// </summary>
    /// <param name="distance">
    /// �n�_����̋���
    /// </param>
    /// <returns>
    /// �n�_��������ɔC�ӂ̋��������i�񂾓_
    /// </returns>
    Vector Point(Scalar distance) const noexcept;

    /// <summary>
    /// �C�ӂ̋��������i�߂����C���擾
    /// </summary>
    /// <param name="distance">
    /// �i�߂鋗��
    /// </param>
    /// <returns>
    /// �C�ӂ̋��������i�߂����C
    /// </returns>
    Ray MovedForward(Scalar distance) const noexcept;

    /// <summary>
    /// �C�ӂ̋����������C��i�߂�
    /// </summary>
    /// <param name="distance">
    /// �i�߂鋗��
    /// </param>
    void MoveForward(Scalar distance) noexcept;

private:

    /// <summary>
    /// ���C�̌��_
    /// </summary>
    Vector m_origin;

    /// <summary>
    /// ���C�̕���(�P�ʃx�N�g��)
    /// </summary>
    Vector m_direction;

};

} // namespace Math
