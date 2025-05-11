#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IChairloaderCryRender.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderPatches.h>
#include <Chairloader/IChairloaderTools.h>
#include <Chairloader/PreditorAPI.h>
#include <Chairloader/IChairToPreditor.h>
#include "WinConsole.h"
#include "Chairloader/IChairServiceProvider.h"

#define PREY_DLL_NAME "PreyDll.dll"

class CSystem;

class Chairloader
	: public Internal::IChairloaderDll
	, public IChairToPreditor
{
public:
	static void CreateInstance(void* hThisDll);
	static Chairloader* Get();

	//! Constructed just after loading PreyDll.dll, before any game code is run.
	Chairloader(void* hThisDll);

	//! Destroyed after CSystem::Shutdown
	~Chairloader();

	//! Called just after the DLL has been loaded.
	void DllAttach();

	//! Called during CSystem::Init, before any engine modules.
	void InitSystem(CSystem* pSystem);

	//! Called before CGame::Init
	void PreInitGame(CGame* pGame, IGameFramework* pFramework);

	//! Called after CGame::Init
	void InitGame(CGame* pGame, IGameFramework* pFramework);

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
	void* m_hThisDll = nullptr;
	WinConsole m_WinConsole;
	uintptr_t m_ModuleBase = 0;
	fs::path m_ModsDirPath;
	IPreditorToChair* m_pPreditorAPI = nullptr;
	bool m_bEditorEnabled = false;
    bool m_bTrainerEnabled = false;
	std::shared_ptr<Internal::IChairloaderCore> m_pCore;
	std::shared_ptr<Internal::IChairloaderCryRender> m_pRender;
	std::shared_ptr<Internal::IChairloaderPatches> m_pPatches;
	std::shared_ptr<Internal::IChairloaderTools> m_pTools;
	std::shared_ptr<Internal::IModDllManager> m_pModDllManager;
	std::shared_ptr<IChairVarManager> m_pVarManager;
	std::shared_ptr<IChairloaderGui> m_pGui;

	unsigned m_SavedUpdateFlags = 0;

	IGameFramework* m_pFramework = nullptr;
	CGame* m_pGame = nullptr;
	KeyNameMap m_KeyNames;

	void ConfigureServices();
	void InitHooks();
	void InitPaths();
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
	bool IsEditorEnabled() override;
	CGame* GetCGame() override;
	int* GetAssertFlagAddress() override;
	void RegisterCVar(ICVar* pCVar, std::string& modName) override;
	const fs::path& GetModsPath() override;

	// IChairloaderDll
	//TODO: remove these in favor of the service provider
	Internal::IChairloaderCore* GetCore() override { return m_pCore.get(); }
	Internal::IChairloaderCryRender* GetCryRender() override { return m_pRender.get(); }
	Internal::IChairloaderPatches* GetPatches() override { return m_pPatches.get(); }
	Internal::IChairloaderTools* GetTools() override { return m_pTools.get(); }
	void* GetDllHandle() override { return m_hThisDll; }
	bool HandleKeyPress(const SInputEvent& event) override;
	void ReloadModDLLs() override;
	IPreditorToChair* GetPreditorAPI() override;

	// IChairToPreditor
	void SetIPreditorToChair(IPreditorToChair* pPreditor) override;
	Internal::IChairloaderDll* GetIChairloaderDll() override;
};
