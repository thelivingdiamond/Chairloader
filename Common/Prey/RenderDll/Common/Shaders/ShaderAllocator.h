// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef SHADERALLOCATOR_H
#define SHADERALLOCATOR_H

#include <Prey/CryMemory/BucketAllocator.h>
#include <Prey/CryMemory/CryMemoryAllocator.h>
#include <Prey/CryMemory/IMemory.h>
#include <Prey/CryCore/StlUtils.h>

typedef cry_crt_node_allocator ShaderBucketAllocator;

extern ShaderBucketAllocator g_shaderBucketAllocator;
inline PreyGlobal<IGeneralMemoryHeap*> g_shaderGeneralHeap(0x2BA5FE8);

template<class T>
class STLShaderAllocator : public stl::SAllocatorConstruct
{
public:
	typedef size_t    size_type;
	typedef ptrdiff_t difference_type;
	typedef T*        pointer;
	typedef const T*  const_pointer;
	typedef T&        reference;
	typedef const T&  const_reference;
	typedef T         value_type;

	template<class U> struct rebind
	{
		typedef STLShaderAllocator<U> other;
	};

	STLShaderAllocator() throw() {}
	STLShaderAllocator(const STLShaderAllocator&) throw() {}
	template<class U> STLShaderAllocator(const STLShaderAllocator<U>&) throw() {}

	pointer address(reference x) const
	{
		return &x;
	}

	const_pointer address(const_reference x) const
	{
		return &x;
	}

	pointer allocate(size_type n = 1, const void* hint = 0)
	{
		MEMREPLAY_SCOPE(EMemReplayAllocClass::C_UserPointer, EMemReplayUserPointerClass::C_STL);

		pointer ret = NULL;

		(void)hint;
		size_t sz = std::max<size_type>(n * sizeof(T), 1);
		if (sz <= ShaderBucketAllocator::MaxSize)
		{
			ret = static_cast<pointer>(g_shaderBucketAllocator.allocate(sz));
		}
		else
		{
			ret = static_cast<pointer>((*g_shaderGeneralHeap)->Malloc(sz, NULL));
		}

		MEMREPLAY_SCOPE_ALLOC(ret, n * sizeof(T), 0);

		return ret;
	}

	void deallocate(pointer p, size_type n = 1)
	{
		//MEMREPLAY_SCOPE(EMemReplayAllocClass::C_UserPointer, EMemReplayUserPointerClass::C_STL);

		(void)n;
		if (p)
		{
			if (!(*g_shaderGeneralHeap)->Free(p))
				g_shaderBucketAllocator.deallocate(p);
		}

		//MEMREPLAY_SCOPE_FREE(p);
	}

	size_type max_size() const throw()
	{
		return INT_MAX;
	}

	void destroy(pointer p)
	{
		p->~T();
	}

	pointer new_pointer()
	{
		return new(allocate())T();
	}

	pointer new_pointer(const T& val)
	{
		return new(allocate())T(val);
	}

	void delete_pointer(pointer p)
	{
		p->~T();
		deallocate(p);
	}

	bool        operator==(const STLShaderAllocator&) { return true; }
	bool        operator!=(const STLShaderAllocator&) { return false; }

	static void GetMemoryUsage(ICrySizer* pSizer)     {}
};

#endif
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <_unknown/STLShaderAllocator.h>

class ICrySizer;
struct SParamCacheInfo;

// STLShaderAllocator<SParamCacheInfo>
// Header:  CryEngine/renderdll/common/shaders/shaderallocator.h
class STLShaderAllocator<SParamCacheInfo> : public stl::SAllocatorConstruct
{ // Size=1 (0x1)
public:
	// STLShaderAllocator<SParamCacheInfo>::rebind<struct SParamCacheInfo>
	// Header:  CryEngine/renderdll/common/shaders/shaderallocator.h
	struct rebind<struct SParamCacheInfo>
	{ // Size=1 (0x1)
		using other = STLShaderAllocator<SParamCacheInfo>;
	};

	// STLShaderAllocator<SParamCacheInfo>::rebind<struct std::_Container_proxy>
	// Header:  CryEngine/renderdll/common/shaders/shaderallocator.h
	struct rebind<struct std::_Container_proxy>
	{ // Size=1 (0x1)
		using other = STLShaderAllocator<std::_Container_proxy>;
	};

	using size_type = uint64_t;
	using difference_type = int64_t;
	using pointer = SParamCacheInfo*;
	using const_pointer = const SParamCacheInfo*;
	using reference = SParamCacheInfo&;
	using const_reference = const SParamCacheInfo&;
	using value_type = SParamCacheInfo;

	void deallocate(SParamCacheInfo* p, uint64_t n) { Fdeallocate(this, p, n); }

#if 0
	STLShaderAllocator<SParamCacheInfo>();
	STLShaderAllocator<SParamCacheInfo>(const STLShaderAllocator<SParamCacheInfo>& _arg0_);
	SParamCacheInfo* address(SParamCacheInfo& _arg0_) const;
	const SParamCacheInfo* address(const SParamCacheInfo& _arg0_) const;
	SParamCacheInfo* allocate(uint64_t _arg0_, const void* _arg1_);
	uint64_t max_size() const;
	void destroy(SParamCacheInfo* _arg0_);
	SParamCacheInfo* new_pointer();
	SParamCacheInfo* new_pointer(const SParamCacheInfo& _arg0_);
	void delete_pointer(SParamCacheInfo* _arg0_);
	bool operator==(const STLShaderAllocator<SParamCacheInfo>& _arg0_);
	bool operator!=(const STLShaderAllocator<SParamCacheInfo>& _arg0_);
	static void GetMemoryUsage(ICrySizer* _arg0_);
#endif

	static inline auto Fdeallocate = PreyFunction<void(STLShaderAllocator<SParamCacheInfo>* const _this, SParamCacheInfo* p, uint64_t n)>(0x1050C30);
};
#endif // !MOONCRASH
