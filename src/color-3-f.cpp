#include <math/color-3-f.h>

std::ostream & Math::operator << (std::ostream & lhs, Color3F const & rhs)
{
    return lhs << "(r:"
        << rhs.GetR() << ", g:"
        << rhs.GetG() << ", b:"
        << rhs.GetB() << ")";
}
