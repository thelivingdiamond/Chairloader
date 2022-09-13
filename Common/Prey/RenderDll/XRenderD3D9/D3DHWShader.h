// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   D3DCGPShader.h : Direct3D9 CG pixel shaders interface declaration.

   Revision history:
* Created by Honitch Andrey

   =============================================================================*/

#ifndef __D3DHWSHADER_H__
#define __D3DHWSHADER_H__
#include "../Common/Shaders/CShader.h"
#include "../Common/Renderer.h"

#if CRY_PLATFORM_ORBIS && defined(USE_SCUE)
//#define USE_PER_FRAME_CONSTANT_BUFFER_UPDATES // TODO: Restore this
#endif

#define MERGE_SHADER_PARAMETERS 1

// Streams redefinitions (TEXCOORD#)
#define VSTR_COLOR1       4   //Base Stream
#define VSTR_NORMAL1      5   //Base Stream
#define VSTR_PSIZE        6   //Base particles stream
//#define VSTR_MORPHTARGETDELTA 7 // MorphTarget stream (VSF_HWSKIN_MORPHTARGET_INFO)
#define VSTR_TANGENT      8   // Tangents stream (VSF_TANGENTS)
#define VSTR_BITANGENT    9   // Tangents stream (VSF_TANGENTS) -> unused, remove
#define VSTR_BLENDWEIGHTS 10  // HWSkin stream (VSF_HWSKIN_INFO)
#define VSTR_BLENDINDICES 11  // HWSkin stream (VSF_HWSKIN_INFO)
#define VSTR_BONESPACE    12  // HWSkin stream (VSF_HWSKIN_INFO)

#define MAX_CONSTANTS_PS  512
#define MAX_CONSTANTS_VS  512
#define MAX_CONSTANTS_GS  512
#define MAX_CONSTANTS_DS  512
#define MAX_CONSTANTS_HS  512
#define MAX_CONSTANTS_CS  512

#define INST_PARAM_SIZE   sizeof(Vec4)

#if CRY_PLATFORM_SSE2
typedef __m128 VECTOR_TYPE;
	#define VECTOR_CONST(x, y, z, w) { x, y, z, w }  //{ w, z, y, x }
	#define VECTOR_ZERO()            _mm_setzero_ps()
	#define VECTOR_XOR(a, b)         _mm_xor_ps(a, b)
#else
union USoftVector
{
	struct
	{
		float x, y, z, w;
	};
	uint32 u[4];
};
typedef CRY_ALIGN (16) USoftVector VECTOR_TYPE;
	#define VECTOR_CONST(x, y, z, w) { \
	  { x, y, z, w }                   \
}
const VECTOR_TYPE g_VectorZero = VECTOR_CONST(0.f, 0.f, 0.f, 0.f);
	#define VECTOR_ZERO()            (g_VectorZero)
inline VECTOR_TYPE VECTOR_XOR(const VECTOR_TYPE& a, const VECTOR_TYPE& b)
{
	VECTOR_TYPE r;
	r.u[0] = a.u[0] ^ b.u[0];
	r.u[1] = a.u[1] ^ b.u[1];
	r.u[2] = a.u[2] ^ b.u[2];
	r.u[3] = a.u[3] ^ b.u[3];
	return r;
}
#endif

union UFloat4
{
	float       f[4];
	uint        ui[4];
	VECTOR_TYPE m128;
};

class CConstantBuffer;

//==============================================================================

int D3DXGetSHParamHandle(void* pSH, SCGBind* pParam);

struct SParamsGroup
{
	std::vector<SCGParam> Params[2];
	std::vector<SCGParam> Params_Inst;
};

enum ED3DShError
{
	ED3DShError_NotCompiled,
	ED3DShError_CompilingError,
	ED3DShError_Fake,
	ED3DShError_Ok,
	ED3DShError_Compiling,
};

//====================================================================================

struct SCGParamsGroup
{
	uint16    nParams;
	uint16    nSamplers;
	uint16    nTextures;
	bool      bGeneral; // Indicates that we should use fast parameters handling
	SCGParam* pParams;
	int       nPool;
	int       nRefCounter;
	SCGParamsGroup()
	{
		nParams = 0;
		bGeneral = false;
		nPool = 0;
		pParams = NULL;
		nRefCounter = 1;
	}
	unsigned Size()                                  { return sizeof(*this); }
	void     GetMemoryUsage(ICrySizer* pSizer) const {}
};

#define PARAMS_POOL_SIZE 256

struct SCGParamPool
{
protected:
	PodArray<alloc_info_struct> m_alloc_info;
	Array<SCGParam>             m_Params;

public:

	SCGParamPool(int nEntries = 0);
	~SCGParamPool();
	SCGParamsGroup Alloc(int nEntries);
	bool           Free(SCGParamsGroup& Group);

	size_t         Size()
	{
		return sizeof(*this) + sizeOfV(m_alloc_info) + m_Params.size_mem();
	}
	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(m_alloc_info);
		pSizer->Add(m_Params.begin(), m_Params.size());
	}
};

template<>
inline bool raw_movable(const SCGParamPool&)
{
	return true;
}

class CGParamManager
{
	friend class CHWShader_D3D;
	//friend struct CHWShader_D3D::SHWSInstance;

	static inline auto s_FreeGroups = PreyGlobal<std::vector<unsigned int, stl::STLGlobalAllocator<unsigned int> >>(0x2B16808);

public:
	static void          Init();
	static void          Shutdown();

	static SCGParamPool* NewPool(int nEntries);
	static int GetParametersGroup(SParamsGroup& InGr, int nId) { return FGetParametersGroup(InGr, nId); }
	static bool FreeParametersGroup(int nIDGroup) { return FFreeParametersGroup(nIDGroup); }

	static inline auto s_Groups = PreyGlobal<std::vector<SCGParamsGroup>>(0x2B167F0);
	static inline auto s_Pools = PreyGlobal<DynArray<SCGParamPool>>(0x2B167E8);
	static inline auto FGetParametersGroup = PreyFunction<int(SParamsGroup& InGr, int nId)>(0xEEB600);
	static inline auto FFreeParametersGroup = PreyFunction<bool(int nIDGroup)>(0xEEB110);
};

//=========================================================================================

struct SD3DShader
{
	int   m_nRef;
	void* m_pHandle;
	bool  m_bBound;
	bool m_bDisabled;

	SD3DShader()
	{
		m_nRef = 1;
		m_pHandle = NULL;
		m_bBound = false;
		m_bDisabled = false;
	}
	int AddRef()
	{
		return m_nRef++;
	}
	int  Release(EHWShaderClass eSHClass, int nSize);

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(this, sizeof(*this));
	}
};

struct SD3DShaderHandle
{
	SD3DShader* m_pShader;
	byte*       m_pData;
	int         m_nData;
	byte        m_bStatus;
	SD3DShaderHandle()
	{
		m_pShader = NULL;
		m_bStatus = 0;
		m_nData = 0;
		m_pData = NULL;
	}
	void SetShader(SD3DShader* pShader)
	{
		m_bStatus = 0;
		m_pShader = pShader;
	}
	void SetFake()
	{
		m_bStatus = 2;
	}
	void SetNonCompilable()
	{
		m_bStatus = 1;
	}
	int AddRef()
	{
		if (!m_pShader)
			return 0;
		return m_pShader->AddRef();
	}
	int Release(EHWShaderClass eSHClass, int nSize)
	{
		if (!m_pShader)
			return 0;
		return m_pShader->Release(eSHClass, nSize);
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		pSizer->AddObject(m_pShader);
	}
};

