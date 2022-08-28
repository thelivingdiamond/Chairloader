#pragma once
#include <memory>
#include <Prey/CrySystem/ISystem.h>

#include "ChairloaderConfigManager.h"
#include "ChairLoaderImGui.h"
#include "ChairLoader/IChairloader.h"
#include "Logging.h"
#include "ChairLoader/IChairloaderMod.h"
#include <boost/assign.hpp>
#include "EntityManager.h"

#define PREY_DLL_NAME "PreyDll.dll"

struct SInputEvent;
struct IGameFramework;
class CSystem;

class ChairLoader : public IChairloader {
public:
	class ModEntry {
	public:
		int GetLoadOrder() const { return loadOrder; }

		//! unique modName
		std::string modName = "";

		//! interface for calling guaranteed functions
		IChairloaderMod* pMod = nullptr;

		//! DLL handle for the mod 
		HMODULE hModule = nullptr;

		//! Functions exported by the mod
		//! @{
		IChairloaderMod::ProcInitialize* pfnInit = nullptr;
		IChairloaderMod::ProcShutdown* pfnShutdown = nullptr;
		//! @}

		//! configuration file
		// pugi::xml_document configFile;

		int loadOrder = -1;

		bool operator<(const ModEntry& rhs) const noexcept { return loadOrder < rhs.loadOrder; }
		bool operator==(const ModEntry& rhs) const noexcept { return modName == rhs.modName; }
	};

	//! Constructed just after loading PreyDll.dll, before any game code is run.
	ChairLoader();

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

	//! Register a mod 
	bool RegisterMod(ModEntry&& mod);

	inline std::thread::id GetMainThreadId() { return m_MainThreadId; }
	inline std::thread::id GetRenderThreadId() { return m_ImGui->GetRenderThreadId(); }
	inline uintptr_t GetModuleBase() { return m_ModuleBase; }
	inline IGameFramework* GetFramework() override { return m_pFramework; }

private:
	//! The mod list
	std::vector<ModEntry> modList;

	//! intermediate structure to keep track of mod load order before the mods are registered
	std::map<std::string, pugi::xml_node> modLoadOrder;

	//! reads the config file to obtain the mod load order
	void ReadModList();

	//! sorts the modList by load order
	void sortLoadOrder();

	//! load all mod DLL's from the mod names obtained from the config Mod List
	void initializeMods();

	//! load all registered mod configs
	void loadAllConfigs();

    //! load config parameters from chairloader config file
    void loadConfigParameters();

	const std::string chairloaderModName = "Chairloader";
	uintptr_t m_ModuleBase = 0;
	IGameFramework* m_pFramework = nullptr;
	std::unique_ptr<ChairLoaderImGui> m_ImGui;
	FILE *m_pConsoleFile = nullptr;
	std::thread::id m_MainThreadId;

	bool m_DevMode;
	bool m_FreeCamEnabled = false;
    bool m_ShowGui = true;

    //! key binds
    EKeyId m_hideGuiKey = EKeyId::eKI_F1;
    EKeyId m_toggleFreecamKey = EKeyId::eKI_F2;

	void CreateConsole();
	void InstallHooks();
	void WaitForRenderDoc();
    KeyNameMap m_KeyNames;

    // init m_KeyNames. Call once
    void LoadKeyNames();
public:
	// IChairloader
    //TODO: reconsider where this map should go
    //! get key names map. Useful for config purposes
    const KeyNameMap &GetKeyNames() const override { return m_KeyNames; }
	ChairloaderGlobalEnvironment* GetChairloaderEnvironment() override;
    std::string getKeyBind(std::string action) override;
};

extern ChairLoader *gCL;
extern SSystemGlobalEnvironment *gEnv;
