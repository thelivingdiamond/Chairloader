#pragma once
#include <cstdint>

enum ETEX_Type : int8_t
{
	eTT_1D = 0x0,
	eTT_2D = 0x1,
	eTT_3D = 0x2,
	eTT_Cube = 0x3,
	eTT_CubeArray = 0x4,
	eTT_Dyn2D = 0x5,
	eTT_User = 0x6,
	eTT_NearestCube = 0x7,
	eTT_2DArray = 0x8,
	eTT_2DMS = 0x9,
	eTT_AutoCube = 0xA,
	eTT_Auto2D = 0xB,
	eTT_MaxTexType = 0xC,
};

enum ETEX_Format : int8_t
{
	eTF_Unknown = 0x0,
	eTF_R8G8B8A8S = 0x1,
	eTF_R8G8B8A8 = 0x2,
	eTF_R1 = 0x3,
	eTF_A8 = 0x4,
	eTF_R8 = 0x5,
	eTF_R8S = 0x6,
	eTF_R16 = 0x7,
	eTF_R16F = 0x8,
	eTF_R32F = 0x9,
	eTF_R8G8 = 0xA,
	eTF_R8G8S = 0xB,
	eTF_R16G16 = 0xC,
	eTF_R16G16S = 0xD,
	eTF_R16G16F = 0xE,
	eTF_R11G11B10F = 0xF,
	eTF_R10G10B10A2 = 0x10,
	eTF_R16G16B16A16 = 0x11,
	eTF_R16G16B16A16S = 0x12,
	eTF_R16G16B16A16F = 0x13,
	eTF_R32G32B32A32F = 0x14,
	eTF_CTX1 = 0x15,
	eTF_BC1 = 0x16,
	eTF_BC2 = 0x17,
	eTF_BC3 = 0x18,
	eTF_BC4U = 0x19,
	eTF_BC4S = 0x1A,
	eTF_BC5U = 0x1B,
	eTF_BC5S = 0x1C,
	eTF_BC6UH = 0x1D,
	eTF_BC6SH = 0x1E,
	eTF_BC7 = 0x1F,
	eTF_R9G9B9E5 = 0x20,
	eTF_D16 = 0x21,
	eTF_D24S8 = 0x22,
	eTF_D32F = 0x23,
	eTF_D32FS8 = 0x24,
	eTF_B5G6R5 = 0x25,
	eTF_B5G5R5 = 0x26,
	eTF_B4G4R4A4 = 0x27,
	eTF_EAC_R11 = 0x28,
	eTF_EAC_RG11 = 0x29,
	eTF_ETC2 = 0x2A,
	eTF_ETC2A = 0x2B,
	eTF_A8L8 = 0x2C,
	eTF_L8 = 0x2D,
	eTF_L8V8U8 = 0x2E,
	eTF_B8G8R8 = 0x2F,
	eTF_L8V8U8X8 = 0x30,
	eTF_B8G8R8X8 = 0x31,
	eTF_B8G8R8A8 = 0x32,
	eTF_YUV = 0x33,
	eTF_YUVA = 0x34,
	eTF_R16G16_UINT = 0x35,
	eTF_R32_UINT = 0x36,
	eTF_MaxFormat = 0x37,
};

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

class ITexture
{
public:
	virtual ~ITexture() = 0;
	virtual int AddRef() = 0;
	virtual int Release() = 0;
	virtual int ReleaseForce() = 0;
	virtual const char *GetName() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual int GetDepth() = 0;
	virtual int GetTextureID() = 0;
	virtual unsigned int GetFlags() = 0;
	virtual int GetNumMips() = 0;
	virtual int GetRequiredMip() = 0;
	virtual int GetDeviceDataSize() = 0;
	virtual int GetDataSize() = 0;
	virtual ETEX_Type GetTextureType() = 0;
	virtual bool IsTextureLoaded() = 0;
	virtual void PrecacheAsynchronously(float, int, int, int) = 0;
	virtual unsigned __int8 *GetData32(int, int, uint8_t *, ETEX_Format) = 0;
	virtual bool SetFilter(int) = 0;
	virtual void SetClamp(bool) = 0;
	virtual float GetAvgBrightness() = 0;
	virtual int StreamCalculateMipsSigned(float) = 0;
	virtual int GetStreamableMipNumber() = 0;
	virtual int GetStreamableMemoryUsage(int) = 0;
	virtual int GetMinLoadedMip() = 0;
	virtual const char *GetFormatName() = 0;
	virtual const char *GetTypeName() = 0;
	virtual bool IsStreamedVirtual() = 0;
	virtual bool IsShared() = 0;
	virtual bool IsStreamable() = 0;
	virtual bool IsStreamedIn(const int *) = 0;
	virtual int GetAccessFrameId() = 0;
	virtual ETEX_Format GetTextureDstFormat() = 0;
	virtual ETEX_Format GetTextureSrcFormat() = 0;
	virtual bool IsPostponed() = 0;
	virtual bool IsParticularMipStreamed(float) = 0;
	virtual void SetRenderTargetTile(unsigned __int8) = 0;
};
