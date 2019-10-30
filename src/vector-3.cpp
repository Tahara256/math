#include <math/vector-3.h>
#include <math/quaternion.h>

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

Math::Vector3 const Math::Vector3::CreateRandomOnUnitSphere(IRandom & random)
{
    auto const angle = random.Range(Math::TwoPi<Float>);
    auto const z = random.Range(static_cast<Float>(-1), static_cast<Float>(1));
    auto const t = Math::Sqrt(static_cast<Float>(1) - Math::Pow2(z));
    auto const x = t * Math::Cos(angle);
    auto const y = t * Math::Sin(angle);
    return { x, y, z };
}

Math::Vector3 const Math::Vector3::CreateRandomInUnitSphere(IRandom & random)
{
    return CreateRandomOnUnitSphere(random) * Math::Cbrt(random.Range());
}

Math::Vector3 const Math::Vector3::CreateRandomOnUnitHemisphere(IRandom & random, Vector3 const & top)
{
    auto const r = random.Range();
    auto const phi = random.Range(static_cast<Float>(0), Math::TwoPi<Float>);
    auto const rootR = Math::Sqrt(r);

    auto const z = Math::Sqrt(static_cast<Float>(1) - r);
    auto const x = Math::Cos(phi) * rootR;
    auto const y = Math::Sin(phi) * rootR;

    auto const dir = Vector3(x, y, z);
    auto const rot = Quaternion::CreateDirection(top);
    return rot * dir;
}

std::ostream & Math::operator << (std::ostream & os, Vector3 const & v)
{
    return os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
}
