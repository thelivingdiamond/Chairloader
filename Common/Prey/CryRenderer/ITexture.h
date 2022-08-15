// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

/*=============================================================================
   IShader.h : Shaders common interface.

   Revision history:
* Created by Anton Kaplanyan

   =============================================================================*/

#ifndef _ITEXTURE_H_
#define _ITEXTURE_H_

#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryMath/Cry_Color.h>
#include "Tarray.h"

class CTexture;

enum ETEX_Type : uint8
{
	eTT_1D = 0,
	eTT_2D,
	eTT_3D,
	eTT_Cube,
	eTT_CubeArray,
	eTT_Dyn2D,
	eTT_User,
	eTT_NearestCube,

	eTT_2DArray,
	eTT_2DMS,

	eTT_AutoCube,
	eTT_Auto2D,

	eTT_MaxTexType,   //!< Not used.
};

//! Texture formats.
enum ETEX_Format : uint8
{
	eTF_Unknown  = 0,
	eTF_R8G8B8A8S,
	eTF_R8G8B8A8 = 2, //!< May be saved into file.

	eTF_R1,
	eTF_A8,
	eTF_R8,
	eTF_R8S,
	eTF_R16,
	eTF_R16F,
	eTF_R32F,
	eTF_R8G8,
	eTF_R8G8S,
	eTF_R16G16,
	eTF_R16G16S,
	eTF_R16G16F,
	eTF_R11G11B10F,
	eTF_R10G10B10A2,
	eTF_R16G16B16A16,
	eTF_R16G16B16A16S,
	eTF_R16G16B16A16F,
	eTF_R32G32B32A32F,

	eTF_CTX1,
	eTF_BC1 = 22, //!< May be saved into file.
	eTF_BC2 = 23, //!< May be saved into file.
	eTF_BC3 = 24, //!< May be saved into file.
	eTF_BC4U,     //!< 3Dc+.
	eTF_BC4S,
	eTF_BC5U,     //!< 3Dc.
	eTF_BC5S,
	eTF_BC6UH,
	eTF_BC6SH,
	eTF_BC7,
	eTF_R9G9B9E5,

	//! Hardware depth buffers.
	eTF_D16,
	eTF_D24S8,
	eTF_D32F,
	eTF_D32FS8,

	//! Only available as hardware format under DX11.1 with DXGI 1.2.
	eTF_B5G6R5,
	eTF_B5G5R5,
	eTF_B4G4R4A4,

	//! Only available as hardware format under OpenGL.
	eTF_EAC_R11,
	eTF_EAC_RG11,
	eTF_ETC2,
	eTF_ETC2A,

	//! Only available as hardware format under DX9.
	eTF_A8L8,
	eTF_L8,
	eTF_L8V8U8,
	eTF_B8G8R8,
	eTF_L8V8U8X8,
	eTF_B8G8R8X8,
	eTF_B8G8R8A8,

	eTF_YUV,
	eTF_YUVA,

	eTF_R16G16_UINT = 0x35,
	eTF_R32_UINT = 0x36,

	eTF_MaxFormat       //!< Unused, but must be always the last in the list.
};

enum ETEX_TileMode : uint8
{
	eTM_None = 0,
	eTM_LinearPadded,
	eTM_Optimal,
};

