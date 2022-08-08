#include <Prey/RenderDll/XRenderD3D9/DeviceInfo.h>

void DeviceInfo::SnapSettings()
{
	if (m_swapChainDesc.Windowed)
	{
		m_swapChainDesc.BufferDesc.RefreshRate.Denominator = 0;
		m_swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		m_swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		m_swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		m_refreshRate = m_desktopRefreshRate;
	}
	else
	{
		DXGI_MODE_DESC desc;
		memset(&desc, 0, sizeof(desc));
		desc.Width = m_swapChainDesc.BufferDesc.Width;
		desc.Height = m_swapChainDesc.BufferDesc.Height;
		desc.Format = m_swapChainDesc.BufferDesc.Format;

		DXGI_MODE_DESC match;
		if (SUCCEEDED(m_pOutput->FindClosestMatchingMode(&desc, &match, m_pDevice)))
		{
			m_swapChainDesc.BufferDesc = match;

			m_refreshRate = match.RefreshRate;
		}
	}
}

void DeviceInfo::ResizeDXGIBuffers()
{
	m_pBackbufferRTV = nullptr;
	std::fill(m_pBackbufferRTVs.begin(), m_pBackbufferRTVs.end(), nullptr);

	HRESULT hr = m_pSwapChain->ResizeBuffers(0, m_swapChainDesc.BufferDesc.Width, m_swapChainDesc.BufferDesc.Height, m_swapChainDesc.BufferDesc.Format, m_swapChainDesc.Flags);

	CreateViews();
}

bool DeviceInfo::CreateViews()
{
	DXGI_SWAP_CHAIN_DESC scDesc;
	m_pSwapChain->GetDesc(&scDesc);

	unsigned int numIndices = 1;
	m_pBackbufferRTVs.resize(numIndices);
	for (unsigned int b = 0; b < numIndices; ++b)
	{
		D3DTexture* pBackBuffer = 0;
		HRESULT hr = m_pSwapChain->GetBuffer(b, __uuidof(D3DTexture), (void**)&pBackBuffer);
		assert(SUCCEEDED(hr) && pBackBuffer != 0);

		D3DSurface* pBackbufferView;
		hr = m_pDevice->CreateRenderTargetView(pBackBuffer, 0, &pBackbufferView);
		assert(SUCCEEDED(hr) && pBackbufferView != nullptr);

		m_pBackbufferRTVs[b] = pBackbufferView;
		SAFE_RELEASE(pBackbufferView);

		char str[32] = "";
		sprintf(str, "Swap-Chain back buffer %d", b);
		pBackBuffer->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(str), str);

		SAFE_RELEASE(pBackBuffer);
	}

	m_pCurrentBackBufferRTVIndex = 0;
	m_pBackbufferRTV = m_pBackbufferRTVs[m_pCurrentBackBufferRTVIndex];

	ID3D11Resource* pBackbufferResource;
	m_pBackbufferRTV->GetResource(&pBackbufferResource);
	m_pBackbufferTex2D = (D3DTexture*)pBackbufferResource;

	return m_pBackbufferRTV != NULL;
}
