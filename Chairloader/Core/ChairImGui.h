#pragma once
#include <mutex>
#include <imgui.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryInput/BaseInput.h>
#include <ChairLoader/IChairloaderImGui.h>
#include <ChairLoader/IChairRender.h>
#include "ImGuiDoubleBuffering.h"

class ITexture;
class ImGuiRendererD3D11;

class ChairImGui
	: public IChairloaderImGui
	, private IChairRenderListener
	, private ISyncMainWithRenderListener
{
public:
	static ChairImGui& Get();

	ChairImGui();
	~ChairImGui();
	void InitSystem();
	void InitGame();
	void ShutdownGame();
	void ShutdownSystem();
	void UpdateBeforeSystem();
	void RenderEnd();

	bool HasExclusiveMouseInput();

private:
	static constexpr float MOUSE_WHEEL_DELTA = 120.0f;

	ImGuiContext* m_pMainContext = nullptr;
	_smart_ptr<ITexture> m_pFontAtlas = nullptr;
	void* m_hGameCursor = nullptr;
	bool m_ImGuiUsesMouse = false;
	ImGuiMouseCursor m_LastMouseCursor = ImGuiMouseCursor_None;

	// Double-buffering
	std::unique_ptr<ImGuiRendererD3D11> m_pRenderer;
	ImRendDrawBuffer m_DrawBufs[2];
	int m_iCurrentFillBuf = 0;
	bool m_bSwapOnSync = false;

	void InitBackend();
	void CreateFontsTexture();
	void UpdateMouseCursor();

	static ImGuiKey KeyIdToImGui(EKeyId keyId);

	// Render callbacks
	int GetChairRenderListenerFlags() override;
	void SyncMainWithRender() override;
	void RT_Present() override;

	// Hooks
	static void CBaseInput_PostInputEvent(CBaseInput *_this, const SInputEvent &event, bool bForce);

public:
	// IChairloaderImGui
	virtual bool CheckVersionAndDataLayout(const char* version_str, size_t sz_io, size_t sz_style,
		size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx) override;
	virtual ImGuiContext* GetContext() override;
	virtual void GetAllocatorFuncs(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data) override;
};
