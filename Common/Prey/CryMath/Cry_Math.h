// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

//
//	File:Cry_Math.h
//	Description: Common math class
//
//	History:
//	-Feb 27,2003: Created by Ivo Herzeg
//
//////////////////////////////////////////////////////////////////////

#ifndef CRYMATH_H
#define CRYMATH_H

#if _MSC_VER > 1000
	#pragma once
#endif

#include <cassert>

template<typename F> using vector4_t = F;
template<typename V> using scalar_t = V;

//! Only enable math asserts in debug builds
#if defined(_DEBUG)
#define CRY_MATH_ASSERT(x) assert(x)
#else
#define CRY_MATH_ASSERT(x)
#endif

//! General template for converting to/from types. Specialize as needed
template<typename D> ILINE D             convert() { return D(0); }
template<typename D, typename S> ILINE D convert(S val) { return D(val); }

// Definitions
constexpr f32 gf_PI = f32(3.14159265358979323846264338327950288419716939937510);
constexpr f64 g_PI = 3.14159265358979323846264338327950288419716939937510;       //!< pi

// Workaround for MSVC 140 bug where constexpr expression did not evaluate
#if !defined(_MSC_VER) || _MSC_VER >= 1910
constexpr f32 gf_PI2 = gf_PI * 2.f;
constexpr f64 g_PI2 = g_PI * 2.0; //!< 2*pi
#else
constexpr f32 gf_PI2 = f32(6.2831853071795864769252867665590057683943387987502);
constexpr f64 g_PI2 = 6.2831853071795864769252867665590057683943387987502; //!< 2*pi
#endif

constexpr f32 gf_ln2 = 0.69314718055994530941723212145818f;       //!< ln(2)

constexpr f64 sqrt2 = 1.4142135623730950488016887242097;
constexpr f64 sqrt3 = 1.7320508075688772935274463415059;

#if !defined(SWIG)
template<typename T>
constexpr auto DEG2RAD(T &&deg) -> decltype(deg * 1.f)
{
	return deg * (gf_PI / 180.0f);
}

constexpr f64 DEG2RAD(f64 deg)
{
	return deg * (g_PI / 180.0);
}

template<typename T>
constexpr auto RAD2DEG(T &&rad) -> decltype(rad * 1.f)
{
	return rad * (180.0f / gf_PI);
}

constexpr f64 RAD2DEG(f64 rad)
{
	return rad * (180.0 / g_PI);
}
#endif

// Define min and max as proper template
#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

template<typename T> ILINE T                 min(T a, T b) { return b < a ? b : a; }
template<typename T> ILINE T                 max(T a, T b) { return a < b ? b : a; }
template<typename T, class _Compare> ILINE T min(T a, T b, _Compare comp) { return comp(b, a) ? b : a; }
template<typename T, class _Compare> ILINE T max(T a, T b, _Compare comp) { return comp(a, b) ? b : a; }
ILINE int                                    min_branchless(int a, int b) { int diff = a - b; int mask = diff >> 31; return (b & (~mask)) | (a & mask); }

template<typename T> ILINE void              Limit(T &val, T min, T max)
{
	if (val < min)
		val = min;
	else if (val > max)
		val = max;
}
template<class T, class U> ILINE T Lerp(const T &a, const T &b, U t) { return a + T((b - a) * t); }

// Selection functions, could be overloaded or optimized as branchless

template<typename S, typename T> ILINE T if_else(S test, T a, T b) { return test ? a : b; }
template<typename S, typename T> ILINE T if_else_zero(S test, T a) { return test ? a : convert<T>(); }

// Deprecated
template<typename T> ILINE T __fsel(T a, T b, T c) { return if_else(a >= convert<T>(), b, c); }

ILINE int32 iszero(f32 x) {
	union
	{
		f32   f;
		int32 i;
	} u;
	u.f = x;
	u.i &= 0x7FFFFFFF;
	return -(u.i >> 31 ^ (u.i - 1) >> 31);
}
ILINE int32 iszero(f64 x) {
	union
	{
		f32   f;
		int32 i;
	} u;
	u.f = (f32)x;
	u.i &= 0x7FFFFFFF;
	return -((u.i >> 31) ^ (u.i - 1) >> 31);
}

