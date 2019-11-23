#include <math/color-4-b.h>
#include <math/color-3-b.h>
#include <limits>

Math::Color4B::Color4B() : Math::Color4B(GetElemMax(), GetElemMax(), GetElemMax(), GetElemMax())
{
}

Math::Color4B::Color4B(Elem r, Elem g, Elem b, Elem a) : m_r(r), m_g(g), m_b(b), m_a(a)
{
}

Math::Color4B::Color4B(Color3B const & rgb, Elem a) : Math::Color4B(rgb.GetR(), rgb.GetG(), rgb.GetB(), a)
{
}

Math::Color4B::Elem Math::Color4B::GetR() const
{
    return m_r;
}

Math::Color4B::Elem Math::Color4B::GetG() const
{
    return m_g;
}

Math::Color4B::Elem Math::Color4B::GetB() const
{
    return m_b;
}

Math::Color4B::Elem Math::Color4B::GetA() const
{
    return m_a;
}

void Math::Color4B::SetR(Elem r)
{
    m_r = r;
}

void Math::Color4B::SetG(Elem g)
{
    m_g = g;
}

void Math::Color4B::SetB(Elem b)
{
    m_b = b;
}

void Math::Color4B::SetA(Elem a)
{
    m_a = a;
}

Math::Color4B::Elem & Math::Color4B::operator [] (std::size_t index) noexcept
{
    return _[index];
}

Math::Color4B::Elem Math::Color4B::operator [] (std::size_t index) const noexcept
{
    return _[index];
}

Math::Color3F Math::Color4B::ToColor3F() const noexcept
{
    using FloatElem = Math::Color3F::Elem;
    constexpr static auto FloatElemMax = static_cast<FloatElem>(GetElemMax());
    return  { GetR() / FloatElemMax, GetG() / FloatElemMax, GetB() / FloatElemMax };
}

std::ostream & Math::operator << (std::ostream & lhs, Color4B const & rhs)
{
    // Œ^ˆø”‚ªcharŒ^‚¾‚Á‚½ê‡‚ÉA”’l‚Åo—Í‚·‚é‚½‚ß‚Éstd::to_string()‚ð’Ê‚·
    return lhs << "(r:"
        << std::to_string(rhs.GetR()) << ", g:"
        << std::to_string(rhs.GetG()) << ", b:"
        << std::to_string(rhs.GetB()) << ", a:"
        << std::to_string(rhs.GetA()) << ")";
}
