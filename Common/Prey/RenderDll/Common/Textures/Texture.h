#pragma once
#include <Prey/CryRenderer/CryDX.h>
#include <Prey/CryRenderer/IShader.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryRenderer/Texture.h>
#include <Prey/RenderDll/Common/Shaders/ShaderResources.h>

class CTexture;
class CTextureStreamPoolMgr;
class CImageFile;
struct STexStreamingInfo;
struct RenderTargetData;
struct ResourceViewData;
struct ITextureStreamer;
struct SStreamFormatCode;
struct SStreamFormatCodeKey;
struct SEnvTexture;
struct STexPool;
struct STexPoolItem;
struct STexData;
struct STexStreamInState;

//dx9 usages
enum ETexture_Usage
{
	eTXUSAGE_AUTOGENMIPMAP,
	eTXUSAGE_DEPTHSTENCIL,
	eTXUSAGE_RENDERTARGET
};

struct SPixFormat
{
	// Pixel format info.
	D3DFormat   DeviceFormat; // Pixel format from Direct3D.
	const char* Desc;         // Stat: Human readable name for stats.
	int8        BitsPerPixel; // Total bits per pixel.
	uint8       bCanDS : 1;
	uint8       bCanRT : 1;
	uint8       bCanMultiSampleRT : 1;
	uint8       bCanMipsAutoGen : 1;
	uint8       bCanReadSRGB : 1;
	uint8       bCanGather : 1;
	uint8       bCanGatherCmp : 1;
	uint8       bCanBlend : 1;
	int16       MaxWidth;
	int16       MaxHeight;
	SPixFormat* Next;

	SPixFormat()
	{
		Init();
	}
	void Init()
	{
		BitsPerPixel = 0;
		DeviceFormat = (D3DFormat)0;
		Desc = NULL;
		Next = NULL;
		bCanDS = false;
		bCanRT = false;
		bCanMultiSampleRT = false;
		bCanMipsAutoGen = false;
		bCanReadSRGB = false;
		bCanGather = false;
		bCanGatherCmp = false;
		bCanBlend = false;
	}
	bool IsValid() const
	{
		if (BitsPerPixel)
			return true;
		return false;
	}
	bool CheckSupport(D3DFormat Format, const char* szDescr, ETexture_Usage eTxUsage = eTXUSAGE_AUTOGENMIPMAP);
};

struct SPixFormatSupport
{
	SPixFormat m_FormatR1;
	SPixFormat m_FormatA8;
	SPixFormat m_FormatR8;
	SPixFormat m_FormatR8S;
	SPixFormat m_FormatR8G8;
	SPixFormat m_FormatR8G8S;
	SPixFormat m_FormatR8G8B8A8;
	SPixFormat m_FormatR8G8B8A8S;
	SPixFormat m_FormatR10G10B10A2;
	SPixFormat m_FormatR16;
	SPixFormat m_FormatR16F;
	SPixFormat m_FormatR32F;
	SPixFormat m_FormatR16G16;
	SPixFormat m_FormatR16G16S;
	SPixFormat m_FormatR16G16UINT;
	SPixFormat m_FormatR32UINT;
	SPixFormat m_FormatR16G16F;
	SPixFormat m_FormatR11G11B10F;
	SPixFormat m_FormatR16G16B16A16F;
	SPixFormat m_FormatR16G16B16A16;
	SPixFormat m_FormatR16G16B16A16S;
	SPixFormat m_FormatR32G32B32A32F;
	SPixFormat m_FormatBC1;
	SPixFormat m_FormatBC2;
	SPixFormat m_FormatBC3;
	SPixFormat m_FormatBC4U;
	SPixFormat m_FormatBC4S;
	SPixFormat m_FormatBC5U;
	SPixFormat m_FormatBC5S;
	SPixFormat m_FormatBC6UH;
	SPixFormat m_FormatBC6SH;
	SPixFormat m_FormatBC7;
	SPixFormat m_FormatR9G9B9E5;
	SPixFormat m_FormatEAC_R11;
	SPixFormat m_FormatEAC_RG11;
	SPixFormat m_FormatETC2;
	SPixFormat m_FormatETC2A;
	SPixFormat m_FormatD16;
	SPixFormat m_FormatD24S8;
	SPixFormat m_FormatD32F;
	SPixFormat m_FormatD32FS8;
	SPixFormat m_FormatB5G6R5;
	SPixFormat m_FormatB5G5R5;
	SPixFormat m_FormatB4G4R4A4;
	SPixFormat m_FormatB8G8R8X8;
	SPixFormat m_FormatB8G8R8A8;

	SPixFormat* m_FirstPixelFormat;

	void        CheckFormatSupport();
};

static_assert(sizeof(SPixFormatSupport) == 1480);

struct SDepthTexture
{
	int              nWidth;
	int              nHeight;
	bool             bBusy;
	int              nFrameAccess;
	D3DTexture* pTarget;
	D3DDepthSurface* pSurface;
	CTexture* pTexture;

	SDepthTexture()
		: nWidth(0)
		, nHeight(0)
		, bBusy(false)
		, nFrameAccess(-1)
		, pTarget(nullptr)
		, pSurface(nullptr)
		, pTexture(nullptr)
	{}

	~SDepthTexture() {};

	void Release(bool bReleaseTexture);
};

class CDeviceTexture;

struct STexStageInfo
{
	int                m_nCurState;
	CDeviceTexture* m_DevTexture;

	STexState          m_State;
	float              m_fMipBias;

	D3DShaderResource* m_pCurResView;
	EHWShaderClass     m_eHWSC;

	STexStageInfo()
	{
		Flush();
	}
	void Flush()
	{
		m_nCurState = -1;
		m_State.m_nMipFilter = -1;
		m_State.m_nMinFilter = -1;
		m_State.m_nMagFilter = -1;
		m_State.m_nAddressU = -1;
		m_State.m_nAddressV = -1;
		m_State.m_nAddressW = -1;
		m_State.m_nAnisotropy = 0;

		m_pCurResView = NULL;
		m_eHWSC = eHWSC_Pixel;

		m_DevTexture = NULL;
		m_fMipBias = 0.f;
	}
};

struct STexCacheFileHeader
{
	int8 m_nSides;
	int8 m_nMipsPersistent;
	STexCacheFileHeader()
	{
		m_nSides = 0;
		m_nMipsPersistent = 0;
	}
};

struct STexStreamRoundInfo
{
	STexStreamRoundInfo()
	{
		nRoundUpdateId = -1;
		bHighPriority = false;
		bLastHighPriority = false;
	}

	int32  nRoundUpdateId : 30;
	uint32 bHighPriority : 1;
	uint32 bLastHighPriority : 1;
};

class CTexture : public ITexture, public CBaseResource
{
public:
	ID3D11RenderTargetView* m_pDeviceRTV;
	ID3D11RenderTargetView* m_pDeviceRTVMS;
	CDeviceTexture* m_pDevTexture;
	SPixFormat const* m_pPixelFormat;
	STexStreamingInfo* m_pFileTexMips;
	uint16_t m_nWidth;
	uint16_t m_nHeight;
	uint16_t m_nDepth;
	ETEX_Format m_eTFDst;
	ETEX_TileMode m_eSrcTileMode;
	uint8_t m_nStreamFormatCode;
	EDeviceMemoryHeap m_memoryHeap;
	unsigned m_nFlags;
	bool m_bStreamed : 1;
	bool m_bStreamPrepared : 1;
	bool m_bStreamRequested : 1;
	bool m_bWasUnloaded : 1;
	bool m_bPostponed : 1;
	bool m_bForceStreamHighRes : 1;
	bool m_bIsLocked : 1;
	bool m_bNoTexture : 1;
	bool m_bResolved : 1;
	bool m_bUseMultisampledRTV : 1;
	bool m_bCustomFormat : 1;
	bool m_bVertexTexture : 1;
	bool m_bUseDecalBorderCol : 1;
	bool m_bIsSRGB : 1;
	bool m_bNoDevTexture : 1;
	bool m_bAsyncDevTexCreation : 1;
	bool m_bInDistanceSortedList : 1;
	bool m_bUsedRecently : 1;
	bool m_bStatTracked : 1;
	bool m_bStreamHighPriority : 1;
	int8_t m_nCustomID;
	uint8_t m_nArraySize;
	int8_t m_nMips;
	ETEX_Type m_eTT;
	ETEX_Format m_eTFSrc;
	int8_t m_nStreamingPriority;
	int8_t m_nMinMipVidUploaded;
	int8_t m_nMinMipVidActive;
	uint16_t m_nStreamSlot;
	int16_t m_fpMinMipCur;
	STexCacheFileHeader m_CacheFileHeader;
	uint16_t m_nDefState;
	int m_nActualSize;
	int m_nPersistentSize;
	int m_nAccessFrameID;
	STexStreamRoundInfo m_streamRounds[2];
	float m_fCurrentMipBias;
	float m_fAvgBrightness;
	ColorF m_cClearColor;
	RenderTargetData* m_pRenderTargetData;
	ResourceViewData* m_pResourceViewData;
	string m_SrcName;
	ID3D11ShaderResourceView* m_pDeviceShaderResource;
	ID3D11ShaderResourceView* m_pDeviceShaderResourceSRGB;

	using InvalidateCallbackType = std::function<void __cdecl(void*, unsigned int)>;

	std::unordered_map<void*, std::function<void __cdecl(void*, unsigned int)>> m_invalidateCallbacks;
	int m_nUpdateFrameID;
	static inline auto s_sClassName = PreyGlobal<CCryNameTSCRC>(0x2B175A0);

