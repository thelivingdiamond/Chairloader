// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef _BASERESOURCE_H_
#define _BASERESOURCE_H_

#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryThreading/CryAtomics.h>
#include <Prey/CryThreading/CryThread.h>
#include <Prey/CryMath/Cry_Math.h>

#include <Prey/CryRenderer/CryDX.h>
#include <Prey/CryRenderer/IRenderer.h>
#include "Defs.h"
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryMath/Cry_Camera.h>
//#include <Prey/CryMemory/MemoryAccess.h>

#include <Prey/CryMemory/STLGlobalAllocator.h>
#include "CryNameR.h"

#define VSCONST_INSTDATA                0
#define VSCONST_SKINMATRIX              0
#define VSCONST_NOISE_TABLE             0
#define NUM_MAX_BONES_PER_GROUP         (250)
#define NUM_MAX_BONES_PER_GROUP_WITH_MB (125)

//////////////////////////////////////////////////////////////////////
class CRenderer;
extern CRenderer* gRenDev;

class CBaseResource;

//====================================================================

#define CR_LITTLE_ENDIAN

struct SWaveForm;

extern bool gbRgb;

inline DWORD COLCONV(DWORD clr)
{
	return ((clr & 0xff00ff00) | ((clr & 0xff0000) >> 16) | ((clr & 0xff) << 16));
}
inline void COLCONV(ColorF& col)
{
	float v = col[0];
	col[0] = col[2];
	col[2] = v;
}

inline void f2d(double* dst, float* src)
{
	for (int i = 0; i < 16; i++)
	{
		dst[i] = src[i];
	}
}

inline void d2f(float* dst, double* src)
{
	for (int i = 0; i < 16; i++)
	{
		dst[i] = (float)src[i];
	}
}

//=================================================================

typedef std::map<CCryNameTSCRC, CBaseResource*>                              ResourcesMap;

typedef ResourcesMap::iterator                                               ResourcesMapItor;

typedef std::vector<CBaseResource*, stl::STLGlobalAllocator<CBaseResource*>> ResourcesList;
typedef std::vector<int, stl::STLGlobalAllocator<int>>                       ResourceIds;

struct SResourceContainer
{
	ResourcesList m_RList;             // List of objects for acces by Id's
	ResourcesMap  m_RMap;              // Map of objects for fast searching
	ResourceIds   m_AvailableIDs;      // Available object Id's for efficient ID's assigning after deleting

	SResourceContainer()
	{
		m_RList.reserve(512);
	}

	~SResourceContainer();
};

typedef std::map<CCryNameTSCRC, SResourceContainer*> ResourceClassMap;

typedef ResourceClassMap::iterator                   ResourceClassMapItor;

class CBaseResource
{
private:
	// Per resource variables
	volatile int32          m_nRefCount;
	int                     m_nID;
	CCryNameTSCRC           m_ClassName;
	CCryNameTSCRC           m_NameCRC;

	static inline auto m_sResources = PreyGlobal<std::map<CCryNameTSCRC, SResourceContainer*, std::less<CCryNameTSCRC>>>(0x2B24A38);

public:
	static inline auto s_cResLock = PreyGlobal<CryCriticalSection>(0x2B24A48);

public:
	//! Dirty flags will indicate what kind of data was invalidated
	enum EDirtyFlags
	{
		eDeviceResourceDirty     = BIT(0),
		eDeviceResourceViewDirty = BIT(1),
	};

private:
	void UnregisterAndDelete() { FUnregisterAndDelete(this); }

public:
	// CCryUnknown interface
	inline void   SetRefCounter(int nRefCounter) { m_nRefCount = nRefCounter; }
	virtual int   GetRefCounter() const { return m_nRefCount; }
	virtual int32 AddRef()
	{
		int32 nRef = CryInterlockedIncrement(&m_nRefCount);
		return nRef;
	}
	virtual int32 Release()
	{
		// TODO: simplify, it's making ref-counting on CTexture much more expensive than it needs to be
		IF(m_nRefCount > 0, 1)
		{
			int32 nRef = CryInterlockedDecrement(&m_nRefCount);
			if (nRef < 0)
			{
				CryFatalError("CBaseResource::Release() called more than once!");
			}

			if (nRef == 0)
			{
				UnregisterAndDelete();
				return 0;
			}
			return nRef;
		}
		return 0;
	}