ILINE int32 iszero(int32 x) { return -(x >> 31 ^ (x - 1) >> 31); }
ILINE int64 iszero(__int64 x) { return -(x >> 63 ^ (x - 1) >> 63); }

// Comparison test functions, can be overloaded for SIMD types
ILINE bool All(bool b) { return b; }
ILINE bool Any(bool b) { return b; }

//! \return i if x==1<<i (i=0..63)
ILINE int ilog2(uint64 x) {
	unsigned long i;
	_BitScanReverse64(&i, x);
	return i;
}

//! Create namespace for standard math functions, imported from std, and our extended versions.
//! SSE versions implemented in Cry_Math_SSE.h
namespace crymath
{

//
// Limiting and rounding functions
//

using std::abs;
using std::floor;
using std::ceil;
using std::trunc;

template<typename T>             ILINE T clamp(T val, T lo, T hi) { return min(max(val, lo), hi); }
template<typename R, typename T> ILINE R clamp_to(T val, T lo, T hi) { return R(clamp(val, lo, hi)); }
template<typename T>             ILINE T saturate(T val) { return clamp(val, convert<T>(0.0f), convert<T>(1.0f)); }

//
// Mathematical functions
//

using std::sin;
using std::cos;
using std::tan;

template<typename T> ILINE T asin(T op) { return std::asin(clamp(op, T(-1), T(1))); }
template<typename T> ILINE T acos(T op) { return std::acos(clamp(op, T(-1), T(1))); }

using std::atan;
using std::atan2;

template<typename T> ILINE void sincos(T angle, T *pSin, T *pCos) { *pSin = sin(angle); *pCos = cos(angle); }

using std::exp;
using std::log;
using std::pow;
using std::sqrt;

//
// Define rcp, rsqrt, etc for different platforms.
//

// _MSC_VER check is a temporary workaround for apparent compiler bug in VS 16.3: SSE version of rsqrt_fast generates incorrect code
ILINE f32 rcp(f32 op) { return 1.0f / op; }
ILINE f32 rcp_fast(f32 op) { return 1.0f / op; }
ILINE f32 sqrt_fast(f32 op) { return sqrt(op); }
ILINE f32 rsqrt(f32 op) { return 1.0f / sqrt(op); }
ILINE f32 rsqrt_fast(f32 op) { return rsqrt(op); }

ILINE f64 rcp(f64 op) { return 1.0 / op; }
ILINE f64 rsqrt(f64 op) { return 1.0 / sqrt(op); }

ILINE f32 rcp_safe(f32 op) { return rcp(max(op, FLT_MIN)); }
ILINE f64 rcp_safe(f64 op) { return rcp(max(op, DBL_MIN)); }

ILINE f32 rsqrt_safe(f32 op) { return rsqrt(max(op, FLT_MIN)); }
ILINE f64 rsqrt_safe(f64 op) { return rsqrt(max(op, DBL_MIN)); }

// signnz returns -1 if negative, 1 if zero or positive
ILINE int32 signnz(int32 op) { return ((op >> 31) << 1) + 1; }
ILINE int64 signnz(int64 op) { return ((op >> 63) << 1) + 1; }

ILINE f32   signnz(f32 op)
{
	// copy sign bit from op to 1
	f32 s = 1.0f;
	reinterpret_cast<int32 &>(s) |= reinterpret_cast<const int32 &>(op) & (1 << 31);
	return s;
}
ILINE f64 signnz(f64 op)
{
	// copy sign bit from op to 1
	f64 s = 1.0;
	reinterpret_cast<int64 &>(s) |= reinterpret_cast<const int64 &>(op) & (1LL << 63);
	return s;
}

// sign returns -1 if negative, 0 if zero, 1 if positive
ILINE int32 sign(int32 op) { return (op >> 31) + ((op - 1) >> 31) + 1; }
ILINE int64 sign(int64 op) { return (op >> 63) + ((op - 1) >> 63) + 1; }

ILINE f32   sign(f32 op)
{
	return if_else_zero(op, signnz(op));
}
ILINE f64 sign(f64 op) { return if_else_zero(op, signnz(op)); }

// Horizontal operating functions; can be specialized for SIMD types
template<typename T> ILINE T hsum(T v) { return v; }
template<typename T> ILINE T hmin(T v) { return v; }
template<typename T> ILINE T hmax(T v) { return v; }

// Name it so in order to avoid conflicts with cmath.h's "isfinite" function.
template<typename T> ILINE bool valueisfinite(T val)
{
	return std::isfinite(val);
}

} // namespace crymath