	enum EDeviceDirtyFlags
	{
		eDeviceResourceDirty = 1,
		eDeviceResourceViewDirty = 2,
	};

	static inline auto s_nStreamingMode = PreyGlobal<int>(0x2B3206C);
	static inline auto s_nStreamingUpdateMode = PreyGlobal<int>(0x2B32200);
	static inline auto s_nStreamingThroughput = PreyGlobal<int>(0x2B32204);
	static inline auto s_nStreamingTotalTime = PreyGlobal<float>(0x2B32208);
	static inline auto s_bStreamDontKeepSystem = PreyGlobal<bool>(0x2B341A0);
	static inline auto s_bPrecachePhase = PreyGlobal<bool>(0x2B316A2);
	static inline auto s_bPrestreamPhase = PreyGlobal<bool>(0x2B316A3);
	static inline auto s_nTexturesDataBytesLoaded = PreyGlobal<int>(0x2B341A4);
	static inline auto s_nTexturesDataBytesUploaded = PreyGlobal<volatile int>(0x2B341A8);
	static inline auto s_nStatsAllocFails = PreyGlobal<int>(0x2B341AC);
	static inline auto s_bOutOfMemoryTotally = PreyGlobal<bool>(0x2B341A1);
	static inline auto s_nStatsStreamPoolInUseMem = PreyGlobal<volatile uint64_t>(0x2B341B0);
	static inline auto s_nStatsStreamPoolBoundMem = PreyGlobal<volatile uint64_t>(0x2B341B8);
	static inline auto s_nStatsStreamPoolBoundPersMem = PreyGlobal<volatile uint64_t>(0x2B341C0);
	static inline auto s_nStatsCurManagedNonStreamedTexMem = PreyGlobal<volatile int>(0x2B341C8);
	static inline auto s_nStatsCurDynamicTexMem = PreyGlobal<volatile int>(0x2B341CC);
	static inline auto s_nStatsStreamPoolWanted = PreyGlobal<volatile uint64_t>(0x2B341D0);
	static inline auto s_bStatsComputeStreamPoolWanted = PreyGlobal<bool>(0x2B341A2);

	struct WantedStat // Id=8000357 Size=16
	{
		_smart_ptr<ITexture> pTex;
		unsigned nWanted;
	};

	static inline auto s_pStatsTexWantedLists = PreyGlobal<std::vector<CTexture::WantedStat>*>(0x2B341D8);
	static inline auto s_vTexReloadRequests = PreyGlobal<std::set<string, std::less<string>>>(0x2B33430);
	static inline auto s_xTexReloadLock = PreyGlobal<CryCriticalSection>(0x2B33440);
	static inline auto s_pPoolMgr = PreyGlobal<CTextureStreamPoolMgr*>(0x2B32210);
	static inline auto s_pTextureStreamer = PreyGlobal<ITextureStreamer*>(0x2B341E0);
	static inline auto s_streamFormatLock = PreyGlobal<CryCriticalSection>(0x2B91E28);
	static inline auto s_formatCodes = PreyGlobal<SStreamFormatCode[256]>(0x2B341F0);
	static inline auto s_nFormatCodes = PreyGlobal<unsigned>(0x2270060);

	using TStreamFormatCodeKeyMap = std::map<SStreamFormatCodeKey, unsigned int, std::less<SStreamFormatCodeKey>>;

	static inline auto s_formatCodeMap = PreyGlobal<TStreamFormatCodeKeyMap>(0x2BA5E58);

	enum
	{
		MaxStreamTasks = 512,
		MaxStreamPrepTasks = 8192,
		StreamOutMask = 32768,
		StreamPrepMask = 16384,
		StreamIdxMask = 16383,
		InvalidStreamSlot = 65535,
	};