	// Increment ref count, if not already scheduled for destruction.
	int32 TryAddRef()
	{
		volatile int nOldRef, nNewRef;
		do
		{
			nOldRef = m_nRefCount;
			if (nOldRef == 0)
				return 0;
			nNewRef = nOldRef + 1;
		}
		while (CryInterlockedCompareExchange(alias_cast<volatile LONG*>(&m_nRefCount), nNewRef, nOldRef) != nOldRef);
		return nNewRef;
	}

	// Constructors.
	CBaseResource() : m_nRefCount(1), m_nID(0) {}
	CBaseResource(const CBaseResource& Src);
	CBaseResource& operator=(const CBaseResource& Src);

	// Destructor.
	virtual ~CBaseResource() {};

	CCryNameTSCRC GetNameCRC() { return m_NameCRC; }
	//inline const char *GetName() const { return m_Name.c_str(); }
	//inline const char *GetClassName() const { return m_ClassName.c_str(); }
	inline int                 GetID() const  { return m_nID; }
	inline void                SetID(int nID) { m_nID = nID; }

	virtual bool               IsValid();

	static ILINE int           RListIndexFromId(int id)  { return id - 1; }
	static ILINE int           IdFromRListIndex(int idx) { return idx + 1; }

	static ResourceClassMap&   GetMaps()                 { return *m_sResources; }
	static CBaseResource*      GetResource(const CCryNameTSCRC& className, int nID, bool bAddRef);
	static CBaseResource*      GetResource(const CCryNameTSCRC& className, const CCryNameTSCRC& Name, bool bAddRef);
	static SResourceContainer* GetResourcesForClass(const CCryNameTSCRC& className);
	static void                ShutDown();

	bool                       Register(const CCryNameTSCRC& resName, const CCryNameTSCRC& Name);
	bool                       UnRegister();

	virtual void               GetMemoryUsage(ICrySizer* pSizer) const = 0;

	// Will notify resource's user that some data of the the resource was invalidated.
	// dirtyFlags - one or more of the EDirtyFlags enum bits
	virtual void InvalidateDeviceResource(uint32 dirtyFlags) {};

	static inline auto FUnregisterAndDelete = PreyFunction<void(CBaseResource* const _this)>(0xFAE210);
	static inline auto FGetRefCounter = PreyFunction<int(CBaseResource const* const _this)>(0xEEBB60);
	static inline auto FAddRef = PreyFunction<int(CBaseResource* const _this)>(0xDA2BE0);
	static inline auto FRelease = PreyFunction<int(CBaseResource* const _this)>(0xE80350);
	static inline auto FIsValid = PreyFunction<bool(CBaseResource* const _this)>(0xFADE80);
	static inline auto FGetResourceOv1 = PreyFunction<CBaseResource* (CCryNameTSCRC const& className, int nID, bool bAddRef)>(0xFADD70);
	static inline auto FGetResourceOv0 = PreyFunction<CBaseResource* (CCryNameTSCRC const& className, CCryNameTSCRC const& Name, bool bAddRef)>(0xFADC90);
	static inline auto FGetResourcesForClass = PreyFunction<SResourceContainer* (CCryNameTSCRC const& className)>(0xFADE40);
	static inline auto FRegister = PreyFunction<bool(CBaseResource* const _this, CCryNameTSCRC const& className, CCryNameTSCRC const& Name)>(0xFADF90);
	static inline auto FInvalidateDeviceResource = PreyFunction<void(CBaseResource* const _this, unsigned dirtyFlags)>(0xA13080);
};

//=================================================================

#if CAPTURE_REPLAY_LOG && (defined(WIN32) || defined (WIN64))
	#define MEMREPLAY_WRAP_D3D11
	#define MEMREPLAY_WRAP_D3D11_CONTEX
