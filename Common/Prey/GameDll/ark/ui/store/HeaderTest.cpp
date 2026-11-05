// Header test file for path Prey/GameDll/ark/ui/store/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkFakeCatalogLoader.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkFakeCatalogLoader) == 8);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkStoreCatalog.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkStoreItem) == 56);
static_assert(sizeof(ArkStoreItem::ArkIDProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkEntitlementProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkNameProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkLabelProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkImageProperty) == 32);
static_assert(sizeof(ArkStoreItem::ArkRarityProperty) == 32);
static_assert(sizeof(ArkStoreCatalog) == 24);
static_assert(sizeof(ArkStoreCatalog::ArkItemsProperty) == 32);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkStoreManager.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkStoreManager) == 112);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkStoreUI.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkStoreUI) == 240);
#endif
#endif