	static inline auto s_RenderLoadingThreadStreamLock = PreyGlobal<CryCriticalSection>(0x2B379F8);
	//static inline auto s_StreamInTasks = PreyGlobal<CTextureArrayAlloc<STexStreamInState, 512>>(0x2B37A20);
	//static inline auto s_StreamPrepTasks = PreyGlobal<CTextureArrayAlloc<STexStreamPrepState*, 8192>>(0x2B91E50);
	static inline auto s_nBytesSubmittedToStreaming = PreyGlobal<volatile int>(0x2B341E8);
	static inline auto s_nMipsSubmittedToStreaming = PreyGlobal<volatile int>(0x2B379F0);
	static inline auto s_nBytesRequiredNotSubmitted = PreyGlobal<int>(0x2B379F4);
	static inline auto s_TexStates = PreyGlobal<std::vector<STexState>>(0x2B32218);
	static inline auto m_bLoadedSystem = PreyGlobal<bool>(0x2B316A0);
	static inline auto s_sDefState = PreyGlobal<STexState>(0x2B34160);
	static inline auto s_TexStages = PreyGlobal<STexStageInfo[64]>(0x2B32230);
	static inline auto s_TexStateIDs = PreyGlobal<int[6][64]>(0x2B316B0);
	static inline auto s_TexState_MipSRGBMask = PreyGlobal<unsigned[64]>(0x0);
	static inline auto s_eTFZ = PreyGlobal<ETEX_Format>(0x2270040);
	static inline auto s_ptexNoTexture = PreyGlobal<CTexture*>(0x2B316A8);
	static inline auto s_ptexNoTextureCM = PreyGlobal<CTexture*>(0x2B31CB0);
	static inline auto s_ptexWhite = PreyGlobal<CTexture*>(0x2B31CB8);
	static inline auto s_ptexGray = PreyGlobal<CTexture*>(0x2B31CC0);
	static inline auto s_ptexBlack = PreyGlobal<CTexture*>(0x2B31CC8);
	static inline auto s_ptexBlackAlpha = PreyGlobal<CTexture*>(0x2B31CD0);
	static inline auto s_ptexBlackCM = PreyGlobal<CTexture*>(0x2B31CD8);
	static inline auto s_ptexDefaultProbeCM = PreyGlobal<CTexture*>(0x2B31CE0);
	static inline auto s_ptexFlatBump = PreyGlobal<CTexture*>(0x2B31CE8);
	static inline auto s_ptexPaletteTexelsPerMeter = PreyGlobal<CTexture*>(0x2B31CF0);
	static inline auto s_ptexShadowJitterMap = PreyGlobal<CTexture*>(0x2B31CF8);
	static inline auto s_ptexEnvironmentBRDF = PreyGlobal<CTexture*>(0x2B31D00);
	static inline auto s_ptexScreenNoiseMap = PreyGlobal<CTexture*>(0x2B31D08);
	static inline auto s_ptexDissolveNoiseMap = PreyGlobal<CTexture*>(0x2B31D10);
	static inline auto s_ptexGrainFilterMap = PreyGlobal<CTexture*>(0x2B31D18);
	static inline auto s_ptexFilmGrainMap = PreyGlobal<CTexture*>(0x2B31D20);
	static inline auto s_ptexVignettingMap = PreyGlobal<CTexture*>(0x2B31D28);
	static inline auto s_ptexAOJitter = PreyGlobal<CTexture*>(0x2B31D30);
	static inline auto s_ptexAOVOJitter = PreyGlobal<CTexture*>(0x2B31D38);
	static inline auto s_ptexShadowMask = PreyGlobal<CTexture*>(0x2B31D40);
	static inline auto s_ptexCachedShadowMap = PreyGlobal<CTexture* [16]>(0x2B31D50);
	static inline auto s_ptexNearestShadowMap = PreyGlobal<CTexture*>(0x2B31D48);
	static inline auto s_ptexNormalsFitting = PreyGlobal<CTexture*>(0x2B31DD0);
	static inline auto s_ptexSceneNormalsMap = PreyGlobal<CTexture*>(0x2B31DD8);
	static inline auto s_ptexSceneNormalsMapMS = PreyGlobal<CTexture*>(0x2B31DE0);
	static inline auto s_ptexSceneNormalsBent = PreyGlobal<CTexture*>(0x2B31DE8);
	static inline auto s_ptexAOColorBleed = PreyGlobal<CTexture*>(0x2B31DF0);
	static inline auto s_ptexSceneDiffuse = PreyGlobal<CTexture*>(0x2B31DF8);
	static inline auto s_ptexSceneSpecular = PreyGlobal<CTexture*>(0x2B31E00);
	static inline auto s_ptexBackBuffer = PreyGlobal<CTexture*>(0x2B31E08);
	static inline auto s_ptexPrevBackBuffer = PreyGlobal<CTexture* [2]>(0x2B31E10);
	static inline auto s_ptexBackBufferScaled = PreyGlobal<CTexture* [3]>(0x2B31E20);
	static inline auto s_ptexBackBufferScaledTemp = PreyGlobal<CTexture* [2]>(0x2B31E38);
	static inline auto s_ptexPrevFrameScaled = PreyGlobal<CTexture*>(0x2B31E50);
	static inline auto s_ptexDepthBufferQuarter = PreyGlobal<CTexture*>(0x2B31E58);
	static inline auto s_ptexDepthBufferHalfQuarter = PreyGlobal<CTexture*>(0x2B31E60);
	static inline auto s_ptexWaterVolumeDDN = PreyGlobal<CTexture*>(0x2B31E68);
	static inline auto s_ptexWaterVolumeTemp = PreyGlobal<CTexture* [2]>(0x2B31E70);
	static inline auto s_ptexWaterRipplesDDN = PreyGlobal<CTexture*>(0x2B31E80);
	static inline auto s_ptexWaterVolumeRefl = PreyGlobal<CTexture* [2]>(0x2B31E88);
	static inline auto s_ptexWaterCaustics = PreyGlobal<CTexture* [2]>(0x2B31E98);
	static inline auto s_ptexRT_ShadowPool = PreyGlobal<CTexture*>(0x2B31EA8);
	static inline auto s_ptexFarPlane = PreyGlobal<CTexture*>(0x2B31EB0);
	static inline auto s_ptexSceneTarget = PreyGlobal<CTexture*>(0x2B31EB8);
	static inline auto s_ptexCurrSceneTarget = PreyGlobal<CTexture*>(0x2B31EC0);
	static inline auto s_ptexSceneTargetR11G11B10F = PreyGlobal<CTexture* [2]>(0x2B31EC8);
	static inline auto s_ptexSceneTargetScaledR11G11B10F = PreyGlobal<CTexture* [4]>(0x2B31ED8);
	static inline auto s_ptexZTarget = PreyGlobal<CTexture*>(0x2B31EF8);
	static inline auto s_ptexZOcclusion = PreyGlobal<CTexture* [2]>(0x2B31F00);
	static inline auto s_ptexZTargetReadBack = PreyGlobal<CTexture* [4]>(0x2B31F10);
	static inline auto s_ptexZTargetDownSample = PreyGlobal<CTexture* [4]>(0x2B31F30);
	static inline auto s_ptexZTargetScaled = PreyGlobal<CTexture*>(0x2B31F50);
	static inline auto s_ptexZTargetScaled2 = PreyGlobal<CTexture*>(0x2B31F58);
	static inline auto s_ptexZTargetScaled3 = PreyGlobal<CTexture*>(0x2B31F60);
	static inline auto s_ptexHDRTarget = PreyGlobal<CTexture*>(0x2B31F68);
	static inline auto s_ptexVelocityObjects = PreyGlobal<CTexture*>(0x2B31F70);
	static inline auto s_ptexVelocity = PreyGlobal<CTexture*>(0x2B31F78);
	static inline auto s_ptexVelocityTiles = PreyGlobal<CTexture* [3]>(0x2B31F80);
	static inline auto s_ptexHDRTargetPrev = PreyGlobal<CTexture*>(0x2B31F98);
	static inline auto s_ptexHDRTargetScaled = PreyGlobal<CTexture* [4]>(0x2B31FA0);
	static inline auto s_ptexHDRTargetScaledTmp = PreyGlobal<CTexture* [4]>(0x2B31FC0);
	static inline auto s_ptexHDRTargetScaledTempRT = PreyGlobal<CTexture* [4]>(0x2B31FE0);
	static inline auto s_ptexHDRDofLayers = PreyGlobal<CTexture* [2]>(0x2B32000);
	static inline auto s_ptexBaseLuminance = PreyGlobal<CTexture*>(0x2B32010);
	static inline auto s_ptexSceneCoC = PreyGlobal<CTexture* [6]>(0x2B32018);
	static inline auto s_ptexSceneCoCTemp = PreyGlobal<CTexture*>(0x2B32048);
	static inline auto s_ptexHDRTempBloom = PreyGlobal<CTexture* [2]>(0x2B32050);
	static inline auto s_ptexHDRFinalBloom = PreyGlobal<CTexture*>(0x2B32060);
	static inline auto s_ptexHDRAdaptedLuminanceCur = PreyGlobal<CTexture* [8]>(0x2B32070);
	static inline auto s_nCurLumTextureIndex = PreyGlobal<int>(0x2B32068);
	static inline auto s_ptexCurLumTexture = PreyGlobal<CTexture*>(0x2B320B0);
	static inline auto s_ptexHDRToneMaps = PreyGlobal<CTexture* [4]>(0x2B320B8);
	static inline auto s_ptexHDRMeasuredLuminance = PreyGlobal<CTexture* [4]>(0x2B320D8);
	static inline auto s_ptexSkyDomeMie = PreyGlobal<CTexture*>(0x2B320F8);
	static inline auto s_ptexSkyDomeRayleigh = PreyGlobal<CTexture*>(0x2B32100);
	static inline auto s_ptexText_FromSF = PreyGlobal<CTexture* [6]>(0x2B32108);
	static inline auto s_ptexSceneTargetScaled = PreyGlobal<CTexture*>(0x2B32138);
	static inline auto s_ptexSceneTargetScaledBlurred = PreyGlobal<CTexture*>(0x2B32140);
	static inline auto s_ptexVolObj_Density = PreyGlobal<CTexture*>(0x2B32148);
	static inline auto s_ptexVolObj_Shadow = PreyGlobal<CTexture*>(0x2B32150);
	static inline auto s_ptexColorChart = PreyGlobal<CTexture*>(0x2B32158);
	static inline auto s_ptexFlaresOcclusionRing = PreyGlobal<CTexture* [8]>(0x2B32160);
	static inline auto s_ptexFlaresGather = PreyGlobal<CTexture*>(0x2B321A0);
	static inline auto s_ptexDepthStencilRemapped = PreyGlobal<CTexture*>(0x0);
	static inline auto s_EnvTexts = PreyGlobal<SEnvTexture[16]>(0x2B33480);
	static inline auto s_CustomRT_2D = PreyGlobal<TArray<SEnvTexture>>(0x2B34100);
	static inline auto s_ShaderTemplates = PreyGlobal<TArray<CTexture>>(0x2270050);
	static inline auto s_ShaderTemplatesInitialized = PreyGlobal<bool>(0x2B316A1);
	static inline auto s_pTexNULL = PreyGlobal<CTexture*>(0x2B321A8);
	static inline auto s_pBackBuffer = PreyGlobal<CTexture*>(0x2B321B0);
	static inline auto s_FrontBufferTextures = PreyGlobal<CTexture* [2]>(0x2B321B8);
	static inline auto s_ptexVolumetricFog = PreyGlobal<CTexture*>(0x2B321C8);
	static inline auto s_ptexVolumetricClipVolumeStencil = PreyGlobal<CTexture*>(0x2B321D0);
	static inline auto s_ptexVolFogShadowBuf = PreyGlobal<CTexture* [2]>(0x2B321D8);
	static inline auto s_ptexSceneMask = PreyGlobal<CTexture*>(0x2B321E8);
	static inline auto s_ptexSceneMaskDevice = PreyGlobal<CTexture*>(0x2B321F0);
	static inline auto s_pStreamDeferredCtx = PreyGlobal<ID3D11DeviceContext*>(0x2B321F8);

