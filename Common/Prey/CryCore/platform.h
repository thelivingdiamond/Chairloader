#pragma once
#include <Prey/CryCore/BaseTypes.h>

#if defined(__clang__)
#include <Prey/CryCore/Compiler/Clangspecific.h>
#elif defined(__GNUC__)
#include <Prey/CryCore/Compiler/GCCspecific.h>
#elif defined(_MSC_VER)
#include <Prey/CryCore/Compiler/MSVCspecific.h>
#else
#error Unsupported compiler was used.
#endif

// TODO: This should be force-inline in release mode
#define ILINE inline

class CTypeInfo;
#define STRUCT_INFO const CTypeInfo &TypeInfo() const
#define AUTO_STRUCT_INFO STRUCT_INFO

template<typename T>
ILINE bool IsAligned(T nData, size_t nAlign)
{
	assert((nAlign & (nAlign - 1)) == 0);
	return (size_t(nData) & (nAlign - 1)) == 0;
}

// Conditionally execute code in debug only
#ifdef _DEBUG
#define IF_DEBUG(expr) (expr)
#else
#define IF_DEBUG(expr)
#endif

// Define BIT macro for use in enums and bit masks.
#define BIT(x)   (1 << (x))
#define BIT64(x) (1ull << (x))
