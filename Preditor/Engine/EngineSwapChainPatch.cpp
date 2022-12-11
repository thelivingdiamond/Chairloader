#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/CryRenderer/DeviceTexture.h>
#include "EngineSwapChainPatch.h"
#include "PreditorImGuiRenderer.h"

enum class EDisplayOutputMode;

namespace
{

EngineSwapChainPatch g_SwapChainPatch;
auto DeviceInfo_CreateDevice = PreyFunction<bool(DeviceInfo* const _this, bool windowed, int width, int height, int backbufferWidth, int backbufferHeight, EDisplayOutputMode _outputMode, int zbpp, HRESULT(*pCreateDeviceCallback)(ID3D11Device*), HWND__* (*pCreateWindowCallback)())>(0xF23FE0);
auto DeviceInfo_CreateViews = PreyFunction<bool(DeviceInfo* const _this)>(0xF24650);
auto g_DeviceInfo_CreateViews_Hook = DeviceInfo_CreateViews.MakeHook();

bool DeviceInfo_CreateViews_Hook(DeviceInfo* const _this)
{
	_this->m_pSwapChain = g_SwapChainPatch.MakeSwapChain(_this->m_pSwapChain);
	return g_DeviceInfo_CreateViews_Hook.InvokeOrig(_this);
}

}

class EngineSwapChainPatch::FakeSwapChain : public IDXGISwapChain
{
public:
	IDXGISwapChain* m_pReal = nullptr;

	FakeSwapChain(IDXGISwapChain* pRealSwapChain)
	{
		m_pReal = pRealSwapChain;
	}

	// Overriden methods
	virtual HRESULT STDMETHODCALLTYPE Present(
		/* [in] */ UINT SyncInterval,
		/* [in] */ UINT Flags)
	{
		g_SwapChainPatch.RT_DrawImGui();
		return m_pReal->Present(SyncInterval, Flags);
	}

	virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
		/* [in] */ UINT BufferCount,
		/* [in] */ UINT Width,
		/* [in] */ UINT Height,
		/* [in] */ DXGI_FORMAT NewFormat,
		/* [in] */ UINT SwapChainFlags)
	{
		g_SwapChainPatch.RT_ResizeBackbuffer(Width, Height, NewFormat);
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE GetBuffer(
		/* [in] */ UINT Buffer,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][out][in] */
		_COM_Outptr_  void** ppSurface)
	{
		assert(Buffer == 0);
		assert(IsEqualGUID(riid, __uuidof(ID3D11Texture2D)));
		*ppSurface = g_SwapChainPatch.m_pBackbuffer->GetDevTexture()->Get2DTexture();
		return S_OK;
	}

public:
	// IUnknown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)
	{
		return m_pReal->QueryInterface(riid, ppvObject);
	}

	virtual ULONG STDMETHODCALLTYPE AddRef(void) { return m_pReal->AddRef(); }
	virtual ULONG STDMETHODCALLTYPE Release(void) { return m_pReal->AddRef(); }

	// IDXGIObject
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [in] */ UINT DataSize,
		/* [annotation][in] */
		_In_reads_bytes_(DataSize)  const void* pData) { return m_pReal->SetPrivateData(Name, DataSize, pData); }

	virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][in] */
		_In_opt_  const IUnknown* pUnknown) { return m_pReal->SetPrivateDataInterface(Name, pUnknown); }

	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][out][in] */
		_Inout_  UINT* pDataSize,
		/* [annotation][out] */
		_Out_writes_bytes_(*pDataSize)  void* pData) { return m_pReal->GetPrivateData(Name, pDataSize, pData); }

	virtual HRESULT STDMETHODCALLTYPE GetParent(
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][retval][out] */
		_COM_Outptr_  void** ppParent) { return m_pReal->GetParent(riid, ppParent); }

	// IDXGIDeviceSubObject
	virtual HRESULT STDMETHODCALLTYPE GetDevice(
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][retval][out] */
		_COM_Outptr_  void** ppDevice) { return m_pReal->GetDevice(riid, ppDevice); }

	// IDXGISwapChain
	virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
		/* [in] */ BOOL Fullscreen,
		/* [annotation][in] */
		_In_opt_  IDXGIOutput* pTarget) { return m_pReal->SetFullscreenState(Fullscreen, pTarget); }

	virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
		/* [annotation][out] */
		_Out_opt_  BOOL* pFullscreen,
		/* [annotation][out] */
		_COM_Outptr_opt_result_maybenull_  IDXGIOutput** ppTarget) { return m_pReal->GetFullscreenState(pFullscreen, ppTarget); }

	virtual HRESULT STDMETHODCALLTYPE GetDesc(
		/* [annotation][out] */
		_Out_  DXGI_SWAP_CHAIN_DESC* pDesc) { return m_pReal->GetDesc(pDesc); }

	virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
		/* [annotation][in] */
		_In_  const DXGI_MODE_DESC* pNewTargetParameters) { return m_pReal->ResizeTarget(pNewTargetParameters); }

	virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
		/* [annotation][out] */
		_COM_Outptr_  IDXGIOutput** ppOutput) { return m_pReal->GetContainingOutput(ppOutput); }

	virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
		/* [annotation][out] */
		_Out_  DXGI_FRAME_STATISTICS* pStats) { return m_pReal->GetFrameStatistics(pStats); }

	virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
		/* [annotation][out] */
		_Out_  UINT* pLastPresentCount) { return m_pReal->GetLastPresentCount(pLastPresentCount); }
};

