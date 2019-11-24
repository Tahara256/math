#pragma once

#include "use-type.h"

namespace Math
{

/// <summary>
/// ��`�̑傫����\���N���X
/// </summary>
template <class T>
class RectSize
{

public:

    /// <summary>
    /// ���ƍ����̑傫����\���^
    /// </summary>
    using Elem = T;


    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="width">
    /// ��
    /// </param>
    /// <param name="height">
    /// ����
    /// </param>
    constexpr RectSize(Elem width, Elem height) noexcept : m_width(width), m_height(height) { }


    /// <summary>
    /// �����擾
    /// </summary>
    constexpr Elem GetWidth() const noexcept { return m_width; }

    /// <summary>
    /// �������擾
    /// </summary>
    constexpr Elem GetHeight() const noexcept { return m_height; }


    /// <summary>
    /// ����ݒ�
    /// </summary>
    /// <param name="width">
    /// ��
    /// </param>
    void SetWidth(Elem width) noexcept { m_width = width; }

    /// <summary>
    /// ������ݒ�
    /// </summary>
    /// <param name="height">
    /// ����
    /// </param>
    void SetHeight(Elem height) noexcept { m_height = height; }


    /// <summary>
    /// �A�X�y�N�g����擾
    /// </summary>
    /// <returns>
    /// �A�X�y�N�g��
    /// </returns>
    constexpr Float GetAspect() const noexcept { return static_cast<Float>(GetWidth()) / GetHeight(); }

private:

    /// <summary>
    /// ��
    /// </summary>
    Elem m_width;

    /// <summary>
    /// ����
    /// </summary>
    Elem m_height;

};

} // namespace Math
