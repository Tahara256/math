#include <math/quaternion.h>
#include <math/matrix-4x4.h>

using namespace Math;

Quaternion::Quaternion(Matrix4x4 const & m) noexcept
{
    auto trace = m[0][0] + m[1][1] + m[2][2];

    // ‘ÎŠp¬•ª‚ðƒ`ƒFƒbƒN
    if (trace > static_cast<Float>(0)) {
        auto const s = Math::Sqrt(trace + static_cast<Float>(1));
        _[3] = s * static_cast<Float>(0.5);
        auto const t = static_cast<Float>(0.5) / s;
        _[0] = (m[2][1] - m[1][2]) * t;
        _[1] = (m[0][2] - m[2][0]) * t;
        _[2] = (m[1][0] - m[0][1]) * t;
    }
    else {
        // ‘ÎŠp¬•ª‚ª•‰‚É‚È‚é
        std::size_t i = 0;
        if (m[1][1] > m[0][0])i = 1;
        if (m[2][2] > m[i][i])i = 2;

        static std::size_t const Next[3] = { 1, 2, 0 };
        auto j = Next[i];
        auto k = Next[j];

        auto s = Math::Sqrt((m[i][i] - (m[j][j] + m[k][k])) + static_cast<Float>(1));

        _[i] = s * static_cast<Float>(0.5);

        auto t = static_cast<Float>(0);
        if (s != static_cast<Float>(0)) t = static_cast<Float>(0.5) / s;
        else t = s;

        _[3] = (m[k][j] - m[j][k]) * t;
        _[j] = (m[j][i] + m[i][j]) * t;
        _[k] = (m[k][i] + m[i][k]) * t;
    }
}

Vector3 const Quaternion::EulerAngles() const noexcept
{
    return Matrix4x4(*this).EulerAngles();
}

Quaternion const Quaternion::Lerp(Quaternion const & other, Float t) const
{
    auto const cos = Dot(other);
    auto const q1 = *this;
    auto q2 = other;
    if (cos < static_cast<Float>(0)) q2 = -q2;
    return (q1 * (1 - t) + q2 * t).Normalized();
}

Quaternion const Quaternion::Slerp(Quaternion const & other, Float t) const
{
    auto cos = Dot(other);
    auto const q1 = *this;
    auto q2 = other;
    if (cos < static_cast<Float>(0)) {
        q2 = -other;
        cos = -cos;
    }
    auto const angle = Math::Acos(cos);
    auto const sin = Math::Sin(angle);
    auto k1 = 1.f - t;
    auto k2 = t;
    auto const sin1 = Math::Sin(k1 * angle);
    auto const sin2 = Math::Sin(k2 * angle);
    k1 = sin1 / sin;
    k2 = sin2 / sin;
    return q1 * k1 + q2 * k2;
}

Quaternion const Quaternion::Identity{};

Quaternion const Quaternion::CreateX(Float angle)
{
    return CreateUnitAxisAngle(Vector3::Right, angle);
}

Quaternion const Quaternion::CreateY(Float angle)
{
    return CreateUnitAxisAngle(Vector3::Up, angle);
}

Quaternion const Quaternion::CreateZ(Float angle)
{
    return CreateUnitAxisAngle(Vector3::Forward, angle);
}

Quaternion const Quaternion::CreateUnitAxisAngle(Vector3 const & unitAxis, Float angle)
{
    return Quaternion{ unitAxis * Math::Sin(angle / static_cast<Float>(2)), Math::Cos(angle / static_cast<Float>(2)) };
}

Quaternion const Quaternion::CreateAxisAngle(Vector3 const & axis, Float angle)
{
    return CreateUnitAxisAngle(axis.Normalized(), angle);
}

Quaternion const Quaternion::CreateEulerAngles(Vector3 const & eulerAngles)
{
    return CreateY(eulerAngles.y) * CreateX(eulerAngles.x) * CreateZ(eulerAngles.z);
}

Quaternion const Quaternion::CreateLookAt(Vector3 const & from, Vector3 const & to, Vector3 const & up)
{
    return Quaternion{ Matrix4x4::CreateRotationLookAt(from, to, up) };
}

Quaternion const Quaternion::CreateUnitDirection(Vector3 const & unitDirection, Vector3 const & up)
{
    return Quaternion{ Matrix4x4::CreateRotationUnitDirection(unitDirection, up) };
}

Quaternion const Quaternion::CreateDirection(Vector3 const & direction, Vector3 const & up)
{
    return Quaternion{ Matrix4x4::CreateRotationDirection(direction, up) };
}

std::ostream & Math::operator << (std::ostream & os, Quaternion const & q)
{
    return std::cout << "{ " << q.w << "; " << q.x << ", " << q.y << ", " << q.z << " }";
}
