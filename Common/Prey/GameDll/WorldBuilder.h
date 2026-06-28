// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/GameDll/PrefabManager.h>

struct ILevel;
struct ILevelInfo;

// CWorldBuilder
// Header:  Prey/GameDll/WorldBuilder.h
class CWorldBuilder : public ILevelSystemListener
{ // Size=80 (0x50)
public:
	CryGame::CPrefabManager m_PrefabManager;

	CWorldBuilder();
	virtual ~CWorldBuilder();
	virtual void OnLevelNotFound(const char* levelName);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevel);
	virtual void OnLoadingStart(ILevelInfo* pLevel);
	virtual void OnLoadingComplete(ILevel* pLevel);
	virtual void OnLoadingError(ILevelInfo* pLevel, const char* error);
	virtual void OnLoadingProgress(ILevelInfo* pLevel, int progressAmount);
	virtual void OnUnloadComplete(ILevel* pLevel);

#if 0
	CryGame::CPrefabManager& GetPrefabManager();
	void DrawDebugInfo();
#endif

	static inline auto FCWorldBuilderOv1 = PreyFunction<void(CWorldBuilder* const _this)>(0x192C360);
	static inline auto FOnLevelNotFound = PreyFunction<void(CWorldBuilder* const _this, const char* levelName)>(0x1333E90);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(CWorldBuilder* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingStart = PreyFunction<void(CWorldBuilder* const _this, ILevelInfo* pLevel)>(0x192C5A0);
	static inline auto FOnLoadingComplete = PreyFunction<void(CWorldBuilder* const _this, ILevel* pLevel)>(0x192C490);
	static inline auto FOnLoadingError = PreyFunction<void(CWorldBuilder* const _this, ILevelInfo* pLevel, const char* error)>(0x1333E90);
	static inline auto FOnLoadingProgress = PreyFunction<void(CWorldBuilder* const _this, ILevelInfo* pLevel, int progressAmount)>(0x1333E90);
	static inline auto FOnUnloadComplete = PreyFunction<void(CWorldBuilder* const _this, ILevel* pLevel)>(0x1333E90);
};
#endif // MOONCRASH
