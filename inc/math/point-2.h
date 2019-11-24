#pragma once

namespace Math
{

/// <summary>
/// �񎟌��x�N�g���N���X(�����^)
/// </summary>
template <class TInt>
class Point2
{

public:

    /// <summary>
    /// �e�v�f��\���^
    /// </summary>
    using Elem = TInt;


    /// <summary>
    /// �f�t�H���g�R���X�g���N�^
    /// </summary>
    constexpr Point2() noexcept : Point2(static_cast<Elem>(0)) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="x">
    /// x ����
    /// </param>
    /// <param name="y">
    /// y ����
    /// </param>
    constexpr Point2(Elem x, Elem y) noexcept : m_x(x), m_y(y) { }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="value">
    /// x ������ y �����Ɋ��蓖�Ă�l
    /// </param>
    constexpr Point2(Elem value) noexcept : Point2(value, value) { }


    /// <summary>
    /// �P���v���X���Z�q
    /// </summary>
    /// <returns>
    /// +1 �ɂ���Z����
    /// </returns>
    constexpr Point2 const operator + () const noexcept { return *this; }

    /// <summary>
    /// �P���}�C�i�X���Z�q
    /// </summary>
    /// <returns>
    /// -1 �ɂ���Z����
    /// </returns>
    constexpr Point2 const operator - () const noexcept { return { -GetX(), -GetY() }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Point2 const operator + (Point2 const & rhs) const noexcept { return { GetX() + rhs.GetX(), GetY() + rhs.GetY() }; }

    /// <summary>
    /// ���Z���Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z��̓񎟌��x�N�g��
    /// </returns>
    constexpr Point2 const operator - (Point2 const & rhs) const noexcept { return { GetX() - rhs.GetX(), GetY() - rhs.GetY() }; }

    /// <summary>
    /// �������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g������������
    /// </returns>
    constexpr bool operator == (Point2 const & rhs) const noexcept { return GetX() == rhs.GetX() && GetY() == rhs.GetY(); }

    /// <summary>
    /// �񓙉����Z�q
    /// </summary>
    /// <param name="rhs">
    /// ��r�Ώۂ̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ��̓񎟌��x�N�g�����������Ȃ���
    /// </returns>
    constexpr bool operator != (Point2 const & rhs) const noexcept { return !(*this == rhs); }

    /// <summary> ���Z������Z�q </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z�����̎��g�ւ̎Q��
    /// </returns>
    Point2 & operator += (Point2 const & rhs) noexcept { return *this = *this + rhs; }

    /// <summary>
    /// ���Z������Z�q
    /// </summary>
    /// <param name="rhs">
    /// ���Z����񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// ���Z������Z�q
    /// </returns>
    Point2 & operator -= (Point2 const & rhs) noexcept { return *this = *this - rhs; }


    /// <summary>
    /// X���W���擾
    /// </summary>
    constexpr Elem GetX() const noexcept { return m_x; }

    /// <summary>
    /// Y���W���擾
    /// </summary>
    constexpr Elem GetY() const noexcept { return m_y; }


    /// <summary>
    /// X���W��ݒ�
    /// </summary>
    /// <param name="x">
    /// �ݒ肷��X���W
    /// </param>
    void SetX(Elem x) noexcept { m_x = x; }

    /// <summary>
    /// Y���W��ݒ�
    /// </summary>
    /// <param name="y">
    /// �ݒ肷��Y���W
    /// </param>
    void SetY(Elem y) noexcept { m_y = y; }


    /// <summary>
    /// �������ق��̗v�f�����񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// �������ق��̗v�f�����񎟌��x�N�g��
    /// </returns>
    constexpr Point2 Min(Point2 const & other) const noexcept { return { Math::Min(GetX(), other.GetX()), Math::Min(GetY(), other.GetY()) }; }

    /// <summary>
    /// �傫���ق��̗v�f�����񎟌��x�N�g�����擾
    /// </summary>
    /// <param name="other">
    /// ��������̓񎟌��x�N�g��
    /// </param>
    /// <returns>
    /// �傫���ق��̗v�f�����񎟌��x�N�g��
    /// </returns>
    constexpr Point2 Max(Point2 const & other) const noexcept { return { Math::Max(GetX(), other.GetX()), Math::Max(GetY(), other.GetY()) }; }

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
    constexpr Point2 Clamp(Point2 const & min, Point2 const & max) const noexcept { return min.Max(max.Min(*this)); }

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
    constexpr bool InRange(Point2 const & min, Point2 const & max) const noexcept { return Math::InRange(GetX(), min.GetX(), max.GetX()) && Math::InRange(GetY(), min.GetY(), max.GetY()); }

private:

    /// <summary>
    /// x ����
    /// </summary>
    Elem m_x;

    /// <summary>
    /// y ����
    /// </summary>
    Elem m_y;

};

} // namespace Math
