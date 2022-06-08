#pragma once
#include <d3d11.h>
#include <Prey/CryRenderer/IRenderer.h>

class ICvar;

struct CRendererCVars
{
	ICVar *CV_capture_frames;
	ICVar *CV_capture_folder;
	ICVar *CV_capture_file_format;
	ICVar *CV_capture_frame_once;
	ICVar *CV_capture_file_name;
	ICVar *CV_capture_file_prefix;
	ICVar *m_CVWidth;
	ICVar *m_CVHeight;
	ICVar *m_CVFullScreen;
	ICVar *m_CVColorBits;
	ICVar *m_CVDisplayInfo;
};

struct DeviceInfo
{
	IDXGIFactory1 *m_pFactory;
	IDXGIAdapter1 *m_pAdapter;
	IDXGIOutput *m_pOutput;
	ID3D11Device *m_pDevice;
	ID3D11DeviceContext *m_pContext;
	IDXGISwapChain *m_pSwapChain;
	ID3D11Texture2D *m_pBackbufferTex2D;
	std::vector<ID3D11RenderTargetView *> m_pBackbufferRTVsUnfinished; // std::vector<_smart_ptr<ID3D11RenderTargetView>>
	ID3D11RenderTargetView *m_pBackbufferRTV;
	unsigned int m_pCurrentBackBufferRTVIndex;
	DXGI_ADAPTER_DESC1 m_adapterDesc;
	DXGI_OUTPUT_DESC m_outputDesc;
	DXGI_SWAP_CHAIN_DESC m_swapChainDesc;
	DXGI_RATIONAL m_refreshRate;
	DXGI_RATIONAL m_desktopRefreshRate;
	D3D_DRIVER_TYPE m_driverType;
	unsigned int m_creationFlags;
	D3D_FEATURE_LEVEL m_featureLevel;
	DXGI_FORMAT m_autoDepthStencilFmt;
	D3D11_FEATURE_DATA_THREADING m_featureDataThreading;
	unsigned int m_outputIndex;
	unsigned int m_syncInterval;
	unsigned int m_presentFlags;
	unsigned int m_hdrCapableOutputs;
	bool m_activated;
	bool m_activatedMT;
#if 0
	CryLockT<2> m_msgQueueLock;
	std::vector<DeviceInfoInternal::MsgQueueItem> m_msgQueue;
	EGPUVendor m_vendor;
	EDeviceFeatures m_features;
	unsigned int m_gpuCount;
	AGSConfiguration m_agsConfig;
	AGSGPUInfo m_agsInfo;
	struct AGSContext *m_pAgsContext;
	unsigned int m_agsExtensionsSupported;
	NVAPI_DEVICE_FEATURE_LEVEL m_nvapiFeatureLevel;
#endif
};

class CRenderer : public IRenderer, public CRendererCVars {};

// Do not be fooled, this is in fact a D3D11 renderer
struct __declspec(align(128)) CD3D9Renderer : public CRenderer {
public:
	static constexpr size_t OFFSET_SWAP_CHAIN = 0xAE88;
	static constexpr size_t OFFSET_DEV_INFO = 0xAF80;
};
