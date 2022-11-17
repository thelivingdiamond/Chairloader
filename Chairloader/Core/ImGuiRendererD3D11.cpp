#include <LibD3D11.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include "ImGuiRendererD3D11.h"
#include "BackupDxState.h"

void ImGuiRendererD3D11::RT_Render(ImRendDrawBuffer& buffer, const wchar_t* eventName)
{

	if (!m_bInitialized)
	{
		if (!RT_Initialize())
			CryFatalError("ImGuiRendererD3D11 failed to initialize on the render thread.");
	}

	m_pAnnot->BeginEvent(eventName);

	// Avoid rendering when minimized
	if (buffer.displaySize.x <= 0.0f || buffer.displaySize.y <= 0.0f)
		return;

	CCryDeviceWrapper& device = gcpRendD3D->GetDevice();
	CCryDeviceContextWrapper& ctx = gcpRendD3D->GetDeviceContext();

	// Create and grow vertex/index buffers if needed
	if (!m_pVB || m_VertexBufferSize < buffer.vtxBuffer.size())
	{
		if (m_pVB) { m_pVB->Release(); m_pVB = NULL; }
		m_VertexBufferSize = (int)buffer.vtxBuffer.size() + BUFFER_SIZE_INCREMENT;
		D3D11_BUFFER_DESC desc;
		memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = m_VertexBufferSize * sizeof(ImDrawVert);
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		desc.MiscFlags = 0;
		if (device.CreateBuffer(&desc, NULL, &m_pVB) < 0)
			return;
	}
	if (!m_pIB || m_IndexBufferSize < buffer.idxBuffer.size())
	{
		if (m_pIB) { m_pIB->Release(); m_pIB = NULL; }
		m_IndexBufferSize = (int)buffer.idxBuffer.size() + 2 * BUFFER_SIZE_INCREMENT;
		D3D11_BUFFER_DESC desc;
		memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = m_IndexBufferSize * sizeof(ImDrawIdx);
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		if (device.CreateBuffer(&desc, NULL, &m_pIB) < 0)
			return;
	}

	// Upload vertex/index data into a single contiguous GPU buffer
	D3D11_MAPPED_SUBRESOURCE vtx_resource, idx_resource;
	if (ctx.Map(m_pVB, 0, D3D11_MAP_WRITE_DISCARD, 0, &vtx_resource) != S_OK)
		return;
	if (ctx.Map(m_pIB, 0, D3D11_MAP_WRITE_DISCARD, 0, &idx_resource) != S_OK)
		return;
	ImDrawVert* vtx_dst = (ImDrawVert*)vtx_resource.pData;
	ImDrawIdx* idx_dst = (ImDrawIdx*)idx_resource.pData;
	memcpy(vtx_dst, buffer.vtxBuffer.data(), buffer.vtxBuffer.size() * sizeof(ImDrawVert));
	memcpy(idx_dst, buffer.idxBuffer.data(), buffer.idxBuffer.size() * sizeof(ImDrawIdx));
	ctx.Unmap(m_pVB, 0);
	ctx.Unmap(m_pIB, 0);

	// Setup orthographic projection matrix into our constant buffer
	// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
	{
		D3D11_MAPPED_SUBRESOURCE mapped_resource;
		if (ctx.Map(m_pVertexConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped_resource) != S_OK)
			return;
		VertexConstantBuffer* constant_buffer = (VertexConstantBuffer*)mapped_resource.pData;
		float L = buffer.displayPos.x;
		float R = buffer.displayPos.x + buffer.displaySize.x;
		float T = buffer.displayPos.y;
		float B = buffer.displayPos.y + buffer.displaySize.y;
		float mvp[4][4] =
		{
			{ 2.0f / (R - L),   0.0f,           0.0f,       0.0f },
			{ 0.0f,         2.0f / (T - B),     0.0f,       0.0f },
			{ 0.0f,         0.0f,           0.5f,       0.0f },
			{ (R + L) / (L - R),  (T + B) / (B - T),    0.5f,       1.0f },
		};
		memcpy(&constant_buffer->mvp, mvp, sizeof(mvp));
		ctx.Unmap(m_pVertexConstantBuffer, 0);
	}

	// Backup DX state that will be modified to restore it afterwards (unfortunately this is very ugly looking and verbose. Close your eyes!)
	BackupDxState stateBackup;
	stateBackup.Backup(ctx.GetRealDeviceContext());

	// Setup desired DX state
	RT_SetupRenderState(buffer);

	// Render command lists
	ImVec2 clip_off = buffer.displayPos;
	for (int n = 0; n < buffer.drawLists.size(); n++)
	{
		const ImRendDrawList& drawList = buffer.drawLists[n];

		for (int cmd_i = 0; cmd_i < drawList.cmdCount; cmd_i++)
		{
			const ImDrawCmd& cmd = buffer.drawCmds[drawList.cmdOffset + cmd_i];
			if (cmd.UserCallback != NULL)
			{
				// User callback, registered via ImDrawList::AddCallback()
				// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
				if (cmd.UserCallback == ImDrawCallback_ResetRenderState)
					RT_SetupRenderState(buffer);
				else
					//cmd.UserCallback(cmd_list, pcmd);
					assert(!("UserCallback not supported"));
			}
			else
			{
				// Project scissor/clipping rectangles into framebuffer space
				ImVec2 clip_min(cmd.ClipRect.x - clip_off.x, cmd.ClipRect.y - clip_off.y);
				ImVec2 clip_max(cmd.ClipRect.z - clip_off.x, cmd.ClipRect.w - clip_off.y);
				if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y)
					continue;

				// Apply scissor/clipping rectangle
				const D3D11_RECT r = { (LONG)clip_min.x, (LONG)clip_min.y, (LONG)clip_max.x, (LONG)clip_max.y };
				ctx.RSSetScissorRects(1, &r);

				// Bind texture, Draw
				ITexture* pITexture = (ITexture*)cmd.GetTexID();
				CTexture* pTexture = static_cast<CTexture*>(pITexture);
				ID3D11ShaderResourceView* pView = pTexture->m_pDeviceShaderResource;
				ctx.PSSetShaderResources(0, 1, &pView);
				ctx.DrawIndexed(cmd.ElemCount, cmd.IdxOffset + drawList.idxOffset, cmd.VtxOffset + drawList.vtxOffset);
			}
		}
	}

	// Restore modified DX state
	stateBackup.Restore(ctx.GetRealDeviceContext());
	m_pAnnot->EndEvent();
}

