#include <math/vector-2.h>

Math::Vector2 const Math::Vector2::Zero { static_cast<Float>( 0), static_cast<Float>( 0) };
Math::Vector2 const Math::Vector2::One  { static_cast<Float>( 1), static_cast<Float>( 1) };
Math::Vector2 const Math::Vector2::UnitX{ static_cast<Float>( 1), static_cast<Float>( 0) };
Math::Vector2 const Math::Vector2::UnitY{ static_cast<Float>( 0), static_cast<Float>( 1) };
Math::Vector2 const Math::Vector2::Left { static_cast<Float>(-1), static_cast<Float>( 0) };
Math::Vector2 const Math::Vector2::Right{ static_cast<Float>( 1), static_cast<Float>( 0) };
Math::Vector2 const Math::Vector2::Up   { static_cast<Float>( 0), static_cast<Float>(-1) };
Math::Vector2 const Math::Vector2::Down { static_cast<Float>( 0), static_cast<Float>( 1) };

std::ostream & Math::operator << (std::ostream & os, Vector2 const & v)
{
    return os << "{ " << v.x << ", " << v.y << " }";
}
