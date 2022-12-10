#pragma once
#include <Preditor/IPreditorEngine.h>
#include <Chairloader/PreditorAPI.h>
#include <Chairloader/IPreditorToChair.h>

class PreditorEngine
	: public IPreditorEngine
	, public IPreditorToChair
{
public:
	// IPreditorEngine
	void Load(const InitParams& params) override;
	bool Start(const InitParams& params) override;
	void Shutdown() override;
	void Update() override;

	// IPreditorToChair
	IChairloaderMod* GetMod() override;

private:
	using DllHandle = std::unique_ptr<std::remove_pointer_t<HMODULE>, BOOL(*)(HMODULE)>;

	DllHandle m_hSystemMSWSock = DllHandle(nullptr, nullptr);
	DllHandle m_hPreyDll = DllHandle(nullptr, nullptr);
	DllHandle m_hChairDll = DllHandle(nullptr, nullptr);
	IChairToPreditor* m_pChair = nullptr;
	IGameStartup* m_pGameStartup = nullptr;
	bool m_bWasEverStarted = false;

	void ApplyBasePatches();	//!< Applies patches used by both full and minimal engine.
	void ApplyFullPatches();	//!< Applies patches used by the full engine.
	void ApplyMinimalPatches();	//!< Applies patches used by the minimal engine.
	void InstallHooks();
};
