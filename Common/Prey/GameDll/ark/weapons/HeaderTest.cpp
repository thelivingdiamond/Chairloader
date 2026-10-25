// Header test file for path Prey/GameDll/ark/weapons/

#include "arkempblast.h"
static_assert(sizeof(CArkEMPBlast) == 152);

#include "ArkGooSignalReceiver.h"
static_assert(sizeof(ArkGooSignalReceiver) == 32);

#include "ArkGrenadeSignalReceiver.h"
static_assert(sizeof(ArkGrenadeSignalReceiver) == 32);

#include "arklaser.h"
static_assert(sizeof(CArkLaserBeam) == 48);
static_assert(sizeof(CArkLaserBeam::ArkLaserParams) == 32);

#include "arkprojectile.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectile) == 664);
#else
static_assert(sizeof(CArkProjectile) == 672);
#endif
static_assert(sizeof(CArkProjectile::ArkProjectileEntityEffect) == 280);
static_assert(sizeof(CArkProjectile::ArkProjectileFFEffect) == 136);

#include "arkprojectilediscrifle.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileDiscRifle) == 712);
#else
static_assert(sizeof(CArkProjectileDiscRifle) == 720);
#endif

#include "arkprojectilegoo.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileGoo) == 1640);
static_assert(sizeof(CArkProjectileGoo::ArkGooSpawnParameters) == 80);
#else
static_assert(sizeof(CArkProjectileGoo) == 1680);
static_assert(sizeof(CArkProjectileGoo::ArkGooSpawnParameters) == 88);
#endif
static_assert(sizeof(CArkProjectileGoo::GooSpawningProperties) == 20);

#include "arkprojectilegooball.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileGooBall) == 776);
#else
static_assert(sizeof(CArkProjectileGooBall) == 800);
#endif

#include "arkprojectilegrenade.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileGrenade) == 1896);
#else
static_assert(sizeof(CArkProjectileGrenade) == 1904);
#endif

#include "arkprojectilehomingpsiblast.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileHomingPsiBlast) == 872);
#else
static_assert(sizeof(CArkProjectileHomingPsiBlast) == 880);
#endif

#include "arkprojectileluregrenade.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileLureGrenade) == 1912);
#else
static_assert(sizeof(CArkProjectileLureGrenade) == 1928);
#endif

#include "arkprojectilenightmareetherform.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileNightmareEtherForm) == 680);
#else
static_assert(sizeof(CArkProjectileNightmareEtherForm) == 688);
#endif

#include "arkprojectilerecyclergrenade.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileRecyclerGrenade) == 3064);
#else
static_assert(sizeof(CArkProjectileRecyclerGrenade) == 2800);
#endif
#ifndef MOONCRASH
static_assert(sizeof(CArkProjectileRecyclerGrenade::RecycleEntityInfo) == 3);
#endif

#include "arkweapon.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeapon) == 1216);
#else
static_assert(sizeof(CArkWeapon) == 1608);
#endif
static_assert(sizeof(CArkWeapon::ReticleInfo) == 24);
static_assert(sizeof(CArkWeapon::ArkWeaponMods) == 64);
static_assert(sizeof(CArkWeapon::ArkIronsightsTargetInfo) == 16);
#ifdef MOONCRASH
static_assert(sizeof(CArkWeapon::ArkWeaponEnchant) == 8);
#endif

#include "arkweaponactions.h"
static_assert(sizeof(ArkWeaponAction) == 136);
static_assert(sizeof(ArkWeaponThrowIdleAction) == 136);
static_assert(sizeof(ArkWeaponReloadAction) == 136);
static_assert(sizeof(ArkWeaponReloadActionOnEvent) == 136);
static_assert(sizeof(ArkWeaponAttackAction) == 136);
static_assert(sizeof(ArkWeaponDeployAction) == 136);
static_assert(sizeof(ArkWeaponAttackOutAction) == 136);
static_assert(sizeof(ArkWeaponAttackOutAndUnselectAction) == 144);
static_assert(sizeof(ArkWeaponAttackInAction) == 136);
static_assert(sizeof(ArkWeaponSelectAction) == 144);
static_assert(sizeof(ArkWeaponUnselectAction) == 136);
static_assert(sizeof(ArkWeaponReloadInAction) == 136);
static_assert(sizeof(ArkWeaponReloadOutAction) == 136);
static_assert(sizeof(ArkWeaponThrowInAction) == 136);
static_assert(sizeof(ArkWeaponAttackContinueMalfunctionAction) == 136);
#ifdef MOONCRASH
static_assert(sizeof(ArkWeaponAttackContinueAction) == 136);
#endif

