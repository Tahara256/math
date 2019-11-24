#pragma once

#pragma comment (lib, "math.lib")

/*-- math header files --*/

/* ベクトルクラス(整数型) */
// 二次元
#include "math/point-2.h"
// 整数型毎のエイリアス
#include "math/point-aliases.h"

/* ベクトルクラス(浮動小数点数型) */
// 二次元
#include "math/vector-2.h"
// 三次元
#include "math/vector-3.h"
// 四次元
#include "math/vector-4.h"

/* 行列クラス */
// 3x3
#include "math/matrix-3x3.h"
// 4x4
#include "math/matrix-4x4.h"

/* 四元数クラス */
#include "math/quaternion.h"

/* レイクラス */
#include "math/ray.h"


/* 色情報クラス(整数型) */
// RGB
#include "math/color-3-b.h"
// RGBA
#include "math/color-4-b.h"

/* 色情報クラス(不動小数点数型) */
// RGB
#include "math/color-3-f.h"
