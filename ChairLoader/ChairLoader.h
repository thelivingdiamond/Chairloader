#pragma once
#include <memory>
#include <Prey/CrySystem/ISystem.h>

#include "ChairloaderConfigManager.h"
#include "ChairLoaderImGui.h"
#include "ChairLoader/IChairloader.h"
#include "Logging.h"
#include "ChairLoader/IChairloaderMod.h"
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
	std::map<std::string, int> modLoadOrder;

	//! reads the config file to obtain the mod load order
	void ReadModList();

	//! sorts the modList by load order
	void sortLoadOrder();

	//! load all mod DLL's from the mod names obtained from the config Mod List
	void initializeMods();

	//! load all registered mod configs
	void loadAllConfigs();

	const std::string chairloaderModName = "Chairloader";
	uintptr_t m_ModuleBase = 0;
	IGameFramework* m_pFramework = nullptr;
	std::unique_ptr<ChairLoaderImGui> m_ImGui;
	FILE *m_pConsoleFile = nullptr;
	std::thread::id m_MainThreadId;

	int m_FreeCamKey = 0;
	bool m_DevMode;
	bool m_FreeCamEnabled = false;

	void CreateConsole();
	void InstallHooks();
	void UpdateFreeCam();
	void WaitForRenderDoc();

public:
	// IChairloader
	ChairloaderGlobalEnvironment* GetChairloaderEnvironment() override;
};

extern ChairLoader *gCL;
extern SSystemGlobalEnvironment *gEnv;
