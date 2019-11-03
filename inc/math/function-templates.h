#pragma once

#include <cmath>
#include "constants.h"
#include "meta-functions.h"
#include "function-templates-impl/sqlt-impl.h"

/* ���w�֐� templates */
namespace Math
{

/// <summary>
/// �l�� 0 �����擾
/// </summary>
template <class T>
constexpr bool IsZero(T value) noexcept
{
    return value == static_cast<T>(0);
}

/// <summary>
/// �l�� ���̒l �����擾
/// </summary>
template <class T>
constexpr bool IsPlus(T value) noexcept
{
    return value >= static_cast<T>(0);
}

/// <summary>
/// �l�� ���̒l �����擾
/// </summary>
template <class T>
constexpr bool IsMinus(T value) noexcept
{
    return value < static_cast<T>(0);
}

/// <summary>
/// ��Βl���擾
/// </summary>
template <class T>
constexpr T Abs(T value) noexcept
{
    return value < static_cast<T>(0) ? -value : value;
}

/// <summary>
/// �w�肳�ꂽ�l���A0 �����̏ꍇ�� -1 �A0 �̏ꍇ�� 0�A0 ���傫���ꍇ�� 1 �����ꂼ��擾
/// </summary>
/// <param name="value">
/// �������擾����l
/// </param>
/// <returns>
/// 0 �����̏ꍇ�� -1 �A0 �̏ꍇ�� 0�A0 ���傫���ꍇ�� 1
/// </returns>
template <class T>
constexpr T Sign(T value) noexcept
{
    return value ? (value > static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(-1)) : static_cast<T>(0);
}

/// <summary>
/// ��̒l���r���āA�ǂ���̒l���傫�����Ɋ�Â��� 0 �܂��� 1 ���擾
/// </summary>
/// <param name="value1">
/// ��r����ŏ��̒l
/// </param>
/// <param name="value2">
/// ��r����2�Ԗڂ̒l
/// </param>
/// <returns>
/// value1 �� value2 �ȏ�̏ꍇ�� 1�A����ȊO�̏ꍇ�� 0
/// </returns>
template <class T>
constexpr T Step(T value1, T value2) noexcept
{
    return value1 > value2 ? static_cast<T>(0) : static_cast<T>(1);
}

/// <summary>
/// value ���͈͓��ɂ��邩���擾
/// </summary>
template <class T>
constexpr bool InRange(T value, T min, T max) noexcept
{
    return min <= value && value <= max;
}

/// <summary>
/// value ��[0, 1]�͈͓̔��ɂ��邩���擾
/// </summary>
template <class T>
constexpr bool InRange01(T value) noexcept
{
    return InRange(value, static_cast<T>(0), static_cast<T>(1));
}

/// <summary>
/// �ŏ��l���擾
/// </summary>
template <class Head, class ... Tail>
constexpr Head Min(Head head, Tail ... tail) noexcept
{
    static_assert(MetaFunctions::IsSameTypeValue<Head, Tail...>, "Template parameters must be same type.");
    auto result = head;
    using Swallow = std::initializer_list<int>;
    void(Swallow{ (void(result = result < tail ? result : tail), 0)... });
    return result;
}

/// <summary>
/// �ő�l���擾
/// </summary>
template <class Head, class ... Tail>
constexpr Head Max(Head head, Tail ... tail) noexcept
{
    static_assert(MetaFunctions::IsSameTypeValue<Head, Tail...>, "Template parameters must be same type.");
    auto result = head;
    using Swallow = std::initializer_list<int>;
    void(Swallow{ (void(result = result > tail ? result : tail), 0)... });
    return result;
}

/// <summary>
/// value �� min �� max �̊Ԃɉ������񂾒l���擾
/// </summary>
template <class T>
constexpr T Clamp(T value, T min, T max) noexcept
{
    return Min(Max(value, min), max);
}

/// <summary>
/// �C�ӂ̒l�� [0, 1] �̋�Ԃɉ�������
/// </summary>
/// <param name="value">
/// [0, 1] �ŉ������ޒl
/// </param>
/// <returns>
/// [0, 1] �̋�Ԃɉ������񂾒l
/// </returns>
template <class TFloat>
constexpr TFloat Saturate(TFloat value) noexcept
{
    return Clamp(value, static_cast<TFloat>(0), static_cast<TFloat>(1));
}

/// <summary>
/// ����͈͓��̒l���قȂ�͈͓��̒l�ɕϊ�
/// </summary>
/// <param name="value">
/// �͈͂�ύX������͒l
/// </param>
/// <param name="inMin">
/// ���͍ŏ��l
/// </param>
/// <param name="inMax">
/// ���͍ő�l
/// </param>
/// <param name="outMin">
/// �o�͍ŏ��l
/// </param>
/// <param name="outMax">
/// �o�͍ő�l
/// </param>
/// <returns>
/// ����͈͓��̒l���قȂ�͈͓��̒l�ɕϊ������l
/// </returns>
template <class TFloat>
constexpr TFloat Remap(TFloat value, TFloat inMin, TFloat inMax, TFloat outMin, TFloat outMax) noexcept
{
    return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
}

/// <summary>
/// �ʓx�@����x���@�֕ϊ������l���擾
/// </summary>
/// <param name="radians">
/// �ʓx�@�̊p�x
/// </param>
/// <returns>
/// �x���@�̊p�x
/// </returns>
template <class TFloat>
constexpr TFloat ToDegrees(TFloat radians)
{
    return radians * Math::ToDegreesConstant<TFloat>;
}

/// <summary>
/// �x���@����ʓx�@�֕ϊ������l���擾
/// </summary>
/// <param name="degrees">
/// �x���@�̊p�x
/// </param>
/// <returns>
/// �ʓx�@�̊p�x
/// </returns>
template <class TFloat>
constexpr TFloat ToRadians(TFloat degrees)
{
    return degrees * Math::ToRadiansConstant<TFloat>;
}

/// <summary>
/// b �� e ����擾
/// </summary>
/// <param name="b">
/// �
/// </param>
/// <param name="e">
/// �w��
/// </param>
/// <returns>
/// b �� e ��
/// </returns>
template <class TFloat>
TFloat Pow(TFloat b, TFloat e)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::pow(b, e);
}

