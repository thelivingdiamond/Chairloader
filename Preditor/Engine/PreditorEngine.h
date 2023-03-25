#pragma once
#include <Preditor/Engine/IPreditorEngine.h>
#include <Chairloader/PreditorAPI.h>
#include <Chairloader/IPreditorToChair.h>

struct IGameViewport;

namespace Engine
{

class PreditorImGui;
class SimulationController;

class PreditorEngine
	: public IPreditorEngine
	, public IPreditorToChair
{
public:
	void InitGame();
	void ShutdownGame();

	//! Processes keyboard events.
	//! @returns true if it was processed and doesn't need to be passed to the game.
	static bool HandleKeyboardMessage(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam);

	// IPreditorEngine
	void Load(const InitParams& params) override;
	bool Start(const InitParams& params) override;
	void Shutdown() override;
	void SetAppImGui() override;
	bool Update() override;
	ITexture* GetViewportTexture() override;
	IChairToPreditor* GetIChairToPreditor() override;
	Engine::ISimulationController* GetSimController() override;
	void SetGameInputEnabled(bool state) override;
	bool SetGameViewportRect(ImGuiID viewportId, Vec2i min, Vec2i max) override;
	void SetGameViewport(IGameViewport* pVP) override;

	// IPreditorToChair
	IChairloaderMod* GetMod() override;
	bool HandleInputEvent(const SInputEvent& event) override;
	bool HandleInputEventPreGame(const SInputEvent& event) override;

private:
	using DllHandle = std::unique_ptr<std::remove_pointer_t<HMODULE>, BOOL(*)(HMODULE)>;

	DllHandle m_hSystemMSWSock = DllHandle(nullptr, nullptr);
	DllHandle m_hPreyDll = DllHandle(nullptr, nullptr);
	DllHandle m_hChairDll = DllHandle(nullptr, nullptr);
	IChairToPreditor* m_pChair = nullptr;
	IGameStartup* m_pGameStartup = nullptr;
	bool m_bWasEverStarted = false;

	std::shared_ptr<PreditorImGui> m_pImGui;
	std::unique_ptr<SimulationController> m_pSimulationController;
	bool m_bGameInput = false;
	IGameViewport* m_pGameViewport = nullptr;

	void ApplyBasePatches();	//!< Applies patches used by both full and minimal engine.
	void ApplyFullPatches();	//!< Applies patches used by the full engine.
	void ApplyMinimalPatches();	//!< Applies patches used by the minimal engine.
	void InstallHooks();
};

} // namespace Engine