#endif

#if CAPTURE_REPLAY_LOG && defined(DURANGO) && defined(DIRECT3D10)
	#define MEMREPLAY_WRAP_D3D11
	#define MEMREPLAY_WRAP_D3D11_CONTEXT
	#define MEMREPLAY_WRAP_XBOX_PERFORMANCE_DEVICE
	#define MEMREPLAY_INSTRUMENT_TEXTUREPOOL
#endif

#ifdef MEMREPLAY_WRAP_D3D11

class MemReplayD3DAnnotation : public IUnknown
{
public:
	static const GUID s_guid;

public:
	MemReplayD3DAnnotation(ID3D11DeviceChild* pRes, size_t sz);
	~MemReplayD3DAnnotation();

	void                              AddMap(UINT nSubRes, void* pData, size_t sz);
	void                              RemoveMap(UINT nSubRes);

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
	virtual ULONG STDMETHODCALLTYPE   AddRef();
	virtual ULONG STDMETHODCALLTYPE   Release();

private:
	struct MapDesc
	{
		UINT  nSubResource;
		void* pData;
	};

private:
	MemReplayD3DAnnotation(const MemReplayD3DAnnotation&);
	MemReplayD3DAnnotation& operator=(const MemReplayD3DAnnotation&);

private:
	ULONG                m_nRefCount;
	ID3D11DeviceChild*   m_pRes;
	std::vector<MapDesc> m_maps;
};

inline void MemReplayAnnotateD3DResource(ID3D11DeviceChild* pResource, size_t resSz)
{
	if (pResource)
	{
		UINT sz = sizeof(MemReplayD3DAnnotation*);
		MemReplayD3DAnnotation* pAnnotation;
		if (FAILED(pResource->GetPrivateData(MemReplayD3DAnnotation::s_guid, &sz, &pAnnotation)))
		{
			pAnnotation = new MemReplayD3DAnnotation(pResource, resSz);
			pResource->SetPrivateDataInterface(MemReplayD3DAnnotation::s_guid, pAnnotation);
		}
	}
}

inline MemReplayD3DAnnotation* MemReplayGetD3DAnnotation(ID3D11DeviceChild* pResource)
{
	if (pResource)
	{
		UINT sz = sizeof(MemReplayD3DAnnotation*);
		MemReplayD3DAnnotation* pAnnotation;
		if (!FAILED(pResource->GetPrivateData(MemReplayD3DAnnotation::s_guid, &sz, &pAnnotation)))
		{
			return pAnnotation;
		}
	}
	return NULL;
}

#endif

// No profiling support
#define FUNCTION_PROFILER_RENDER_FLAT /**/
#define FUNCTION_PROFILER_RENDERER /**/
#define PROFILE_LABEL_SCOPE(s) /**/

#define SUPPORT_FLEXIBLE_INDEXBUFFER // supports 16 as well as 32 bit indices AND index buffer bind offset

enum RenderIndexType
{
#if defined(SUPPORT_FLEXIBLE_INDEXBUFFER)
	Index16 = DXGI_FORMAT_R16_UINT,
	Index32 = DXGI_FORMAT_R32_UINT
#else
	Index16,
	Index32
#endif
};

enum ERenderPrimitiveType
{
	eptUnknown = -1,
	eptTriangleList = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
	eptTriangleStrip = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
	eptLineList = D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
	eptLineStrip = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
	eptPointList = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
	ept1ControlPointPatchList = D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST,
	ept2ControlPointPatchList = D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST,
	ept3ControlPointPatchList = D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST,
	ept4ControlPointPatchList = D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST,

	// non-real primitives, used for logical batching
	eptHWSkinGroups = 0x3f
};

#define MAX_TMU   64

template<class Container>
unsigned sizeOfVP(Container& arr)
{
	int i;
	unsigned size = 0;
	for (i = 0; i < (int)arr.size(); i++)
	{
		typename Container::value_type& T = arr[i];
		size += T->Size();

	}
	size += (arr.capacity() - arr.size()) * sizeof(typename Container::value_type);
	return size;
}