/// <summary>
/// b �� 2 ����擾
/// </summary>
/// <param name="b">
/// �
/// </param>
/// <returns>
/// b �� 2 ��
/// </returns>
template <class T>
constexpr T Pow2(T b) noexcept
{
    return b * b;
}

/// <summary>
/// b �� 3 ����擾
/// </summary>
/// <param name="b">
/// �
/// </param>
/// <returns>
/// b �� 3 ��
/// </returns>
template <class T>
constexpr T Pow3(T b) noexcept
{
    return b * b * b;
}

/// <summary>
/// b �� 4 ����擾
/// </summary>
/// <param name="b">
/// �
/// </param>
/// <returns>
/// b �� 4 ��
/// </returns>
template <class T>
constexpr T Pow4(T b) noexcept
{
    return b * b * b * b;
}

/// <summary>
/// b �� 5 ����擾
/// </summary>
/// <param name="b">
/// �
/// </param>
/// <returns>
/// b �� 5 ��
/// </returns>
template <class T>
constexpr T Pow5(T b) noexcept
{
    return b * b * b * b * b;
}

/// <summary>
/// �������Ǝw�������畂�������_�����擾
/// </summary>
/// <param name="x">
/// ������
/// </param>
/// <param name="exp">
/// �w����
/// </param>
/// <returns>
/// ���������_��
/// </returns>
template <class TFloat>
TFloat Ldexp(TFloat x, I32 exp) noexcept
{
    return std::ldexp(x, exp);
}

