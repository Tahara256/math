#pragma once

#include "use-type.h"

namespace Math
{

/// <summary>
/// ��l���z�����擾�C���^�t�F�[�X
/// </summary>
class IRandom
{

public:

    virtual ~IRandom() = default;

    /// <summary>
    /// [  0,   1] �̋�Ԃ̃����_���� ���������_���^ �̒l���擾
    /// </summary>
    virtual Float Range() = 0;

    /// <summary>
    /// [  0, max] �̋�Ԃ̃����_���� ���������_���^ �̒l���擾
    /// </summary>
    virtual Float Range(Float max) = 0;

    /// <summary>
    /// [min, max] �̋�Ԃ̃����_���� ���������_���^ �̒l���擾
    /// </summary>
    virtual Float Range(Float min, Float max) = 0;

};

} // namespace Math
