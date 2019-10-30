#include <math/matrix-4x4.h>
#include <math/quaternion.h>

using namespace Math;

Matrix4x4 const Matrix4x4::Identity{
    static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
};

Matrix4x4 const Matrix4x4::Zero{
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
    static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0)
};

Matrix4x4::Matrix4x4()
{
    *this = Matrix4x4::Identity;
}

Matrix4x4::Matrix4x4(
    Float m11, Float m12, Float m13, Float m14,
    Float m21, Float m22, Float m23, Float m24,
    Float m31, Float m32, Float m33, Float m34,
    Float m41, Float m42, Float m43, Float m44) noexcept :
    m11(m11), m12(m12), m13(m13), m14(m14),
    m21(m21), m22(m22), m23(m23), m24(m24),
    m31(m31), m32(m32), m33(m33), m34(m34),
    m41(m41), m42(m42), m43(m43), m44(m44)
{
}

Matrix4x4::Matrix4x4(Vector4 const & r1, Vector4 const & r2, Vector4 const & r3, Vector4 const & r4) noexcept :
    r1(r1), r2(r2), r3(r3), r4(r4)
{
}

Matrix4x4::Matrix4x4(Matrix4x4 const & other) :
    r1(other.r1), r2(other.r2), r3(other.r3), r4(other.r4)
{
}

Matrix4x4::Matrix4x4(Quaternion const & q) noexcept :
    r1{ 1 - 2 * q.y * q.y - 2 * q.z * q.z,        2 * q.x * q.y - 2 * q.z * q.w,        2 * q.x * q.z + 2 * q.y * q.w,    static_cast<Float>(0) },
    r2{     2 * q.x * q.y + 2 * q.z * q.w,    1 - 2 * q.x * q.x - 2 * q.z * q.z,        2 * q.y * q.z - 2 * q.x * q.w,    static_cast<Float>(0) },
    r3{     2 * q.x * q.z - 2 * q.y * q.w,        2 * q.y * q.z + 2 * q.x * q.w,    1 - 2 * q.x * q.x - 2 * q.y * q.y,    static_cast<Float>(0) },
    r4{             static_cast<Float>(0),                static_cast<Float>(0),                static_cast<Float>(0),    static_cast<Float>(1) }
{
}

Matrix4x4 & Matrix4x4::operator = (Matrix4x4 const & other)
{
    if (this != &other) {
        r1 = other.r1;
        r2 = other.r2;
        r3 = other.r3;
        r4 = other.r4;
    }
    return *this;
}

Vector3 const Matrix4x4::operator * (Vector3 const & v) const
{
    auto const r = *this * Vector4(v, static_cast<Float>(1));
    return r.xyz();
}

Vector4 const Matrix4x4::operator * (Vector4 const & v) const
{
    return { r1.Dot(v), r2.Dot(v), r3.Dot(v), r4.Dot(v) };
}

Matrix4x4 const Matrix4x4::operator * (Matrix4x4 const & m) const
{
    return {
        r1.Dot(m.Column(0)), r1.Dot(m.Column(1)), r1.Dot(m.Column(2)), r1.Dot(m.Column(3)),
        r2.Dot(m.Column(0)), r2.Dot(m.Column(1)), r2.Dot(m.Column(2)), r2.Dot(m.Column(3)),
        r3.Dot(m.Column(0)), r3.Dot(m.Column(1)), r3.Dot(m.Column(2)), r3.Dot(m.Column(3)),
        r4.Dot(m.Column(0)), r4.Dot(m.Column(1)), r4.Dot(m.Column(2)), r4.Dot(m.Column(3))
    };
}

bool Matrix4x4::operator == (Matrix4x4 const & m) const
{
    return r1 == m.r1 && r2 == m.r2 && r3 == m.r3 && r4 == m.r4;
}

bool Matrix4x4::operator != (Matrix4x4 const & m) const
{
    return !(*this == m);
}

Vector4 & Matrix4x4::operator [] (std::size_t index)
{
    return r[index];
}

Vector4 const & Matrix4x4::operator [] (std::size_t index) const
{
    return r[index];
}

Vector4 const Matrix4x4::Column(std::size_t index) const
{
    return { m[0][index], m[1][index], m[2][index], m[3][index] };
}

bool Matrix4x4::Approximately(Matrix4x4 const & other) const noexcept
{
    return r1.Approximately(other.r1) && r2.Approximately(other.r2) && r3.Approximately(other.r3) && r4.Approximately(other.r4);
}

