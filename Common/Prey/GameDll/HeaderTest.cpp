// Header test file for path Prey/GameDll/actordefinitions.h
#include "ArkInventory.h"
static_assert(sizeof(ArkInventory) == 136);
static_assert(sizeof(ArkInventory::StorageCell) == 20);

#include "arkitem.h"
static_assert(sizeof(CArkItem) == 360);

#include "IGameRules.h"
static_assert(sizeof(IGameRules) == 64);
static_assert(sizeof(IGameRules::SGameCollision) == 40);

#include "itemstring.h"
static_assert(sizeof(SharedString::CSharedString) == 8);

#include "SGameWeaponSwayParams.h"
static_assert(sizeof(SGameWeaponSwayParams) == 48);

#include "weaponbumpoffset.h"
static_assert(sizeof(CBumpOffset) == 44);

#include "weaponlookoffset.h"
static_assert(sizeof(SStaticWeaponSwayParams) == 108);
static_assert(sizeof(CLookOffset) == 168);

#include "weaponoffset.h"
static_assert(sizeof(SWeaponOffset) == 24);
static_assert(sizeof(CWeaponOffsetState) == 56);
static_assert(sizeof(CWeaponOffsetStack) == 88);
static_assert(sizeof(CWeaponOffsetStack::SWeaponOffsetLayer) == 32);

#include "weaponoffsetinput.h"
static_assert(sizeof(CWeaponOffsetInput) == 80);

#include "weaponrecoiloffset.h"
static_assert(sizeof(SStaticWeaponRecoilParams) == 24);
static_assert(sizeof(CRecoilOffset) == 80);

#include "weaponstrafeoffset.h"
static_assert(sizeof(CStrafeOffset) == 200);

#include "weaponzoomoffset.h"
static_assert(sizeof(CWeaponZoomOffset) == 208);
