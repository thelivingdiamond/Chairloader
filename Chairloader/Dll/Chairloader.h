#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IChairloaderCryRender.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderTools.h>
#include "WinConsole.h"

#define PREY_DLL_NAME "PreyDll.dll"

class CSystem;

class Chairloader : public Internal::IChairloaderDll {
public:
	static void CreateInstance();
	static Chairloader* Get();

	//! Constructed just after loading PreyDll.dll, before any game code is run.
	Chairloader();

	//! Destroyed after CSystem::Shutdown
	~Chairloader();

	//! Called during CSystem::Init, before any engine modules.
	void InitSystem(CSystem* pSystem);

	//! Called after CGame::Init
	void InitGame(IGameFramework* pFramework);

	//! Called before CGame::Shutdown.
	void ShutdownGame();

	//! Called before CSystem::Shutdown.
	void ShutdownSystem();

	//! Check IChairloaderMod for when these are called.
	void UpdateBeforeSystem(unsigned updateFlags);
	void UpdateBeforePhysics();
	void MainUpdate(unsigned updateFlags);
	void LateUpdate(unsigned updateFlags);

	inline uintptr_t GetModuleBase() { return m_ModuleBase; }
	inline IGameFramework* GetFramework() override { return m_pFramework; }

private:
	WinConsole m_WinConsole;
	uintptr_t m_ModuleBase = 0;
	bool m_bEditorEnabled = false;
	std::unique_ptr<Internal::IChairloaderCore> m_pCore;
	std::unique_ptr<Internal::IChairloaderCryRender> m_pRender;
	std::unique_ptr<Internal::IChairloaderTools> m_pTools;
	unsigned m_SavedUpdateFlags = 0;

	IGameFramework* m_pFramework = nullptr;
	KeyNameMap m_KeyNames;

	void InitHooks();
	void InstallHooks();

    // init m_KeyNames. Call once
    void LoadKeyNames();
public:
	// IChairloader
	void GetModSdkVersion(int& major, int& minor, int& patch) override;
    //TODO: reconsider where this map should go
    //! get key names map. Useful for config purposes
    const KeyNameMap &GetKeyNames() const override { return m_KeyNames; }
	ChairloaderGlobalEnvironment* GetChairloaderEnvironment() override;
	uintptr_t GetPreyDllBase() override;
	std::unique_ptr<IChairLogger> CreateLogger() override;
	bool IsEditorEnabled() override;

	// IChairloaderDll
	Internal::IChairloaderCore* GetCore() override { return m_pCore.get(); }
	Internal::IChairloaderCryRender* GetCryRender() override { return m_pRender.get(); }
	Internal::IChairloaderTools* GetTools() override { return m_pTools.get(); }
	bool HandleKeyPress(const SInputEvent& event) override;
	void ReloadModDLLs() override;
};