EngineSwapChainPatch::EngineSwapChainPatch()
{
}

EngineSwapChainPatch::~EngineSwapChainPatch()
{
}

void EngineSwapChainPatch::InitHooks()
{
	g_DeviceInfo_CreateViews_Hook.SetHookFunc(&DeviceInfo_CreateViews_Hook);
}

ITexture* EngineSwapChainPatch::GetBackbuffer()
{
	return g_SwapChainPatch.m_pBackbufferRef;
}

IDXGISwapChain* EngineSwapChainPatch::MakeSwapChain(IDXGISwapChain* pRealSwapChain)
{
	m_pSwapChain = std::make_unique<FakeSwapChain>(pRealSwapChain);
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	pRealSwapChain->GetDesc(&desc);
	RT_ResizeBackbuffer(desc.BufferDesc.Width, desc.BufferDesc.Height, desc.BufferDesc.Format);
	return m_pSwapChain.get();
}

void EngineSwapChainPatch::RT_ResizeBackbuffer(int width, int height, DXGI_FORMAT dxgiFormat)
{
	assert(width != 0 && height != 0);
	ETEX_Format format = CTexture::TexFormatFromDeviceFormat(dxgiFormat);

	if (!m_pBackbufferRef)
	{
		CTexture* pTex = CTexture::CreateTextureObject("$PreditorSwapChainRef", 0, 0, 1, eTT_2D, FT_DONT_STREAM | FT_USAGE_RENDERTARGET, format);
		m_pBackbufferRef = pTex;
		SAFE_RELEASE(pTex);
	}

	if (!m_pBackbuffer || m_pBackbuffer->GetWidth() != width || m_pBackbuffer->GetHeight() != height)
	{
		CTexture* pTex = CTexture::CreateRenderTarget("$PreditorSwapChainTexture", width, height,
			ColorF(0, 0, 0, 1), eTT_2D, FT_DONT_STREAM | FT_USAGE_RENDERTARGET, format);
		m_pBackbuffer = pTex;

		CDeviceTexture* pDeviceTexture = new CDeviceTexture(pTex->GetDevTexture()->Get2DTexture());
		m_pBackbufferRef->SetDevTexture(pDeviceTexture);
		m_pBackbufferRef->m_nWidth = m_pBackbuffer->GetWidth();
		m_pBackbufferRef->m_nHeight = m_pBackbuffer->GetHeight();
		m_pBackbufferRef->ClosestFormatSupported(m_pBackbufferRef->m_eTFDst);
		
		// Resource view
		SAFE_RELEASE(m_pBackbufferRef->m_pDeviceShaderResource);
		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		ZeroMemory(&srvDesc, sizeof(srvDesc));
		srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = 1;
		srvDesc.Texture2D.MostDetailedMip = 0;
		gcpRendD3D->GetDevice().CreateShaderResourceView(pTex->GetDevTexture()->Get2DTexture(), &srvDesc, &m_pBackbufferRef->m_pDeviceShaderResource);

		SAFE_RELEASE(pTex);
	}
}

void EngineSwapChainPatch::RT_DrawImGui()
{
	PreditorImGuiRenderer* pImGui = PreditorImGuiRenderer::Get();
	if (pImGui && gcpRendD3D && gRenDev)
	{
		// Switch to real swap chain
		// TODO: Cache the view
		ID3D11Texture2D* swapTex = nullptr;
		ID3D11RenderTargetView* swapTexView = nullptr;
		m_pSwapChain->m_pReal->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&swapTex);
		gcpRendD3D->GetDevice().CreateRenderTargetView(swapTex, nullptr, &swapTexView);

		ID3D11RenderTargetView* views[1] = { swapTexView };
		gcpRendD3D->GetDeviceContext().OMSetRenderTargets(1, views, nullptr);
		float clearColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		gcpRendD3D->GetDeviceContext().ClearRenderTargetView(swapTexView, clearColor);
		pImGui->RT_Render();

		SAFE_RELEASE(swapTex);
		SAFE_RELEASE(swapTexView);
	}
}
