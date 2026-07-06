// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ui/
#include "UIGameEvents.h"
static_assert(sizeof(CUIGameEvents) == 72);

#include "UIInput.h"
static_assert(sizeof(CUIInput) == 152);

#include "UIManager.h"
static_assert(sizeof(CUIManager) == 152);

#include "UIMenuEvents.h"
static_assert(sizeof(CUIMenuEvents) == 104);

#include "iuigameeventsystem.h"
static_assert(sizeof(SAutoRegUIEventSystem<ArkBrightnessMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkGenderSelectMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkLauncherMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkLeaderboardUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkModalDialogInGame>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkModalDialogMetaGame>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkModalDialogRepair>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkNoteUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkPauseMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkReadyRoomManager>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkSaveLoadMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkStoreUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkSubtitleHandler>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkTutorialCardUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkTutorialMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<ArkUIOptionMenu>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CArkPlayerHitDeathUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CArkPsiPowerMimicUI>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CArkUIHUD>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CUIGameEvents>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CUIInput>) == 16);
static_assert(sizeof(SAutoRegUIEventSystem<CUIMenuEvents>) == 16);
#endif // MOONCRASH
