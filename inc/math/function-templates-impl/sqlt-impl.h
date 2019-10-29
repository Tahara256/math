#pragma once

namespace Math
{

namespace Impl
{

/// <summary>
/// �ċA�Łu�o�r���j�A�̕������v���g�p���ĕ����������߂�
/// </summary>
/// <param name="value">
/// ���������擾�������l
/// </param>
/// <param name="previous">
/// �������ɂȂ�ׂ��߂��l(���̃p�����[�^���ċA���Ƃɕ������ɋ߂Â�)
/// </param>
/// <returns>
/// ������
/// </returns>
template <class TFloat>
constexpr TFloat RecursiveBabylonianMethod(TFloat value, TFloat previous) noexcept
{
    auto const result = ((previous + value / previous) / static_cast<TFloat>(2));
    return result == previous ? result : RecursiveBabylonianMethod(value, result);
}

} // namespace Impl

} // namespace Math