	//static CCryNameTSCRC GenName(const char* name, unsigned nFlags) { return FGenName(name, nFlags); }
	ETEX_Format FormatFixup(ETEX_Format src) { return FFormatFixupOv1(this, src); }
	virtual ~CTexture();
	CTexture(const unsigned nFlags, ColorF const& clearColor, CDeviceTexture* devTexToOwn);
	virtual int AddRef();
	virtual int Release();
	virtual int ReleaseForce();
	virtual const char* GetName() const;
	virtual const int GetWidth() const;
	virtual const int GetHeight() const;
	virtual const int GetDepth() const;
	virtual const int GetTextureID() const;
	virtual const unsigned GetFlags() const;
	virtual const int GetNumMips() const;
	virtual const int GetRequiredMip() const;
	virtual const ETEX_Type GetTextureType() const;
	virtual void SetClamp(bool bEnable);
	virtual const bool IsTextureLoaded() const;
	virtual void PrecacheAsynchronously(float fMipFactor, int nFlags, int nUpdateId, int nCounter);
	virtual uint8_t* GetData32(int nSide, int nLevel, uint8_t* pDst, ETEX_Format eDstFormat);
	virtual const int GetDeviceDataSize() const;
	virtual const int GetDataSize() const;
	virtual bool SetFilter(int nFilter);
	virtual bool Clear();
	virtual bool Clear(ColorF const& cClear);
	virtual float GetAvgBrightness() const;
	virtual void SetAvgBrightness(float fBrightness);
	virtual ColorF const& GetClearColor() const;
	virtual void SetClearColor(ColorF const& cClearColor);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual const char* GetFormatName() const;
	virtual const char* GetTypeName() const;
	virtual const bool IsShared() const;
	virtual const ETEX_Format GetTextureDstFormat() const;
	virtual const ETEX_Format GetTextureSrcFormat() const;
	virtual const bool IsParticularMipStreamed(float fMipFactor) const;
	const unsigned StreamGetNumSlices() const { return FStreamGetNumSlices(this); }
	void RT_ReleaseDevice() { FRT_ReleaseDevice(this); }
	virtual bool IsPostponed() const;
	virtual const bool IsStreamedVirtual() const;
	virtual bool IsStreamedIn(const int* nMinPrecacheRoundIds) const;
	virtual const int GetAccessFrameId() const;
	virtual const int GetCustomID() const;
	virtual void SetCustomID(int nID);
	virtual const bool IsStreamable() const;
	virtual void SetRenderTargetTile(uint8_t nTile);
	void SetDevTexture(CDeviceTexture* pDeviceTex) { FSetDevTexture(this, pDeviceTex); }
	void OwnDevTexture(unsigned nFlags, CDeviceTexture* pDeviceTex) { FOwnDevTexture(this, nFlags, pDeviceTex); }
	bool GenerateMipMaps(bool bSetOrthoProj, bool bUseHW, bool bNormalMap) { return FGenerateMipMaps(this, bSetOrthoProj, bUseHW, bNormalMap); }
	ID3D11ShaderResourceView* GetShaderResourceView(uint64_t resourceViewID, bool bLegacySrgbLookup) { return FGetShaderResourceViewOv1(this, resourceViewID, bLegacySrgbLookup); }
	void SetShaderResourceView(ID3D11ShaderResourceView* pDeviceShaderResource, bool bMultisampled) { FSetShaderResourceView(this, pDeviceShaderResource, bMultisampled); }
	ID3D11UnorderedAccessView* GetDeviceUAV() { return FGetDeviceUAVOv1(this); }
	void* GetResourceView(SResourceView const& rvDesc) { return FGetResourceViewOv1(this, rvDesc); }
	void* CreateDeviceResourceView(SResourceView const& rv) { return FCreateDeviceResourceView(this, rv); }
	ID3D11DepthStencilView* GetDeviceDepthStencilView(int nFirstSlice, int nSliceCount, bool bMultisampled, bool readOnly) { return FGetDeviceDepthStencilView(this, nFirstSlice, nSliceCount, bMultisampled, readOnly); }
	ID3D11ShaderResourceView* GetDeviceDepthReadOnlySRV(int nFirstSlice, int nSliceCount, bool bMultisampled) { return FGetDeviceDepthReadOnlySRV(this, nFirstSlice, nSliceCount, bMultisampled); }
	ID3D11ShaderResourceView* GetDeviceStencilReadOnlySRV(int nFirstSlice, int nSliceCount, bool bMultisampled) { return FGetDeviceStencilReadOnlySRV(this, nFirstSlice, nSliceCount, bMultisampled); }
	ID3D11RenderTargetView* GetSurface(int nCMSide, int nLevel) { return FGetSurfaceOv1(this, nCMSide, nLevel); }
	bool Invalidate(int nNewWidth, int nNewHeight, ETEX_Format eTF) { return FInvalidate(this, nNewWidth, nNewHeight, eTF); }
	void PostCreate() { FPostCreate(this); }
	virtual void InvalidateDeviceResource(unsigned dirtyFlags);
	void AddInvalidateCallback(void* listener, std::function<void __cdecl(void*, unsigned int)> callback) { FAddInvalidateCallback(this, listener, callback); }
	void RemoveInvalidateCallbacks(void* listener) { FRemoveInvalidateCallbacks(this, listener); }
	static void Precache() { FPrecache(); }
	static void RT_Precache(bool _bStepping) { FRT_Precache(_bStepping); }
	static void StreamValidateTexSize() { FStreamValidateTexSize(); }
	static uint8_t StreamComputeFormatCode(unsigned nWidth, unsigned nHeight, unsigned nMips, ETEX_Format fmt) { return FStreamComputeFormatCode(nWidth, nHeight, nMips, fmt); }
	int StreamComputeDevDataSize(int nFromMip) const { return FStreamComputeDevDataSize(this, nFromMip); }
	void StreamExpandMip(const void* vpRawData, int nMip, int nBaseMipOffset, int nSideDelta) { FStreamExpandMip(this, vpRawData, nMip, nBaseMipOffset, nSideDelta); }
	static void RT_FlushAllStreamingTasks(const bool bAbort) { FRT_FlushAllStreamingTasks(bAbort); }
	static void AbortStreamingTasks(CTexture* pTex) { FAbortStreamingTasks(pTex); }
	//static bool StartStreaming(CTexture* pTex, STexPoolItem* pNewPoolItem, const int nStartMip, const int nEndMip, const int nActivateMip, EStreamTaskPriority estp) { return FStartStreaming(pTex, pNewPoolItem, nStartMip, nEndMip, nActivateMip, estp); }
	void StreamCopyMipsTexToMem(int nStartMip, int nEndMip, bool bToDevice, STexPoolItem* pNewPoolItem) { FStreamCopyMipsTexToMem(this, nStartMip, nEndMip, bToDevice, pNewPoolItem); }
	static void StreamCopyMipsTexToTex(STexPoolItem* pSrcItem, int nMipSrc, STexPoolItem* pDestItem, int nMipDest, int nNumMips) { FStreamCopyMipsTexToTex(pSrcItem, nMipSrc, pDestItem, nMipDest, nNumMips); }
	static void CopySliceChain(CDeviceTexture* const pDevTexture, int ownerMips, int nDstSlice, int nDstMip, CDeviceTexture* pSrcDevTex, int nSrcSlice, int nSrcMip, int nSrcMips, int nNumMips) { FCopySliceChain(pDevTexture, ownerMips, nDstSlice, nDstMip, pSrcDevTex, nSrcSlice, nSrcMip, nSrcMips, nNumMips); }
	ID3D11CommandList* StreamCreateDeferred(int nStartMip, int nEndMip, STexPoolItem* pNewPoolItem, STexPoolItem* pSrcPoolItem) { return FStreamCreateDeferred(this, nStartMip, nEndMip, pNewPoolItem, pSrcPoolItem); }
	void StreamApplyDeferred(ID3D11CommandList* pCmdList) { FStreamApplyDeferred(this, pCmdList); }
	void StreamReleaseMipsData(int nStartMip, int nEndMip) { FStreamReleaseMipsData(this, nStartMip, nEndMip); }
	int16_t StreamCalculateMipsSignedFP(float fMipFactor) const { return FStreamCalculateMipsSignedFP(this, fMipFactor); }
	float StreamCalculateMipFactor(int16_t nMipsSigned) const { return FStreamCalculateMipFactor(this, nMipsSigned); }
	virtual int StreamCalculateMipsSigned(float fMipFactor) const;
	virtual int GetStreamableMipNumber() const;
	virtual int GetStreamableMemoryUsage(int nStartMip) const;
	virtual int GetMinLoadedMip() const;
	void SetMinLoadedMip(int nMinMip) { FSetMinLoadedMip(this, nMinMip); }
	int StreamTrim(int nToMip) { return FStreamTrim(this, nToMip); }
	void StreamLoadFromCache(const int Flags) { FStreamLoadFromCache(this, Flags); }
	bool StreamPrepare(bool bFromLoad) { return FStreamPrepareOv1(this, bFromLoad); }
	bool StreamPrepare(CImageFile* pIM) { return FStreamPrepareOv0(this, pIM); }
	bool StreamPrepare_Platform() { return FStreamPrepare_Platform(this); }
	bool StreamPrepare_Finalise(bool bFromLoad) { return FStreamPrepare_Finalise(this, bFromLoad); }
	STexPool* StreamGetPool(int nStartMip, int nMips) { return FStreamGetPool(this, nStartMip, nMips); }
	STexPoolItem* StreamGetPoolItem(int nStartMip, int nMips, bool bShouldBeCreated, bool bCreateFromMipData, bool bCanCreate, bool bForStreamOut) { return FStreamGetPoolItem(this, nStartMip, nMips, bShouldBeCreated, bCreateFromMipData, bCanCreate, bForStreamOut); }
	void StreamRemoveFromPool() { FStreamRemoveFromPool(this); }
	void StreamAssignPoolItem(STexPoolItem* pItem, int nMinMip) { FStreamAssignPoolItem(this, pItem, nMinMip); }
	static void StreamState_Update() { FStreamState_Update(); }
	static void StreamState_UpdatePrep() { FStreamState_UpdatePrep(); }
	static void StreamState_ReleaseIn(STexStreamInState* pState) { FStreamState_ReleaseIn(pState); }
	static void StreamState_ReleaseInfo(CTexture* pOwnerTex, STexStreamingInfo* pInfo) { FStreamState_ReleaseInfo(pOwnerTex, pInfo); }
	void Relink() { FRelink(this); }
	void Unlink() { FUnlink(this); }
	//static CCryNameTSCRC const& mfGetClassName() { return FmfGetClassName(); }
	static CTexture* GetByID(int nID) { return FGetByID(nID); }
	static CTexture* GetByName(const char* szName, unsigned flags) { return FGetByName(szName, flags); }
	static CTexture* ForName(const char* name, unsigned nFlags, ETEX_Format eTFDst) { return FForName(name, nFlags, eTFDst); }
	static CTexture* CreateTextureArray(const char* name, ETEX_Type eType, unsigned nWidth, unsigned nHeight, unsigned nArraySize, int nMips, unsigned nFlags, ETEX_Format eTF, int nCustomID, EDeviceMemoryHeap _heapId) { return FCreateTextureArray(name, eType, nWidth, nHeight, nArraySize, nMips, nFlags, eTF, nCustomID, _heapId); }
	static CTexture* CreateRenderTarget(const char* name, unsigned nWidth, unsigned nHeight, ColorF const& cClear, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID = -1) { return FCreateRenderTargetOv1(name, nWidth, nHeight, cClear, eTT, nFlags, eTF, nCustomID); }
	bool CreateRenderTarget(ETEX_Format eTF, ColorF const& cClear) { return FCreateRenderTargetOv0(this, eTF, cClear); }
	static CTexture* CreateTextureObject(const char* name, unsigned nWidth, unsigned nHeight, int nDepth, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID, EDeviceMemoryHeap _heapId) { return FCreateTextureObject(name, nWidth, nHeight, nDepth, eTT, nFlags, eTF, nCustomID, _heapId); }
	static CTexture* NewTexture(const char* name, unsigned nFlags, ETEX_Format eTFDst, EDeviceMemoryHeap _heapId, bool& bFound) { return FNewTexture(name, nFlags, eTFDst, _heapId, bFound); }
	static void InitStreaming() { FInitStreaming(); }
	static void InitStreamingDev() { FInitStreamingDev(); }
	static void Init() { FInit(); }
	static void PostInit() { FPostInit(); }
	static void RT_FlushStreaming(bool bAbort) { FRT_FlushStreaming(bAbort); }
	static void ShutDown() { FShutDown(); }
	static void CreateSystemTargets() { FCreateSystemTargets(); }
	static void ReleaseMiscTargets() { FReleaseMiscTargets(); }
	static void ReleaseSystemTextures(bool bFinalRelease) { FReleaseSystemTextures(bFinalRelease); }
	static void LoadDefaultSystemTextures() { FLoadDefaultSystemTextures(); }
	static void LoadScaleformSystemTextures() { FLoadScaleformSystemTextures(); }
	static bool ReloadFile(const char* szFileName) { return FReloadFile(szFileName); }
	static bool ReloadFile_Request(const char* szFileName) { return FReloadFile_Request(szFileName); }
	static void ReloadTextures() { FReloadTextures(); }
	static CTexture* Create2DTexture(const char* szName, int nWidth, int nHeight, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst, EDeviceMemoryHeap heapId, bool bAsyncDevTexCreation) { return FCreate2DTextureOv1(szName, nWidth, nHeight, nMips, nFlags, pData, eTFSrc, eTFDst, heapId, bAsyncDevTexCreation); }
	bool Create2DTexture(int nWidth, int nHeight, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst) { return FCreate2DTextureOv0(this, nWidth, nHeight, nMips, nFlags, pData, eTFSrc, eTFDst); }
	static CTexture* Create3DTexture(const char* szName, int nWidth, int nHeight, int nDepth, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst, EDeviceMemoryHeap heapId) { return FCreate3DTextureOv1(szName, nWidth, nHeight, nDepth, nMips, nFlags, pData, eTFSrc, eTFDst, heapId); }
	bool Create3DTexture(int nWidth, int nHeight, int nDepth, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst) { return FCreate3DTextureOv0(this, nWidth, nHeight, nDepth, nMips, nFlags, pData, eTFSrc, eTFDst); }
	static void Update() { FUpdate(); }
	static void RT_LoadingUpdate() { FRT_LoadingUpdate(); }
	static void RLT_LoadingUpdate() { FRLT_LoadingUpdate(); }
	bool Load(ETEX_Format eTFDst) { return FLoadOv1(this, eTFDst); }
	bool Load(CImageFile* pImage) { return FLoadOv0(this, pImage); }
	bool LoadFromImage(const char* name, ETEX_Format eTFDst) { return FLoadFromImage(this, name, eTFDst); }
	bool Reload() { return FReload(this); }
	bool ToggleStreaming(const bool bEnable) { return FToggleStreaming(this, bEnable); }
	bool CreateTexture(STexData& td) { return FCreateTexture(this, td); }
	void Unbind() { FUnbind(this); }
	bool Resolve(int nTarget, bool bUseViewportSize) { return FResolve(this, nTarget, bUseViewportSize); }
	bool CreateDeviceTexture(uint8_t** pData) { return FCreateDeviceTexture(this, pData); }
	bool RT_CreateDeviceTexture(uint8_t** pData) { return FRT_CreateDeviceTexture(this, pData); }
	void DisableStreaming() { FDisableStreaming(this); }
	void ReleaseDeviceTexture(bool bKeepLastMips, bool bFromUnload) { FReleaseDeviceTexture(this, bKeepLastMips, bFromUnload); }
	void Apply(int nTUnit, int nState, int nTexMatSlot, int nSUnit, uint64_t nResViewKey, EHWShaderClass eHWSC) { FApply(this, nTUnit, nState, nTexMatSlot, nSUnit, nResViewKey, eHWSC); }
	void ApplyTexture(int nTUnit, EHWShaderClass eHWSC, uint64_t nResViewKey) { FApplyTexture(this, nTUnit, eHWSC, nResViewKey); }
	ETEX_Format ClosestFormatSupported(ETEX_Format eTFDst) { return FClosestFormatSupportedOv1(this, eTFDst); }
	static ETEX_Format ClosestFormatSupported(ETEX_Format eTFDst, SPixFormat const*& pPF) { return FClosestFormatSupportedOv0(eTFDst, pPF); }
	void SetTexStates() { FSetTexStates(this); }
	void UpdateTexStates() { FUpdateTexStates(this); }
	bool SetFilterMode(int nFilter) { return FSetFilterMode(this, nFilter); }
	bool SetClampingMode(int nAddressU, int nAddressV, int nAddressW) { return FSetClampingMode(this, nAddressU, nAddressV, nAddressW); }
	void UpdateTextureRegion(uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc) { FUpdateTextureRegion(this, data, nX, nY, nZ, USize, VSize, ZSize, eTFSrc); }
	void RT_UpdateTextureRegion(uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc) { FRT_UpdateTextureRegion(this, data, nX, nY, nZ, USize, VSize, ZSize, eTFSrc); }
	bool SetNoTexture(CTexture* pDefaultTexture, bool _bOutOfMemory) { return FSetNoTexture(this, pDefaultTexture, _bOutOfMemory); }
	static void SetSamplerState(int nTS, int nSUnit, EHWShaderClass eHWSC) { FSetSamplerState(nTS, nSUnit, eHWSC); }
	static void GenerateZMaps() { FGenerateZMaps(); }
	static void DestroyZMaps() { FDestroyZMaps(); }
	static void GenerateHDRMaps() { FGenerateHDRMaps(); }
	static void GenerateSceneMap(ETEX_Format eTF) { FGenerateSceneMap(eTF); }
	static void GenerateCachedShadowMaps() { FGenerateCachedShadowMaps(); }
	static void GenerateLookingGlassMaps() { FGenerateLookingGlassMaps(); }
	static uint8_t* Convert(uint8_t* pSrc, int nWidth, int nHeight, int nMips, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nOutMips, int& nOutSize, bool bLinear) { return FConvert(pSrc, nWidth, nHeight, nMips, eTFSrc, eTFDst, nOutMips, nOutSize, bLinear); }
	static int CalcNumMips(int nWidth, int nHeight) { return FCalcNumMips(nWidth, nHeight); }
	static void ExpandMipFromFile(uint8_t* dest, const int destSize, const uint8_t* src, const int srcSize, ETEX_Format fmt) { FExpandMipFromFile(dest, destSize, src, srcSize, fmt); }
	static unsigned TextureDataSize(unsigned nWidth, unsigned nHeight, unsigned nDepth, unsigned nMips, unsigned nSlices, ETEX_Format eTF, ETEX_TileMode eTM) { return FTextureDataSize(nWidth, nHeight, nDepth, nMips, nSlices, eTF, eTM); }
	static const char* NameForTextureType(ETEX_Type eTT) { return FNameForTextureType(eTT); }
	static bool IsDeviceFormatTypeless(DXGI_FORMAT nFormat) { return FIsDeviceFormatTypeless(nFormat); }
	static bool IsDeviceFormatSRGBReadable(DXGI_FORMAT nFormat) { return FIsDeviceFormatSRGBReadable(nFormat); }
	static DXGI_FORMAT DeviceFormatFromTexFormat(ETEX_Format eTF) { return FDeviceFormatFromTexFormat(eTF); }
	static ETEX_Format TexFormatFromDeviceFormat(DXGI_FORMAT nFormat); // { return FTexFormatFromDeviceFormat(nFormat); }
	static DXGI_FORMAT ConvertToDepthStencilFmt(DXGI_FORMAT nFormat) { return FConvertToDepthStencilFmt(nFormat); }
	static DXGI_FORMAT ConvertToSRGBFmt(DXGI_FORMAT fmt) { return FConvertToSRGBFmt(fmt); }
	static DXGI_FORMAT ConvertToTypelessFmt(DXGI_FORMAT fmt) { return FConvertToTypelessFmt(fmt); }
	static int GetTexState(STexState const& TS) { return FGetTexState(TS); }

