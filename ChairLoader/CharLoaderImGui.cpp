#include "pch.h"
#include "CharLoaderImGui.h"
#include "ChairloaderUtils.h"
#include "mem.h"
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryRenderer/Renderer.h>
#include <Prey/CryRenderer/Texture.h>

ChairLoaderImGui *ChairLoaderImGui::m_pInstance = nullptr;

ChairLoaderImGui::ChairLoaderImGui() {
	m_pInstance = this;
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	ImGui::StyleColorsDark();
	InitBackend();

	// Hook functions
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	m_hookCBaseInputPostInputEvent = chairloader->internalPreyFunctions->CBaseInputF->PostInputEvent;
	DetourAttach(&(LPVOID &)m_hookCBaseInputPostInputEvent, (PBYTE)CBaseInput_PostInputEvent);
	HookPresent();
	DetourTransactionCommit();
}

ChairLoaderImGui::~ChairLoaderImGui() {
	m_pFontAtlas->Release();
	m_pFontAtlas = nullptr;
}

void ChairLoaderImGui::PreUpdate(bool haveFocus) {
	ImGuiIO &io = ImGui::GetIO();

	// Setup display size (every frame to accommodate for window resizing)
	int x, y, width, height;
	chairloader->preyEnvironmentPointers->pRenderer->GetViewport(x, y, width, height);
	io.DisplaySize = ImVec2(width, height);

	// Setup time step
	io.DeltaTime = chairloader->preyEnvironmentPointers->pTimer->GetRealFrameTime();

	// Update mouse
	if (haveFocus && io.WantSetMousePos)
		chairloader->preyEnvironmentPointers->pHardwareMouse->SetHardwareMouseClientPosition(io.MousePos.x, io.MousePos.y);

	ImGui::NewFrame();
}

void ChairLoaderImGui::PostUpdate() {
	ImGui::Render();
	SubmitRenderData();
}

void ChairLoaderImGui::InitBackend() {
	ImGuiIO &io = ImGui::GetIO();
	io.BackendPlatformUserData = this;
	io.BackendPlatformName = "Prey (CryEngine)";
	io.BackendRendererName = "D3D11";
	//io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;       // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
	CreateFontsTexture();
}

void ChairLoaderImGui::CreateFontsTexture() {
	assert(!m_pFontAtlas);

	// Create texture
	ImGuiIO &io = ImGui::GetIO();
	unsigned char *pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
	m_pFontAtlas = chairloader->preyEnvironmentPointers->pRenderer->CreateTexture(
		"ImGui Font Atlas", width, height, 1, pixels, eTF_R8G8B8A8, FT_TEX_FONT
	);

	// Store our identifier
	io.Fonts->SetTexID((ImTextureID)m_pFontAtlas);
}

void ChairLoaderImGui::HookPresent() {
	CD3D9Renderer *pRenderer = static_cast<CD3D9Renderer *>(chairloader->preyEnvironmentPointers->pRenderer);
	auto pSwapChain = mem::OffsetInStruct<IDXGISwapChain *>(pRenderer, CD3D9Renderer::OFFSET_SWAP_CHAIN);

	DWORD_PTR *pSwapChainVtable = nullptr;
	pSwapChainVtable = (DWORD_PTR *)pSwapChain;
	pSwapChainVtable = (DWORD_PTR *)pSwapChainVtable[0];
	m_hookPresent = (IDXGISwapChain_Present)(DWORD_PTR)pSwapChainVtable[8];
	DetourAttach(&(LPVOID &)m_hookPresent, (PBYTE)Present);
}

