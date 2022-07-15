#pragma once
#include <memory>
#include <Prey/CrySystem/ISystem.h>
#include "PreyFunctions.h"
#include "ChairLoaderImGui.h"
#include "Logging.h"

#define PREY_DLL_NAME "PreyDll.dll"

struct SInputEvent;
struct IGameFramework;
class CSystem;

class ChairLoader {
public:
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

	//! Process smoke form exit
	void SmokeFormExit();

	inline std::thread::id GetMainThreadId() { return m_MainThreadId; }
	inline std::thread::id GetRenderThreadId() { return m_ImGui->GetRenderThreadId(); }
	inline uintptr_t GetModuleBase() { return m_ModuleBase; }
	inline IGameFramework* GetFramework() { return m_pFramework; }

private:
	uintptr_t m_ModuleBase = 0;
	IGameFramework* m_pFramework = nullptr;
	std::unique_ptr<ChairLoaderImGui> m_ImGui;
	FILE *m_pConsoleFile = nullptr;
	std::thread::id m_MainThreadId;
	int m_GuiToggleKey = 0;
	int m_FreeCamKey = 0;
	bool m_DevMode;
	bool m_FreeCamEnabled = false;

	void CreateConsole();
	void LoadPreyPointers();
	void InstallHooks();
	void LoadConfigFile();
	void UpdateFreeCam();
};

extern ChairLoader *gCL;
extern SSystemGlobalEnvironment *gEnv;