	CDeviceTexture* GetDevTexture() const { return m_pDevTexture; }

#if 0
	bool FormatFixup(STexData& arg0);
	bool ImagePreprocessing(STexData& arg0);
	const int GetWidthNonVirtual() const;
	const int GetHeightNonVirtual() const;
	const int GetDepthNonVirtual() const;
	const int GetNumSides() const;
	const int8_t GetNumPersistentMips() const;
	const bool IsForceStreamHighRes() const;
	const bool IsStreamHighPriority() const;
	void SetFlags(unsigned arg0);
	const int GetNumMipsNonVirtual() const;
	const int GetRequiredMipNonVirtual() const;
	const int GetRequiredMipNonVirtualFP() const;
	ETEX_Format GetDstFormat() const;
	ETEX_Format GetSrcFormat() const;
	ETEX_Type GetTexType() const;
	static bool IsTextureExist(CTexture const* arg0);
	const bool IsNoTexture() const;
	void SetWasUnload(bool arg0);
	const bool IsPartiallyLoaded() const;
	const bool IsUnloaded() const;
	void SetStreamingInProgress(uint16_t arg0);
	void SetStreamingPriority(const uint8_t arg0);
	STexStreamRoundInfo const& GetStreamRoundInfo(int arg0) const;
	const int StreamGetLoadedMip() const;
	const uint8_t StreamGetFormatCode() const;
	const int StreamGetActiveMip() const;
	const int StreamGetPriority() const;
	const bool IsResolved() const;
	void SetUseMultisampledRTV(bool arg0);
	const bool UseMultisampledRTV() const;
	const bool IsVertexTexture() const;
	void SetVertexTexture(bool arg0);
	const bool IsDynamic() const;
	bool IsStillUsedByGPU();
	void Lock();
	void Unlock();
	const bool IsLoaded() const;
	const bool IsLocked() const;
	const bool IsStreamed() const;
	const bool IsInDistanceSortedList() const;
	const bool IsStreaming() const;
	const int GetAccessFrameIdNonVirtual() const;
	void SetResolved(bool arg0);
	const bool UseDecalBorderCol() const;
	const bool IsSRGB() const;
	void SRGBRead(bool arg0);
	const bool IsCustomFormat() const;
	void SetCustomFormat();
	void SetWidth(int16_t arg0);
	void SetHeight(int16_t arg0);
	void SetMemoryHeap(EDeviceMemoryHeap arg0);
	EDeviceMemoryHeap GetMemoryHeap() const;
	int GetUpdateFrameID() const;
	const int GetActualSize() const;
	const int GetPersistentSize() const;
	void PrefetchStreamingInfo() const;
	STexStreamingInfo const* GetStreamingInfo() const;
	const bool IsStreamableNonVirtual() const;
	void DisableMgpuSync();
	void MgpuResourceUpdate(bool arg0);
	void SetRenderTargetTileOffset(uint8_t arg0);
	const uint8_t GetRenderTargetTile() const;
	const uint8_t GetRenderTargetTileOffset() const;
	bool IsFPFormat() const;
	void* GetDeviceRT() const;
	CDeviceTexture* GetDevTexture() const;
	void AddDirtRect(tagRECT& arg0, unsigned arg1, unsigned arg2);
	bool IsAsyncDevTexCreation() const;
	ID3D11ShaderResourceView* GetShaderResourceView(uint64_t arg0, bool arg1) const;
	ID3D11UnorderedAccessView* GetDeviceUAV() const;
	void* GetResourceView(SResourceView const& arg0) const;
	void SetResourceView(SResourceView const& arg0, void* arg1);
	ID3D11RenderTargetView* GetSurface(int arg0, int arg1) const;
	_D3DPOOL GetPool();
	SPixFormat const* GetPixelFormat() const;
	const char* GetSourceName() const;
	const int GetSize(bool arg0) const;
	void StreamUploadMip(IReadStream* arg0, int arg1, int arg2, STexPoolItem* arg3, STexStreamInMipState& arg4);
	void StreamUploadMipSide(const int arg0, const int arg1, const uint8_t* const arg2, int arg3, STexMipHeader const& arg4, const bool arg5, const int arg6, const int arg7, const int arg8, CDeviceTexture* arg9, unsigned arg10, unsigned arg11, int arg12);
	static bool IsStreamingInProgress();
	bool CanStreamInPlace(int arg0, STexPoolItem* arg1);
	void StreamUploadMips(int arg0, int arg1, STexPoolItem* arg2);
	int StreamUnload();
	void StreamActivateLod(int arg0);
	static STexStreamInState* StreamState_AllocateIn();
	static STexStreamingInfo* StreamState_AllocateInfo(int arg0);
	void RT_Relink();
	void RT_Unlink();
	static void ApplyForID(int arg0, int arg1, int arg2, int arg3);
	static CTexture* GetByNameCRC(CCryNameTSCRC arg0);
	static void ReleaseSystemTargets();
	static void ResetTMUs();
	uint8_t* GetSubImageData32(int arg0, int arg1, int arg2, int arg3, int& arg4);
	void ApplySamplerState(int arg0, EHWShaderClass arg1, int arg2);
	static bool IsFormatSupported(ETEX_Format arg0);
	static void DestroyHDRMaps();
	static void DestroySceneMap();
	static void DestroyCachedShadowMaps();
	static void GenerateNearestShadowMap();
	static void DestroyNearestShadowMap();
	static void DestroyLookingGlassMaps();
	static bool IsInPlaceFormat(ETEX_Format arg0);
	static bool IsBlockCompressed(ETEX_Format arg0);
	static bool IsFourBit(ETEX_Format arg0);
	static int BytesPerBlock(ETEX_Format arg0);
	static int BitsPerPixel(ETEX_Format arg0);
	static int BytesPerPixel(ETEX_Format arg0);
	static const char* NameForTextureFormat(ETEX_Format arg0);
	static ETEX_Format TextureFormatForName(const char* arg0);
	static ETEX_Type TextureTypeForName(const char* arg0);
	static unsigned WriteMaskFromTexFormat(ETEX_Format arg0);
	static DXGI_FORMAT GetD3DLinFormat(DXGI_FORMAT arg0);
	static DXGI_FORMAT ConvertToStencilOnlyFmt(DXGI_FORMAT arg0);
	static DXGI_FORMAT ConvertToDepthOnlyFmt(DXGI_FORMAT arg0);
	static DXGI_FORMAT ConvertToSignedFmt(DXGI_FORMAT arg0);
	static SEnvTexture* FindSuitableEnvTex(Vec3& arg0, Ang3& arg1, bool arg2, int arg3, bool arg4, CShader* arg5, CShaderResources* arg6, CRenderObject* arg7, bool arg8, CRendElementBase* arg9, bool* arg10);
	static CTexture* GetSceneSpecularTarget();
	static CTexture* GetDecalsSpecularTarget();
	static CTexture* GetRefractionTarget();
	static CTexture* GetLensFlareTarget();
#endif