#include "arkweapondiscrifle.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponDiscRifle) == 1288);
#else
static_assert(sizeof(CArkWeaponDiscRifle) == 1680);
#endif

#include "ArkWeaponDoubleWrench.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkWeaponDoubleWrench) == 1312);
#else
static_assert(sizeof(ArkWeaponDoubleWrench) == 1704);
#endif

#include "arkweapongoogun.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponGooGun) == 1280);
#else
static_assert(sizeof(CArkWeaponGooGun) == 1664);
#endif

#include "arkweapongrenade.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponGrenade) == 1336);
#else
static_assert(sizeof(CArkWeaponGrenade) == 1712);
#endif

#include "arkweaponinstalaser.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponInstalaser) == 1648);
#else
static_assert(sizeof(CArkWeaponInstalaser) == 2040);
#endif

#include "arkweaponshotgun.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponShotgun) == 1312);
#else
static_assert(sizeof(CArkWeaponShotgun) == 1696);
#endif

#include "arkweaponstungun.h"
#ifndef MOONCRASH
static_assert(sizeof(CArkWeaponStunGun) == 1632);
#else
static_assert(sizeof(CArkWeaponStunGun) == 2152);
#endif

#include "ArkWeaponUtils.h"
static_assert(sizeof(ArkWeaponUtils) == 1);
static_assert(sizeof(ArkWeaponUtils::PhysicsMaterialInfo) == 64);
static_assert(sizeof(ArkWeaponUtils::ArkExplosionInfo) == 168);

#include "ArkWeaponWrench.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkWeaponWrench) == 1376);
#else
static_assert(sizeof(ArkWeaponWrench) == 1768);
#endif

#include "ArkWrenchComponent.h"
static_assert(sizeof(ArkWrenchComponent) == 88);
static_assert(sizeof(ArkWrenchComponent::Action<ArkWeaponDoubleWrench>) == 136);
static_assert(sizeof(ArkWrenchComponent::Action<ArkWeaponWrench>) == 136);
static_assert(sizeof(ArkWrenchComponent::GenericFatalityAction<ArkWeaponDoubleWrench>) == 144);
static_assert(sizeof(ArkWrenchComponent::GenericFatalityAction<ArkWeaponWrench>) == 144);

#include "IArkGlooEffectObserver.h"
static_assert(sizeof(IArkGlooEffectObserver) == 8);

#include "IArkGlooIslandNavLinkManager.h"
static_assert(sizeof(IArkGlooIslandNavLinkManager) == 8);

#include "IArkOverlappingGooListener.h"
static_assert(sizeof(IArkOverlappingGooListener) == 8);

#include "IArkWeapon.h"
static_assert(sizeof(IArkWeapon) == 8);

#include "SStaticBumpParams.h"
static_assert(sizeof(SStaticBumpParams) == 12);

#include "SStaticWeaponPoseParams.h"
static_assert(sizeof(SStaticWeaponPoseParams) == 32);

#include "SStaticWiggleParams.h"
static_assert(sizeof(SStaticWiggleParams) == 8);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPhantomThermogenesisBlast.h"
static_assert(sizeof(CArkPhantomThermogenesisBlast) == 248);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileArchetypeGrenade.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileArchetypeGrenade) == 1912);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileBounceGrenade.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileBounceGrenade) == 1912);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileGooGrenade.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileGooGrenade) == 1968);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileMatter.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileMatter) == 952);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileSolarFlare.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileSolarFlare) == 1168);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProjectileSwordSwipe.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkProjectileSwordSwipe) == 720);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTechnopathEMPHazard.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTechnopathEMPHazard) == 1048);
#else
static_assert(sizeof(ArkTechnopathEMPHazard) == 1080);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkWeaponRapidFire.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkWeaponRapidFire) == 1704);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkWeaponRecyclizer.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkWeaponRecyclizer) == 1680);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkWeaponSkin.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkWeaponSkin) == 56);
static_assert(sizeof(ArkWeaponSkin::ArkIDProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkNameProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkLabelProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkIconProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkMaterial1PProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkGroupProperty) == 32);
static_assert(sizeof(ArkWeaponSkinGroup) == 32);
static_assert(sizeof(ArkWeaponSkinGroup::ArkIDProperty) == 32);
static_assert(sizeof(ArkWeaponSkinGroup::ArkWeaponsProperty) == 32);
static_assert(sizeof(ArkWeaponSkins) == 56);
static_assert(sizeof(ArkWeaponSkins::ArkWeaponSkinsProperty) == 32);
static_assert(sizeof(ArkWeaponSkins::ArkGroupsProperty) == 32);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkWeaponSword.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkWeaponSword) == 2624);
#endif
#endif
