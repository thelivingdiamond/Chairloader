// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

class CRenderObjectsPools
{
	void* pad[280 / sizeof(void*)];
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryRenderer/IShader.h>
#include <Prey/CryRenderer/RenderObject.h>
#include <_unknown/CryLockT.h>
#include <_unknown/SSpecialRenderItemArray.h>

class CConstantBuffer;
class CDeviceCommandList;
class CDeviceGraphicsPSO;
struct CDeviceInputStream;
struct CGpuBuffer;
class CRendElementBase;
class CRenderMesh;
class CRenderObjectsPools;
struct IMaterial;
struct SGraphicsPipelinePassContext;

// CCompiledRenderObject
// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
// Include: Prey/RenderDll/XRenderD3D9/CompiledRenderObject.h
class CCompiledRenderObject
{ // Size=360 (0x168)
public:
	enum EDrawParams
	{
		eDrawParam_General = 0,
		eDrawParam_Shadow = 1,
		eDrawParam_Count = 2,
	};

	// CCompiledRenderObject::SDrawParams
	// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
	struct SDrawParams
	{ // Size=12 (0xC)
		int m_nVerticesCount;
		int m_nStartIndex;
		int m_nNumIndices;

	#if 0
		SDrawParams();
	#endif
	};

	CRenderObject* m_pRO;
	unsigned m_StencilRef : 8;
	unsigned m_nNumVertexStreams : 8;
	unsigned m_nLastVertexStreamSlot : 8;
	unsigned m_bOwnPerInstanceCB : 1;
	unsigned m_bRenderNearest : 1;
	unsigned m_bIncomplete : 1;
	unsigned m_bHasTessellation : 1;
	unsigned m_bSharedWithShadow : 1;
	unsigned m_nModificationId;
	std::array<CDeviceGraphicsPSO*, 5> m_pso[5];
	std::shared_ptr<CDeviceResourceSet> m_materialResourceSet;
	_smart_ptr<CConstantBuffer> m_perInstanceCB;
	std::shared_ptr<CDeviceResourceSet> m_perInstanceExtraResources;
	int m_TessellationPatchIDOffset;
	CGpuBuffer* m_pTessellationAdjacencyBuffer;
	const CDeviceInputStream* m_vertexStreamSet;
	const CDeviceInputStream* m_indexStreamSet;
	CCompiledRenderObject::SDrawParams m_drawParams[2];
	_smart_ptr<CConstantBuffer> m_skinningCB[2];
	CRendElementBase* m_pRenderElement;
	SShaderItem m_shaderItem;
	static inline auto s_pPools = PreyGlobal<CRenderObjectsPools*>(0x2C7E3E0);

	CCompiledRenderObject();
	~CCompiledRenderObject();
	bool Compile(CRenderObject* pRenderObject) { return FCompile(this, pRenderObject); }
	void PrepareForUse(CDeviceCommandList& commandList, bool bInstanceOnly) const { FPrepareForUse(this, commandList, bInstanceOnly); }
	void DrawToCommandList(const SGraphicsPipelinePassContext& passContext, CConstantBuffer* pDynamicInstancingBuffer, unsigned dynamicInstancingCount) const { FDrawToCommandList(this, passContext, pDynamicInstancingBuffer, dynamicInstancingCount); }
	void Init(const SShaderItem& shaderItem, CRendElementBase* pRE) { FInit(this, shaderItem, pRE); }
	static CCompiledRenderObject* AllocateFromPool() { return FAllocateFromPool(); }
	void CompilePerInstanceConstantBuffer(CRenderObject* pRenderObject) { FCompilePerInstanceConstantBuffer(this, pRenderObject); }
	void CompilePerInstanceExtraResources(CRenderObject* pRenderObject) { FCompilePerInstanceExtraResources(this, pRenderObject); }
	void UpdatePerInstanceCB(void* pData, uint64_t size) { FUpdatePerInstanceCB(this, pData, size); }

#if 0
	SShaderItem& GetShaderItem();
	static void FreeToPool(CCompiledRenderObject* _arg0_);
	static void SetStaticPools(CRenderObjectsPools* _arg0_);
#endif