void ChairLoaderImGui::SubmitRenderData() {
	RenderLists *data = nullptr;

	{
		// Swap buffers
		std::unique_lock lock(m_CurrentBufferMutex);
		data = &m_RenderData[m_CurrentBuffer];
		m_CurrentBuffer = !m_CurrentBuffer;
	}

	std::unique_lock lock(data->mutex);
	data->Clear();
	const ImDrawData &imDrawData = *ImGui::GetDrawData();

	data->displayPos = imDrawData.DisplayPos;
	data->displaySize = imDrawData.DisplaySize;
	data->framebufferScale = imDrawData.FramebufferScale;
	data->drawLists.reserve(imDrawData.CmdListsCount);

	for (int n = 0; n < imDrawData.CmdListsCount; n++)
	{
		const ImDrawList &imDrawList = *imDrawData.CmdLists[n];
		DrawList &drawList = data->drawLists.emplace_back();
		drawList.flags = imDrawList.Flags;

		drawList.cmdOffset = data->drawCmds.size();
		data->drawCmds.insert(data->drawCmds.end(), imDrawList.CmdBuffer.begin(), imDrawList.CmdBuffer.end());
		drawList.cmdCount = data->drawCmds.size() - drawList.cmdOffset;

		drawList.idxOffset = data->idxBuffer.size();
		data->idxBuffer.insert(data->idxBuffer.end(), imDrawList.IdxBuffer.begin(), imDrawList.IdxBuffer.end());
		drawList.idxCount = data->idxBuffer.size() - drawList.idxOffset;

		drawList.vtxOffset = data->vtxBuffer.size();
		data->vtxBuffer.insert(data->vtxBuffer.end(), imDrawList.VtxBuffer.begin(), imDrawList.VtxBuffer.end());
		drawList.vtxCount = data->vtxBuffer.size() - drawList.vtxOffset;
	}
}

