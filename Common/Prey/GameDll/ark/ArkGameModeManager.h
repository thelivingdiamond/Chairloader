// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkgamemode.h>
#include <Prey/CryString/CryName.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkGameModeManager.h
class ArkGameModeManager // Id=80169EB Size=80
{
public:
	ArkGameModes m_modeLibrary;
	unsigned m_currentMode;
	static int g_startupGameMode;
	std::vector<string> m_globalPrecachePakPaths;
	std::vector<string> m_gameModePrecachePakPaths;
	
	ArkGameModeManager();
	~ArkGameModeManager() { FBitNotArkGameModeManager(this); }
	void Init() { FInit(this); }
	void SetGameMode(unsigned _gameMode) { FSetGameMode(this,_gameMode); }
	CCryName GetCurrentModeName() const { return FGetCurrentModeName(this); }
	
	static inline auto FBitNotArkGameModeManager = PreyFunction<void(ArkGameModeManager *const _this)>(0x1172F10);
	static inline auto FInit = PreyFunction<void(ArkGameModeManager *const _this)>(0x11732E0);
	static inline auto FSetGameMode = PreyFunction<void(ArkGameModeManager *const _this, unsigned _gameMode)>(0x11735A0);
	static inline auto FGetCurrentModeName = PreyFunction<CCryName(ArkGameModeManager const *const _this)>(0x11732B0);
};

