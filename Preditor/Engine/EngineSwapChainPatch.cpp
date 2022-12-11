#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include "EngineSwapChainPatch.h"
#include "PreditorImGuiRenderer.h"

enum class EDisplayOutputMode;

namespace
{

EngineSwapChainPatch g_SwapChainPatch;
auto DeviceInfo_CreateDevice = PreyFunction<bool(DeviceInfo* const _this, bool windowed, int width, int height, int backbufferWidth, int backbufferHeight, EDisplayOutputMode _outputMode, int zbpp, HRESULT(*pCreateDeviceCallback)(ID3D11Device*), HWND__* (*pCreateWindowCallback)())>(0xF23FE0);
auto g_DeviceInfo_CreateDevice_Hook = DeviceInfo_CreateDevice.MakeHook();

bool DeviceInfo_CreateDevice_Hook(DeviceInfo* const _this, bool windowed, int width, int height, int backbufferWidth, int backbufferHeight, EDisplayOutputMode _outputMode, int zbpp, HRESULT(*pCreateDeviceCallback)(ID3D11Device*), HWND__* (*pCreateWindowCallback)())
{
	bool result = g_DeviceInfo_CreateDevice_Hook.InvokeOrig(_this, windowed, width, height, backbufferWidth, backbufferHeight, _outputMode, zbpp, pCreateDeviceCallback, pCreateWindowCallback);
	if (result)
	{
		_this->m_pSwapChain = g_SwapChainPatch.MakeSwapChain(_this->m_pSwapChain);
	}

	return result;
}

}

class EngineSwapChainPatch::FakeSwapChain : public IDXGISwapChain
{
public:
	FakeSwapChain(IDXGISwapChain* pRealSwapChain)
	{
		m_pReal = pRealSwapChain;
	}

	// Overriden methods
	virtual HRESULT STDMETHODCALLTYPE Present(
		/* [in] */ UINT SyncInterval,
		/* [in] */ UINT Flags) {
		g_SwapChainPatch.RT_DrawImGui();
		return m_pReal->Present(SyncInterval, Flags);
	}

private:
	IDXGISwapChain* m_pReal = nullptr;

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
	virtual HRESULT STDMETHODCALLTYPE GetBuffer(
		/* [in] */ UINT Buffer,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][out][in] */
		_COM_Outptr_  void** ppSurface) { return m_pReal->GetBuffer(Buffer, riid, ppSurface); }

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

	virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
		/* [in] */ UINT BufferCount,
		/* [in] */ UINT Width,
		/* [in] */ UINT Height,
		/* [in] */ DXGI_FORMAT NewFormat,
		/* [in] */ UINT SwapChainFlags) { return m_pReal->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags); }

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
	g_DeviceInfo_CreateDevice_Hook.SetHookFunc(&DeviceInfo_CreateDevice_Hook);
}

IDXGISwapChain* EngineSwapChainPatch::MakeSwapChain(IDXGISwapChain* pRealSwapChain)
{
	m_pSwapChain = std::make_unique<FakeSwapChain>(pRealSwapChain);
	return m_pSwapChain.get();
}

void EngineSwapChainPatch::RT_DrawImGui()
{
	PreditorImGuiRenderer* pImGui = PreditorImGuiRenderer::Get();
	if (pImGui && gcpRendD3D && gRenDev)
		pImGui->RT_Render();
}