struct SShaderAsyncInfo
{
	SShaderAsyncInfo* m_Next;           //!<
	SShaderAsyncInfo* m_Prev;           //!<
	inline void       Unlink()
	{
		if (!m_Next || !m_Prev)
			return;
		m_Next->m_Prev = m_Prev;
		m_Prev->m_Next = m_Next;
		m_Next = m_Prev = NULL;
	}
	inline void Link(SShaderAsyncInfo* Before)
	{
		if (m_Next || m_Prev)
			return;
		m_Next = Before->m_Next;
		Before->m_Next->m_Prev = this;
		Before->m_Next = this;
		m_Prev = Before;
	}
	static void FlushPendingShaders();

#if CRY_PLATFORM_DURANGO || defined(OPENGL)
	#define LPD3DXBUFFER    D3DBlob *
	#define ID3DXBuffer     D3DBlob
	#define D3D10CreateBlob D3DCreateBlob
#endif

	int                  m_nHashInstance;
	uint64               m_RTMask;
	uint32               m_LightMask;
	uint32               m_MDMask;
	uint32               m_MDVMask;
	EHWShaderClass       m_eClass;
	UPipelineState       m_pipelineState;
	class CHWShader_D3D* m_pShader;
	CShader*             m_pFXShader;

	LPD3D10BLOB          m_pDevShader;
	LPD3D10BLOB          m_pErrors;
	void*                m_pConstants;
	string               m_Name;
	string               m_Text;
	string               m_Errors;
	string               m_Profile;
	string               m_RequestLine;
	string               m_shaderList;
	//CShaderThread *m_pThread;
	std::vector<SCGBind> m_InstBindVars;
	byte                 m_bPending;
	bool                 m_bPendedFlush;
	bool                 m_bPendedSamplers;
	bool                 m_bPendedEnv;
	bool                 m_bDeleteAfterRequest;
	float                m_fMinDistance;
	int                  m_nFrame;
	int                  m_nThread;
	int                  m_nCombination;

	SShaderAsyncInfo()
		: m_Next(nullptr)
		, m_Prev(nullptr)
		, m_nHashInstance(-1)
		, m_RTMask(0)
		, m_LightMask(0)
		, m_MDMask(0)
		, m_MDVMask(0)
		, m_eClass(eHWSC_Num)
		, m_pShader(nullptr)
		, m_pFXShader(nullptr)
		, m_pDevShader(nullptr)
		, m_pErrors(nullptr)
		, m_pConstants(nullptr)
		, m_bPending(true) // this flag is now used as an atomic indication that if the async shader has been compiled
		, m_bPendedFlush(false)
		, m_bPendedSamplers(false)
		, m_bPendedEnv(false)
		, m_bDeleteAfterRequest(false)
		, m_fMinDistance(0.0f)
		, m_nFrame(0)
		, m_nThread(0)
		, m_nCombination(-1)
	{
	}

	~SShaderAsyncInfo();
	static inline auto s_nPendingAsyncShaders = PreyGlobal<volatile int>(0x2B168A4);
	static inline auto s_nPendingAsyncShadersFXC = PreyGlobal<int>(0x2B168A8);
	static SShaderAsyncInfo& PendingList();
	static SShaderAsyncInfo& PendingListT();
	static inline auto s_RequestEv = PreyGlobal<CryEvent>(0x2B168D8);
};

#ifdef SHADER_ASYNC_COMPILATION

	#include <CryThreading/IThreadManager.h>
	#define SHADER_THREAD_NAME "ShaderCompile"

class CAsyncShaderTask
{
	friend class CD3D9Renderer; // so it can instantiate us

public:
	CAsyncShaderTask();

	static void InsertPendingShader(SShaderAsyncInfo* pAsync);
	int         GetThread()
	{
		return m_nThread;
	}
	int GetThreadFXC()
	{
		return m_nThreadFXC;
	}
	void SetThread(int nThread)
	{
		m_nThread = nThread;
		m_nThreadFXC = -1;
	}
	void SetThreadFXC(int nThread)
	{
		m_nThreadFXC = nThread;
	}

private:
	void                     FlushPendingShaders();

	static SShaderAsyncInfo& BuildList();
	SShaderAsyncInfo         m_flush_list;
	int                      m_nThread;
	int                      m_nThreadFXC;

	class CShaderThread : public IThread
	{
	public:
		CShaderThread(CAsyncShaderTask* task)
			: m_task(task)
			, m_quit(false)
		{
			CAsyncShaderTask::BuildList().m_Next = &CAsyncShaderTask::BuildList();
			CAsyncShaderTask::BuildList().m_Prev = &CAsyncShaderTask::BuildList();

			task->m_flush_list.m_Next = &task->m_flush_list;
			task->m_flush_list.m_Prev = &task->m_flush_list;

			if (!gEnv->pThreadManager->SpawnThread(this, SHADER_THREAD_NAME))
			{
				CryFatalError("Error spawning \"%s\" thread.", SHADER_THREAD_NAME);
			}
		}

		~CShaderThread()
		{
			m_quit = true;
			gEnv->pThreadManager->JoinThread(this, eJM_Join);
		}

	private:
		// Start accepting work on thread
		virtual void ThreadEntry();

		CAsyncShaderTask* m_task;
		volatile bool     m_quit;
	};

	CShaderThread m_thread;

	bool CompileAsyncShader(SShaderAsyncInfo* pAsync);
	void SubmitAsyncRequestLine(SShaderAsyncInfo* pAsync);
	bool PostCompile(SShaderAsyncInfo* pAsync);
};
#endif

class CHWShader_D3D : public CHWShader
{
	friend class CCompiledRenderObject;
	friend class CD3D9Renderer;
	friend class CAsyncShaderTask;
	friend class CGParamManager;
	friend struct SShaderAsyncInfo;
	friend class CHWShader;
	friend class CShaderMan;
	friend struct InstContainerByHash;
	friend class CREGeomCache;
	friend struct SRenderStatePassD3D;
	friend struct SDeviceObjectHelpers;
	friend class CDeviceGraphicsCommandList;
	friend class CDeviceGraphicsPSO;
	friend class CDeviceGraphicsPSO_DX11;
	friend class CDeviceGraphicsPSO_DX12;

	SShaderDevCache* m_pDevCache;

	struct SHWSInstance
	{
		friend struct SShaderAsyncInfo;

		SShaderCombIdent           m_Ident;

		SD3DShaderHandle           m_Handle;
		EHWShaderClass             m_eClass;

		int                        m_nParams[2]; // 0: Instance independent; 1: Instance depended
		std::vector<STexSamplerRT> m_pSamplers;
		std::vector<SCGSampler>    m_Samplers;
		std::vector<SCGTexture>    m_Textures;
		std::vector<SCGBind>       m_pBindVars;
		int                        m_nParams_Inst;
		float                      m_fLastAccess;
		int                        m_nUsed;
		int                        m_nUsedFrame;
		int                        m_nFrameSubmit;
		void*                      m_pShaderData;
		int                        m_nMaxVecs[3];
		short                      m_nInstMatrixID;
		short                      m_nInstIndex;
		short                      m_nInstructions;
		short                      m_nTempRegs;
		uint16                     m_VStreamMask_Stream;
		uint16                     m_VStreamMask_Decl;
		short                      m_nCache;
		short                      m_nParent;
		byte                       m_bDeleted         : 1;
		byte                       m_bHasPMParams     : 1;
		//byte                     m_bFallback        : 1;
		byte                       m_bCompressed      : 1;
		byte                       m_bAsyncActivating : 1;
		byte                       m_bHasSendRequest  : 1;
		byte                       m_nVertexFormat;
		byte                       m_nNumInstAttributes;

