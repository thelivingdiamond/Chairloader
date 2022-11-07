#pragma once
#include <memory>
#include <Prey/CrySystem/ISystem.h>

#include "ChairloaderConfigManager.h"
#include "ChairLoaderImGui.h"
#include "ChairLoader/IChairloader.h"
#include "Logging.h"
#include "ChairLoader/IChairloaderMod.h"
#include <boost/assign.hpp>

#define PREY_DLL_NAME "PreyDll.dll"

struct SInputEvent;
struct IGameFramework;
class CSystem;
class ModDllManager;
class Editor;

class ChairLoader : public IChairloader {
public:
	//! Constructed just after loading PreyDll.dll, before any game code is run.
	ChairLoader();

	//! Initializes function hooks and installs them. Called during InitSystem.
	void InitHooks();

	//! Called during CSystem::Init, before any engine modules.
	void InitSystem(CSystem* pSystem);

	//! Called after CGame::Init
	void InitGame(IGameFramework* pFramework);

	//! Called before CGame::Shutdown.
	void ShutdownGame();

	//! Called before CSystem::Shutdown.
	void ShutdownSystem();

	//! Destroyed after CSystem::Shutdown
	~ChairLoader();

	//! Before CGame::Update
	void PreUpdate(bool haveFocus, unsigned int updateFlags);

	//! After CGame::Update
	void PostUpdate(bool haveFocus, unsigned int updateFlags);

	//! Process a key press.
	//! @returns whether it was handled and shouldn't be passed over to the game.
	bool HandleKeyPress(const SInputEvent &event);

	//! Process smoke form exit TODO: move this to separate mod
	void SmokeFormExit();

	inline std::thread::id GetMainThreadId() { return m_MainThreadId; }
	inline std::thread::id GetRenderThreadId() { return m_ImGui->GetRenderThreadId(); }
	inline uintptr_t GetModuleBase() { return m_ModuleBase; }
	inline IGameFramework* GetFramework() override { return m_pFramework; }

private:
	//! Reads the config file to register mods with ModDllManager
	void RegisterMods();

    //! load config parameters from chairloader config file
    void loadConfigParameters();

	const std::string chairloaderModName = "Chairloader";
	uintptr_t m_ModuleBase = 0;
	std::unique_ptr<ModDllManager> m_pModDllManager;
	IGameFramework* m_pFramework = nullptr;
	std::unique_ptr<ChairLoaderImGui> m_ImGui;
	std::unique_ptr<Editor> m_pEditor;
	FILE *m_pConsoleFile = nullptr;
	std::thread::id m_MainThreadId;

	bool m_DevMode;
	bool m_FreeCamEnabled = false;
    bool m_ShowGui = true;
	bool m_bEditorEnabled = false;

    //! key binds
    EKeyId m_hideGuiKey = EKeyId::eKI_F1;
    EKeyId m_toggleFreecamKey = EKeyId::eKI_F2;

	void CreateConsole();
	void InstallHooks();
    KeyNameMap m_KeyNames;

    // init m_KeyNames. Call once
    void LoadKeyNames();
public:
	// IChairloader
    //TODO: reconsider where this map should go
    //! get key names map. Useful for config purposes
    const KeyNameMap &GetKeyNames() const override { return m_KeyNames; }
	ChairloaderGlobalEnvironment* GetChairloaderEnvironment() override;
	uintptr_t GetPreyDllBase() override;
    std::string getKeyBind(std::string action) override;
	bool IsEditorEnabled() override;
	void ReloadModDLLs() override;
	bool CheckDLLsForChanges() override;
};

extern ChairLoader* gChair;
