// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IUIEventSystemFactory.h>

// Header: Exact
// Prey/GameDll/ui/iuigameeventsystem.h
template <typename T>
struct SAutoRegUIEventSystem : public IUIEventSystemFactory // Id=801B922 Size=16
{
#if 0
	virtual std::shared_ptr<IUIGameEventSystem> Create();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/ui/IUIEventSystemFactory.h>

// SAutoRegUIEventSystem<ArkBrightnessMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkBrightnessMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkBrightnessMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x14201C0);
};

// SAutoRegUIEventSystem<ArkGenderSelectMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkGenderSelectMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkGenderSelectMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1423170);
};

// SAutoRegUIEventSystem<ArkLauncherMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkLauncherMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkLauncherMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x143E810);
};

// SAutoRegUIEventSystem<ArkLeaderboardUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkLeaderboardUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkLeaderboardUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1425D20);
};

// SAutoRegUIEventSystem<ArkModalDialogInGame>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkModalDialogInGame> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkModalDialogInGame>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x17263F0);
};

// SAutoRegUIEventSystem<ArkModalDialogMetaGame>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkModalDialogMetaGame> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkModalDialogMetaGame>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x17265E0);
};

// SAutoRegUIEventSystem<ArkModalDialogRepair>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkModalDialogRepair> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkModalDialogRepair>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1428DE0);
};

// SAutoRegUIEventSystem<ArkNoteUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkNoteUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkNoteUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1726730);
};

// SAutoRegUIEventSystem<ArkPauseMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkPauseMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkPauseMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1451470);
};

// SAutoRegUIEventSystem<ArkReadyRoomManager>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkReadyRoomManager> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkReadyRoomManager>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1472BD0);
};

// SAutoRegUIEventSystem<ArkSaveLoadMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkSaveLoadMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkSaveLoadMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1459830);
};

// SAutoRegUIEventSystem<ArkStoreUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkStoreUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkStoreUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x142EFA0);
};

// SAutoRegUIEventSystem<ArkSubtitleHandler>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkSubtitleHandler> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkSubtitleHandler>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1752570);
};

// SAutoRegUIEventSystem<ArkTutorialCardUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkTutorialCardUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkTutorialCardUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1755AD0);
};

// SAutoRegUIEventSystem<ArkTutorialMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkTutorialMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkTutorialMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1431710);
};

// SAutoRegUIEventSystem<ArkUIOptionMenu>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<ArkUIOptionMenu> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<ArkUIOptionMenu>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x17605A0);
};

// SAutoRegUIEventSystem<CArkPlayerHitDeathUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CArkPlayerHitDeathUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CArkPlayerHitDeathUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x174F630);
};

// SAutoRegUIEventSystem<CArkPsiPowerMimicUI>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CArkPsiPowerMimicUI> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CArkPsiPowerMimicUI>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x16C2210);
};

// SAutoRegUIEventSystem<CArkUIHUD>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CArkUIHUD> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CArkUIHUD>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1756BB0);
};

// SAutoRegUIEventSystem<CUIGameEvents>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CUIGameEvents> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CUIGameEvents>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1921B40);
};

// SAutoRegUIEventSystem<CUIInput>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CUIInput> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CUIInput>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1922C80);
};

// SAutoRegUIEventSystem<CUIMenuEvents>
// Header:  Prey/GameDll/ui/iuigameeventsystem.h
struct SAutoRegUIEventSystem<CUIMenuEvents> : public IUIEventSystemFactory
{ // Size=16 (0x10)
	virtual std::shared_ptr<IUIGameEventSystem> Create();

	static inline auto FCreate = PreyFunction<std::shared_ptr<IUIGameEventSystem>*(SAutoRegUIEventSystem<CUIMenuEvents>* const _this, std::shared_ptr<IUIGameEventSystem>* _return_value_)>(0x1927800);
};
#endif // !MOONCRASH