		int                        m_nDataSize;
		int                        m_DeviceObjectID;
#if defined(FEATURE_PER_SHADER_INPUT_LAYOUT_CACHE)
		enum { NUM_CACHE = 2 };
		ID3D11InputLayout* m_pInputLayout[NUM_CACHE];
		uint32             m_cacheID[NUM_CACHE];
#endif
		SShaderAsyncInfo*  m_pAsync;

		SHWSInstance()
			: m_Ident()
			, m_Handle()
			, m_eClass(eHWSC_Num)
			, m_nParams_Inst(-1)
			, m_fLastAccess(0.0f)
			, m_nUsed(0)
			, m_nUsedFrame(0)
			, m_nFrameSubmit(0)
			, m_pShaderData(nullptr)
			, m_nInstMatrixID(1)
			, m_nInstIndex(-1)
			, m_nInstructions(0)
			, m_nTempRegs(0)
			, m_VStreamMask_Stream(0)
			, m_VStreamMask_Decl(0)
			, m_nCache(-1)
			, m_nParent(-1)
			, m_bDeleted(false)
			, m_bHasPMParams(false)
			//, m_bFallback(false)
			, m_bCompressed(false)
			, m_bAsyncActivating(false)
			, m_bHasSendRequest(false)
			, m_nVertexFormat(1)
			, m_nNumInstAttributes(0)
			, m_nDataSize(0)
			, m_DeviceObjectID(-1)
			, m_pAsync(nullptr)
		{
			m_nParams[0] = -1;
			m_nParams[1] = -1;
			m_nMaxVecs[0] = 0;
			m_nMaxVecs[1] = 0;
			m_nMaxVecs[2] = 0;

#if defined(FEATURE_PER_SHADER_INPUT_LAYOUT_CACHE)
			for (int i = 0; i < NUM_CACHE; ++i)
			{
				m_pInputLayout[i] = nullptr;
				m_cacheID[i] = 0;
			}
#endif
		}

#if defined(FEATURE_PER_SHADER_INPUT_LAYOUT_CACHE)
		~SHWSInstance()
		{
			for (uint i = 0; i < NUM_CACHE; ++i)
			{
				SAFE_RELEASE(m_pInputLayout[i]);
			}
		}
		ID3D11InputLayout* GetCachedInputLayout(uint32 cacheID)
		{
			for (uint i = 0; i < NUM_CACHE; ++i)
			{
				if (cacheID == m_cacheID[i])
				{
					return m_pInputLayout[i];
				}
			}
			return NULL;
		}
		void SetCachedInputLayout(ID3D11InputLayout* pInputLayout, uint32 cacheID)
		{
			// First try empy slot
			for (uint i = 0; i < NUM_CACHE; ++i)
			{
				if (m_pInputLayout[i] == NULL)
				{
					m_pInputLayout[i] = pInputLayout;
					m_cacheID[i] = cacheID;
					return;
				}
			}
			// Cache is full - look for matching InputLayout
			for (uint i = 0; i < NUM_CACHE; ++i)
			{
				if (m_pInputLayout[i] == pInputLayout)
				{
					m_cacheID[i] = cacheID;
					return;
				}
			}
			// Replace first entry (cache is thrashing)
			SAFE_RELEASE(m_pInputLayout[0]);
			m_pInputLayout[0] = pInputLayout;
			m_cacheID[0] = cacheID;
		}
#endif
		void Release(SShaderDevCache* pCache = NULL, bool bReleaseData = true);
		void GetInstancingAttribInfo(uint8 Attributes[32], int32 & nUsedAttr, int& nInstAttrMask);

		int  Size()
		{
			int nSize = sizeof(*this);
			nSize += sizeOfV(m_pSamplers);
			nSize += sizeOfV(m_pBindVars);

			return nSize;
		}

		void GetMemoryUsage(ICrySizer* pSizer) const
		{
			pSizer->AddObject(m_Handle);
			pSizer->AddObject(m_pSamplers);
			pSizer->AddObject(m_pBindVars);
			pSizer->AddObject(m_pShaderData, m_nDataSize);
		}

		bool IsAsyncCompiling()
		{
			if (m_pAsync || m_bAsyncActivating)
				return true;

			return false;
		}
	};

	static_assert(sizeof(SHWSInstance) == 256);

	typedef std::vector<SHWSInstance*> InstContainer;
	typedef InstContainer::iterator    InstContainerIt;

public:

	SHWSInstance* m_pCurInst;
	InstContainer m_Insts;

	static int    m_FrameObj;

	// FX support
	//std::vector<STexSamplerFX> m_Samplers;
	//std::vector<SFXParam> m_Params;
	int m_nCurInstFrame;

	// Bin FX support
	//FXShaderToken  m_TokenTable;
	//TArray<uint32> m_TokenData;

