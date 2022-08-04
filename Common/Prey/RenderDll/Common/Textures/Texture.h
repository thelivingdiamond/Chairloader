#pragma once
#include <Prey/CryRenderer/CryDX.h>

class CTexture;

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

	~SDepthTexture();

	void Release(bool bReleaseTexture);
};