//! T = applies to texture objects read from disk.
//! R = applies to texture objects allocated for render-targets.
enum ETextureFlags
{
	FT_NOMIPS = 0x1,						// TR: don't allocate or use any mip-maps (even if they exist)
	FT_TEX_NORMAL_MAP = 0x2,				// T: indicator that a texture contains normal vectors (used for tracking statistics, debug messages and the default texture)
	FT_TEX_WAS_NOT_PRE_TILED = 0x4,
	FT_USAGE_DEPTHSTENCIL = 0x8,			// R: use as depth-stencil render-target
	FT_USAGE_ALLOWREADSRGB = 0x10,			// TR: allows the renderer to cast the texture-format to a sRGB type if available
	FT_FILESINGLE = 0x20,					// T: suppress loading of additional files like _DDNDIF (faster, RC can tag the file for that)
	FT_TEX_FONT = 0x40,						// T: indicator that a texture contains font glyphs (used solely for tracking statistics!)
	FT_HAS_ATTACHED_ALPHA = 0x80,			// T: indicator that the texture has another texture attached (see FT_ALPHA)
	FT_USAGE_UNORDERED_ACCESS = 0x100,		// R: allow write-only UAVs for the texture object
	FT______________________ = 0x200,		// UNUSED
	FT_USAGE_MSAA = 0x400,					// R: use as MSAA render-target
	FT_FORCE_MIPS = 0x800,					// TR: always allocate mips (even if normally this would be optimized away)
	FT_USAGE_RENDERTARGET = 0x1000,			// R: use as render-target
	FT_USAGE_DYNAMIC = 0x2000,
	FT_STAGE_READBACK = 0x4000,				// R: allow read-back of the texture contents by the CPU through a persistent staging texture (otherwise the staging is dynamic)
	FT_STAGE_UPLOAD = 0x8000,				// R: allow up-load of the texture contents by the CPU through a persistent staging texture (otherwise the staging is dynamic)
	FT_DONT_RELEASE = 0x10000,				// TR: texture will not be freed automatically when ref counter goes to 0. Use ReleaseForce() to free the texture.
	FT_ASYNC_PREPARE = 0x20000,				// T: run the streaming preparation of this texture asynchronously
	FT_DONT_STREAM = 0x40000,				// T: prevent progressive streaming-in/out of the texture, it's fully loaded or not at all
	FT_______________________ = 0x80000,
	FT_FAILED = 0x100000,					// TR: indicator that the allocation of the texture failed the last time it has been tried, for render-targets this is fatal
	FT_FROMIMAGE = 0x200000,				// T: indicator that the textures originates from disk
	FT_STATE_CLAMP = 0x400000,				// T: set the sampling mode to clamp in the corresponding sampler-state
	FT_USAGE_ATLAS = 0x800000,				// R: indicator that the texture's contents form an atlas or flip-book (used solely for tracking statistics!)
	FT_ALPHA = 0x1000000,					// T: indicator that this is a texture attached to another one (see FT_HAS_ATTACHED_ALPHA)
	FT_REPLICATE_TO_ALL_SIDES = 0x2000000,	// T: Replicate single texture to all cube-map sides on allocation and on file-load
	FT____________________ = 0x4000000,
	FT_SPLITTED = 0x8000000,				// T: indicator that the texture is available splitted on disk
	FT_STREAMED_PREPARE = 0x10000000,		// REMOVE
	FT_NO_DEPTH_COMPRESSION = 0x20000000,
	FT_NO_COLOR_COMPRESSION = 0x40000000,
	FT_USAGE_UAV_RWTEXTURE = 0x80000000,	// R: enable RW usage for the UAV, otherwise UAVs are write-only (see FT_USAGE_UNORDERED_ACCESS)
};

struct SDepthTexture;

struct STextureStreamingStats
{
	STextureStreamingStats(bool bComputeTexturesPerFrame) : bComputeReuquiredTexturesPerFrame(bComputeTexturesPerFrame)
	{
		nMaxPoolSize = 0;
		nCurrentPoolSize = 0;
		nStreamedTexturesSize = 0;
		nStaticTexturesSize = 0;
		nDynamicTexturesSize = 0;
		nThroughput = 0;
		nNumTexturesPerFrame = 0;
		nRequiredStreamedTexturesSize = 0;
		nRequiredStreamedTexturesCount = 0;
		bPoolOverflow = false;
		bPoolOverflowTotally = false;
		fPoolFragmentation = 0.0f;
	}
	size_t     nMaxPoolSize;
	size_t     nCurrentPoolSize;
	size_t     nStreamedTexturesSize;
	size_t     nStaticTexturesSize;
	size_t     nDynamicTexturesSize;
	uint32     nNumTexturesPerFrame;
	size_t     nThroughput;
	size_t     nRequiredStreamedTexturesSize;
	uint32     nRequiredStreamedTexturesCount;
	float      fPoolFragmentation;
	uint32     bPoolOverflow        : 1;
	uint32     bPoolOverflowTotally : 1;
	const bool bComputeReuquiredTexturesPerFrame;
};