bool ImGuiRendererD3D11::RT_Initialize()
{
	CCryDeviceWrapper& pd3dDevice = gcpRendD3D->GetDevice();
	CCryDeviceContextWrapper& pd3dDeviceContext = gcpRendD3D->GetDeviceContext();
	pd3dDeviceContext.QueryInterface(__uuidof(ID3DUserDefinedAnnotation), (void**)&m_pAnnot);

	// Create the vertex shader
	{
		static const char* vertexShader =
			"cbuffer vertexBuffer : register(b0) \
            {\
              float4x4 ProjectionMatrix; \
            };\
            struct VS_INPUT\
            {\
              float2 pos : POSITION;\
              float4 col : COLOR0;\
              float2 uv  : TEXCOORD0;\
            };\
            \
            struct PS_INPUT\
            {\
              float4 pos : SV_POSITION;\
              float4 col : COLOR0;\
              float2 uv  : TEXCOORD0;\
            };\
            \
            PS_INPUT main(VS_INPUT input)\
            {\
              PS_INPUT output;\
              output.pos = mul( ProjectionMatrix, float4(input.pos.xy, 0.f, 1.f));\
              output.col = input.col;\
              output.uv  = input.uv;\
              return output;\
            }";

		ID3DBlob* vertexShaderBlob;
		if (FAILED(D3DCompile(vertexShader, strlen(vertexShader), NULL, NULL, NULL, "main", "vs_4_0", 0, 0, &vertexShaderBlob, NULL)))
			return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
		if (pd3dDevice.CreateVertexShader(vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), NULL, &m_pVertexShader) != S_OK)
		{
			vertexShaderBlob->Release();
			return false;
		}

		// Create the input layout
		D3D11_INPUT_ELEMENT_DESC local_layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,   0, (UINT)IM_OFFSETOF(ImDrawVert, pos), D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,   0, (UINT)IM_OFFSETOF(ImDrawVert, uv),  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR",    0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, (UINT)IM_OFFSETOF(ImDrawVert, col), D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};
		if (pd3dDevice.CreateInputLayout(local_layout, 3, vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), &m_pInputLayout) != S_OK)
		{
			vertexShaderBlob->Release();
			return false;
		}
		vertexShaderBlob->Release();

		// Create the constant buffer
		{
			D3D11_BUFFER_DESC desc;
			desc.ByteWidth = sizeof(VertexConstantBuffer);
			desc.Usage = D3D11_USAGE_DYNAMIC;
			desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			desc.MiscFlags = 0;
			pd3dDevice.CreateBuffer(&desc, NULL, &m_pVertexConstantBuffer);
		}

		// Create texture sampler
		{
			D3D11_SAMPLER_DESC desc;
			ZeroMemory(&desc, sizeof(desc));
			desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
			desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
			desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
			desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
			desc.MipLODBias = 0.f;
			desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
			desc.MinLOD = 0.f;
			desc.MaxLOD = 0.f;
			pd3dDevice.CreateSamplerState(&desc, &m_pFontSampler);
		}
	}

	// Create the pixel shader
	{
		static const char* pixelShader =
			"struct PS_INPUT\
            {\
            float4 pos : SV_POSITION;\
            float4 col : COLOR0;\
            float2 uv  : TEXCOORD0;\
            };\
            sampler sampler0;\
            Texture2D texture0;\
            \
            float4 main(PS_INPUT input) : SV_Target\
            {\
            float4 out_col = input.col * texture0.Sample(sampler0, input.uv); \
            return out_col; \
            }";

		ID3DBlob* pixelShaderBlob;
		if (FAILED(D3DCompile(pixelShader, strlen(pixelShader), NULL, NULL, NULL, "main", "ps_4_0", 0, 0, &pixelShaderBlob, NULL)))
			return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
		if (pd3dDevice.CreatePixelShader(pixelShaderBlob->GetBufferPointer(), pixelShaderBlob->GetBufferSize(), NULL, &m_pPixelShader) != S_OK)
		{
			pixelShaderBlob->Release();
			return false;
		}
		pixelShaderBlob->Release();
	}

	// Create the blending setup
	{
		D3D11_BLEND_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.AlphaToCoverageEnable = false;
		desc.RenderTarget[0].BlendEnable = true;
		desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
		desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		pd3dDevice.CreateBlendState(&desc, &m_pBlendState);
	}

	// Create the rasterizer state
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.FillMode = D3D11_FILL_SOLID;
		desc.CullMode = D3D11_CULL_NONE;
		desc.ScissorEnable = true;
		desc.DepthClipEnable = true;
		pd3dDevice.CreateRasterizerState(&desc, &m_pRasterizerState);
	}

	// Create depth-stencil State
	{
		D3D11_DEPTH_STENCIL_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.DepthEnable = false;
		desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
		desc.StencilEnable = false;
		desc.FrontFace.StencilFailOp = desc.FrontFace.StencilDepthFailOp = desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		desc.BackFace = desc.FrontFace;
		pd3dDevice.CreateDepthStencilState(&desc, &m_pDepthStencilState);
	}

	return true;
}