/// <summary>
/// �l�������傩���擾
/// </summary>
/// <param name="value">
/// �����傩���擾����l
/// </param>
/// <returns>
/// �l�������傩
/// </returns>
template <class THasInf>
constexpr bool IsInf(THasInf value) noexcept
{
    static_assert(std::numeric_limits<THasInf>::has_infinity, "Type can not has infinity.");
    return std::numeric_limits<THasInf>::infinity() == Abs(value);
}

/// <summary>
/// ��̒l���قړ����������擾
/// </summary>
/// <param name="value1">
/// ��r����ŏ��̒l
/// </param>
/// <param name="value2">
/// ��r����2�Ԗڂ̒l
/// </param>
/// <returns>
/// ��̒l�̍����C�v�V�������������� true �A�����łȂ������� false
/// </returns>
template <class TFloat>
constexpr bool Approximately(TFloat value1, TFloat value2) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Abs(value1 - value2) < std::numeric_limits<TFloat>::epsilon();
}

/// <summary>
/// ��������؂�̂Ă��l���擾
/// </summary>
/// <param name="value">
/// ��������؂�̂Ă�l
/// </param>
/// <returns>
/// ��������؂�̂Ă��l
/// </returns>
template <class TFloat>
constexpr TFloat Trunc(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return static_cast<TFloat>(static_cast<I32>(value));
}

/// <summary>
/// ��]���擾
/// </summary>
/// <param name="value1">
/// �폜��
/// </param>
/// <param name="value2">
/// ����
/// </param>
/// <returns>
/// ��]
/// </returns>
template <class TFloat>
constexpr TFloat Mod(TFloat value1, TFloat value2) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return value1 - Trunc(value1 / value2) * value2;
}

/// <summary>
/// �w�肳�ꂽ�l�̏��������擾
/// </summary>
/// <param name="value">
/// �����������o���l
/// </param>
/// <returns>
/// value �̏�����
/// </returns>
template <class TFloat>
constexpr TFloat Frac(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Abs(Mod(value, static_cast<TFloat>(1)));
}

/// <summary>
/// �w�肳�ꂽ�l�ȉ��̍ő�̐��������擾
/// </summary>
/// <param name="value">
/// ���������擾����l
/// </param>
/// <returns>
/// �w�肳�ꂽ�l�ȉ��̍ő�̐�����
/// </returns>
template <class TFloat>
constexpr TFloat Floor(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return value - Frac(value);
}

/// <summary>
/// �w�肳�ꂽ�l�ȏ�̍ŏ��̐����l���擾
/// </summary>
/// <param name="value">
/// �w�肷��l
/// </param>
/// <returns>
/// �w�肳�ꂽ�l�ȏ�̍ŏ��̐����l
/// </returns>
template <class TFloat>
constexpr TFloat Ceil(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Floor(value) + static_cast<TFloat>(1);
}

/// <summary>
/// �w�肳�ꂽ�l�ɍł��߂��������擾(�l�̌ܓ�)
/// </summary>
/// <param name="value">
/// �w�肷��l
/// </param>
/// <returns>
/// �w�肳�ꂽ�l�ɍł��߂�����
/// </returns>
template <class TFloat>
constexpr TFloat Round(TFloat value) noexcept
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return Floor(value + static_cast<TFloat>(0.5));
}

/// <summary>
/// �p�x f �̃T�C�����擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃T�C��
/// </returns>
template <class TFloat>
TFloat Sin(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::sin(f);
}

/// <summary>
/// �p�x f �̃R�T�C�����擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃R�T�C��
/// </returns>
template <class TFloat>
TFloat Cos(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::cos(f);
}

/// <summary>
/// �p�x f �̃^���W�F���g���擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃R�T�C��
/// </returns>
template <class TFloat>
TFloat Tan(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::tan(f);
}