//! Texture object interface.
class ITexture
{
protected:
	virtual ~ITexture() {}
public:
	// <interfuscator:shuffle>
	virtual int             AddRef() = 0;
	virtual int             Release() = 0;
	virtual int             ReleaseForce() = 0;

	virtual const char*     GetName() const = 0;
	virtual const int       GetWidth() const = 0;
	virtual const int       GetHeight() const = 0;
	virtual const int       GetDepth() const = 0;
	virtual const int       GetTextureID() const = 0;
	virtual const uint32    GetFlags() const = 0;
	virtual const int       GetNumMips() const = 0;
	virtual const int       GetRequiredMip() const = 0;
	virtual const int       GetDeviceDataSize() const = 0;
	virtual const int       GetDataSize() const = 0;
	virtual const ETEX_Type GetTextureType() const = 0;
	virtual const bool      IsTextureLoaded() const = 0;
	virtual void            PrecacheAsynchronously(float fMipFactor, int nFlags, int nUpdateId, int nCounter = 1) = 0;
	virtual uint8*          GetData32(int nSide = 0, int nLevel = 0, uint8* pDst = NULL, ETEX_Format eDstFormat = eTF_R8G8B8A8) = 0;
	virtual bool            SetFilter(int nFilter) = 0; //!< FILTER_ flags.
	virtual void            SetClamp(bool bEnable) = 0; //!< Texture addressing set.
	virtual float           GetAvgBrightness() const = 0;

	virtual int             StreamCalculateMipsSigned(float fMipFactor) const = 0;
	virtual int             GetStreamableMipNumber() const = 0;
	virtual int             GetStreamableMemoryUsage(int nStartMip) const = 0;
	virtual int             GetMinLoadedMip() const = 0;

	//! Used for debugging/profiling.
	virtual const char*       GetFormatName() const = 0;
	virtual const char*       GetTypeName() const = 0;
	virtual const bool        IsStreamedVirtual() const = 0;
	virtual const bool        IsShared() const = 0;
	virtual const bool        IsStreamable() const = 0;
	virtual bool              IsStreamedIn(const int nMinPrecacheRoundIds[2]) const = 0;
	virtual const int         GetAccessFrameId() const = 0;

	virtual const ETEX_Format GetTextureDstFormat() const = 0;
	virtual const ETEX_Format GetTextureSrcFormat() const = 0;

	virtual bool              IsPostponed() const = 0;
	virtual const bool        IsParticularMipStreamed(float fMipFactor) const = 0;

	virtual void SetRenderTargetTile(uint8 nTile = 0) = 0;
};

//=========================================================================================

struct IDynTextureSource
{
	enum EDynTextureSource
	{
		DTS_UNKNOWN,

		DTS_I_FLASHPLAYER,
		DTS_I_BINK,
	};

	enum EDynTextureRTType
	{
		DTS_RT_SHARED,
		DTS_RT_UNIQUE
	};

	// <interfuscator:shuffle>
	virtual void              AddRef() = 0;
	virtual void              Release() = 0;
	virtual void*             GetSourceTemp(EDynTextureSource type) const = 0;
	virtual void*             GetSourcePerm(EDynTextureSource type) = 0;
	virtual const char*       GetSourceFilePath() const = 0;
	virtual EDynTextureSource GetSourceType() const = 0;
	virtual EDynTextureRTType GetRTType() const = 0;
	virtual ITexture*         GetTexture() const = 0;

