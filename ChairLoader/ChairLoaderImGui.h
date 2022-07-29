#pragma once
#include <mutex>
#include <imgui.h>
#include <Prey/CryInput/BaseInput.h>
#include "LibD3D11.h"

class ITexture;

class ChairLoaderImGui {
public:
	static void InitHooks();
	ChairLoaderImGui();
	~ChairLoaderImGui();
	void PreUpdate(bool haveFocus);
	void PostUpdate();
	inline std::thread::id GetRenderThreadId() { return m_RenderThreadId; }

	static bool HasExclusiveMouseInput();

private:
	static constexpr int BUFFER_SIZE_INCREMENT = 5000;
	static constexpr float MOUSE_WHEEL_DELTA = 120.0f;

	ITexture *m_pFontAtlas = nullptr;
	HCURSOR m_hGameCursor = nullptr;
	std::thread::id m_RenderThreadId;
	bool m_ImGuiUsesMouse = false;
	ImGuiMouseCursor m_LastMouseCursor = ImGuiMouseCursor_None;

	void InitBackend();
	void CreateFontsTexture();
	void HookPresent();
	void UpdateMouseCursor();
	void SubmitRenderData();

	static ImGuiKey KeyIdToImGui(EKeyId keyId);

	// Shared
	struct DrawList {
		ImDrawListFlags flags;
		int cmdOffset;
		int cmdCount;
		int idxOffset;
		int idxCount;
		int vtxOffset;
		int vtxCount;
	};

	struct RenderLists {
		ImVec2 displayPos;
		ImVec2 displaySize;
		ImVec2 framebufferScale;
		std::vector<DrawList> drawLists;
		std::vector<ImDrawCmd> drawCmds;
		std::vector<ImDrawIdx> idxBuffer;
		std::vector<ImDrawVert> vtxBuffer;
		ImDrawData a;
		std::mutex mutex;

		void Clear() {
			drawLists.clear();
			drawCmds.clear();
			idxBuffer.clear();
			vtxBuffer.clear();
		}
	};

	int m_CurrentBuffer = 0;
	RenderLists m_RenderData[2];
	std::mutex m_CurrentBufferMutex;

	// Render thread
	struct RenderThreadData {
		bool bIsInitialized = false;
		bool bIsReady = false;
		ID3D11Device *pd3dDevice = nullptr;
		ID3D11DeviceContext *pd3dDeviceContext = nullptr;
		IDXGIFactory *pFactory = nullptr;
		ID3D11Buffer *pVB = nullptr;
		ID3D11Buffer *pIB = nullptr;
		ID3D11VertexShader *pVertexShader = nullptr;
		ID3D11InputLayout *pInputLayout = nullptr;
		ID3D11Buffer *pVertexConstantBuffer = nullptr;
		ID3D11PixelShader *pPixelShader = nullptr;
		ID3D11SamplerState *pFontSampler = nullptr;
		ID3D11ShaderResourceView *pFontTextureView = nullptr;
		ID3D11RasterizerState *pRasterizerState = nullptr;
		ID3D11BlendState *pBlendState = nullptr;
		ID3D11DepthStencilState *pDepthStencilState = nullptr;
		int vertexBufferSize = BUFFER_SIZE_INCREMENT;
		int indexBufferSize = BUFFER_SIZE_INCREMENT;
	};

	struct VERTEX_CONSTANT_BUFFER {
		float   mvp[4][4];
	};

	RenderThreadData m_RTData;
	bool RT_Initialize();
	void RT_Render();
	void RT_SetupRenderState(RenderLists *list, ID3D11DeviceContext *ctx);

	// Hooks
	static void CBaseInput_PostInputEvent(CBaseInput *_this, const SInputEvent &event, bool bForce);

	using IDXGISwapChain_Present = HRESULT (*)(IDXGISwapChain *pChain, UINT SyncInterval, UINT Flags);
	IDXGISwapChain_Present m_hookPresent;
	static HRESULT Present(IDXGISwapChain *pChain, UINT SyncInterval, UINT Flags);

	static ChairLoaderImGui *m_pInstance;
};
