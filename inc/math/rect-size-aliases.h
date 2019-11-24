#pragma once

#include "integer-types.h"
#include "rect-size.h"

namespace Math
{

using RectSizeI8 = RectSize<I8>;
using RectSizeI16 = RectSize<I16>;
using RectSizeI32 = RectSize<I32>;
using RectSizeI64 = RectSize<I64>;

using RectSizeU8 = RectSize<U8>;
using RectSizeU16 = RectSize<U16>;
using RectSizeU32 = RectSize<U32>;
using RectSizeU64 = RectSize<U64>;

using RectSizeF = RectSize<Float>;
using RectSizeF32 = RectSize<F32>;
using RectSizeF64 = RectSize<F64>;

} // namespace Math
