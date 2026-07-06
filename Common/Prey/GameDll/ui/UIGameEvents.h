// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <_unknown/SUIEventReceiverDispatcher.h>

struct IGameFramework;
struct ILevelSystem;
struct IUIEventSystem;

// CUIGameEvents
// Header:  Prey/GameDll/ui/UIGameEvents.h
class CUIGameEvents : public IUIGameEventSystem
{ // Size=72 (0x48)
public:
	IUIEventSystem* m_pUIEvents;
	SUIEventReceiverDispatcher<CUIGameEvents> m_eventDispatcher;
	IGameFramework* m_pGameFramework;
	ILevelSystem* m_pLevelSystem;

	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	void OnLoadLevel(const char* mapname, bool isServer, const char* gamerules) { FOnLoadLevel(this, mapname, isServer, gamerules); }
	void OnReloadLevel() { FOnReloadLevel(this); }
	void OnSaveGame(bool shouldResume) { FOnSaveGame(this, shouldResume); }
	void OnLoadGame(bool shouldResume) { FOnLoadGame(this, shouldResume); }
	void OnPauseGame() { FOnPauseGame(this); }
	void OnResumeGame() { FOnResumeGame(this); }
	void OnExitGame() { FOnExitGame(this); }
	void OnStartGame() { FOnStartGame(this); }

#if 0
	CUIGameEvents();
	static const char* GetTypeNameS();
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const CUIGameEvents* const _this)>(0x1922100);
	static inline auto FInitEventSystem = PreyFunction<void(CUIGameEvents* const _this)>(0x1922110);
	static inline auto FUnloadEventSystem = PreyFunction<void(CUIGameEvents* const _this)>(0x1333E90);
	static inline auto FOnLoadLevel = PreyFunction<void(CUIGameEvents* const _this, const char* mapname, bool isServer, const char* gamerules)>(0x19229B0);
	static inline auto FOnReloadLevel = PreyFunction<void(CUIGameEvents* const _this)>(0x1922AD0);
	static inline auto FOnSaveGame = PreyFunction<void(CUIGameEvents* const _this, bool shouldResume)>(0x1922BA0);
	static inline auto FOnLoadGame = PreyFunction<void(CUIGameEvents* const _this, bool shouldResume)>(0x1922920);
	static inline auto FOnPauseGame = PreyFunction<void(CUIGameEvents* const _this)>(0x1922AA0);
	static inline auto FOnResumeGame = PreyFunction<void(CUIGameEvents* const _this)>(0x1922B80);
	static inline auto FOnExitGame = PreyFunction<void(CUIGameEvents* const _this)>(0x1440700);
	static inline auto FOnStartGame = PreyFunction<void(CUIGameEvents* const _this)>(0x1922C50);
};
#endif // MOONCRASH
