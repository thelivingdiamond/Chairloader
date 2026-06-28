// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CGameLocalizationManager
// Header:  Prey/GameDll/GameLocalizationManager.h
class CGameLocalizationManager
{ // Size=32 (0x20)
public:
	enum ELocalizationTag
	{
		eLT_Init = 0,
		eLT_GameType = 1,
		eLT_Credits = 2,
		eLT_Num = 3,
	};

	string m_loadedTag[3];

	CGameLocalizationManager();
	virtual ~CGameLocalizationManager();
	void SetGameType() { FSetGameType(this); }
	void LegacyLoadLocalizationData() { FLegacyLoadLocalizationData(this); }
	void LoadTagInternal(CGameLocalizationManager::ELocalizationTag tag, const char* pTag) { FLoadTagInternal(this, tag, pTag); }
	void UnloadTag(CGameLocalizationManager::ELocalizationTag tag) { FUnloadTag(this, tag); }

#if 0
	void SetCredits(bool _arg0_);
	void LoadLocalizationData();
	void LoadTag(CGameLocalizationManager::ELocalizationTag _arg0_);
#endif

	static inline auto FCGameLocalizationManagerOv1 = PreyFunction<void(CGameLocalizationManager* const _this)>(0x1834420);
	static inline auto FSetGameType = PreyFunction<void(CGameLocalizationManager* const _this)>(0x1834C90);
	static inline auto FLegacyLoadLocalizationData = PreyFunction<void(CGameLocalizationManager* const _this)>(0x1834610);
	static inline auto FLoadTagInternal = PreyFunction<void(CGameLocalizationManager* const _this, CGameLocalizationManager::ELocalizationTag tag, const char* pTag)>(0x1834A70);
	static inline auto FUnloadTag = PreyFunction<void(CGameLocalizationManager* const _this, CGameLocalizationManager::ELocalizationTag tag)>(0x1834CD0);
};
#endif // MOONCRASH