template<class Container>
unsigned sizeOfV(Container& arr)
{
	int i;
	unsigned size = 0;
	for (i = 0; i < (int)arr.size(); i++)
	{
		typename Container::value_type& T = arr[i];
		size += T.Size();

	}
	size += (arr.capacity() - arr.size()) * sizeof(typename Container::value_type);
	return size;
}
template<class Container>
unsigned sizeOfA(Container& arr)
{
	int i;
	unsigned size = 0;
	for (i = 0; i < arr.size(); i++)
	{
		typename Container::value_type& T = arr[i];
		size += T.Size();

	}
	return size;
}
template<class Map>
unsigned sizeOfMap(Map& map)
{
	unsigned size = 0;
	for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		typename Map::mapped_type& T = it->second;
		size += T.Size();
	}
	size += map.size() * sizeof(stl::MapLikeStruct);
	return size;
}
template<class Map>
unsigned sizeOfMapStr(Map& map)
{
	unsigned size = 0;
	for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		typename Map::mapped_type& T = it->second;
		size += T.capacity();
	}
	size += map.size() * sizeof(stl::MapLikeStruct);
	return size;
}
template<class Map>
unsigned sizeOfMapP(Map& map)
{
	unsigned size = 0;
	for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		typename Map::mapped_type& T = it->second;
		size += T->Size();
	}
	size += map.size() * sizeof(stl::MapLikeStruct);
	return size;
}
template<class Map>
unsigned sizeOfMapS(Map& map)
{
	unsigned size = 0;
	for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		typename Map::mapped_type& T = it->second;
		size += sizeof(T);
	}
	size += map.size() * sizeof(stl::MapLikeStruct);
	return size;
}

#endif
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/RenderDll/Common/CryNameR.h>
#include <_unknown/CryLockT.h>

class CDeviceObjectFactory;
struct D3D11_BLEND_DESC;
struct D3D11_BUFFER_DESC;
struct D3D11_COUNTER_DESC;
struct D3D11_COUNTER_INFO;
enum class D3D11_COUNTER_TYPE;
struct D3D11_DEPTH_STENCIL_DESC;
struct D3D11_DEPTH_STENCIL_VIEW_DESC;
enum class D3D11_FEATURE;
struct D3D11_INPUT_ELEMENT_DESC;
struct D3D11_QUERY_DESC;
struct D3D11_RASTERIZER_DESC;
struct D3D11_RENDER_TARGET_VIEW_DESC;
enum class D3D11_RESOURCE_DIMENSION;
struct D3D11_SAMPLER_DESC;
struct D3D11_SHADER_RESOURCE_VIEW_DESC;
struct D3D11_SO_DECLARATION_ENTRY;
struct D3D11_SUBRESOURCE_DATA;
struct D3D11_TEXTURE1D_DESC;
struct D3D11_TEXTURE2D_DESC;
struct D3D11_TEXTURE3D_DESC;
struct D3D11_UNORDERED_ACCESS_VIEW_DESC;
enum class D3D_FEATURE_LEVEL;
enum class DXGI_FORMAT;
struct ICryDeviceWrapperHook;
class ICrySizer;
struct ID3D11BlendState;
struct ID3D11Buffer;
struct ID3D11ClassLinkage;
struct ID3D11ComputeShader;
struct ID3D11Counter;
struct ID3D11DepthStencilState;
struct ID3D11DepthStencilView;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11DomainShader;
struct ID3D11GeometryShader;
struct ID3D11HullShader;
struct ID3D11InputLayout;
struct ID3D11PixelShader;
struct ID3D11Predicate;
struct ID3D11Query;
struct ID3D11RasterizerState;
struct ID3D11RenderTargetView;
struct ID3D11Resource;
struct ID3D11SamplerState;
struct ID3D11ShaderResourceView;
struct ID3D11Texture1D;
struct ID3D11Texture2D;
struct ID3D11Texture3D;
struct ID3D11UnorderedAccessView;
struct ID3D11VertexShader;
struct IUnknown;
struct SResourceContainer;