	static inline auto s_CurPSParams = PreyGlobal<Vec4[0]>(0x2B127A0);
	static inline auto s_CurVSParams = PreyGlobal<Vec4[0]>(0x2B147A0);
	static inline auto s_pCB = PreyGlobal<CConstantBuffer** [6][8]>(0x2B11840);
	static inline auto s_pCurReqCB = PreyGlobal<CConstantBuffer* [6][8]>(0x2B119C0);
	static inline auto s_pCurDevCB = PreyGlobal<uint64_t[6][8]>(0x2B11B40);
	static inline auto s_pDataCB = PreyGlobal<Vec4* [6][8]>(0x2B11CC0);
	static inline auto s_nCurMaxVecs = PreyGlobal<int[6][8]>(0x2B11E40);
	static inline auto s_nMax_PF_Vecs = PreyGlobal<int[6]>(0x2B11F00);
	static inline auto s_nMax_SG_Vecs = PreyGlobal<int[6]>(0x2B11F18);
	static inline auto s_nMax_CM_Vecs = PreyGlobal<int[6]>(0x0);
	static inline auto s_pCurInstGS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F30);
	static inline auto s_bFirstGS = PreyGlobal<bool>(0x226D130);
	static inline auto s_pCurInstDS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F38);
	static inline auto s_bFirstDS = PreyGlobal<bool>(0x226D131);
	static inline auto s_pCurInstHS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F40);
	static inline auto s_bFirstHS = PreyGlobal<bool>(0x226D132);
	static inline auto s_pCurInstCS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F48);
	static inline auto s_bFirstCS = PreyGlobal<bool>(0x226D133);
	static inline auto s_pCurInstVS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F50);
	static inline auto s_bFirstVS = PreyGlobal<bool>(0x226D134);
	static inline auto s_pCurInstPS = PreyGlobal<CHWShader_D3D::SHWSInstance*>(0x2B11F58);
	static inline auto s_bFirstPS = PreyGlobal<bool>(0x226D135);
	static inline auto s_nActivationFailMask = PreyGlobal<int>(0x2B11F60);
	static inline auto s_PSParamsToCommit = PreyGlobal<int[0]>(0x2B11F70);
	static inline auto s_NumPSParamsToCommit = PreyGlobal<int>(0x2B11F64);
	static inline auto s_VSParamsToCommit = PreyGlobal<int[0]>(0x2B12370);
	static inline auto s_NumVSParamsToCommit = PreyGlobal<int>(0x2B11F68);
	static inline auto s_bInitShaders = PreyGlobal<bool>(0x226D136);
	static inline auto s_nResetDeviceFrame = PreyGlobal<int>(0x226D138);
	static inline auto s_nInstFrame = PreyGlobal<int>(0x226D13C);
	static inline auto s_nDevicePSDataSize = PreyGlobal<int>(0x2B16898);
	static inline auto s_nDeviceVSDataSize = PreyGlobal<int>(0x2B1689C);
	static inline auto s_PF_Samplers = PreyGlobal<std::vector<STexSamplerRT>>(0x2B167A0);

	virtual int Size();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	static void mfInit() { FmfInit(); }
	SShaderCacheHeaderItem* mfGetCompressedItem(unsigned nFlags, int& nSize) { return FmfGetCompressedItem(this, nFlags, nSize); }
	//SShaderCacheHeaderItem* mfGetCacheItem(unsigned& nFlags, int& nSize) { return FmfGetCacheItem(this, nFlags, nSize); }
	//bool mfActivateCacheItem(CShader* pSH, SShaderCacheHeaderItem* pItem, unsigned nSize, unsigned nFlags) { return FmfActivateCacheItem(this, pSH, pItem, nSize, nFlags); }
	static bool mfCreateCacheItem(CHWShader_D3D::SHWSInstance* pInst, std::vector<SCGBind>& InstBinds, uint8_t* pData, int nLen, CHWShader_D3D* pSH) { return FmfCreateCacheItem(pInst, InstBinds, pData, nLen, pSH); }
	//void mfOutputCompilerError(string& strErr, const char* szSrc) { FmfOutputCompilerError(this, strErr, szSrc); }
	static bool mfCreateShaderEnv(int nThread, CHWShader_D3D::SHWSInstance* pInst, ID3D10Blob* pShader, void* pConstantTable, ID3D10Blob* pErrorMsgs, std::vector<SCGBind>& InstBindVars, CHWShader_D3D* pSH, CShader* pFXShader, int nCombination, const char* src) { return FmfCreateShaderEnv(nThread, pInst, pShader, pConstantTable, pErrorMsgs, InstBindVars, pSH, pFXShader, nCombination, src); }
	//void mfPrintCompileInfo(CHWShader_D3D::SHWSInstance* pInst) { FmfPrintCompileInfo(this, pInst); }
	//int mfAsyncCompileReady(CHWShader_D3D::SHWSInstance* pInst) { return FmfAsyncCompileReady(this, pInst); }
	//bool mfUploadHW(CHWShader_D3D::SHWSInstance* pInst, uint8_t* pBuf, unsigned nSize, CShader* pSH, unsigned nFlags) { return FmfUploadHWOv1(this, pInst, pBuf, nSize, pSH, nFlags); }
	//bool mfUploadHW(ID3D10Blob* pShader, CHWShader_D3D::SHWSInstance* pInst, CShader* pSH, unsigned nFlags) { return FmfUploadHWOv0(this, pShader, pInst, pSH, nFlags); }
	ED3DShError mfIsValid_Int(CHWShader_D3D::SHWSInstance*& pInst, bool bFinalise) { return FmfIsValid_Int(this, pInst, bFinalise); }
	void mfLogShaderCacheMiss(CHWShader_D3D::SHWSInstance* pInst) { FmfLogShaderCacheMiss(this, pInst); }
	void mfLogShaderRequest(CHWShader_D3D::SHWSInstance* pInst) { FmfLogShaderRequest(this, pInst); }
	void mfBind() { FmfBind(this); }
	static void mfCommitParamsMaterial() { FmfCommitParamsMaterial(); }
	static void mfCommitParamsGlobal() { FmfCommitParamsGlobal(); }
	static void mfCommitParams() { FmfCommitParams(); }
	static void mfBindGS(SD3DShader* pShader, void* pHandle) { FmfBindGS(pShader, pHandle); }
	static void mfBindDS(SD3DShader* pShader, void* pHandle) { FmfBindDS(pShader, pHandle); }
	static void mfBindHS(SD3DShader* pShader, void* pHandle) { FmfBindHS(pShader, pHandle); }
	static void mfSetCB(int eClass, int nSlot, CConstantBuffer* pBuffer) { FmfSetCB(eClass, nSlot, pBuffer); }
	static void mfUnbindCB(CConstantBuffer* pCB) { FmfUnbindCB(pCB); }
	static void mfCommitCB(int nCBufSlot, EHWShaderClass eSHData, EHWShaderClass eSH) { FmfCommitCB(nCBufSlot, eSHData, eSH); }
	static void mfSetCBConst(int nReg, int nCBufSlot, EHWShaderClass eSH, const float* fData, const int nVecs, int nMaxVecs) { FmfSetCBConst(nReg, nCBufSlot, eSH, fData, nVecs, nMaxVecs); }
	SCGBind* mfGetParameterBind(CCryNameR const& Name) { return FmfGetParameterBind(this, Name); }
	static float* mfSetParametersPI(SCGParam* pParams, const int nINParams, float* pDst, EHWShaderClass eSH, int nMaxVecs) { return FmfSetParametersPIOv1(pParams, nINParams, pDst, eSH, nMaxVecs); }
	void mfSetParametersPI(CRenderObject* pObj, CShader* pFXShader) { FmfSetParametersPIOv0(this, pObj, pFXShader); }
	static void mfSetParameters(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs, float* pOutBuffer, unsigned* pOutBufferSize) { FmfSetParameters(pParams, nINParams, eSH, nMaxVecs, pOutBuffer, pOutBufferSize); }
	static void mfSetGeneralParametersPI(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs) { FmfSetGeneralParametersPI(pParams, nINParams, eSH, nMaxVecs); }
	static void mfSetGeneralParameters(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs) { FmfSetGeneralParameters(pParams, nINParams, eSH, nMaxVecs); }
	void mfSetParametersPB() { FmfSetParametersPB(this); }
	void mfSetSamplers(std::vector<STexSamplerRT> const& Samplers, EHWShaderClass eHWClass) { FmfSetSamplersOv1(this, Samplers, eHWClass); }
	static bool mfSetSamplers(std::vector<SCGSampler> const& Samplers, EHWShaderClass eSHClass) { return FmfSetSamplersOv0(Samplers, eSHClass); }
	static bool mfSetTextures(std::vector<SCGTexture> const& Textures, EHWShaderClass eSHClass) { return FmfSetTextures(Textures, eSHClass); }
	static bool mfSetSamplers_Old(std::vector<STexSamplerRT> const& Samplers, EHWShaderClass eSHClass) { return FmfSetSamplers_Old(Samplers, eSHClass); }
	CHWShader_D3D::SHWSInstance* mfGetInstance(CShader* pSH, SShaderCombIdent& Ident, unsigned nFlags) { return FmfGetInstanceOv1(this, pSH, Ident, nFlags); }
	CHWShader_D3D::SHWSInstance* mfGetInstance(CShader* pSH, int nHashInstance, SShaderCombIdent& Ident) { return FmfGetInstanceOv0(this, pSH, nHashInstance, Ident); }
	CHWShader_D3D::SHWSInstance* mfGetHashInst(std::vector<CHWShader_D3D::SHWSInstance*>* pInstCont, unsigned identHash, SShaderCombIdent& Ident, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CHWShader_D3D::SHWSInstance*> > >& it) { return FmfGetHashInst(this, pInstCont, identHash, Ident, it); }
	//static void mfPrepareShaderDebugInfo(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, const char* szAsm, std::vector<SCGBind>& InstBindVars, void* pConstantTable) { FmfPrepareShaderDebugInfo(pInst, pSH, szAsm, InstBindVars, pConstantTable); }
	//static void mfGetDstFileName(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, char* dstname, int nSize, uint8_t bType) { FmfGetDstFileName(pInst, pSH, dstname, nSize, bType); }
	//bool mfStoreCacheTokenMap(std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, const char* szName) { return FmfStoreCacheTokenMap(this, Table, pSHData, szName); }
	//void mfGetTokenMap(CResFile* pRes, SDirEntry* pDE, std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData) { FmfGetTokenMap(this, pRes, pDE, Table, pSHData); }
	//void mfSetDefaultRT(uint64_t& nAndMask, uint64_t& nOrMask) { FmfSetDefaultRT(this, nAndMask, nOrMask); }
	//bool mfGetCacheTokenMap(std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, uint64_t nMaskGenFX) { return FmfGetCacheTokenMap(this, Table, pSHData, nMaskGenFX); }
	bool mfActivate(CShader* pSH, unsigned nFlags, std::vector<STokenD>* Table, TArray<unsigned int>* pSHData, bool bCompressedOnly) { return FmfActivate(this, pSH, nFlags, Table, pSHData, bCompressedOnly); }
	uint64_t CheckIfExpr_r(unsigned* pTokens, unsigned& nCur, unsigned nSize) { return FCheckIfExpr_r(this, pTokens, nCur, nSize); }
	void mfConstructFX_Mask_RT(std::vector<STokenD>* Table, TArray<unsigned int>* pSHData) { FmfConstructFX_Mask_RT(this, Table, pSHData); }
	//static void mfAddFXParameter(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, SFXParam* pr, const char* ParamName, SCGBind* pBind, CShader* ef, bool bInstParam, EHWShaderClass eSHClass) { FmfAddFXParameterOv1(pInst, OutParams, FXParams, pr, ParamName, pBind, ef, bInstParam, eSHClass); }
	//static bool mfAddFXParameter(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, const char* param, SCGBind* bn, bool bInstParam, EHWShaderClass eSHClass, CShader* pFXShader) { return FmfAddFXParameterOv0(pInst, OutParams, FXParams, param, bn, bInstParam, eSHClass, pFXShader); }
	static void mfGatherFXParameters(CHWShader_D3D::SHWSInstance* pInst, std::vector<SCGBind>* BindVars, std::vector<SCGBind>* InstBindVars, CHWShader_D3D* pSH, CShader* pFXShader) { FmfGatherFXParameters(pInst, BindVars, InstBindVars, pSH, pFXShader); }
	//static void mfCreateBinds(CHWShader_D3D::SHWSInstance* pInst, void* pConstantTable, uint8_t* pShader, int nSize) { FmfCreateBinds(pInst, pConstantTable, pShader, nSize); }
	bool mfUpdateSamplers(CShader* pSH) { return FmfUpdateSamplers(this, pSH); }
	//void mfUpdateFXVertexFormat(CHWShader_D3D::SHWSInstance* pInst, CShader* pSH) { FmfUpdateFXVertexFormat(this, pInst, pSH); }
	virtual ~CHWShader_D3D();
	bool mfSetVS(int nFlags) { return FmfSetVS(this, nFlags); }
	bool mfSetPS(int nFlags) { return FmfSetPS(this, nFlags); }
	bool mfSetGS(int nFlags) { return FmfSetGS(this, nFlags); }
	bool mfSetHS(int nFlags) { return FmfSetHS(this, nFlags); }
	bool mfSetCS(int nFlags) { return FmfSetCS(this, nFlags); }
	bool mfSetDS(int nFlags) { return FmfSetDS(this, nFlags); }
	bool mfSet(int nFlags) { return FmfSet(this, nFlags); }
	virtual bool mfAddEmptyCombination(CShader* pSH, uint64_t nRT, uint64_t nGL, unsigned nLT);
	virtual bool mfStoreEmptyCombination(SEmptyCombination& Comb);
	virtual bool mfSetV(int nFlags);
	virtual void mfReset(unsigned CRC32);
	virtual const char* mfGetEntryName();
	virtual bool mfFlushCacheFile();
	virtual bool mfPrecache(SShaderCombination& cmb, bool bForce, bool bCompressedOnly, CShader* pSH, CShaderResources* pRes);
	virtual EVertexFormat mfVertexFormat(bool& bUseTangents, bool& bUseLM, bool& bUseHWSkin);
	//static EVertexFormat mfVertexFormat(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, ID3D10Blob* pShader) { return FmfVertexFormatOv0(pInst, pSH, pShader); }
	virtual const char* mfGetActivatedCombinations(bool bForLevel);
	static void mfSetGlobalParams() { FmfSetGlobalParams(); }
	static void mfSetCameraParams() { FmfSetCameraParams(); }
	static bool mfAddGlobalSampler(STexSamplerRT& Sampler) { return FmfAddGlobalSampler(Sampler); }
	static void ShutDown() { FShutDown(); }
	static Vec4 GetVolumetricFogParams() { return FGetVolumetricFogParams(); }
	static Vec4 GetVolumetricFogRampParams() { return FGetVolumetricFogRampParams(); }
	static Vec4 GetVolumetricFogSunDir() { return FGetVolumetricFogSunDir(); }
	static void GetFogColorGradientConstants(Vec4& fogColGradColBase, Vec4& fogColGradColDelta) { FGetFogColorGradientConstants(fogColGradColBase, fogColGradColDelta); }
	static Vec4 GetFogColorGradientRadial() { return FGetFogColorGradientRadial(); }

