// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/ui/store/
#include "ArkFakeCatalogLoader.h"
static_assert(sizeof(ArkFakeCatalogLoader) == 8);

#include "ArkStoreCatalog.h"
static_assert(sizeof(ArkStoreCatalog) == 24);
static_assert(sizeof(ArkStoreCatalog::ArkItemsProperty) == 32);
static_assert(sizeof(ArkStoreItem) == 56);
static_assert(sizeof(ArkStoreItem::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkEntitlementProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkIDProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkImageProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkLabelProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkNameProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkRarityProperty) == 32);

#include "ArkStoreManager.h"
static_assert(sizeof(ArkStoreManager) == 112);

#include "ArkStoreUI.h"
static_assert(sizeof(ArkStoreUI) == 240);
#endif // MOONCRASH