// CBaseResource
// Header:  CryEngine/renderdll/common/commonrender.h
// Include: Prey/RenderDll/Common/CommonRender.h
class CBaseResource
{ // Size=24 (0x18)
public:
	enum EDirtyFlags
	{
		eDeviceResourceDirty = 1,
		eDeviceResourceViewDirty = 2,
	};

	volatile int m_nRefCount;
	int m_nID;
	CCryNameTSCRC m_ClassName;
	CCryNameTSCRC m_NameCRC;
	static inline auto m_sResources = PreyGlobal<std::map<CCryNameTSCRC, SResourceContainer*>>(0x2C93C98);
	static inline auto s_cResLock = PreyGlobal<CryCriticalSection>(0x2C93CA8);

	void UnregisterAndDelete() { FUnregisterAndDelete(this); }
	virtual int GetRefCounter() const;
	virtual int AddRef();
	virtual int Release();
	virtual ~CBaseResource();
	virtual bool IsValid();
	static CBaseResource* GetResource(const CCryNameTSCRC& className, int nID, bool bAddRef) { return FGetResourceOv1(className, nID, bAddRef); }
	static CBaseResource* GetResource(const CCryNameTSCRC& className, const CCryNameTSCRC& Name, bool bAddRef) { return FGetResourceOv0(className, Name, bAddRef); }
	static SResourceContainer* GetResourcesForClass(const CCryNameTSCRC& className) { return FGetResourcesForClass(className); }
	bool Register(const CCryNameTSCRC& className, const CCryNameTSCRC& Name) { return FRegister(this, className, Name); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual void InvalidateDeviceResource(unsigned dirtyFlags);

#if 0
	void SetRefCounter(int _arg0_);
	int TryAddRef();
	CBaseResource();
	CBaseResource(const CBaseResource& _arg0_);
	CBaseResource& operator=(const CBaseResource& _arg0_);
	CCryNameTSCRC GetNameCRC();
	int GetID() const;
	void SetID(int _arg0_);
	static int RListIndexFromId(int _arg0_);
	static int IdFromRListIndex(int _arg0_);
	static std::map<CCryNameTSCRC, SResourceContainer*>& GetMaps();
	static void ShutDown();
	bool UnRegister();
#endif

	static inline auto FUnregisterAndDelete = PreyFunction<void(CBaseResource* const _this)>(0xFCA4B0);
	static inline auto FGetRefCounter = PreyFunction<int(const CBaseResource* const _this)>(0x899030);
	static inline auto FAddRef = PreyFunction<int(CBaseResource* const _this)>(0xDC0880);
	static inline auto FRelease = PreyFunction<int(CBaseResource* const _this)>(0xE9C780);
	static inline auto FIsValid = PreyFunction<bool(CBaseResource* const _this)>(0xFCA120);
	static inline auto FGetResourceOv1 = PreyFunction<CBaseResource* (const CCryNameTSCRC& className, int nID, bool bAddRef)>(0xFCA010);
	static inline auto FGetResourceOv0 = PreyFunction<CBaseResource* (const CCryNameTSCRC& className, const CCryNameTSCRC& Name, bool bAddRef)>(0xFC9F30);
	static inline auto FGetResourcesForClass = PreyFunction<SResourceContainer* (const CCryNameTSCRC& className)>(0xFCA0E0);
	static inline auto FRegister = PreyFunction<bool(CBaseResource* const _this, const CCryNameTSCRC& className, const CCryNameTSCRC& Name)>(0xFCA230);
	static inline auto FInvalidateDeviceResource = PreyFunction<void(CBaseResource* const _this, unsigned dirtyFlags)>(0x1333E90);
};

// CCryDeviceWrapper
// Header:  CryEngine/renderdll/common/commonrender.h
// Include: Prey/RenderDll/Common/CryDeviceWrapper.h
class CCryDeviceWrapper
{ // Size=16 (0x10)
public:
	ID3D11Device* m_pDevice;
	_smart_ptr<ICryDeviceWrapperHook> m_pDeviceHooks;