void ImGuiRendererD3D11::RT_SetupRenderState(ImRendDrawBuffer& buffer)
{
	CCryDeviceContextWrapper& ctx = gcpRendD3D->GetDeviceContext();

	// Setup viewport
	D3D11_VIEWPORT vp;
	memset(&vp, 0, sizeof(D3D11_VIEWPORT));
	vp.Width = buffer.displaySize.x;
	vp.Height = buffer.displaySize.y;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = vp.TopLeftY = 0;
	ctx.RSSetViewports(1, &vp);

	// Setup shader and vertex buffers
	unsigned int stride = sizeof(ImDrawVert);
	unsigned int offset = 0;
	ctx.IASetInputLayout(m_pInputLayout);
	ctx.IASetVertexBuffers(0, 1, &m_pVB, &stride, &offset);
	ctx.IASetIndexBuffer(m_pIB, sizeof(ImDrawIdx) == 2 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT, 0);
	ctx.IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	ctx.VSSetShader(m_pVertexShader, NULL, 0);
	ctx.VSSetConstantBuffers(0, 1, &m_pVertexConstantBuffer);
	ctx.PSSetShader(m_pPixelShader, NULL, 0);
	ctx.PSSetSamplers(0, 1, &m_pFontSampler);
	ctx.GSSetShader(NULL, NULL, 0);
	ctx.HSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
	ctx.DSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
	ctx.CSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..

	// Setup blend state
	const float blend_factor[4] = { 0.f, 0.f, 0.f, 0.f };
	ctx.OMSetBlendState(m_pBlendState, blend_factor, 0xffffffff);
	ctx.OMSetDepthStencilState(m_pDepthStencilState, 0);
	ctx.RSSetState(m_pRasterizerState);
}