	static inline auto FCCompiledRenderObjectOv1 = PreyFunction<void(CCompiledRenderObject* const _this)>(0xF7FA50);
	static inline auto FBitNotCCompiledRenderObject = PreyFunction<void(CCompiledRenderObject* const _this)>(0xEEF460);
	static inline auto FCompile = PreyFunction<bool(CCompiledRenderObject* const _this, CRenderObject* pRenderObject)>(0xEEFB70);
	static inline auto FPrepareForUse = PreyFunction<void(const CCompiledRenderObject* const _this, CDeviceCommandList& commandList, bool bInstanceOnly)>(0xEF0C20);
	static inline auto FDrawToCommandList = PreyFunction<void(const CCompiledRenderObject* const _this, const SGraphicsPipelinePassContext& passContext, CConstantBuffer* pDynamicInstancingBuffer, unsigned dynamicInstancingCount)>(0xEF0930);
	static inline auto FInit = PreyFunction<void(CCompiledRenderObject* const _this, const SShaderItem& shaderItem, CRendElementBase* pRE)>(0xEF0B70);
	static inline auto FAllocateFromPool = PreyFunction<CCompiledRenderObject* ()>(0xED3D90);
	static inline auto FCompilePerInstanceConstantBuffer = PreyFunction<void(CCompiledRenderObject* const _this, CRenderObject* pRenderObject)>(0xEF0070);
	static inline auto FCompilePerInstanceExtraResources = PreyFunction<void(CCompiledRenderObject* const _this, CRenderObject* pRenderObject)>(0xEF06F0);
	static inline auto FUpdatePerInstanceCB = PreyFunction<void(CCompiledRenderObject* const _this, void* pData, uint64_t size)>(0xEF0D10);
};

// CPermanentRenderObject
// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
// Include: Prey/RenderDll/XRenderD3D9/CompiledRenderObject.h
class CPermanentRenderObject : public CRenderObject
{ // Size=624 (0x270)
public:
	enum ERenderPassType
	{
		eRenderPass_General = 0,
		eRenderPass_Shadows = 1,
		eRenderPass_NumTypes = 2,
	};

	// CPermanentRenderObject::SPermanentRendItem
	// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
	struct SPermanentRendItem
	{ // Size=40 (0x28)
		CCompiledRenderObject* m_pCompiledObject;
		CRendElementBase* m_pRenderElement;
		unsigned m_sortValue;
		unsigned m_shaderPreprocessFlags;
		unsigned m_nBatchFlags;
		uint8_t m_nSceneMask;
		unsigned m_nRenderList : 8;
	};

	SSpecialRenderItemArray<CPermanentRenderObject::SPermanentRendItem,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_permanentRenderItems[2];
	CPermanentRenderObject* m_pNextPermanent;
	volatile int m_compiledReadyMask;
	int m_lastCompiledFrame;
	_smart_ptr<CRenderMesh> m_pUsedRenderMesh[2];
	_smart_ptr<IMaterial> m_pUsedMaterial;
	volatile int m_accessLock;
	static inline auto s_pPools = PreyGlobal<CRenderObjectsPools*>(0x2CA0318);

	~CPermanentRenderObject();
	static CPermanentRenderObject* AllocateFromPool() { return FAllocateFromPool(); }
	static void FreeToPool(CPermanentRenderObject* pObj) { FFreeToPool(pObj); }

#if 0
	CPermanentRenderObject();
	void PrepareForUse(CRendElementBase* _arg0_, CPermanentRenderObject::ERenderPassType _arg1_);
	static void SetStaticPools(CRenderObjectsPools* _arg0_);
#endif

	static inline auto FBitNotCPermanentRenderObject = PreyFunction<void(CPermanentRenderObject* const _this)>(0xEEF690);
	static inline auto FAllocateFromPool = PreyFunction<CPermanentRenderObject* ()>(0xEEFA00);
	static inline auto FFreeToPool = PreyFunction<void(CPermanentRenderObject* pObj)>(0xEF0B30);
};

// CRenderObjectsPools
// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
// Include: Prey/RenderDll/XRenderD3D9/CompiledRenderObject.h
class CRenderObjectsPools
{ // Size=280 (0x118)
public:
	// CRenderObjectsPools::PoolSyncCriticalSection
	// Header:  CryEngine/renderdll/xrenderd3d9/CompiledRenderObject.h
	struct PoolSyncCriticalSection
	{ // Size=40 (0x28)
		CryCriticalSectionNonRecursive m_cs;

	#if 0
		void Lock();
		void Unlock();
	#endif
	};

	stl::TPoolAllocator<CCompiledRenderObject,CRenderObjectsPools::PoolSyncCriticalSection,0> m_compiledObjectsPool;
	stl::TPoolAllocator<CPermanentRenderObject,CRenderObjectsPools::PoolSyncCriticalSection,0> m_permanentRenderObjectsPool;
	std::vector<_smart_ptr<CConstantBuffer>> m_freeConstantBuffers;

	CRenderObjectsPools();
	~CRenderObjectsPools();

#if 0
	_smart_ptr<CConstantBuffer> AllocatePerInstanceConstantBuffer();
	void FreePerInstanceConstantBuffer(_smart_ptr<CConstantBuffer>&& _arg0_);
#endif

	static inline auto FCRenderObjectsPools = PreyFunction<void(CRenderObjectsPools* const _this)>(0xEEF1B0);
	static inline auto FBitNotCRenderObjectsPools = PreyFunction<void(CRenderObjectsPools* const _this)>(0xEEF8A0);
};
#endif // !MOONCRASH