ImGuiKey ChairLoaderImGui::KeyIdToImGui(EKeyId keyId) {
	switch (keyId)
	{
	case eKI_Tab: return ImGuiKey_Tab;
	case eKI_Left: return ImGuiKey_LeftArrow;
	case eKI_Right: return ImGuiKey_RightArrow;
	case eKI_Up: return ImGuiKey_UpArrow;
	case eKI_Down: return ImGuiKey_DownArrow;
	case eKI_PgUp: return ImGuiKey_PageUp;
	case eKI_PgDn: return ImGuiKey_PageDown;
	case eKI_Home: return ImGuiKey_Home;
	case eKI_End: return ImGuiKey_End;
	case eKI_Insert: return ImGuiKey_Insert;
	case eKI_Delete: return ImGuiKey_Delete;
	case eKI_Backspace: return ImGuiKey_Backspace;
	case eKI_Space: return ImGuiKey_Space;
	case eKI_Enter: return ImGuiKey_Enter;
	case eKI_Escape: return ImGuiKey_Escape;
	case eKI_Apostrophe: return ImGuiKey_Apostrophe;
	case eKI_Comma: return ImGuiKey_Comma;
	case eKI_Minus: return ImGuiKey_Minus;
	case eKI_Period: return ImGuiKey_Period;
	case eKI_Slash: return ImGuiKey_Slash;
	case eKI_Semicolon: return ImGuiKey_Semicolon;
	case eKI_Equals: return ImGuiKey_Equal;
	case eKI_LBracket: return ImGuiKey_LeftBracket;
	case eKI_Backslash: return ImGuiKey_Backslash;
	case eKI_RBracket: return ImGuiKey_RightBracket;
	case eKI_Tilde: return ImGuiKey_GraveAccent;
	case eKI_CapsLock: return ImGuiKey_CapsLock;
	case eKI_ScrollLock: return ImGuiKey_ScrollLock;
	case eKI_NumLock: return ImGuiKey_NumLock;
	case eKI_Print: return ImGuiKey_PrintScreen;
	case eKI_Pause: return ImGuiKey_Pause;
	case eKI_NP_0: return ImGuiKey_Keypad0;
	case eKI_NP_1: return ImGuiKey_Keypad1;
	case eKI_NP_2: return ImGuiKey_Keypad2;
	case eKI_NP_3: return ImGuiKey_Keypad3;
	case eKI_NP_4: return ImGuiKey_Keypad4;
	case eKI_NP_5: return ImGuiKey_Keypad5;
	case eKI_NP_6: return ImGuiKey_Keypad6;
	case eKI_NP_7: return ImGuiKey_Keypad7;
	case eKI_NP_8: return ImGuiKey_Keypad8;
	case eKI_NP_9: return ImGuiKey_Keypad9;
	case eKI_NP_Period: return ImGuiKey_KeypadDecimal;
	case eKI_NP_Divide: return ImGuiKey_KeypadDivide;
	case eKI_NP_Multiply: return ImGuiKey_KeypadMultiply;
	case eKI_NP_Substract: return ImGuiKey_KeypadSubtract;
	case eKI_NP_Add: return ImGuiKey_KeypadAdd;
	case eKI_NP_Enter: return ImGuiKey_KeypadEnter;
	case eKI_LShift: return ImGuiKey_LeftShift;
	case eKI_LCtrl: return ImGuiKey_LeftCtrl;
	case eKI_LAlt: return ImGuiKey_LeftAlt;
	case eKI_LWin: return ImGuiKey_LeftSuper;
	case eKI_RShift: return ImGuiKey_RightShift;
	case eKI_RCtrl: return ImGuiKey_RightCtrl;
	case eKI_RAlt: return ImGuiKey_RightAlt;
	case eKI_RWin: return ImGuiKey_RightSuper;
	//case VK_APPS: return ImGuiKey_Menu;
	case eKI_0: return ImGuiKey_0;
	case eKI_1: return ImGuiKey_1;
	case eKI_2: return ImGuiKey_2;
	case eKI_3: return ImGuiKey_3;
	case eKI_4: return ImGuiKey_4;
	case eKI_5: return ImGuiKey_5;
	case eKI_6: return ImGuiKey_6;
	case eKI_7: return ImGuiKey_7;
	case eKI_8: return ImGuiKey_8;
	case eKI_9: return ImGuiKey_9;
	case eKI_A: return ImGuiKey_A;
	case eKI_B: return ImGuiKey_B;
	case eKI_C: return ImGuiKey_C;
	case eKI_D: return ImGuiKey_D;
	case eKI_E: return ImGuiKey_E;
	case eKI_F: return ImGuiKey_F;
	case eKI_G: return ImGuiKey_G;
	case eKI_H: return ImGuiKey_H;
	case eKI_I: return ImGuiKey_I;
	case eKI_J: return ImGuiKey_J;
	case eKI_K: return ImGuiKey_K;
	case eKI_L: return ImGuiKey_L;
	case eKI_M: return ImGuiKey_M;
	case eKI_N: return ImGuiKey_N;
	case eKI_O: return ImGuiKey_O;
	case eKI_P: return ImGuiKey_P;
	case eKI_Q: return ImGuiKey_Q;
	case eKI_R: return ImGuiKey_R;
	case eKI_S: return ImGuiKey_S;
	case eKI_T: return ImGuiKey_T;
	case eKI_U: return ImGuiKey_U;
	case eKI_V: return ImGuiKey_V;
	case eKI_W: return ImGuiKey_W;
	case eKI_X: return ImGuiKey_X;
	case eKI_Y: return ImGuiKey_Y;
	case eKI_Z: return ImGuiKey_Z;
	case eKI_F1: return ImGuiKey_F1;
	case eKI_F2: return ImGuiKey_F2;
	case eKI_F3: return ImGuiKey_F3;
	case eKI_F4: return ImGuiKey_F4;
	case eKI_F5: return ImGuiKey_F5;
	case eKI_F6: return ImGuiKey_F6;
	case eKI_F7: return ImGuiKey_F7;
	case eKI_F8: return ImGuiKey_F8;
	case eKI_F9: return ImGuiKey_F9;
	case eKI_F10: return ImGuiKey_F10;
	case eKI_F11: return ImGuiKey_F11;
	case eKI_F12: return ImGuiKey_F12;
	default: return ImGuiKey_None;
	}
}

