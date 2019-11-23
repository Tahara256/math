#include <math/ray.h>

Math::Ray::Ray() noexcept
    : Ray(Vector::Zero, Vector::Forward)
{
}

Math::Ray::Ray(Vector origin, Vector direction) noexcept
    : m_origin(origin)
    , m_direction(direction.IsZero() ? Vector::Forward : direction.Normalized())
{
}


Math::Ray::Vector Math::Ray::GetOrigin() const noexcept
{
    return m_origin;
}

Math::Ray::Vector Math::Ray::GetDirection() const noexcept
{
    return m_direction;
}


void Math::Ray::SetOrigin(Vector const & origin) noexcept
{
    m_origin = origin;
}

void Math::Ray::SetDirection(Vector const & direction) noexcept
{
    m_direction = direction.Normalized();
}


Math::Ray::Vector Math::Ray::Point(Scalar distance) const noexcept
{
    return GetOrigin() + distance * GetDirection();
}

Math::Ray Math::Ray::MovedForward(Scalar distance) const noexcept
{
    return { Point(distance), GetDirection() };
}

void Math::Ray::MoveForward(Scalar distance) noexcept
{
    *this = MovedForward(distance);
}