Float Matrix4x4::Determinant() const noexcept
{
    return
        m11 * m22 * m33 * m44 + m11 * m23 * m34 * m42 + m11 * m24 * m32 * m43
        - m11 * m24 * m33 * m42 - m11 * m23 * m32 * m44 - m11 * m22 * m34 * m43
        - m12 * m21 * m33 * m44 - m13 * m21 * m34 * m42 - m14 * m21 * m32 * m43
        + m14 * m21 * m33 * m42 + m13 * m21 * m32 * m44 + m12 * m21 * m34 * m43
        + m12 * m23 * m31 * m44 + m13 * m24 * m31 * m42 + m14 * m22 * m31 * m43
        - m14 * m23 * m31 * m42 - m13 * m22 * m31 * m44 - m12 * m24 * m31 * m43
        - m12 * m23 * m34 * m41 - m13 * m24 * m32 * m41 - m14 * m22 * m33 * m41
        + m14 * m23 * m32 * m41 + m13 * m22 * m34 * m41 + m12 * m24 * m33 * m41;
}

Matrix4x4 const Matrix4x4::Inverse() const noexcept
{
    auto det = Determinant();
    if (det == static_cast<Float>(0)) {
        return *this;
    }
    auto detInv = static_cast<Float>(1) / det;

    return{
        detInv * (m22 * m33 * m44 + m23 * m34 * m42 + m24 * m32 * m43 - m24 * m33 * m42 - m23 * m32 * m44 - m22 * m34 * m43),
        detInv * (-m12 * m33 * m44 - m13 * m34 * m42 - m14 * m32 * m43 + m14 * m33 * m42 + m13 * m32 * m44 + m12 * m34 * m43),
        detInv * (m12 * m23 * m44 + m13 * m24 * m42 + m14 * m22 * m43 - m14 * m23 * m42 - m13 * m22 * m44 - m12 * m24 * m43),
        detInv * (-m12 * m23 * m34 - m13 * m24 * m32 - m14 * m22 * m33 + m14 * m23 * m32 + m13 * m22 * m34 + m12 * m24 * m33),

        detInv * (-m21 * m33 * m44 - m23 * m34 * m41 - m24 * m31 * m43 + m24 * m33 * m41 + m23 * m31 * m44 + m21 * m34 * m43),
        detInv * (m11 * m33 * m44 + m13 * m34 * m41 + m14 * m31 * m43 - m14 * m33 * m41 - m13 * m31 * m44 - m11 * m34 * m43),
        detInv * (-m11 * m23 * m44 - m13 * m24 * m41 - m14 * m21 * m43 + m14 * m23 * m41 + m13 * m21 * m44 + m11 * m24 * m43),
        detInv * (m11 * m23 * m34 + m13 * m24 * m31 + m14 * m21 * m33 - m14 * m23 * m31 - m13 * m21 * m34 - m11 * m24 * m33),

        detInv * (m21 * m32 * m44 + m22 * m34 * m41 + m24 * m31 * m42 - m24 * m32 * m41 - m22 * m31 * m44 - m21 * m34 * m42),
        detInv * (-m11 * m32 * m44 - m12 * m34 * m41 - m14 * m31 * m42 + m14 * m32 * m41 + m12 * m31 * m44 + m11 * m34 * m42),
        detInv * (m11 * m22 * m44 + m12 * m24 * m41 + m14 * m21 * m42 - m14 * m22 * m41 - m12 * m21 * m44 - m11 * m24 * m42),
        detInv * (-m11 * m22 * m34 - m12 * m24 * m31 - m14 * m21 * m32 + m14 * m22 * m31 + m12 * m21 * m34 + m11 * m24 * m32),

        detInv * (-m21 * m32 * m43 - m22 * m33 * m41 - m23 * m31 * m42 + m23 * m32 * m41 + m22 * m31 * m43 + m21 * m33 * m42),
        detInv * (m11 * m32 * m43 + m12 * m33 * m41 + m13 * m31 * m42 - m13 * m32 * m41 - m12 * m31 * m43 - m11 * m33 * m42),
        detInv * (-m11 * m22 * m43 - m12 * m23 * m41 - m13 * m21 * m42 + m13 * m22 * m41 + m12 * m21 * m43 + m11 * m23 * m42),
        detInv * (m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32 - m13 * m22 * m31 - m12 * m21 * m33 - m11 * m23 * m32)
    };
}

Matrix4x4 const Matrix4x4::Transpose() const noexcept
{
    return { Column(0), Column(1), Column(2), Column(3) };
}

Vector3 const Matrix4x4::EulerAngles() const noexcept
{
    auto result = Vector3::Zero;

    if (Math::Approximately(m[1][2], static_cast<Float>(1))) {
        result.x = -Math::Pi<Float> / static_cast<Float>(2);
        result.y = static_cast<Float>(0);
        result.z = Math::Atan2(-m[0][1], m[0][0]);
    }
    else if (Math::Approximately(m[1][2], static_cast<Float>(-1))) {
        result.x = Math::Pi<Float> / static_cast<Float>(2);
        result.y = static_cast<Float>(0);
        result.z = Math::Atan2(m[0][1], m[0][0]);
    }
    else {
        result.x = Math::Asin(-m[1][2]);
        result.y = Math::Atan2(m[0][2], m[2][2]);
        result.z = Math::Atan2(m[1][0], m[1][1]);
    }

    return result;
}

