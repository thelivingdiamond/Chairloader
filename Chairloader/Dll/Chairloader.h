#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IChairloaderCryRender.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderTools.h>

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

	//! Before CGame::Update
	void PreUpdate(bool haveFocus, unsigned int updateFlags);

	//! After CGame::Update
	void PostUpdate(bool haveFocus, unsigned int updateFlags);

	inline uintptr_t GetModuleBase() { return m_ModuleBase; }
	inline IGameFramework* GetFramework() override { return m_pFramework; }

private:
	FILE* m_pConsoleFile = nullptr;
	uintptr_t m_ModuleBase = 0;
	bool m_bEditorEnabled = false;
	std::unique_ptr<Internal::IChairloaderCore> m_pCore;
	std::unique_ptr<Internal::IChairloaderCryRender> m_pRender;
	std::unique_ptr<Internal::IChairloaderTools> m_pTools;

	IGameFramework* m_pFramework = nullptr;
	KeyNameMap m_KeyNames;

	void CreateConsole();
	void InitHooks();
	void InstallHooks();

    // init m_KeyNames. Call once
    void LoadKeyNames();
public:
	// IChairloader
    //TODO: reconsider where this map should go
    //! get key names map. Useful for config purposes
    const KeyNameMap &GetKeyNames() const override { return m_KeyNames; }
	ChairloaderGlobalEnvironment* GetChairloaderEnvironment() override;
	uintptr_t GetPreyDllBase() override;
	bool IsEditorEnabled() override;

	// IChairloaderDll
	Internal::IChairloaderCore* GetCore() override { return m_pCore.get(); }
	Internal::IChairloaderCryRender* GetCryRender() override { return m_pRender.get(); }
	Internal::IChairloaderTools* GetTools() override { return m_pTools.get(); }
	bool HandleKeyPress(const SInputEvent& event) override;
	void ReloadModDLLs() override;
};
