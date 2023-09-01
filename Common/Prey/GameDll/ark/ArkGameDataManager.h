// Header file automatically created from a PDB.

#pragma once

class ArkReflectedLibrary;
class ArkClass;

// Header: FromCpp
// Prey/GameDll/ark/ArkGameDataManager.h
class ArkGameDataManager // Id=8015355 Size=64
{
public:
	std::unordered_map<ArkClass const *,std::unique_ptr<ArkReflectedLibrary>> m_libraries;
	
	ArkGameDataManager();
	void OnGameModeChanged() { FOnGameModeChanged(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void LoadLibraries(bool _bAlwaysLoaded) { FLoadLibraries(this,_bAlwaysLoaded); }
	
	static inline auto FOnGameModeChanged = PreyFunction<void(ArkGameDataManager *const _this)>(0x1437630);
	static inline auto FReset = PreyFunction<void(ArkGameDataManager *const _this, bool _bEnteringGameMode)>(0x1437640);
	static inline auto FLoadLibraries = PreyFunction<void(ArkGameDataManager *const _this, bool _bAlwaysLoaded)>(0x1437290);
};

