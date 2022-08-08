#pragma once
#include <Prey/CryRenderer/CryDX.h>
#include <Prey/CryRenderer/IShader.h>
#include <Prey/CryRenderer/Texture.h>
#include <Prey/RenderDll/Common/Shaders/ShaderResources.h>

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

class CTexture : public ITexture, public CBaseResource {
public:
	static constexpr size_t OFFSET_m_pDevTexture = 0x30;
	static constexpr size_t OFFSET_SHADER_RESOURCE = 0xB0;
	static inline auto FSetDevTexture = PreyFunction<void(CTexture* _this, CDeviceTexture* pDeviceTex)>(0xFE6620);
	static inline auto FClosestFormatSupported = PreyFunction<ETEX_Format(CTexture* _this, ETEX_Format eTFDst)>(0xF29150);
	static inline auto FGetResourceView = PreyFunction<void* (CTexture* _this, const SResourceView& rvDesc)>(0xFE0760);
	static inline auto FSetShaderResourceView = PreyFunction<void(CTexture* _this, D3DShaderResource* pDeviceShaderResource, bool bMultisampled)>(0xFE6860);
	static inline auto FCreateRenderTargetOv1 = PreyFunction<CTexture* (const char* name, unsigned nWidth, unsigned nHeight, ColorF const& cClear, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID)>(0xFDE820);
	static inline auto FGetDeviceDepthStencilView = PreyFunction<ID3D11DepthStencilView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled, bool readOnly)>(0xFE0340);
	static inline auto FGetDeviceDepthReadOnlySRV = PreyFunction<ID3D11ShaderResourceView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled)>(0xFE02E0);
	static inline auto FGetDeviceStencilReadOnlySRV = PreyFunction<ID3D11ShaderResourceView* (CTexture* const _this, int nFirstSlice, int nSliceCount, bool bMultisampled)>(0xFE03B0);
	static inline auto FGetSurfaceOv1 = PreyFunction<ID3D11RenderTargetView* (CTexture* const _this, int nCMSide, int nLevel)>(0xF2B2D0);

	static inline auto s_TexStages = PreyGlobal<STexStageInfo[64]>(0x2B32230);

	CDeviceTexture* GetDevTexture() const { return mem::OffsetInStruct<CDeviceTexture*>(this, OFFSET_m_pDevTexture); }
	void SetDevTexture(CDeviceTexture* pDeviceTex) { FSetDevTexture(this, pDeviceTex); }
	ETEX_Format ClosestFormatSupported(ETEX_Format eTFDst) { return FClosestFormatSupported(this, eTFDst); }
	void* GetResourceView(const SResourceView& rvDesc) { return FGetResourceView(this, rvDesc); }
	void SetShaderResourceView(D3DShaderResource* pDeviceShaderResource, bool bMultisampled = false) { FSetShaderResourceView(this, pDeviceShaderResource, bMultisampled); }
	ID3D11DepthStencilView* GetDeviceDepthStencilView(int nFirstSlice, int nSliceCount, bool bMultisampled, bool readOnly) { return FGetDeviceDepthStencilView(this, nFirstSlice, nSliceCount, bMultisampled, readOnly); }
	ID3D11ShaderResourceView* GetDeviceDepthReadOnlySRV(int nFirstSlice, int nSliceCount, bool bMultisampled) { return FGetDeviceDepthReadOnlySRV(this, nFirstSlice, nSliceCount, bMultisampled); }
	ID3D11ShaderResourceView* GetDeviceStencilReadOnlySRV(int nFirstSlice, int nSliceCount, bool bMultisampled) { return FGetDeviceStencilReadOnlySRV(this, nFirstSlice, nSliceCount, bMultisampled); }
	ID3D11RenderTargetView* GetSurface(int nCMSide, int nLevel) { return FGetSurfaceOv1(this, nCMSide, nLevel); }


	static ETEX_Format TexFormatFromDeviceFormat(DXGI_FORMAT nFormat);
	static CTexture* CreateRenderTarget(const char* name, unsigned nWidth, unsigned nHeight, ColorF const& cClear, ETEX_Type eTT, unsigned nFlags, ETEX_Format eTF, int nCustomID = -1) { return FCreateRenderTargetOv1(name, nWidth, nHeight, cClear, eTT, nFlags, eTF, nCustomID); }
};