bool ChairLoaderImGui::RT_Initialize() {
	RenderThreadData &data = m_pInstance->m_RTData;
	data.bIsInitialized = true;

	CD3D9Renderer *pRenderer = static_cast<CD3D9Renderer *>(chairloader->preyEnvironmentPointers->pRenderer);
	const DeviceInfo &devInfo = mem::OffsetInStruct<DeviceInfo>(pRenderer, CD3D9Renderer::OFFSET_DEV_INFO);

	data.pd3dDevice = devInfo.m_pDevice;
	data.pd3dDeviceContext = devInfo.m_pContext;
	data.pFactory = devInfo.m_pFactory;

	// Create the vertex shader
	{
		static const char *vertexShader =
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

		ID3DBlob *vertexShaderBlob;
		if (FAILED(D3DCompile(vertexShader, strlen(vertexShader), NULL, NULL, NULL, "main", "vs_4_0", 0, 0, &vertexShaderBlob, NULL)))
			return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
		if (data.pd3dDevice->CreateVertexShader(vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), NULL, &data.pVertexShader) != S_OK)
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
		if (data.pd3dDevice->CreateInputLayout(local_layout, 3, vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), &data.pInputLayout) != S_OK)
		{
			vertexShaderBlob->Release();
			return false;
		}
		vertexShaderBlob->Release();

		// Create the constant buffer
		{
			D3D11_BUFFER_DESC desc;
			desc.ByteWidth = sizeof(VERTEX_CONSTANT_BUFFER);
			desc.Usage = D3D11_USAGE_DYNAMIC;
			desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			desc.MiscFlags = 0;
			data.pd3dDevice->CreateBuffer(&desc, NULL, &data.pVertexConstantBuffer);
		}
	}

	// Create the pixel shader
	{
		static const char *pixelShader =
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

		ID3DBlob *pixelShaderBlob;
		if (FAILED(D3DCompile(pixelShader, strlen(pixelShader), NULL, NULL, NULL, "main", "ps_4_0", 0, 0, &pixelShaderBlob, NULL)))
			return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
		if (data.pd3dDevice->CreatePixelShader(pixelShaderBlob->GetBufferPointer(), pixelShaderBlob->GetBufferSize(), NULL, &data.pPixelShader) != S_OK)
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
		data.pd3dDevice->CreateBlendState(&desc, &data.pBlendState);
	}

	// Create the rasterizer state
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.FillMode = D3D11_FILL_SOLID;
		desc.CullMode = D3D11_CULL_NONE;
		desc.ScissorEnable = true;
		desc.DepthClipEnable = true;
		data.pd3dDevice->CreateRasterizerState(&desc, &data.pRasterizerState);
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
		data.pd3dDevice->CreateDepthStencilState(&desc, &data.pDepthStencilState);
	}

	return true;
}

