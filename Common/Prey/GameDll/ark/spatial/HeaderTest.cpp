// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/spatial/ArkSpatiallySortedApexTentacle.h
#include "ArkSpatiallySortedApexTentacle.h"
static_assert(sizeof(ArkSpatiallySortedApexTentacle) == 8);

#include "ArkSpatiallySortedEntity.h"
static_assert(sizeof(ArkSpatiallySortedEntity) == 8);

#include "ArkSpatiallySortedKey.h"
static_assert(sizeof(ArkSpatiallySortedKey) == 8);

#include "ArkSpatiallySortedNpc.h"
static_assert(sizeof(ArkSpatiallySortedNpc) == 8);

#include "ArkSpatiallySortedTurret.h"
static_assert(sizeof(ArkSpatiallySortedCystoidNest) == 8);
static_assert(sizeof(ArkSpatiallySortedTurret) == 8);

#include "ArkSpatialManager.h"
static_assert(sizeof(ArkSpatialManager) == 824);

#include "arkspatialmanagerentry_apextentacle.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_ApexTentacle) == 1);

#include "arkspatialmanagerentry_cystoidnest.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_CystoidNest) == 1);

#include "arkspatialmanagerentry_energizable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Energizable) == 1);

#include "arkspatialmanagerentry_interferable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Interferable) == 1);

#include "arkspatialmanagerentry_interferableandenergizable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_InterferableAndEnergizable) == 1);

#include "arkspatialmanagerentry_npc.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Npc) == 1);

#include "arkspatialmanagerentry_turret.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Turret) == 1);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/spatial/
#include "ArkSpatialManager.h"
static_assert(sizeof(ArkSpatialManager) == 896);

#include "ArkSpatiallySortedApexTentacle.h"
static_assert(sizeof(ArkSpatiallySortedApexTentacle) == 8);

#include "ArkSpatiallySortedEntity.h"
static_assert(sizeof(ArkSpatiallySortedEntity) == 8);

#include "ArkSpatiallySortedKey.h"
static_assert(sizeof(ArkSpatiallySortedKey) == 8);

#include "ArkSpatiallySortedNpc.h"
static_assert(sizeof(ArkSpatiallySortedNpc) == 8);

#include "arkspatiallysorted.h"
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>) == 72);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>::ObjectCoordinate) == 16);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedEntity>) == 72);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedEntity>::ObjectCoordinate) == 16);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedNpc>) == 72);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedNpc>::ObjectCoordinate) == 16);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedTurret>) == 72);
static_assert(sizeof(ArkSpatiallySorted<ArkSpatiallySortedTurret>::ObjectCoordinate) == 16);

#include "arkspatialmanagerentry.h"
static_assert(sizeof(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>) == 16);
static_assert(sizeof(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>) == 16);

#include "arkspatialmanagerentry_apextentacle.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_ApexTentacle) == 1);

#include "arkspatialmanagerentry_energizable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Energizable) == 1);

#include "arkspatialmanagerentry_interferable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Interferable) == 1);

#include "arkspatialmanagerentry_interferableandenergizable.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_InterferableAndEnergizable) == 1);

#include "arkspatialmanagerentry_npc.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Npc) == 1);

#include "arkspatialmanagerentry_npcspawner.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_NpcSpawner) == 1);

#include "arkspatialmanagerentry_turret.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_Turret) == 1);

#include "arkspatialmanagerentry_typhonnest.h"
static_assert(sizeof(ArkSpatialManagerEntryImpl_TyphonNest) == 1);
#endif // !MOONCRASH
