#include <math/matrix-3x3.h>

using namespace Math;

Matrix3x3 const Matrix3x3::Identity{
    static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
};

Matrix3x3::Matrix3x3()
{
    *this = Identity;
}

Matrix3x3::Matrix3x3(
    Float m11, Float m12, Float m13,
    Float m21, Float m22, Float m23,
    Float m31, Float m32, Float m33) noexcept :
    m11(m11), m12(m12), m13(m13),
    m21(m21), m22(m22), m23(m23),
    m31(m31), m32(m32), m33(m33)
{
}

Matrix3x3::Matrix3x3(Vector3 const & r1, Vector3 const & r2, Vector3 const & r3) noexcept :
    r1(r1), r2(r2), r3(r3)
{
}

Matrix3x3::Matrix3x3(Matrix3x3 const & other) :
    r1(other.r1), r2(other.r2), r3(other.r3)
{
}

Matrix3x3 & Matrix3x3::operator = (Matrix3x3 const & other)
{
    if (this != &other) {
        r1 = other.r1;
        r2 = other.r2;
        r3 = other.r3;
    }
    return *this;
}

Vector3 const Matrix3x3::operator * (Vector3 const & v) const
{
    return { r1.Dot(v), r2.Dot(v), r3.Dot(v) };
}

Matrix3x3 const Matrix3x3::operator * (Matrix3x3 const & m) const
{
    return {
        r1.Dot(m.Column(0)), r1.Dot(m.Column(1)), r1.Dot(m.Column(2)),
        r2.Dot(m.Column(0)), r2.Dot(m.Column(1)), r2.Dot(m.Column(2)),
        r3.Dot(m.Column(0)), r3.Dot(m.Column(1)), r3.Dot(m.Column(2))
    };
}

bool Matrix3x3::operator == (Matrix3x3 const & m) const
{
    return r1 == m.r1 && r2 == m.r2 && r3 == m.r3;
}

bool Matrix3x3::operator != (Matrix3x3 const & m) const
{
    return !(*this == m);
}

Vector3 & Matrix3x3::operator [] (std::size_t index)
{
    return r[index];
}

Vector3 const & Matrix3x3::operator [] (std::size_t index) const
{
    return r[index];
}

Vector3 const Matrix3x3::Column(std::size_t index) const
{
    return { m[0][index], m[1][index], m[2][index] };
}

bool Matrix3x3::Approximately(Matrix3x3 const & other) const noexcept
{
    return r1.Approximately(other.r1) && r2.Approximately(other.r2) && r3.Approximately(other.r3);
}

Float Matrix3x3::Determinant() const noexcept
{
    return m11 * m22 * m33
        + m12 * m23 * m31
        + m13 * m21 * m32
        - m11 * m23 * m32
        - m12 * m21 * m33
        - m13 * m22 * m31;
}

Matrix3x3 const Matrix3x3::Transpose() const noexcept
{
    return { Column(0), Column(1), Column(2) };
}