Matrix4x4 const Matrix4x4::CreateScale(Float scale)
{
    return {
                        scale, static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0),                 scale, static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0),                 scale, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateScale(Vector3 const & scale)
{
    return {
                      scale.x, static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0),               scale.y, static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0),               scale.z, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationX(Float angle)
{
    auto const sin = Math::Sin(angle);
    auto const cos = Math::Cos(angle);
    return {
        static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0),                   cos,                  -sin, static_cast<Float>(0),
        static_cast<Float>(0),                   sin,                   cos, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationY(Float angle)
{
    auto const sin = Math::Sin(angle);
    auto const cos = Math::Cos(angle);
    return {
                          cos, static_cast<Float>(0),                   sin, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0),
                         -sin, static_cast<Float>(0),                   cos, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationZ(Float angle)
{
    auto const sin = Math::Sin(angle);
    auto const cos = Math::Cos(angle);
    return {
                          cos,                  -sin, static_cast<Float>(0), static_cast<Float>(0),
                          sin,                   cos, static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationUnitAxisAngle(Vector3 const & a, Float angle)
{
    auto const sin = Math::Sin(angle);
    auto const cos = Math::Cos(angle);
    auto const nxSq = Math::Pow2(a.x);
    auto const nySq = Math::Pow2(a.y);
    auto const nzSq = Math::Pow2(a.z);
    return {
                   cos + nxSq * (1 - cos),    a.x * a.y * (1 - cos) - a.z * sin,    a.x * a.z * (1 - cos) + a.y * sin,    static_cast<Float>(0),
        a.y * a.x * (1 - cos) + a.z * sin,               cos + nySq * (1 - cos),    a.y * a.z * (1 - cos) - a.x * sin,    static_cast<Float>(0),
        a.z * a.x * (1 - cos) - a.y * sin,    a.z * a.y * (1 - cos) + a.x * sin,               cos + nzSq * (1 - cos),    static_cast<Float>(0),
                    static_cast<Float>(0),                static_cast<Float>(0),                static_cast<Float>(0),    static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationAxisAngle(Vector3 const & axis, Float angle)
{
    return CreateRotationUnitAxisAngle(axis.Normalized(), angle);
}

Matrix4x4 const Matrix4x4::CreateRotationEulerAngles(Vector3 const & eulerAngles)
{
    return CreateRotationY(eulerAngles.y) * CreateRotationX(eulerAngles.x) * CreateRotationZ(eulerAngles.z);
}

Matrix4x4 const Matrix4x4::CreateRotationLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & worldUp)
{
    return CreateRotationDirection(to - from, worldUp);
}

Matrix4x4 const Matrix4x4::CreateRotationUnitDirection(Vector3 const & unitDirection, Vector3 const & worldUp)
{
    auto const forward = unitDirection;
    auto right = worldUp.Cross(forward).Normalized();

    // äOêœÇ≈ï˚å¸Ç™ï™Ç©ÇÁÇ»Ç¢èÍçáÇÕìKìñÇ…åàÇﬂÇƒÇµÇ‹Ç§
    if (right.IsZero()) right = Vector3::Right;

    auto up = forward.Cross(right);

    return {
                      right.x,                  up.x,             forward.x, static_cast<Float>(0),
                      right.y,                  up.y,             forward.y, static_cast<Float>(0),
                      right.z,                  up.z,             forward.z, static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreateRotationDirection(Vector3 const & direction, Vector3 const & worldUp)
{
    return CreateRotationUnitDirection(direction.Normalized());
}

Matrix4x4 const Matrix4x4::CreateTranslation(Vector3 const & position)
{
    return{
        static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0),           position.x,
        static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0),           position.y,
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1),           position.z,
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1)
    };
}

Matrix4x4 const Matrix4x4::CreatePerspective(Float fovAngleY, Float aspect, Float nearZ, Float farZ)
{
    auto const w = Math::Cot(fovAngleY / static_cast<Float>(2)) / aspect;
    auto const h = Math::Cot(fovAngleY / static_cast<Float>(2));
    auto const q = farZ / (farZ - nearZ);
    return{
                            w, static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0),                     h, static_cast<Float>(0), static_cast<Float>(0),
        static_cast<Float>(0), static_cast<Float>(0),                     q,            -q * nearZ,
        static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0)
    };
}

std::ostream & Math::operator << (std::ostream & os, Matrix4x4 const & m)
{
    return os << "{" << m.r1 << "," << std::endl << m.r2 << "," << std::endl << m.r3 << "," << std::endl << m.r4 << "}";
}