void ChairLoaderImGui::RT_Render() {
	// Based on ImGui_ImplDX11_RenderDrawData
	RenderThreadData &data = m_pInstance->m_RTData;
	RenderLists *list = nullptr;

	{
		std::unique_lock lock(m_CurrentBufferMutex);
		list = &m_RenderData[m_CurrentBuffer];
	}

	// Avoid rendering when minimized
	if (list->displaySize.x <= 0.0f || list->displaySize.y <= 0.0f)
		return;

	ID3D11DeviceContext *ctx = data.pd3dDeviceContext;

	// Create and grow vertex/index buffers if needed
	if (!data.pVB || data.vertexBufferSize < list->vtxBuffer.size())
	{
		if (data.pVB) { data.pVB->Release(); data.pVB = NULL; }
		data.vertexBufferSize = list->vtxBuffer.size() + BUFFER_SIZE_INCREMENT;
		D3D11_BUFFER_DESC desc;
		memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = data.vertexBufferSize * sizeof(ImDrawVert);
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		desc.MiscFlags = 0;
		if (data.pd3dDevice->CreateBuffer(&desc, NULL, &data.pVB) < 0)
			return;
	}
	if (!data.pIB || data.indexBufferSize < list->idxBuffer.size())
	{
		if (data.pIB) { data.pIB->Release(); data.pIB = NULL; }
		data.indexBufferSize = list->idxBuffer.size() + 2 * BUFFER_SIZE_INCREMENT;
		D3D11_BUFFER_DESC desc;
		memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = data.indexBufferSize * sizeof(ImDrawIdx);
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		if (data.pd3dDevice->CreateBuffer(&desc, NULL, &data.pIB) < 0)
			return;
	}

	// Upload vertex/index data into a single contiguous GPU buffer
	D3D11_MAPPED_SUBRESOURCE vtx_resource, idx_resource;
	if (ctx->Map(data.pVB, 0, D3D11_MAP_WRITE_DISCARD, 0, &vtx_resource) != S_OK)
		return;
	if (ctx->Map(data.pIB, 0, D3D11_MAP_WRITE_DISCARD, 0, &idx_resource) != S_OK)
		return;
	ImDrawVert *vtx_dst = (ImDrawVert *)vtx_resource.pData;
	ImDrawIdx *idx_dst = (ImDrawIdx *)idx_resource.pData;
	memcpy(vtx_dst, list->vtxBuffer.data(), list->vtxBuffer.size() * sizeof(ImDrawVert));
	memcpy(idx_dst, list->idxBuffer.data(), list->idxBuffer.size() * sizeof(ImDrawIdx));
	ctx->Unmap(data.pVB, 0);
	ctx->Unmap(data.pIB, 0);

	// Setup orthographic projection matrix into our constant buffer
	// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
	{
		D3D11_MAPPED_SUBRESOURCE mapped_resource;
		if (ctx->Map(data.pVertexConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped_resource) != S_OK)
			return;
		VERTEX_CONSTANT_BUFFER *constant_buffer = (VERTEX_CONSTANT_BUFFER *)mapped_resource.pData;
		float L = list->displayPos.x;
		float R = list->displayPos.x + list->displaySize.x;
		float T = list->displayPos.y;
		float B = list->displayPos.y + list->displaySize.y;
		float mvp[4][4] =
		{
			{ 2.0f / (R - L),   0.0f,           0.0f,       0.0f },
			{ 0.0f,         2.0f / (T - B),     0.0f,       0.0f },
			{ 0.0f,         0.0f,           0.5f,       0.0f },
			{ (R + L) / (L - R),  (T + B) / (B - T),    0.5f,       1.0f },
		};
		memcpy(&constant_buffer->mvp, mvp, sizeof(mvp));
		ctx->Unmap(data.pVertexConstantBuffer, 0);
	}

	// Backup DX state that will be modified to restore it afterwards (unfortunately this is very ugly looking and verbose. Close your eyes!)
	struct BACKUP_DX11_STATE
	{
		UINT                        ScissorRectsCount, ViewportsCount;
		D3D11_RECT                  ScissorRects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
		D3D11_VIEWPORT              Viewports[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
		ID3D11RasterizerState *RS;
		ID3D11BlendState *BlendState;
		FLOAT                       BlendFactor[4];
		UINT                        SampleMask;
		UINT                        StencilRef;
		ID3D11DepthStencilState *DepthStencilState;
		ID3D11ShaderResourceView *PSShaderResource;
		ID3D11SamplerState *PSSampler;
		ID3D11PixelShader *PS;
		ID3D11VertexShader *VS;
		ID3D11GeometryShader *GS;
		UINT                        PSInstancesCount, VSInstancesCount, GSInstancesCount;
		ID3D11ClassInstance *PSInstances[256], *VSInstances[256], *GSInstances[256];   // 256 is max according to PSSetShader documentation
		D3D11_PRIMITIVE_TOPOLOGY    PrimitiveTopology;
		ID3D11Buffer *IndexBuffer, *VertexBuffer, *VSConstantBuffer;
		UINT                        IndexBufferOffset, VertexBufferStride, VertexBufferOffset;
		DXGI_FORMAT                 IndexBufferFormat;
		ID3D11InputLayout *InputLayout;
	};
	BACKUP_DX11_STATE old = {};
	old.ScissorRectsCount = old.ViewportsCount = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
	ctx->RSGetScissorRects(&old.ScissorRectsCount, old.ScissorRects);
	ctx->RSGetViewports(&old.ViewportsCount, old.Viewports);
	ctx->RSGetState(&old.RS);
	ctx->OMGetBlendState(&old.BlendState, old.BlendFactor, &old.SampleMask);
	ctx->OMGetDepthStencilState(&old.DepthStencilState, &old.StencilRef);
	ctx->PSGetShaderResources(0, 1, &old.PSShaderResource);
	ctx->PSGetSamplers(0, 1, &old.PSSampler);
	old.PSInstancesCount = old.VSInstancesCount = old.GSInstancesCount = 256;
	ctx->PSGetShader(&old.PS, old.PSInstances, &old.PSInstancesCount);
	ctx->VSGetShader(&old.VS, old.VSInstances, &old.VSInstancesCount);
	ctx->VSGetConstantBuffers(0, 1, &old.VSConstantBuffer);
	ctx->GSGetShader(&old.GS, old.GSInstances, &old.GSInstancesCount);

	ctx->IAGetPrimitiveTopology(&old.PrimitiveTopology);
	ctx->IAGetIndexBuffer(&old.IndexBuffer, &old.IndexBufferFormat, &old.IndexBufferOffset);
	ctx->IAGetVertexBuffers(0, 1, &old.VertexBuffer, &old.VertexBufferStride, &old.VertexBufferOffset);
	ctx->IAGetInputLayout(&old.InputLayout);

	// Setup desired DX state
	RT_SetupRenderState(list, ctx);

	// Render command lists
	ImVec2 clip_off = list->displayPos;
	for (int n = 0; n < list->drawLists.size(); n++)
	{
		const DrawList &drawList = list->drawLists[n];

		for (int cmd_i = 0; cmd_i < drawList.cmdCount; cmd_i++)
		{
			const ImDrawCmd &cmd = list->drawCmds[drawList.cmdOffset + cmd_i];
			if (cmd.UserCallback != NULL)
			{
				// User callback, registered via ImDrawList::AddCallback()
				// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
				if (cmd.UserCallback == ImDrawCallback_ResetRenderState)
					RT_SetupRenderState(list, ctx);
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
				ctx->RSSetScissorRects(1, &r);

				// Bind texture, Draw
				ITexture *pITexture = (ITexture *)cmd.GetTexID();
				CTexture *pTexture = static_cast<CTexture *>(pITexture);
				auto pView = mem::OffsetInStruct<ID3D11ShaderResourceView *>(pTexture, CTexture::OFFSET_SHADER_RESOURCE);
				ctx->PSSetShaderResources(0, 1, &pView);
				ctx->DrawIndexed(cmd.ElemCount, cmd.IdxOffset + drawList.idxOffset, cmd.VtxOffset + drawList.vtxOffset);
			}
		}
	}

	// Restore modified DX state
	ctx->RSSetScissorRects(old.ScissorRectsCount, old.ScissorRects);
	ctx->RSSetViewports(old.ViewportsCount, old.Viewports);
	ctx->RSSetState(old.RS); if (old.RS) old.RS->Release();
	ctx->OMSetBlendState(old.BlendState, old.BlendFactor, old.SampleMask); if (old.BlendState) old.BlendState->Release();
	ctx->OMSetDepthStencilState(old.DepthStencilState, old.StencilRef); if (old.DepthStencilState) old.DepthStencilState->Release();
	ctx->PSSetShaderResources(0, 1, &old.PSShaderResource); if (old.PSShaderResource) old.PSShaderResource->Release();
	ctx->PSSetSamplers(0, 1, &old.PSSampler); if (old.PSSampler) old.PSSampler->Release();
	ctx->PSSetShader(old.PS, old.PSInstances, old.PSInstancesCount); if (old.PS) old.PS->Release();
	for (UINT i = 0; i < old.PSInstancesCount; i++) if (old.PSInstances[i]) old.PSInstances[i]->Release();
	ctx->VSSetShader(old.VS, old.VSInstances, old.VSInstancesCount); if (old.VS) old.VS->Release();
	ctx->VSSetConstantBuffers(0, 1, &old.VSConstantBuffer); if (old.VSConstantBuffer) old.VSConstantBuffer->Release();
	ctx->GSSetShader(old.GS, old.GSInstances, old.GSInstancesCount); if (old.GS) old.GS->Release();
	for (UINT i = 0; i < old.VSInstancesCount; i++) if (old.VSInstances[i]) old.VSInstances[i]->Release();
	ctx->IASetPrimitiveTopology(old.PrimitiveTopology);
	ctx->IASetIndexBuffer(old.IndexBuffer, old.IndexBufferFormat, old.IndexBufferOffset); if (old.IndexBuffer) old.IndexBuffer->Release();
	ctx->IASetVertexBuffers(0, 1, &old.VertexBuffer, &old.VertexBufferStride, &old.VertexBufferOffset); if (old.VertexBuffer) old.VertexBuffer->Release();
	ctx->IASetInputLayout(old.InputLayout); if (old.InputLayout) old.InputLayout->Release();
}

void ChairLoaderImGui::RT_SetupRenderState(RenderLists *list, ID3D11DeviceContext *ctx) {
	RenderThreadData &data = m_pInstance->m_RTData;

	// Setup viewport
	D3D11_VIEWPORT vp;
	memset(&vp, 0, sizeof(D3D11_VIEWPORT));
	vp.Width = list->displaySize.x;
	vp.Height = list->displaySize.y;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = vp.TopLeftY = 0;
	ctx->RSSetViewports(1, &vp);

	// Setup shader and vertex buffers
	unsigned int stride = sizeof(ImDrawVert);
	unsigned int offset = 0;
	ctx->IASetInputLayout(data.pInputLayout);
	ctx->IASetVertexBuffers(0, 1, &data.pVB, &stride, &offset);
	ctx->IASetIndexBuffer(data.pIB, sizeof(ImDrawIdx) == 2 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT, 0);
	ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	ctx->VSSetShader(data.pVertexShader, NULL, 0);
	ctx->VSSetConstantBuffers(0, 1, &data.pVertexConstantBuffer);
	ctx->PSSetShader(data.pPixelShader, NULL, 0);
	ctx->PSSetSamplers(0, 1, &data.pFontSampler);
	ctx->GSSetShader(NULL, NULL, 0);
	ctx->HSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
	ctx->DSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
	ctx->CSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..

	// Setup blend state
	const float blend_factor[4] = { 0.f, 0.f, 0.f, 0.f };
	ctx->OMSetBlendState(data.pBlendState, blend_factor, 0xffffffff);
	ctx->OMSetDepthStencilState(data.pDepthStencilState, 0);
	ctx->RSSetState(data.pRasterizerState);
}

void ChairLoaderImGui::CBaseInput_PostInputEvent(CBaseInput *_this, const SInputEvent &event, bool bForce) {
	ImGuiIO &io = ImGui::GetIO();

	if (event.deviceType == eIDT_Keyboard) {
		// Update modifiers
		io.AddKeyEvent(ImGuiKey_ModCtrl, event.modifiers & eMM_Ctrl);
		io.AddKeyEvent(ImGuiKey_ModShift, event.modifiers & eMM_Shift);
		//io.AddKeyEvent(ImGuiKey_ModAlt, IsVkDown(VK_MENU));
		io.AddKeyEvent(ImGuiKey_ModSuper, event.modifiers & eMM_Win);

		// Send key events
		ImGuiKey key = KeyIdToImGui(event.keyId);
		if (key != ImGuiKey_None) {
			io.AddKeyEvent(key, event.value != 0.0f);
		}

		if (event.inputChar > 0 && event.inputChar < 0x10000 && event.state == eIS_UI) {
			io.AddInputCharacterUTF16(event.inputChar);
		}
	} else if (event.deviceType == eIDT_Mouse) {
		switch (event.keyId) {
		case eKI_Mouse1:
		case eKI_Mouse2:
		case eKI_Mouse3: {
			io.AddMouseButtonEvent(event.keyId - eKI_Mouse1, event.state == eIS_Down);
			break;
		}
		case eKI_MouseWheelUp:
		case eKI_MouseWheelDown: {
			io.AddMouseWheelEvent(0.0f, event.value / MOUSE_WHEEL_DELTA);
			break;
		}
		case eKI_MouseX:
		case eKI_MouseY:
		case eKI_MouseXAbsolute: 
		case eKI_MouseYAbsolute: {
			float x, y;
			chairloader->preyEnvironmentPointers->pHardwareMouse->GetHardwareMouseClientPosition(x, y);
			io.AddMousePosEvent(x, y);
			break;
		}
		}
	}

	//if (event.deviceType == eIDT_Mouse)
	//    printf("%d, %d - %s, %d, %f\n", event.deviceType, event.keyId, event.keyName.key, event.state, event.value);
	// if(!io.WantCaptureKeyboard){
	if ((event.deviceType == eIDT_Keyboard) && io.WantTextInput)
		return;
	m_pInstance->m_hookCBaseInputPostInputEvent(_this, event, bForce);
	// }
}

HRESULT ChairLoaderImGui::Present(IDXGISwapChain *pChain, UINT SyncInterval, UINT Flags) {
	RenderThreadData &data = m_pInstance->m_RTData;

	if (!data.bIsInitialized) {
		if (m_pInstance->RT_Initialize()) {
			data.bIsReady = true;
		} else {
			data.bIsReady = false;
			printf("ImGui RT: Failed to initialize. God help you.\n");
		}
	}

	if (data.bIsReady)
		m_pInstance->RT_Render();

	return m_pInstance->m_hookPresent(pChain, SyncInterval, Flags);
}
