// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkGameMode.h>
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
	~ArkGameModeManager();
	void Init() { FInit(this); }
	void SetGameMode(unsigned _gameMode) { FSetGameMode(this,_gameMode); }
	CCryName GetCurrentModeName() const { return FGetCurrentModeName(this); }
	
	static inline auto FBitNotArkGameModeManager = PreyFunction<void(ArkGameModeManager *const _this)>(0x1172F10);
	static inline auto FInit = PreyFunction<void(ArkGameModeManager *const _this)>(0x11732E0);
	static inline auto FSetGameMode = PreyFunction<void(ArkGameModeManager *const _this, unsigned _gameMode)>(0x11735A0);
	static inline auto FGetCurrentModeName = PreyFunction<CCryName(ArkGameModeManager const *const _this)>(0x11732B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkGameMode.h>

class CCryName;

// ArkGameModeManager
// Header:  Prey/GameDll/ark/ArkGameModeManager.h
class ArkGameModeManager
{ // Size=80 (0x50)
public:
	ArkGameModes m_modeLibrary;
	unsigned m_currentMode;
	static inline auto g_startupGameMode = PreyGlobal<int>(0x2D3C3A0);
	std::vector<string> m_globalPrecachePakPaths;
	std::vector<string> m_gameModePrecachePakPaths;

	ArkGameModeManager();
	~ArkGameModeManager();
	void Init() { FInit(this); }
	void SetGameMode(unsigned _gameMode) { FSetGameMode(this, _gameMode); }
	CCryName GetCurrentModeName() const { alignas(CCryName) std::byte _return_buf_[sizeof(CCryName)]; return *FGetCurrentModeName(this, reinterpret_cast<CCryName*>(_return_buf_)); }

	static inline auto FArkGameModeManagerOv1 = PreyFunction<void(ArkGameModeManager* const _this)>(0x11ECB90);
	static inline auto FBitNotArkGameModeManager = PreyFunction<void(ArkGameModeManager* const _this)>(0x11ECFD0);
	static inline auto FInit = PreyFunction<void(ArkGameModeManager* const _this)>(0x11ED3A0);
	static inline auto FSetGameMode = PreyFunction<void(ArkGameModeManager* const _this, unsigned _gameMode)>(0x11ED820);
	static inline auto FGetCurrentModeName = PreyFunction<CCryName*(const ArkGameModeManager* const _this, CCryName* _return_value_)>(0x11ED370);
};
#endif // !MOONCRASH