	static inline auto FGenName = PreyFunction<CCryNameTSCRC(const char* name, unsigned nFlags)>(0xFDFD00);
	static inline auto FFormatFixupOv1 = PreyFunction<ETEX_Format(CTexture* const _this, ETEX_Format src)>(0xFDFCA0);
	static inline auto FAddRef = PreyFunction<int(CTexture* const _this)>(0x1019C30);
	static inline auto FRelease = PreyFunction<int(CTexture* const _this)>(0xE803B0);
	static inline auto FReleaseForce = PreyFunction<int(CTexture* const _this)>(0xFE59A0);
	static inline auto FGetName = PreyFunction<const char* (CTexture const* const _this)>(0x1315370);
	static inline auto FGetWidth = PreyFunction<const int(CTexture const* const _this)>(0xFE0B80);
	static inline auto FGetHeight = PreyFunction<const int(CTexture const* const _this)>(0xFE04F0);
	static inline auto FGetDepth = PreyFunction<const int(CTexture const* const _this)>(0xFE02D0);
	static inline auto FGetTextureID = PreyFunction<const int(CTexture const* const _this)>(0xD9C610);
	static inline auto FGetFlags = PreyFunction<const unsigned(CTexture const* const _this)>(0xCECB0);
	static inline auto FGetNumMips = PreyFunction<const int(CTexture const* const _this)>(0xFE0660);
	static inline auto FGetRequiredMip = PreyFunction<const int(CTexture const* const _this)>(0xFE0750);
	static inline auto FGetTextureType = PreyFunction<ETEX_Type(CTexture const* const _this)>(0xFE0AE0);
	static inline auto FSetClamp = PreyFunction<void(CTexture* const _this, bool bEnable)>(0xFE65D0);
	static inline auto FIsTextureLoaded = PreyFunction<const bool(CTexture const* const _this)>(0xFE0DE0);
	static inline auto FPrecacheAsynchronously = PreyFunction<void(CTexture* const _this, float fMipFactor, int nFlags, int nUpdateId, int nCounter)>(0xFEB7B0);
	static inline auto FGetData32 = PreyFunction<uint8_t* (CTexture* const _this, int nSide, int nLevel, uint8_t* pDst, ETEX_Format eDstFormat)>(0xFE0190);
	static inline auto FGetDeviceDataSize = PreyFunction<const int(CTexture const* const _this)>(0xD9C5E0);
	static inline auto FGetDataSize = PreyFunction<const int(CTexture const* const _this)>(0xFE0210);
	static inline auto FSetFilter = PreyFunction<bool(CTexture* const _this, int nFilter)>(0xFE6730);
	static inline auto FClearOv1 = PreyFunction<bool(CTexture* const _this)>(0xF290F0);
	static inline auto FClearOv0 = PreyFunction<bool(CTexture* const _this, ColorF const& cClear)>(0xF290B0);
	static inline auto FGetAvgBrightness = PreyFunction<float(CTexture const* const _this)>(0xFE0110);
	static inline auto FSetAvgBrightness = PreyFunction<void(CTexture* const _this, float fBrightness)>(0xFE65C0);
	static inline auto FGetClearColor = PreyFunction<ColorF const& (CTexture const* const _this)>(0x10BD7F0);
	static inline auto FSetClearColor = PreyFunction<void(CTexture* const _this, ColorF const& cClearColor)>(0xFE65E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CTexture const* const _this, ICrySizer* pSizer)>(0xFE0500);
	static inline auto FGetFormatName = PreyFunction<const char* (CTexture const* const _this)>(0xFE0470);
	static inline auto FGetTypeName = PreyFunction<const char* (CTexture const* const _this)>(0xFE0AF0);
	static inline auto FIsShared = PreyFunction<const bool(CTexture const* const _this)>(0xFE0DC0);
	static inline auto FGetTextureDstFormat = PreyFunction<ETEX_Format(CTexture const* const _this)>(0xFE0AC0);
	static inline auto FGetTextureSrcFormat = PreyFunction<ETEX_Format(CTexture const* const _this)>(0xFE0AD0);
	static inline auto FIsParticularMipStreamed = PreyFunction<const bool(CTexture const* const _this, float fMipFactor)>(0xFEB6D0);
	static inline auto FStreamGetNumSlices = PreyFunction<const unsigned(CTexture const* const _this)>(0xF2D3D0);
	static inline auto FRT_ReleaseDevice = PreyFunction<void(CTexture* const _this)>(0xFE5890);
	static inline auto FIsPostponed = PreyFunction<bool(CTexture const* const _this)>(0xFE0DB0);
	static inline auto FIsStreamedVirtual = PreyFunction<const bool(CTexture const* const _this)>(0xFE0DD0);
	static inline auto FIsStreamedIn = PreyFunction<bool(CTexture const* const _this, const int* nMinPrecacheRoundIds)>(0xFEB710);
	static inline auto FGetAccessFrameId = PreyFunction<const int(CTexture const* const _this)>(0xD9C5F0);
	static inline auto FGetCustomID = PreyFunction<const int(CTexture const* const _this)>(0xEEB310);
	static inline auto FSetCustomID = PreyFunction<void(CTexture* const _this, int nID)>(0xFE6610);
	static inline auto FIsStreamable = PreyFunction<const bool(CTexture const* const _this)>(0xFE0DD0);
	static inline auto FSetRenderTargetTile = PreyFunction<void(CTexture* const _this, uint8_t nTile)>(0xA13080);
	static inline auto FSetDevTexture = PreyFunction<void(CTexture* const _this, CDeviceTexture* pDeviceTex)>(0xFE6620);
	static inline auto FOwnDevTexture = PreyFunction<void(CTexture* const _this, unsigned nFlags, CDeviceTexture* pDeviceTex)>(0xFE5030);
	static inline auto FGenerateMipMaps = PreyFunction<bool(CTexture* const _this, bool bSetOrthoProj, bool bUseHW, bool bNormalMap)>(0xF2AFA0);
	static inline auto FGetShaderResourceViewOv1 = PreyFunction<ID3D11ShaderResourceView* (CTexture* const _this, uint64_t resourceViewID, bool bLegacySrgbLookup)>(0xFE0850);
	static inline auto FSetShaderResourceView = PreyFunction<void(CTexture* const _this, ID3D11ShaderResourceView* pDeviceShaderResource, bool bMultisampled)>(0xFE6860);
	static inline auto FGetDeviceUAVOv1 = PreyFunction<ID3D11UnorderedAccessView* (CTexture* const _this)>(0xFE0410);
	static inline auto FGetResourceViewOv1 = PreyFunction<void* (CTexture* const _this, SResourceView const& rvDesc)>(0xFE0760);
	static inline auto FCreateDeviceResourceView = PreyFunction<void* (CTexture* const _this, SResourceView const& rv)>(0xF29EE0);
	static inline auto FGetDeviceDepthStencilView = PreyFunction<ID3D11DepthStencilView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled, bool readOnly)>(0xFE0340);
	static inline auto FGetDeviceDepthReadOnlySRV = PreyFunction<ID3D11ShaderResourceView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled)>(0xFE02E0);
	static inline auto FGetDeviceStencilReadOnlySRV = PreyFunction<ID3D11ShaderResourceView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled)>(0xFE03B0);
	static inline auto FGetSurfaceOv1 = PreyFunction<ID3D11RenderTargetView* (CTexture* const _this, int nCMSide, int nLevel)>(0xF2B2D0);
	static inline auto FInvalidate = PreyFunction<bool(CTexture* const _this, int nNewWidth, int nNewHeight, ETEX_Format eTF)>(0xFE0C40);
	static inline auto FPostCreate = PreyFunction<void(CTexture* const _this)>(0xFE5270);
	static inline auto FInvalidateDeviceResource = PreyFunction<void(CTexture* const _this, unsigned dirtyFlags)>(0xFE0CC0);
	static inline auto FAddInvalidateCallback = PreyFunction<void(CTexture* const _this, void* listener, std::function<void __cdecl(void*, unsigned int)> callback)>(0xF42CA0);
	static inline auto FRemoveInvalidateCallbacks = PreyFunction<void(CTexture* const _this, void* listener)>(0xF461E0);
	static inline auto FPrecache = PreyFunction<void()>(0xFE52B0);
	static inline auto FRT_Precache = PreyFunction<void(bool _bStepping)>(0xFE53A0);
	static inline auto FStreamValidateTexSize = PreyFunction<void()>(0xA13080);
	static inline auto FStreamComputeFormatCode = PreyFunction<uint8_t(unsigned nWidth, unsigned nHeight, unsigned nMips, ETEX_Format fmt)>(0xFEC3F0);
	static inline auto FStreamComputeDevDataSize = PreyFunction<int(CTexture const* const _this, int nFromMip)>(0xEC5CB0);
	static inline auto FStreamExpandMip = PreyFunction<void(CTexture* const _this, const void* vpRawData, int nMip, int nBaseMipOffset, int nSideDelta)>(0xF2E920);
	static inline auto FRT_FlushAllStreamingTasks = PreyFunction<void(const bool bAbort)>(0xFEB820);
	static inline auto FAbortStreamingTasks = PreyFunction<void(CTexture* pTex)>(0xFEB0B0);
	//static inline auto FStartStreaming = PreyFunction<bool(CTexture* pTex, STexPoolItem* pNewPoolItem, const int nStartMip, const int nEndMip, const int nActivateMip, EStreamTaskPriority estp)>(0xFEBC60);
	static inline auto FStreamCopyMipsTexToMem = PreyFunction<void(CTexture* const _this, int nStartMip, int nEndMip, bool bToDevice, STexPoolItem* pNewPoolItem)>(0xF2E030);
	static inline auto FStreamCopyMipsTexToTex = PreyFunction<void(STexPoolItem* pSrcItem, int nMipSrc, STexPoolItem* pDestItem, int nMipDest, int nNumMips)>(0xF2E4C0);
	static inline auto FCopySliceChain = PreyFunction<void(CDeviceTexture* const pDevTexture, int ownerMips, int nDstSlice, int nDstMip, CDeviceTexture* pSrcDevTex, int nSrcSlice, int nSrcMip, int nSrcMips, int nNumMips)>(0xF29DD0);
	static inline auto FStreamCreateDeferred = PreyFunction<ID3D11CommandList* (CTexture* const _this, int nStartMip, int nEndMip, STexPoolItem* pNewPoolItem, STexPoolItem* pSrcPoolItem)>(0xF2E580);
	static inline auto FStreamApplyDeferred = PreyFunction<void(CTexture* const _this, ID3D11CommandList* pCmdList)>(0xF2DD10);
	static inline auto FStreamReleaseMipsData = PreyFunction<void(CTexture* const _this, int nStartMip, int nEndMip)>(0xFEDAB0);
	static inline auto FStreamCalculateMipsSignedFP = PreyFunction<int16_t(CTexture const* const _this, float fMipFactor)>(0xEAC460);
	static inline auto FStreamCalculateMipFactor = PreyFunction<float(CTexture const* const _this, int16_t nMipsSigned)>(0xEAC3D0);
	static inline auto FStreamCalculateMipsSigned = PreyFunction<int(CTexture const* const _this, float fMipFactor)>(0xFEC3D0);
	static inline auto FGetStreamableMipNumber = PreyFunction<int(CTexture const* const _this)>(0xFEB330);
	static inline auto FGetStreamableMemoryUsage = PreyFunction<int(CTexture const* const _this, int nStartMip)>(0xFEB310);
	static inline auto FGetMinLoadedMip = PreyFunction<int(CTexture const* const _this)>(0xFE0650);
	static inline auto FSetMinLoadedMip = PreyFunction<void(CTexture* const _this, int nMinMip)>(0xFEBC50);
	static inline auto FStreamTrim = PreyFunction<int(CTexture* const _this, int nToMip)>(0xF2F130);
	static inline auto FStreamLoadFromCache = PreyFunction<void(CTexture* const _this, const int Flags)>(0xFEC750);
	static inline auto FStreamPrepareOv1 = PreyFunction<bool(CTexture* const _this, bool bFromLoad)>(0xFED3F0);
	static inline auto FStreamPrepareOv0 = PreyFunction<bool(CTexture* const _this, CImageFile* pIM)>(0xFEC7A0);
	static inline auto FStreamPrepare_Platform = PreyFunction<bool(CTexture* const _this)>(0x1B933B0);
	static inline auto FStreamPrepare_Finalise = PreyFunction<bool(CTexture* const _this, bool bFromLoad)>(0xFED880);
	static inline auto FStreamGetPool = PreyFunction<STexPool* (CTexture* const _this, int nStartMip, int nMips)>(0xF2EA70);
	static inline auto FStreamGetPoolItem = PreyFunction<STexPoolItem* (CTexture* const _this, int nStartMip, int nMips, bool bShouldBeCreated, bool bCreateFromMipData, bool bCanCreate, bool bForStreamOut)>(0xF2EB40);
	static inline auto FStreamRemoveFromPool = PreyFunction<void(CTexture* const _this)>(0xF2F040);
	static inline auto FStreamAssignPoolItem = PreyFunction<void(CTexture* const _this, STexPoolItem* pItem, int nMinMip)>(0xF2DD80);
	static inline auto FStreamState_Update = PreyFunction<void()>(0xFEDD40);
	static inline auto FStreamState_UpdatePrep = PreyFunction<void()>(0xFEDE20);
	static inline auto FStreamState_ReleaseIn = PreyFunction<void(STexStreamInState* pState)>(0xFEDBA0);
	static inline auto FStreamState_ReleaseInfo = PreyFunction<void(CTexture* pOwnerTex, STexStreamingInfo* pInfo)>(0xFEDC50);
	static inline auto FRelink = PreyFunction<void(CTexture* const _this)>(0xFEBB90);
	static inline auto FUnlink = PreyFunction<void(CTexture* const _this)>(0xFEE0B0);
	static inline auto FmfGetClassName = PreyFunction<CCryNameTSCRC const& ()>(0xFE9200);
	static inline auto FGetByID = PreyFunction<CTexture* (int nID)>(0xFE0120);
	static inline auto FGetByName = PreyFunction<CTexture* (const char* szName, unsigned flags)>(0xFE0150);
	static inline auto FForName = PreyFunction<CTexture* (const char* name, unsigned nFlags, ETEX_Format eTFDst)>(0xFDFBA0);
	static inline auto FCreateTextureArray = PreyFunction<CTexture* (const char* name, ETEX_Type eType, unsigned nWidth, unsigned nHeight, unsigned nArraySize, int nMips, unsigned nFlags, ETEX_Format eTF, int nCustomID, EDeviceMemoryHeap _heapId)>(0xFDECE0);
	static inline auto FCreateRenderTargetOv1 = PreyFunction<CTexture* (const char* name, unsigned nWidth, unsigned nHeight, ColorF const& cClear, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID)>(0xFDE820);
	static inline auto FCreateRenderTargetOv0 = PreyFunction<bool(CTexture* const _this, ETEX_Format eTF, ColorF const& cClear)>(0xF2A370);
	static inline auto FCreateTextureObject = PreyFunction<CTexture* (const char* name, unsigned nWidth, unsigned nHeight, int nDepth, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID, EDeviceMemoryHeap _heapId)>(0xFDEEE0);
	static inline auto FNewTexture = PreyFunction<CTexture* (const char* name, unsigned nFlags, ETEX_Format eTFDst, EDeviceMemoryHeap _heapId, bool& bFound)>(0xFE4F40);
	static inline auto FInitStreaming = PreyFunction<void()>(0xFEB350);
	static inline auto FInitStreamingDev = PreyFunction<void()>(0xF2DCD0);
	static inline auto FInit = PreyFunction<void()>(0xFE0B90);
	static inline auto FPostInit = PreyFunction<void()>(0xFE52A0);
	static inline auto FRT_FlushStreaming = PreyFunction<void(bool bAbort)>(0xFEBB20);
	static inline auto FShutDown = PreyFunction<void()>(0xFE6AC0);
	static inline auto FCreateSystemTargets = PreyFunction<void()>(0xF2A490);
	static inline auto FReleaseMiscTargets = PreyFunction<void()>(0xF2CCB0);
	static inline auto FReleaseSystemTextures = PreyFunction<void(bool bFinalRelease)>(0xFE5A10);
	static inline auto FLoadDefaultSystemTextures = PreyFunction<void()>(0xFE13F0);
	static inline auto FLoadScaleformSystemTextures = PreyFunction<void()>(0xFE3FA0);
	static inline auto FReloadFile = PreyFunction<bool(const char* szFileName)>(0xFE5DD0);
	static inline auto FReloadFile_Request = PreyFunction<bool(const char* szFileName)>(0xFE60F0);
	static inline auto FReloadTextures = PreyFunction<void()>(0xFE61D0);
	static inline auto FCreate2DTextureOv1 = PreyFunction<CTexture* (const char* szName, int nWidth, int nHeight, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst, EDeviceMemoryHeap heapId, bool bAsyncDevTexCreation)>(0xFDE420);
	static inline auto FCreate2DTextureOv0 = PreyFunction<bool(CTexture* const _this, int nWidth, int nHeight, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst)>(0xFDE320);
	static inline auto FCreate3DTextureOv1 = PreyFunction<CTexture* (const char* szName, int nWidth, int nHeight, int nDepth, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst, EDeviceMemoryHeap heapId)>(0xFDE670);
	static inline auto FCreate3DTextureOv0 = PreyFunction<bool(CTexture* const _this, int nWidth, int nHeight, int nDepth, int nMips, int nFlags, uint8_t* pData, ETEX_Format eTFSrc, ETEX_Format eTFDst)>(0xFDE5A0);
	static inline auto FUpdate = PreyFunction<void()>(0xFE71C0);
	static inline auto FRT_LoadingUpdate = PreyFunction<void()>(0xFE5330);
	static inline auto FRLT_LoadingUpdate = PreyFunction<void()>(0xFE5320);
	static inline auto FLoadOv1 = PreyFunction<bool(CTexture* const _this, ETEX_Format eTFDst)>(0xFE1380);
	static inline auto FLoadOv0 = PreyFunction<bool(CTexture* const _this, CImageFile* pImage)>(0xFE0DF0);
	static inline auto FLoadFromImage = PreyFunction<bool(CTexture* const _this, const char* name, ETEX_Format eTFDst)>(0xFE3960);
	static inline auto FReload = PreyFunction<bool(CTexture* const _this)>(0xFE5C70);
	static inline auto FToggleStreaming = PreyFunction<bool(CTexture* const _this, const bool bEnable)>(0xFE7100);
	static inline auto FCreateTexture = PreyFunction<bool(CTexture* const _this, STexData& td)>(0xFDEA50);
	static inline auto FUnbind = PreyFunction<void(CTexture* const _this)>(0xF2D630);
	static inline auto FResolve = PreyFunction<bool(CTexture* const _this, int nTarget, bool bUseViewportSize)>(0x1B933B0);
	static inline auto FCreateDeviceTexture = PreyFunction<bool(CTexture* const _this, uint8_t** pData)>(0xF2A300);
	static inline auto FRT_CreateDeviceTexture = PreyFunction<bool(CTexture* const _this, uint8_t** pData)>(0xF2B7A0);
	static inline auto FDisableStreaming = PreyFunction<void(CTexture* const _this)>(0xF2A980);
	static inline auto FReleaseDeviceTexture = PreyFunction<void(CTexture* const _this, bool bKeepLastMips, bool bFromUnload)>(0xF2CA10);
	static inline auto FApply = PreyFunction<void(CTexture* const _this, int nTUnit, int nState, int nTexMatSlot, int nSUnit, uint64_t nResViewKey, EHWShaderClass eHWSC)>(0xF288A0);
	static inline auto FApplyTexture = PreyFunction<void(CTexture* const _this, int nTUnit, EHWShaderClass eHWSC, uint64_t nResViewKey)>(0xF28CE0);
	static inline auto FClosestFormatSupportedOv1 = PreyFunction<ETEX_Format(CTexture* const _this, ETEX_Format eTFDst)>(0xF29150);
	static inline auto FClosestFormatSupportedOv0 = PreyFunction<ETEX_Format(ETEX_Format eTFDst, SPixFormat const*& pPF)>(0xF29160);
	static inline auto FSetTexStates = PreyFunction<void(CTexture* const _this)>(0xF2D320);
	static inline auto FUpdateTexStates = PreyFunction<void(CTexture* const _this)>(0xF2D9E0);
	static inline auto FSetFilterMode = PreyFunction<bool(CTexture* const _this, int nFilter)>(0xF2CE70);
	static inline auto FSetClampingMode = PreyFunction<bool(CTexture* const _this, int nAddressU, int nAddressV, int nAddressW)>(0xF2CE20);
	static inline auto FUpdateTextureRegion = PreyFunction<void(CTexture* const _this, uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc)>(0xF2DA00);
	static inline auto FRT_UpdateTextureRegion = PreyFunction<void(CTexture* const _this, uint8_t* data, int nX, int nY, int nZ, int USize, int VSize, int ZSize, ETEX_Format eTFSrc)>(0xF2C3D0);
	static inline auto FSetNoTexture = PreyFunction<bool(CTexture* const _this, CTexture* pDefaultTexture, bool _bOutOfMemory)>(0xFE6740);
	static inline auto FSetSamplerState = PreyFunction<void(int nTS, int nSUnit, EHWShaderClass eHWSC)>(0xF2D1F0);
	static inline auto FGenerateZMaps = PreyFunction<void()>(0xF2B200);
	static inline auto FDestroyZMaps = PreyFunction<void()>(0xA13080);
	static inline auto FGenerateHDRMaps = PreyFunction<void()>(0xEE8E30);
	static inline auto FGenerateSceneMap = PreyFunction<void(ETEX_Format eTF)>(0xF2B070);
	static inline auto FGenerateCachedShadowMaps = PreyFunction<void()>(0xF2A9D0);
	static inline auto FGenerateLookingGlassMaps = PreyFunction<void()>(0xECFDE0);
	static inline auto FConvert = PreyFunction<uint8_t* (uint8_t* pSrc, int nWidth, int nHeight, int nMips, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nOutMips, int& nOutSize, bool bLinear)>(0xF296E0);
	static inline auto FCalcNumMips = PreyFunction<int(int nWidth, int nHeight)>(0xFDE270);
	static inline auto FExpandMipFromFile = PreyFunction<void(uint8_t* dest, const int destSize, const uint8_t* src, const int srcSize, ETEX_Format fmt)>(0xFDF720);
	static inline auto FTextureDataSize = PreyFunction<unsigned(unsigned nWidth, unsigned nHeight, unsigned nDepth, unsigned nMips, unsigned nSlices, ETEX_Format eTF, ETEX_TileMode eTM)>(0xFE6DC0);
	static inline auto FNameForTextureType = PreyFunction<const char* (ETEX_Type eTT)>(0xFE4EA0);
	static inline auto FIsDeviceFormatTypeless = PreyFunction<bool(DXGI_FORMAT nFormat)>(0xF2B440);
	static inline auto FIsDeviceFormatSRGBReadable = PreyFunction<bool(DXGI_FORMAT nFormat)>(0xF2B3C0);
	static inline auto FDeviceFormatFromTexFormat = PreyFunction<DXGI_FORMAT(ETEX_Format eTF)>(0xF2A780);
	static inline auto FTexFormatFromDeviceFormat = PreyFunction<ETEX_Format(DXGI_FORMAT nFormat)>(0xF2D400);
	static inline auto FConvertToDepthStencilFmt = PreyFunction<DXGI_FORMAT(DXGI_FORMAT nFormat)>(0xF29B60);
	static inline auto FConvertToSRGBFmt = PreyFunction<DXGI_FORMAT(DXGI_FORMAT fmt)>(0xF29B90);
	static inline auto FConvertToTypelessFmt = PreyFunction<DXGI_FORMAT(DXGI_FORMAT fmt)>(0xF29C70);
	static inline auto FGetTexState = PreyFunction<int(STexState const& TS)>(0xE7EB20);
};

static_assert(sizeof(CTexture) == 264);