/// <summary>
/// �p�x f �̃R�Z�J���g���擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃R�Z�J���g
/// </returns>
template <class TFloat>
TFloat Csc(TFloat f)
{
    return static_cast<TFloat>(1) / Sin(f);
}

/// <summary>
/// �p�x f �̃Z�J���g���擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃Z�J���g
/// </returns>
template <class TFloat>
TFloat Sec(TFloat f)
{
    return static_cast<TFloat>(1) / Cos(f);
}

/// <summary>
/// �p�x f �̃R�^���W�F���g���擾
/// </summary>
/// <param name="f">
/// �ʓx�@�̓��͊p�x
/// </param>
/// <returns>
/// �p�x f �̃R�^���W�F���g
/// </returns>
template <class TFloat>
TFloat Cot(TFloat f)
{
    return static_cast<TFloat>(1) / Tan(f);
}

/// <summary>
/// �T�C���� f �ɂȂ�ʓx�@�̊p�x���擾
/// </summary>
/// <param name="f">
/// �p�x�����߂����T�C��
/// </param>
/// <returns>
/// �T�C���� f �ɂȂ�ʓx�@�̊p�x
/// </returns>
template <class TFloat>
TFloat Asin(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::asin(f);
}

/// <summary>
/// �R�T�C���� f �ɂȂ�ʓx�@�̊p�x���擾
/// </summary>
/// <param name="f">
/// �p�x�����߂����R�T�C��
/// </param>
/// <returns>
/// �R�T�C���� f �ɂȂ�ʓx�@�̊p�x
/// </returns>
template <class TFloat>
TFloat Acos(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::acos(f);
}

/// <summary>
/// �^���W�F���g�� f �ɂȂ�ʓx�@�̊p�x���擾
/// </summary>
/// <param name="f">
/// �p�x�����߂����^���W�F���g
/// </param>
/// <returns>
/// �^���W�F���g�� f �ɂȂ�ʓx�@�̊p�x
/// </returns>
template <class TFloat>
TFloat Atan(TFloat f)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::atan(f);
}

/// <summary>
/// �^���W�F���g�� y / x �ɂȂ�ʓx�@�̊p�x���擾
/// </summary>
/// <param name="y">
/// y / x �� y
/// </param>
/// <param name="x">
/// y / x �� x
/// </param>
/// <returns>
/// �^���W�F���g�� y / x �ɂȂ�ʓx�@�̊p�x
/// </returns>
template <class TFloat>
TFloat Atan2(TFloat y, TFloat x)
{
    static_assert(std::is_floating_point_v<TFloat>, "Type must be floating point type.");
    return std::atan2(y, x);
}

/// <summary>
/// �C�ӂ̒l�̕��������擾
/// </summary>
/// <param name="value">
/// ���������擾�������l
/// </param>
/// <returns>
/// ������
/// </returns>
template <class TFloat>
constexpr TFloat Sqrt(TFloat value) noexcept
{
    return (IsInf(value) || IsZero(value)) ? value : IsPlus(value) ? Impl::RecursiveBabylonianMethod(value, value / static_cast<TFloat>(2)) : NAN;
}

/// <summary>
/// �C�ӂ̒l�̗̂��������擾
/// </summary>
/// <param name="value">
/// ���������擾�������l
/// </param>
/// <returns>
/// ������
/// </returns>
template <class TFloat>
TFloat Cbrt(TFloat value)
{
    return std::cbrt(value);
}

/// <summary>
/// ���`���
/// </summary>
template <class TFloat>
constexpr TFloat Lerp(TFloat value1, TFloat value2, TFloat amount) noexcept
{
    return value1 + (value2 - value1) * amount;
}

/// <summary>
/// Hermite���
/// </summary>
template <class TFloat>
constexpr TFloat Smoothstep(TFloat value1, TFloat value2, TFloat amount) noexcept
{
    return Lerp(value1, value2, amount * amount * (static_cast<TFloat>(3) - static_cast<TFloat>(2) * amount));
}

} // namespace Math
