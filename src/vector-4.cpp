#include <math/vector-4.h>

Math::Vector4 const Math::Vector4::Zero { static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0) };
Math::Vector4 const Math::Vector4::One  { static_cast<Float>(1), static_cast<Float>(1), static_cast<Float>(1), static_cast<Float>(1) };
Math::Vector4 const Math::Vector4::UnitX{ static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0) };
Math::Vector4 const Math::Vector4::UnitY{ static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0), static_cast<Float>(0) };
Math::Vector4 const Math::Vector4::UnitZ{ static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1), static_cast<Float>(0) };
Math::Vector4 const Math::Vector4::UnitW{ static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(0), static_cast<Float>(1) };

std::ostream & Math::operator << (std::ostream & os, Vector4 const & v)
{
    return os << "{ " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " }";
}
