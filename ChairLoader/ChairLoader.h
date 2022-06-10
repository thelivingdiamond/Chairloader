#pragma once
#include <memory>
#include "PreyFunctions.h"
#include "ChairLoaderImGui.h"
#include "Logging.h"

struct SInputEvent;

class ChairLoader {
public:
	// After CGame::Init
	ChairLoader();

	// TODO: Call this somewhere
	~ChairLoader();

	// Before CGame::Update
	void PreUpdate(bool haveFocus, unsigned int updateFlags);

	// After CGame::Update
	void PostUpdate(bool haveFocus, unsigned int updateFlags);

	//! Process a key press.
	//! @returns whether it was handled and shouldn't be passed over to the game.
	bool HandleKeyPress(const SInputEvent &event);

	inline std::thread::id GetMainThreadId() { return m_MainThreadId; }
	inline std::thread::id GetRenderThreadId() { return m_ImGui->GetRenderThreadId(); }

private:
	std::unique_ptr<ChairLoaderImGui> m_ImGui;
	FILE *m_pConsoleFile = nullptr;
	std::thread::id m_MainThreadId;
	PreyFunctions::CGamePrivate::_Update m_CGameUpdate = nullptr;
	int m_GuiToggleKey = 0;
	int m_FreeCamKey = 0;
	bool m_DevMode;
	bool m_FreeCamEnabled = false;

	void CreateConsole();
	void LoadPreyPointers(uintptr_t moduleBase);
	void HookGameUpdate(uintptr_t moduleBase);
	void LoadConfigFile();
	void UpdateFreeCam();

	static int GameUpdate(CGame *_this, bool haveFocus, unsigned int updateFlags);
};

extern ChairLoader *gCL;
extern SSystemGlobalEnvironment *gEnv;
