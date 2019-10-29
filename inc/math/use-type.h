#pragma once

#include "integer-types.h"

namespace Math
{

#ifdef USE_DOUBLE_IN_MATH

using Float = F64;

#else

using Float = F32;

#endif

} // namespace Math