	virtual void              EnablePerFrameRendering(bool enable) = 0;
	virtual void              Activate(bool activate) = 0;
	// </interfuscator:shuffle>
#if defined(ENABLE_DYNTEXSRC_PROFILING)
	virtual string GetProfileInfo() const = 0;
#endif

protected:
	virtual ~IDynTextureSource() {}
};

//=========================================================================================

class IDynTexture
{
public:
	enum
	{
		fNeedRegenerate = 1ul << 0,
	};
	// <interfuscator:shuffle>
	virtual ~IDynTexture(){}
	virtual void      Release() = 0;
	virtual void      GetSubImageRect(uint32& nX, uint32& nY, uint32& nWidth, uint32& nHeight) = 0;
	virtual void      GetImageRect(uint32& nX, uint32& nY, uint32& nWidth, uint32& nHeight) = 0;
	virtual int       GetTextureID() = 0;
	virtual void      Lock() = 0;
	virtual void      UnLock() = 0;
	virtual int       GetWidth() = 0;
	virtual int       GetHeight() = 0;
	virtual bool      IsValid() = 0;
	virtual uint8     GetFlags() const = 0;
	virtual void      SetFlags(uint8 flags) {}
	virtual bool      Update(int nNewWidth, int nNewHeight) = 0;
	virtual void      Apply(int nTUnit, int nTS = -1) = 0;
	virtual bool      ClearRT() = 0;
	virtual bool      SetRT(int nRT, bool bPush, struct SDepthTexture* pDepthSurf, bool bScreenVP = false) = 0;
	virtual bool      SetRectStates() = 0;
	virtual bool      RestoreRT(int nRT, bool bPop) = 0;
	virtual ITexture* GetTexture() = 0;
	virtual void      SetUpdateMask() = 0;
	virtual void      ResetUpdateMask() = 0;
	virtual bool      IsSecondFrame() = 0;
	virtual bool      GetImageData32(uint8* pData, int nDataSize) { return 0; }
	// </interfuscator:shuffle>
};

//! Animating Texture sequence definition.
struct STexAnim
{
	int               m_nRefCount;
	TArray<CTexture*> m_TexPics;
	int               m_Rand;
	int               m_NumAnimTexs;
	bool              m_bLoop;
	float             m_Time;

	int               Size()
	{
		int nSize = sizeof(STexAnim);
		nSize += m_TexPics.GetMemoryUsage();
		return nSize;
	}
	void Release()
	{
		long refCnt = CryInterlockedDecrement(&m_nRefCount);
		if (refCnt > 0)
			return;
		delete this;
	}
	void AddRef()
	{
		CryInterlockedIncrement(&m_nRefCount);
	}

	STexAnim()
	{
		m_nRefCount = 1;
		m_Rand = 0;
		m_NumAnimTexs = 0;
		m_bLoop = false;
		m_Time = 0.0f;
	}

	~STexAnim()
	{
		for (uint32 i = 0; i < m_TexPics.Num(); i++)
		{
			ITexture* pTex = (ITexture*) m_TexPics[i];
			SAFE_RELEASE(pTex);
		}
		m_TexPics.Free();
	}

	STexAnim& operator=(const STexAnim& sl)
	{
		// make sure not same object
		if (this == &sl)
		{
			return *this;
		}

		for (uint32 i = 0; i < m_TexPics.Num(); i++)
		{
			ITexture* pTex = (ITexture*)m_TexPics[i];
			SAFE_RELEASE(pTex);
		}
		m_TexPics.Free();

		for (uint32 i = 0; i < sl.m_TexPics.Num(); i++)
		{
			ITexture* pTex = (ITexture*)sl.m_TexPics[i];
			if (pTex)
			{
				pTex->AddRef();
			}

			m_TexPics.AddElem(sl.m_TexPics[i]);
		}

		m_Rand = sl.m_Rand;
		m_NumAnimTexs = sl.m_NumAnimTexs;
		m_bLoop = sl.m_bLoop;
		m_Time = sl.m_Time;

		return *this;
	}
};

#endif// _ITEXTURE_H_
