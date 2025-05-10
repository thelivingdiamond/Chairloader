#pragma once
#include <mutex>
#include <imgui.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryInput/BaseInput.h>
#include <Chairloader/IChairloaderImGui.h>
#include <Chairloader/IChairRender.h>
#include "ImGuiDoubleBuffering.h"

class ITexture;
class ImGuiRendererD3D11;

class ChairImGui
	: public IChairloaderImGui
	, private IChairRenderListener
	, private ISyncMainWithRenderListener
{
public:
	ChairImGui(std::shared_ptr<IChairRender> pRender);
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
	static constexpr char FONT_CONFIG_PATH[] = "Libs/Chairloader/Fonts/Fonts.xml";
	static constexpr float DEFAULT_DPI = 96.0f;

	std::shared_ptr<IChairRender> m_pRender;
	ImGuiContext* m_pMainContext = nullptr;
	_smart_ptr<ITexture> m_pFontAtlas = nullptr;
	ImFont* m_Fonts[(int)EFont::FontCount] = {};
	void* m_hGameCursor = nullptr;
	bool m_ImGuiUsesMouse = false;
	ImGuiMouseCursor m_LastMouseCursor = ImGuiMouseCursor_None;
	float m_CV_scale = 0.0f;
	float m_flScale = 0.0f;

	// Double-buffering
	std::unique_ptr<ImGuiRendererD3D11> m_pRenderer;
	ImRendDrawBuffer m_DrawBufs[2];
	int m_iCurrentFillBuf = 0;
	bool m_bSwapOnSync = false;

	void InitBackend();
	void UpdateScale();
	void ReloadStyle();
	void ReloadFonts();
	void SetFont(EFont font, ImFont* fontPtr);
	void LoadFontConfig();
	std::map<std::string, ImFont*> ParseFontConfig();
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
	virtual ImFont* GetFont(EFont font) override;
};