template<typename F> ILINE F sqr(const F &op) { return op * op; }
template<typename F> ILINE F square(const F &op) { return op * op; }  //!< Deprecated
template<typename F> ILINE F sqr_signed(const F &op) { return op * crymath::abs(op); }
template<typename F> ILINE F cube(const F &op) { return op * op * op; }

namespace crymath
{

// std::fmod is extremely slow
template<typename T> ILINE T mod(T a, T b)
{
	return a - trunc(a / b) * b;
}

template<typename T> ILINE T frac(T val)
{
	return val - floor(val);
}

template<typename T> ILINE T wrap(T f, T lo, T hi)
{
	const T range = hi - lo;
	return f - floor((f - lo) / range) * range;
}

template<typename T>
ILINE int solve_quadratic(T a, T b, T c, T x[2])
{
	if (!a)
	{
		if (b)
		{
			x[0] = -c / b;
			return 1;
		}
		if (!c)
		{
			x[0] = T(0);
			return 1;
		}
	}
	else
	{
		T bh = b * T(-0.5);
		T d = bh * bh - a * c;

		if (d > T(0))
		{
			T s = bh + signnz(bh) * sqrt(d);

			x[0] = c / s;
			x[1] = s / a;
			return 2;
		}
		if (!d)
		{
			x[0] = bh / a;
			return 1;
		}
	}
	return 0;
}

template<typename T>
float solve_quadratic_in_range(T a, T b, T c, T lo, T hi)
{
	T t[2];
	for (int n = solve_quadratic(a, b, c, t); --n >= 0; )
	{
		if (t[n] >= lo && t[n] <= hi)
			hi = t[n];
	}
	return hi;
}



} // namespace crymath

const int32 inc_mod3[] = { 1, 2, 0 }, dec_mod3[] = { 2, 0, 1 };

template<typename T>
inline bool IsValid(const T &val)
{
	// HACK
	return true;
}

template<>
inline bool IsValid(const float &val) {
	return !isnan(val);
}

template<typename T>
inline void SetInvalid(T &val)
{
	// HACK
}

// Legacy math function names
#define clamp_tpl      crymath::clamp

#define fabs_tpl       crymath::abs
#define floor_tpl      crymath::floor
#define ceil_tpl       crymath::ceil

#define sin_tpl        crymath::sin
#define cos_tpl        crymath::cos
#define tan_tpl        crymath::tan
#define asin_tpl       crymath::asin
#define acos_tpl       crymath::acos
#define atan_tpl       crymath::atan
#define atan2_tpl      crymath::atan2
#define sincos_tpl     crymath::sincos

#define exp_tpl        crymath::exp
#define log_tpl        crymath::log
#define pow_tpl        crymath::pow
#define fmod_tpl       crymath::mod

#define sqrt_tpl       crymath::sqrt
#define sqrt_fast_tpl  crymath::sqrt_fast

#define isqrt_tpl      crymath::rsqrt
#define isqrt_fast_tpl crymath::rsqrt_fast
#define isqrt_safe_tpl crymath::rsqrt_safe

#define __fres         crymath::rcp

// Previously in Cry_XOptimise.h
#define FtoI               int
#define fastftol_positive  int
#define fastround_positive pos_round

//////////////////////////////////////////////////////////////////////////
enum type_zero { ZERO };
enum type_min { VMIN };
enum type_max { VMAX };
enum type_identity { IDENTITY };

#include "NumberVector.h"
#include "Cry_Vector2.h"
#include "Cry_Vector3.h"
#include "Cry_Vector4.h"
#include "Cry_MatrixDiag.h"
#include "Cry_Matrix33.h"
#include "Cry_Matrix34.h"
#include "Cry_Matrix44.h"
#include "Cry_Quat.h"
#include "CryHalf.inl"

#endif //math
