#include <math/vector-3.h>

Math::Vector3 const Math::Vector3::Zero     { static_cast<Float>( 0), static_cast<Float>( 0), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::One      { static_cast<Float>( 1), static_cast<Float>( 1), static_cast<Float>( 1) };
Math::Vector3 const Math::Vector3::UnitX    { static_cast<Float>( 1), static_cast<Float>( 0), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::UnitY    { static_cast<Float>( 0), static_cast<Float>( 1), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::UnitZ    { static_cast<Float>( 0), static_cast<Float>( 0), static_cast<Float>( 1) };
Math::Vector3 const Math::Vector3::Left     { static_cast<Float>(-1), static_cast<Float>( 0), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::Right    { static_cast<Float>( 1), static_cast<Float>( 0), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::Down     { static_cast<Float>( 0), static_cast<Float>(-1), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::Up       { static_cast<Float>( 0), static_cast<Float>( 1), static_cast<Float>( 0) };
Math::Vector3 const Math::Vector3::Back     { static_cast<Float>( 0), static_cast<Float>( 0), static_cast<Float>(-1) };
Math::Vector3 const Math::Vector3::Forward  { static_cast<Float>( 0), static_cast<Float>( 0), static_cast<Float>( 1) };

std::ostream & Math::operator << (std::ostream & os, Vector3 const & v)
{
    return os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
}