	static CDeviceObjectFactory& GetObjectFactory() { return FGetObjectFactory(); }

#if 0
	CCryDeviceWrapper();
	bool IsValid() const;
	void AssignDevice(ID3D11Device* _arg0_);
	void SwitchNodeVisibility(unsigned _arg0_);
	void ReleaseDevice();
	ID3D11Device* GetRealDevice() const;
	void RegisterHook(ICryDeviceWrapperHook* _arg0_);
	void UnregisterHook(const char* _arg0_);
	HRESULT QueryInterface(const _GUID& _arg0_, void* * _arg1_);
	unsigned long AddRef();
	unsigned long Release();
	HRESULT GetDeviceRemovedReason();
	HRESULT SetExceptionMode(unsigned _arg0_);
	unsigned GetExceptionMode();
	HRESULT GetPrivateData(const _GUID& _arg0_, unsigned* _arg1_, void* _arg2_);
	HRESULT SetPrivateData(const _GUID& _arg0_, unsigned _arg1_, const void* _arg2_);
	HRESULT SetPrivateDataInterface(const _GUID& _arg0_, const IUnknown* _arg1_);
	HRESULT CreateBuffer(const D3D11_BUFFER_DESC* _arg0_, const D3D11_SUBRESOURCE_DATA* _arg1_, ID3D11Buffer* * _arg2_);
	HRESULT CreateTexture1D(const D3D11_TEXTURE1D_DESC* _arg0_, const D3D11_SUBRESOURCE_DATA* _arg1_, ID3D11Texture1D* * _arg2_);
	HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* _arg0_, const D3D11_SUBRESOURCE_DATA* _arg1_, ID3D11Texture2D* * _arg2_);
	HRESULT CreateTexture3D(const D3D11_TEXTURE3D_DESC* _arg0_, const D3D11_SUBRESOURCE_DATA* _arg1_, ID3D11Texture3D* * _arg2_);
	HRESULT CreateShaderResourceView(ID3D11Resource* _arg0_, const D3D11_SHADER_RESOURCE_VIEW_DESC* _arg1_, ID3D11ShaderResourceView* * _arg2_);
	HRESULT CreateRenderTargetView(ID3D11Resource* _arg0_, const D3D11_RENDER_TARGET_VIEW_DESC* _arg1_, ID3D11RenderTargetView* * _arg2_);
	HRESULT CreateDepthStencilView(ID3D11Resource* _arg0_, const D3D11_DEPTH_STENCIL_VIEW_DESC* _arg1_, ID3D11DepthStencilView* * _arg2_);
	HRESULT CreateUnorderedAccessView(ID3D11Resource* _arg0_, const D3D11_UNORDERED_ACCESS_VIEW_DESC* _arg1_, ID3D11UnorderedAccessView* * _arg2_);
	HRESULT CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* _arg0_, unsigned _arg1_, const void* _arg2_, uint64_t _arg3_, ID3D11InputLayout* * _arg4_);
	HRESULT CreateVertexShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11VertexShader* * _arg3_);
	HRESULT CreateGeometryShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11GeometryShader* * _arg3_);
	HRESULT CreateGeometryShaderWithStreamOutput(const void* _arg0_, uint64_t _arg1_, const D3D11_SO_DECLARATION_ENTRY* _arg2_, unsigned _arg3_, const unsigned* _arg4_, unsigned _arg5_, unsigned _arg6_, ID3D11ClassLinkage* _arg7_, ID3D11GeometryShader* * _arg8_);
	HRESULT CreatePixelShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11PixelShader* * _arg3_);
	HRESULT CreateHullShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11HullShader* * _arg3_);
	HRESULT CreateDomainShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11DomainShader* * _arg3_);
	HRESULT CreateComputeShader(const void* _arg0_, uint64_t _arg1_, ID3D11ClassLinkage* _arg2_, ID3D11ComputeShader* * _arg3_);
	HRESULT CreateBlendState(const D3D11_BLEND_DESC* _arg0_, ID3D11BlendState* * _arg1_);
	HRESULT CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC* _arg0_, ID3D11DepthStencilState* * _arg1_);
	HRESULT CreateRasterizerState(const D3D11_RASTERIZER_DESC* _arg0_, ID3D11RasterizerState* * _arg1_);
	HRESULT CreateSamplerState(const D3D11_SAMPLER_DESC* _arg0_, ID3D11SamplerState* * _arg1_);
	HRESULT CreateQuery(const D3D11_QUERY_DESC* _arg0_, ID3D11Query* * _arg1_);
	HRESULT CreatePredicate(const D3D11_QUERY_DESC* _arg0_, ID3D11Predicate* * _arg1_);
	HRESULT CreateClassLinkage(ID3D11ClassLinkage* * _arg0_);
	unsigned GetCreationFlags();
	void GetImmediateContext(ID3D11DeviceContext* * _arg0_);
	HRESULT CreateDeferredContext(unsigned _arg0_, ID3D11DeviceContext* * _arg1_);
	D3D_FEATURE_LEVEL GetFeatureLevel();
	unsigned GetNodeCount();
	HRESULT CheckFeatureSupport(D3D11_FEATURE _arg0_, void* _arg1_, unsigned _arg2_);
	HRESULT CheckFormatSupport(DXGI_FORMAT _arg0_, unsigned* _arg1_);
	HRESULT CheckMultisampleQualityLevels(DXGI_FORMAT _arg0_, unsigned _arg1_, unsigned* _arg2_);
	void CheckCounterInfo(D3D11_COUNTER_INFO* _arg0_);
	HRESULT CreateCounter(const D3D11_COUNTER_DESC* _arg0_, ID3D11Counter* * _arg1_);
	HRESULT CheckCounter(const D3D11_COUNTER_DESC* _arg0_, D3D11_COUNTER_TYPE* _arg1_, unsigned* _arg2_, char* _arg3_, unsigned* _arg4_, char* _arg5_, unsigned* _arg6_, char* _arg7_, unsigned* _arg8_);
	HRESULT OpenSharedResource(void* _arg0_, const _GUID& _arg1_, void* * _arg2_);
	HRESULT CreateTarget1D(const D3D11_TEXTURE1D_DESC* _arg0_, const float* _arg1_, const D3D11_SUBRESOURCE_DATA* _arg2_, ID3D11Texture1D* * _arg3_);
	HRESULT CreateTarget2D(const D3D11_TEXTURE2D_DESC* _arg0_, const float* _arg1_, const D3D11_SUBRESOURCE_DATA* _arg2_, ID3D11Texture2D* * _arg3_);
	HRESULT CreateTarget3D(const D3D11_TEXTURE3D_DESC* _arg0_, const float* _arg1_, const D3D11_SUBRESOURCE_DATA* _arg2_, ID3D11Texture3D* * _arg3_);
	HRESULT CreateNullResource(D3D11_RESOURCE_DIMENSION _arg0_, ID3D11Resource* * _arg1_);
	HRESULT ReleaseNullResource(ID3D11Resource* _arg0_);
	HRESULT CreateStagingResource(ID3D11Resource* _arg0_, ID3D11Resource* * _arg1_, int _arg2_);
	HRESULT ReleaseStagingResource(ID3D11Resource* _arg0_);
#endif

	static inline auto FGetObjectFactory = PreyFunction<CDeviceObjectFactory& ()>(0xFC9EB0);
};

// SResourceContainer
// Header:  CryEngine/renderdll/common/commonrender.h
// Include: Prey/RenderDll/Common/CommonRender.h
struct SResourceContainer
{ // Size=64 (0x40)
	std::vector<CBaseResource*, stl::STLGlobalAllocator<CBaseResource*>> m_RList;
	std::map<CCryNameTSCRC, CBaseResource*> m_RMap;
	std::vector<int, stl::STLGlobalAllocator<int>> m_AvailableIDs;

	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }

#if 0
	SResourceContainer();
	~SResourceContainer();
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const SResourceContainer* const _this, ICrySizer* pSizer)>(0xF6AA20);
};
#endif // !MOONCRASH