#if 0
	static void InitialiseContainers();
	void mfConstruct();
	void mfFree(unsigned arg0);
	static bool mfAddCacheItem(SShaderCache* arg0, SShaderCacheHeaderItem* arg1, const uint8_t* arg2, int arg3, bool arg4, CCryNameTSCRC arg5);
	bool mfCloseCacheFile();
	static uint8_t* mfBindsToCache(CHWShader_D3D::SHWSInstance* arg0, std::vector<SCGBind>* arg1, int arg2, uint8_t* arg3);
	uint8_t* mfBindsFromCache(std::vector<SCGBind>*& arg0, int arg1, uint8_t* arg2);
	int mfGetParams(int arg0);
	bool mfSetHWStartProfile(unsigned arg0);
	void mfSaveCGFile(const char* arg0, const char* arg1);
	ED3DShError mfIsValid(CHWShader_D3D::SHWSInstance*& arg0, bool arg1);
	ED3DShError mfFallBack(CHWShader_D3D::SHWSInstance*& arg0, int arg1);
	void mfCommitCombinations(int arg0, int arg1);
	void mfCommitCombination(CHWShader_D3D::SHWSInstance* arg0, int arg1, int arg2);
	void mfBindInstance(CHWShader_D3D::SHWSInstance* arg0, EHWShaderClass arg1);
	static void mfBindCS(SD3DShader* arg0, void* arg1);
	static void mfClearCB();
	static void mfFreeCB(int arg0, EHWShaderClass arg1);
	static void mfSetGSConst(int arg0, int arg1, const float* arg2, int arg3, int arg4);
	static void mfSetGSConst(int arg0, const float* arg1, int arg2, int arg3);
	static void mfSetPSConst(int arg0, int arg1, const float* arg2, int arg3, int arg4);
	static void mfSetPSConst(int arg0, const float* arg1, int arg2, int arg3);
	static void mfSetPSConstA(int arg0, int arg1, const float* arg2, int arg3, int arg4);
	static void mfSetVSConst(int arg0, int arg1, const float* arg2, int arg3, int arg4);
	static void mfSetVSConst(int arg0, const float* arg1, int arg2, int arg3);
	static void mfSetVSConstA(int arg0, int arg1, const float* arg2, int arg3, int arg4);
	static void mfParameterReg(int arg0, int arg1, EHWShaderClass arg2, const float* arg3, int arg4, int arg5);
	static void mfParameterf(SCGBind const* arg0, const float* arg1, int arg2, EHWShaderClass arg3, int arg4);
	static void mfParameterf(SCGBind const* arg0, const float* arg1, EHWShaderClass arg2, int arg3);
	void mfParameterf(CCryNameR const& arg0, const float* arg1);
	static void mfParameterfA(SCGBind const* arg0, const float* arg1, int arg2, EHWShaderClass arg3, int arg4);
	static void mfParameterfA(SCGBind const* arg0, const float* arg1, EHWShaderClass arg2, int arg3);
	static void mfParameteri(SCGBind const* arg0, const float* arg1, EHWShaderClass arg2, int arg3);
	static void mfParameterb(SCGBind const* arg0, const float* arg1, EHWShaderClass arg2, int arg3);
	void GetReflectedShaderParameters(CRenderObject* arg0, SShaderItem const& arg1, CHWShader_D3D::SHWSInstance* arg2, uint8_t* arg3, unsigned& arg4);
	void mfLostDevice(CHWShader_D3D::SHWSInstance* arg0, uint8_t* arg1, int arg2);
	int mfCheckActivation(CShader* arg0, CHWShader_D3D::SHWSInstance*& arg1, unsigned arg2);
	void mfGetSrcFileName(char* arg0, int arg1);
	static void mfGenName(CHWShader_D3D::SHWSInstance* arg0, char* arg1, int arg2, uint8_t arg3);
	void CorrectScriptEnums(CParserBin& arg0, CHWShader_D3D::SHWSInstance* arg1, std::vector<SCGBind>& arg2, std::vector<STokenD>* arg3);
	bool ConvertBinScriptToASCII(CParserBin& arg0, CHWShader_D3D::SHWSInstance* arg1, std::vector<SCGBind>& arg2, std::vector<STokenD>* arg3, TArray<char>& arg4);
	void RemoveUnaffectedParameters_D3D10(CParserBin& arg0, CHWShader_D3D::SHWSInstance* arg1, std::vector<SCGBind>& arg2);
	void SetTokenFlags(unsigned arg0);
	uint64_t CheckToken(unsigned arg0);
	void mfConstructFX(std::vector<STokenD>* arg0, TArray<unsigned int>* arg1);
	static bool mfAddFXSampler(CHWShader_D3D::SHWSInstance* arg0, SShaderFXParams& arg1, SFXSampler* arg2, const char* arg3, SCGBind* arg4, CShader* arg5, EHWShaderClass arg6);
	static bool mfAddFXTexture(CHWShader_D3D::SHWSInstance* arg0, SShaderFXParams& arg1, SFXTexture* arg2, const char* arg3, SCGBind* arg4, CShader* arg5, EHWShaderClass arg6);
	static void mfPostVertexFormat(CHWShader_D3D::SHWSInstance* arg0, CHWShader_D3D* arg1, bool arg2, uint8_t arg3, bool arg4, bool* arg5, bool arg6, bool* arg7, bool* arg8, bool arg9, bool* arg10, bool arg11, bool arg12);
	void ModifyLTMask(unsigned& arg0);
	static void mfSetPV();
	static void* GetVSDataForDecl(D3D11_INPUT_ELEMENT_DESC const* arg0, int arg1, int& arg2);
	static uint16_t GetDeclaredVertexStreamMask(void* arg0);
