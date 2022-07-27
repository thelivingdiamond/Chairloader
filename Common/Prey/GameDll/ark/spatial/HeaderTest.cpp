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