#endif

	// Shader compiling in Chairloader
	static bool mfAddFXSampler(SHWSInstance* pInst, SShaderFXParams& FXParams, SFXSampler* pr, const char* ParamName, SCGBind* pBind, CShader* ef, EHWShaderClass eSHClass);
	static bool mfAddFXTexture(SHWSInstance* pInst, SShaderFXParams& FXParams, SFXTexture* pr, const char* ParamName, SCGBind* pBind, CShader* ef, EHWShaderClass eSHClass);
	static void mfGatherFXParameters(SHWSInstance* pInst, std::vector<SCGBind>* BindVars, std::vector<SCGBind>* InstBindVars, CHWShader_D3D* pSH, int nFlags, CShader* pFXShader);
	static void mfPostVertexFormat(SHWSInstance* pInst, CHWShader_D3D* pHWSH, bool bCol, byte bNormal, bool bTC0, bool bTC1[2], bool bPSize, bool bTangent[2], bool bBitangent[2], bool bHWSkin, bool bSH[2], bool bMorphTarget, bool bMorph);
	bool        mfGenerateScript(CShader* pSH, SHWSInstance*& pInst, std::vector<SCGBind>& InstBindVars, uint32 nFlags, FXShaderToken* Table, TArray<uint32>* pSHData, TArray<char>& sNewScr);
	void          CorrectScriptEnums(CParserBin& Parser, SHWSInstance* pInst, std::vector<SCGBind>& InstBindVars, FXShaderToken* Table);
	bool          ConvertBinScriptToASCII(CParserBin& Parser, SHWSInstance* pInst, std::vector<SCGBind>& InstBindVars, FXShaderToken* Table, TArray<char>& Scr);
	void          RemoveUnaffectedParameters_D3D10(CParserBin& Parser, SHWSInstance* pInst, std::vector<SCGBind>& InstBindVars);
	void          mfGetSrcFileName(char* srcName, int nSize);
	static void   mfGetDstFileName(SHWSInstance* pInst, CHWShader_D3D* pSH, char* dstname, int nSize, byte bType);
	static void   mfGenName(SHWSInstance* pInst, char* dstname, int nSize, byte bType);
	static bool             mfAddCacheItem(SShaderCache* pCache, SShaderCacheHeaderItem* pItem, const byte* pData, int nLen, bool bFlush, CCryNameTSCRC Name);
	static byte* mfBindsToCache(SHWSInstance* pInst, std::vector<SCGBind>* Binds, int nParams, byte* pP);
	byte* mfBindsFromCache(std::vector<SCGBind>*& Binds, int nParams, byte* pP);
	static bool  mfCreateCacheItem(SHWSInstance* pInst, std::vector<SCGBind>& InstBinds, byte* pData, int nLen, CHWShader_D3D* pSH, bool bShaderThread);
	void        mfSaveCGFile(const char* scr, const char* path);
	bool        mfRequestAsync(CShader* pSH, SHWSInstance* pInst, std::vector<SCGBind>& InstBindVars, const char* prog_text, const char* szProfile, const char* szEntry);
	void        mfSubmitRequestLine(SHWSInstance* pInst, string* pRequestLine = NULL);
	bool        mfCompileHLSL_Int(CShader* pSH, char* prog_text, LPD3D10BLOB* ppShader, void** ppConstantTable, LPD3D10BLOB* ppErrorMsgs, string& strErr, std::vector<SCGBind>& InstBindVars);
	LPD3D10BLOB mfCompileHLSL(CShader* pSH, char* prog_text, void** ppConstantTable, LPD3D10BLOB* ppErrorMsgs, uint32 nFlags, std::vector<SCGBind>& InstBindVars);
	static bool mfCreateShaderEnv(int nThread, SHWSInstance* pInst, LPD3D10BLOB pShader, void* pConstantTable, LPD3D10BLOB pErrorMsgs, std::vector<SCGBind>& InstBindVars, CHWShader_D3D* pSH, bool bShaderThread, CShader* pFXShader, int nCombination, const char* src = NULL);
	bool        mfActivate(CShader* pSH, uint32 nFlags, FXShaderToken* Table = NULL, TArray<uint32>* pSHData = NULL);
	ED3DShError mfIsValid(SHWSInstance*& pInst, bool bFinalise);
	bool ExportSamplers(SCHWShader& SHW, SShaderSerializeContext& SC);
	bool ExportParams(SCHWShader& SHW, SShaderSerializeContext& SC);
	bool        Export(SShaderSerializeContext& SC);
	static void mfAddFXParameter(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, SFXParam* pr, const char* ParamName, SCGBind* pBind, CShader* ef, bool bInstParam, EHWShaderClass eSHClass);
	static bool mfAddFXParameter(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, const char* param, SCGBind* bn, bool bInstParam, EHWShaderClass eSHClass, CShader* pFXShader);
	static void mfCreateBinds(CHWShader_D3D::SHWSInstance* pInst, void* pConstantTable, uint8_t* pShader, int nSize);
	void mfUpdateFXVertexFormat(CHWShader_D3D::SHWSInstance* pInst, CShader* pSH);
	static EVertexFormat mfVertexFormat(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, ID3D10Blob* pShader);
	void mfSetDefaultRT(uint64_t& nAndMask, uint64_t& nOrMask);
	bool mfStoreCacheTokenMap(std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, const char* szName);
	void mfGetTokenMap(CResFile* pRes, SDirEntry* pDE, std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData);
	bool mfGetCacheTokenMap(std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, uint64_t nMaskGenFX);
	SShaderCacheHeaderItem* mfGetCacheItem(unsigned& nFlags, int& nSize);
	bool mfUploadHW(CHWShader_D3D::SHWSInstance* pInst, uint8_t* pBuf, unsigned nSize, CShader* pSH, unsigned nFlags);
	bool mfUploadHW(ID3D10Blob* pShader, CHWShader_D3D::SHWSInstance* pInst, CShader* pSH, unsigned nFlags);
	bool mfActivateCacheItem(CShader* pSH, SShaderCacheHeaderItem* pItem, unsigned nSize, unsigned nFlags);
	void mfOutputCompilerError(string& strErr, const char* szSrc);
	int mfAsyncCompileReady(CHWShader_D3D::SHWSInstance* pInst);
	static void mfPrepareShaderDebugInfo(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, const char* szAsm, std::vector<SCGBind>& InstBindVars, void* pConstantTable);
	void mfPrintCompileInfo(CHWShader_D3D::SHWSInstance* pInst);


	static inline auto FSize = PreyFunction<int(CHWShader_D3D* const _this)>(0xEEC3C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CHWShader_D3D const* const _this, ICrySizer* pSizer)>(0xEEB420);
	static inline auto FmfInit = PreyFunction<void()>(0xEEE1D0);
	static inline auto FmfGetCompressedItem = PreyFunction<SShaderCacheHeaderItem* (CHWShader_D3D* const _this, unsigned nFlags, int& nSize)>(0xEFD160);
	static inline auto FmfGetCacheItem = PreyFunction<SShaderCacheHeaderItem* (CHWShader_D3D* const _this, unsigned& nFlags, int& nSize)>(0xEFCC20);
	static inline auto FmfActivateCacheItem = PreyFunction<bool(CHWShader_D3D* const _this, CShader* pSH, SShaderCacheHeaderItem* pItem, unsigned nSize, unsigned nFlags)>(0xEF95F0);
	static inline auto FmfCreateCacheItem = PreyFunction<bool(CHWShader_D3D::SHWSInstance* pInst, std::vector<SCGBind>& InstBinds, uint8_t* pData, int nLen, CHWShader_D3D* pSH)>(0xEFAAE0);
	static inline auto FmfOutputCompilerError = PreyFunction<void(CHWShader_D3D* const _this, string& strErr, const char* szSrc)>(0xEFEB00);
	static inline auto FmfCreateShaderEnv = PreyFunction<bool(int nThread, CHWShader_D3D::SHWSInstance* pInst, ID3D10Blob* pShader, void* pConstantTable, ID3D10Blob* pErrorMsgs, std::vector<SCGBind>& InstBindVars, CHWShader_D3D* pSH, CShader* pFXShader, int nCombination, const char* src)>(0xEFAFE0);
	static inline auto FmfPrintCompileInfo = PreyFunction<void(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst)>(0xEFF280);
	static inline auto FmfAsyncCompileReady = PreyFunction<int(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst)>(0xEFA0D0);
	static inline auto FmfUploadHWOv1 = PreyFunction<bool(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst, uint8_t* pBuf, unsigned nSize, CShader* pSH, unsigned nFlags)>(0xEFFF60);
	static inline auto FmfUploadHWOv0 = PreyFunction<bool(CHWShader_D3D* const _this, ID3D10Blob* pShader, CHWShader_D3D::SHWSInstance* pInst, CShader* pSH, unsigned nFlags)>(0xEFFE10);
	static inline auto FmfIsValid_Int = PreyFunction<ED3DShError(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance*& pInst, bool bFinalise)>(0xEEE250);
	static inline auto FmfLogShaderCacheMiss = PreyFunction<void(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst)>(0xF1B560);
	static inline auto FmfLogShaderRequest = PreyFunction<void(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst)>(0xA13080);
	static inline auto FmfBind = PreyFunction<void(CHWShader_D3D* const _this)>(0xEED0F0);
	static inline auto FmfCommitParamsMaterial = PreyFunction<void()>(0xEED620);
	static inline auto FmfCommitParamsGlobal = PreyFunction<void()>(0xEED520);
	static inline auto FmfCommitParams = PreyFunction<void()>(0xEED2F0);
	static inline auto FmfBindGS = PreyFunction<void(SD3DShader* pShader, void* pHandle)>(0xEE6EF0);
	static inline auto FmfBindDS = PreyFunction<void(SD3DShader* pShader, void* pHandle)>(0xEE6E50);
	static inline auto FmfBindHS = PreyFunction<void(SD3DShader* pShader, void* pHandle)>(0xEE6F90);
	static inline auto FmfSetCB = PreyFunction<void(int eClass, int nSlot, CConstantBuffer* pBuffer)>(0xEEE7C0);
	static inline auto FmfUnbindCB = PreyFunction<void(CConstantBuffer* pCB)>(0xEC1950);
	static inline auto FmfCommitCB = PreyFunction<void(int nCBufSlot, EHWShaderClass eSHData, EHWShaderClass eSH)>(0xEED260);
	static inline auto FmfSetCBConst = PreyFunction<void(int nReg, int nCBufSlot, EHWShaderClass eSH, const float* fData, const int nVecs, int nMaxVecs)>(0xEE7030);
	static inline auto FmfGetParameterBind = PreyFunction<SCGBind* (CHWShader_D3D* const _this, CCryNameR const& Name)>(0xF1B4E0);
	static inline auto FmfSetParametersPIOv1 = PreyFunction<float* (SCGParam* pParams, const int nINParams, float* pDst, EHWShaderClass eSH, int nMaxVecs)>(0xEF0C60);
	static inline auto FmfSetParametersPIOv0 = PreyFunction<void(CHWShader_D3D* const _this, CRenderObject* pObj, CShader* pFXShader)>(0xEE73D0);
	static inline auto FmfSetParameters = PreyFunction<void(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs, float* pOutBuffer, unsigned* pOutBufferSize)>(0xEEFE50);
	static inline auto FmfSetGeneralParametersPI = PreyFunction<void(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs)>(0xEEF420);
	static inline auto FmfSetGeneralParameters = PreyFunction<void(SCGParam* pParams, const int nINParams, EHWShaderClass eSH, int nMaxVecs)>(0xEEF3A0);
	static inline auto FmfSetParametersPB = PreyFunction<void(CHWShader_D3D* const _this)>(0xEE7360);
	static inline auto FmfSetSamplersOv1 = PreyFunction<void(CHWShader_D3D* const _this, std::vector<STexSamplerRT> const& Samplers, EHWShaderClass eHWClass)>(0xEE7440);
	static inline auto FmfSetSamplersOv0 = PreyFunction<bool(std::vector<SCGSampler> const& Samplers, EHWShaderClass eSHClass)>(0xEF1B40);
	static inline auto FmfSetTextures = PreyFunction<bool(std::vector<SCGTexture> const& Textures, EHWShaderClass eSHClass)>(0xEF2DB0);
	static inline auto FmfSetSamplers_Old = PreyFunction<bool(std::vector<STexSamplerRT> const& Samplers, EHWShaderClass eSHClass)>(0xEF1D70);
	static inline auto FmfGetInstanceOv1 = PreyFunction<CHWShader_D3D::SHWSInstance* (CHWShader_D3D* const _this, CShader* pSH, SShaderCombIdent& Ident, unsigned nFlags)>(0xEEDF70);
	static inline auto FmfGetInstanceOv0 = PreyFunction<CHWShader_D3D::SHWSInstance* (CHWShader_D3D* const _this, CShader* pSH, int nHashInstance, SShaderCombIdent& Ident)>(0xEEE1A0);
	static inline auto FmfGetHashInst = PreyFunction<CHWShader_D3D::SHWSInstance* (CHWShader_D3D* const _this, std::vector<CHWShader_D3D::SHWSInstance*>* pInstCont, unsigned identHash, SShaderCombIdent& Ident, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CHWShader_D3D::SHWSInstance*> > >& it)>(0xEEDE60);
	static inline auto FmfPrepareShaderDebugInfo = PreyFunction<void(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, const char* szAsm, std::vector<SCGBind>& InstBindVars, void* pConstantTable)>(0xEFEE20);
	static inline auto FmfGetDstFileName = PreyFunction<void(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, char* dstname, int nSize, uint8_t bType)>(0xEFD3F0);
	static inline auto FmfStoreCacheTokenMap = PreyFunction<bool(CHWShader_D3D* const _this, std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, const char* szName)>(0xEFF770);
	static inline auto FmfGetTokenMap = PreyFunction<void(CHWShader_D3D* const _this, CResFile* pRes, SDirEntry* pDE, std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData)>(0xEFDEF0);
	static inline auto FmfSetDefaultRT = PreyFunction<void(CHWShader_D3D* const _this, uint64_t& nAndMask, uint64_t& nOrMask)>(0xEFF6B0);
	static inline auto FmfGetCacheTokenMap = PreyFunction<bool(CHWShader_D3D* const _this, std::vector<STokenD>*& Table, TArray<unsigned int>*& pSHData, uint64_t nMaskGenFX)>(0xEFCEC0);
	static inline auto FmfActivate = PreyFunction<bool(CHWShader_D3D* const _this, CShader* pSH, unsigned nFlags, std::vector<STokenD>* Table, TArray<unsigned int>* pSHData, bool bCompressedOnly)>(0xEF8D00);
	static inline auto FCheckIfExpr_r = PreyFunction<uint64_t(CHWShader_D3D* const _this, unsigned* pTokens, unsigned& nCur, unsigned nSize)>(0xEEAF60);
	static inline auto FmfConstructFX_Mask_RT = PreyFunction<void(CHWShader_D3D* const _this, std::vector<STokenD>* Table, TArray<unsigned int>* pSHData)>(0xEED810);
	static inline auto FmfAddFXParameterOv1 = PreyFunction<void(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, SFXParam* pr, const char* ParamName, SCGBind* pBind, CShader* ef, bool bInstParam, EHWShaderClass eSHClass)>(0xEF9AE0);
	static inline auto FmfAddFXParameterOv0 = PreyFunction<bool(CHWShader_D3D::SHWSInstance* pInst, SParamsGroup& OutParams, SShaderFXParams& FXParams, const char* param, SCGBind* bn, bool bInstParam, EHWShaderClass eSHClass, CShader* pFXShader)>(0xEF9D40);
	static inline auto FmfGatherFXParameters = PreyFunction<void(CHWShader_D3D::SHWSInstance* pInst, std::vector<SCGBind>* BindVars, std::vector<SCGBind>* InstBindVars, CHWShader_D3D* pSH, CShader* pFXShader)>(0xEFB570);
	static inline auto FmfCreateBinds = PreyFunction<void(CHWShader_D3D::SHWSInstance* pInst, void* pConstantTable, uint8_t* pShader, int nSize)>(0xEFA700);
	static inline auto FmfUpdateSamplers = PreyFunction<bool(CHWShader_D3D* const _this, CShader* pSH)>(0xEF3A60);
	static inline auto FmfUpdateFXVertexFormat = PreyFunction<void(CHWShader_D3D* const _this, CHWShader_D3D::SHWSInstance* pInst, CShader* pSH)>(0xEFFD30);
	static inline auto FmfSetVS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEF3700);
	static inline auto FmfSetPS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEEF990);
	static inline auto FmfSetGS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEEF060);
	static inline auto FmfSetHS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEEF650);
	static inline auto FmfSetCS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEEE940);
	static inline auto FmfSetDS = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEEECE0);
	static inline auto FmfSet = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEF36C0);
	static inline auto FmfAddEmptyCombination = PreyFunction<bool(CHWShader_D3D* const _this, CShader* pSH, uint64_t nRT, uint64_t nGL, unsigned nLT)>(0xEF9A20);
	static inline auto FmfStoreEmptyCombination = PreyFunction<bool(CHWShader_D3D* const _this, SEmptyCombination& Comb)>(0xEFF9F0);
	static inline auto FmfSetV = PreyFunction<bool(CHWShader_D3D* const _this, int nFlags)>(0xEF36C0);
	static inline auto FmfReset = PreyFunction<void(CHWShader_D3D* const _this, unsigned CRC32)>(0xEEE610);
	static inline auto FmfGetEntryName = PreyFunction<const char* (CHWShader_D3D* const _this)>(0x864AF0);
	static inline auto FmfFlushCacheFile = PreyFunction<bool(CHWShader_D3D* const _this)>(0xEFB260);
	static inline auto FmfPrecache = PreyFunction<bool(CHWShader_D3D* const _this, SShaderCombination& cmb, bool bForce, bool bCompressedOnly, CShader* pSH, CShaderResources* pRes)>(0xEEE2D0);
	static inline auto FmfVertexFormatOv1 = PreyFunction<EVertexFormat(CHWShader_D3D* const _this, bool& bUseTangents, bool& bUseLM, bool& bUseHWSkin)>(0xF004F0);
	static inline auto FmfVertexFormatOv0 = PreyFunction<EVertexFormat(CHWShader_D3D::SHWSInstance* pInst, CHWShader_D3D* pSH, ID3D10Blob* pShader)>(0xF00130);
	static inline auto FmfGetActivatedCombinations = PreyFunction<const char* (CHWShader_D3D* const _this, bool bForLevel)>(0xEFC8C0);
	static inline auto FmfSetGlobalParams = PreyFunction<void()>(0xEEF570);
	static inline auto FmfSetCameraParams = PreyFunction<void()>(0xEEECC0);
	static inline auto FmfAddGlobalSampler = PreyFunction<bool(STexSamplerRT& Sampler)>(0xEED070);
	static inline auto FShutDown = PreyFunction<void()>(0xEEBF80);
	static inline auto FGetVolumetricFogParams = PreyFunction<Vec4()>(0xEEBB70);
	static inline auto FGetVolumetricFogRampParams = PreyFunction<Vec4()>(0xEEBB90);
	static inline auto FGetVolumetricFogSunDir = PreyFunction<Vec4()>(0xEEBBB0);
	static inline auto FGetFogColorGradientConstants = PreyFunction<void(Vec4& fogColGradColBase, Vec4& fogColGradColDelta)>(0xEEB320);
	static inline auto FGetFogColorGradientRadial = PreyFunction<Vec4()>(0xEEB330);

	friend struct SShaderTechniqueStat;
};

struct SShaderTechniqueStat
{
	SShaderTechnique*            pTech;
	CShader*                     pShader;
	CHWShader_D3D*               pVS;
	CHWShader_D3D*               pPS;
	CHWShader_D3D::SHWSInstance* pVSInst;
	CHWShader_D3D::SHWSInstance* pPSInst;
};

extern std::vector<SShaderTechniqueStat> g_SelectedTechs;

#endif  // __D3DHWSHADER_H__
