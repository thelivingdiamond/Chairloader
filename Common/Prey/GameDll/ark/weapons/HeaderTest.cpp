// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/weapons/arkempblast.h
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
static_assert(sizeof(CArkProjectile) == 664);
static_assert(sizeof(CArkProjectile::ArkProjectileEntityEffect) == 280);
static_assert(sizeof(CArkProjectile::ArkProjectileFFEffect) == 136);

#include "arkprojectilediscrifle.h"
static_assert(sizeof(CArkProjectileDiscRifle) == 712);

#include "arkprojectilegoo.h"
static_assert(sizeof(CArkProjectileGoo) == 1640);
static_assert(sizeof(CArkProjectileGoo::ArkGooSpawnParameters) == 80);
static_assert(sizeof(CArkProjectileGoo::GooSpawningProperties) == 20);

#include "arkprojectilegooball.h"
static_assert(sizeof(CArkProjectileGooBall) == 776);

#include "arkprojectilegrenade.h"
static_assert(sizeof(CArkProjectileGrenade) == 1896);

#include "arkprojectilehomingpsiblast.h"
static_assert(sizeof(CArkProjectileHomingPsiBlast) == 872);

#include "arkprojectileluregrenade.h"
static_assert(sizeof(CArkProjectileLureGrenade) == 1912);

#include "arkprojectilenightmareetherform.h"
static_assert(sizeof(CArkProjectileNightmareEtherForm) == 680);

#include "arkprojectilerecyclergrenade.h"
static_assert(sizeof(CArkProjectileRecyclerGrenade) == 3064);
static_assert(sizeof(CArkProjectileRecyclerGrenade::RecycleEntityInfo) == 3);

#include "arkweapon.h"
static_assert(sizeof(CArkWeapon) == 1216);
static_assert(sizeof(CArkWeapon::ReticleInfo) == 24);
static_assert(sizeof(CArkWeapon::ArkWeaponMods) == 64);
static_assert(sizeof(CArkWeapon::ArkIronsightsTargetInfo) == 16);

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

#include "arkweapondiscrifle.h"
static_assert(sizeof(CArkWeaponDiscRifle) == 1288);

#include "ArkWeaponDoubleWrench.h"
static_assert(sizeof(ArkWeaponDoubleWrench) == 1312);

#include "arkweapongoogun.h"
static_assert(sizeof(CArkWeaponGooGun) == 1280);

#include "arkweapongrenade.h"
static_assert(sizeof(CArkWeaponGrenade) == 1336);

#include "arkweaponinstalaser.h"
static_assert(sizeof(CArkWeaponInstalaser) == 1648);

#include "arkweaponshotgun.h"
static_assert(sizeof(CArkWeaponShotgun) == 1312);

#include "arkweaponstungun.h"
static_assert(sizeof(CArkWeaponStunGun) == 1632);

#include "ArkWeaponUtils.h"
static_assert(sizeof(ArkWeaponUtils) == 1);
static_assert(sizeof(ArkWeaponUtils::PhysicsMaterialInfo) == 64);
static_assert(sizeof(ArkWeaponUtils::ArkExplosionInfo) == 168);

#include "ArkWeaponWrench.h"
static_assert(sizeof(ArkWeaponWrench) == 1376);

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
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/weapons/
#include "ArkEMPBlast.h"
static_assert(sizeof(CArkEMPBlast) == 152);

#include "ArkGooSignalReceiver.h"
static_assert(sizeof(ArkGooSignalReceiver) == 32);

#include "ArkGrenadeSignalReceiver.h"
static_assert(sizeof(ArkGrenadeSignalReceiver) == 32);

#include "ArkPhantomThermogenesisBlast.h"
static_assert(sizeof(CArkPhantomThermogenesisBlast) == 248);

#include "ArkProjectile.h"
static_assert(sizeof(CArkProjectile) == 672);
static_assert(sizeof(CArkProjectile::ArkProjectileEntityEffect) == 280);
static_assert(sizeof(CArkProjectile::ArkProjectileFFEffect) == 136);

#include "ArkProjectileArchetypeGrenade.h"
static_assert(sizeof(CArkProjectileArchetypeGrenade) == 1912);

#include "ArkProjectileBounceGrenade.h"
static_assert(sizeof(CArkProjectileBounceGrenade) == 1912);

#include "ArkProjectileDiscRifle.h"
static_assert(sizeof(CArkProjectileDiscRifle) == 720);

#include "ArkProjectileGoo.h"
static_assert(sizeof(CArkProjectileGoo) == 1680);
static_assert(sizeof(CArkProjectileGoo::ArkGooSpawnParameters) == 88);
static_assert(sizeof(CArkProjectileGoo::GooSpawningProperties) == 20);

#include "ArkProjectileGooBall.h"
static_assert(sizeof(CArkProjectileGooBall) == 800);

#include "ArkProjectileGooGrenade.h"
static_assert(sizeof(CArkProjectileGooGrenade) == 1968);

#include "ArkProjectileGrenade.h"
static_assert(sizeof(CArkProjectileGrenade) == 1904);

#include "ArkProjectileHomingPsiBlast.h"
static_assert(sizeof(CArkProjectileHomingPsiBlast) == 880);

#include "ArkProjectileLureGrenade.h"
static_assert(sizeof(CArkProjectileLureGrenade) == 1928);

#include "ArkProjectileMatter.h"
static_assert(sizeof(CArkProjectileMatter) == 952);

#include "ArkProjectileNightmareEtherForm.h"
static_assert(sizeof(CArkProjectileNightmareEtherForm) == 688);

#include "ArkProjectileRecyclerGrenade.h"
static_assert(sizeof(CArkProjectileRecyclerGrenade) == 2800);

#include "ArkProjectileSolarFlare.h"
static_assert(sizeof(CArkProjectileSolarFlare) == 1168);

#include "ArkProjectileSwordSwipe.h"
static_assert(sizeof(CArkProjectileSwordSwipe) == 720);

#include "ArkTechnopathEMPHazard.h"
static_assert(sizeof(ArkTechnopathEMPHazard) == 1080);

#include "ArkWeapon.h"
static_assert(sizeof(CArkWeapon) == 1608);
static_assert(sizeof(CArkWeapon::ArkIronsightsTargetInfo) == 16);
static_assert(sizeof(CArkWeapon::ArkWeaponEnchant) == 8);
static_assert(sizeof(CArkWeapon::ArkWeaponMods) == 64);
static_assert(sizeof(CArkWeapon::ReticleInfo) == 24);

#include "ArkWeaponDiscRifle.h"
static_assert(sizeof(CArkWeaponDiscRifle) == 1680);

#include "ArkWeaponDoubleWrench.h"
static_assert(sizeof(ArkWeaponDoubleWrench) == 1704);

#include "ArkWeaponGooGun.h"
static_assert(sizeof(CArkWeaponGooGun) == 1664);

#include "ArkWeaponGrenade.h"
static_assert(sizeof(CArkWeaponGrenade) == 1712);

#include "ArkWeaponInstalaser.h"
static_assert(sizeof(CArkWeaponInstalaser) == 2040);

#include "ArkWeaponRapidFire.h"
static_assert(sizeof(CArkWeaponRapidFire) == 1704);

#include "ArkWeaponRecyclizer.h"
static_assert(sizeof(CArkWeaponRecyclizer) == 1680);

#include "ArkWeaponShotgun.h"
static_assert(sizeof(CArkWeaponShotgun) == 1696);

#include "ArkWeaponSkin.h"
static_assert(sizeof(ArkWeaponSkin) == 56);
static_assert(sizeof(ArkWeaponSkin::ArkDescriptionProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkGroupProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkIDProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkIconProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkLabelProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkMaterial1PProperty) == 32);
static_assert(sizeof(ArkWeaponSkin::ArkNameProperty) == 32);
static_assert(sizeof(ArkWeaponSkinGroup) == 32);
static_assert(sizeof(ArkWeaponSkinGroup::ArkIDProperty) == 32);
static_assert(sizeof(ArkWeaponSkinGroup::ArkWeaponsProperty) == 32);
static_assert(sizeof(ArkWeaponSkins) == 56);
static_assert(sizeof(ArkWeaponSkins::ArkGroupsProperty) == 32);
static_assert(sizeof(ArkWeaponSkins::ArkWeaponSkinsProperty) == 32);

#include "ArkWeaponStunGun.h"
static_assert(sizeof(CArkWeaponStunGun) == 2152);

#include "ArkWeaponSword.h"
static_assert(sizeof(ArkWeaponSword) == 2624);

#include "ArkWeaponUtils.h"
static_assert(sizeof(ArkWeaponUtils) == 1);
static_assert(sizeof(ArkWeaponUtils::ArkExplosionInfo) == 168);
static_assert(sizeof(ArkWeaponUtils::PhysicsMaterialInfo) == 64);

#include "ArkWeaponWrench.h"
static_assert(sizeof(ArkWeaponWrench) == 1768);

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

#include "arkfatalityaction.h"
static_assert(sizeof(ArkFatalityAction<ArkWeaponDoubleWrench>) == 208);
static_assert(sizeof(ArkFatalityAction<ArkWeaponWrench>) == 208);

#include "arklaser.h"
static_assert(sizeof(CArkLaserBeam) == 48);
static_assert(sizeof(CArkLaserBeam::ArkLaserParams) == 32);

#include "arkweaponactions.h"
static_assert(sizeof(ArkWeaponAction) == 136);
static_assert(sizeof(ArkWeaponAttackAction) == 136);
static_assert(sizeof(ArkWeaponAttackContinueAction) == 136);
static_assert(sizeof(ArkWeaponAttackContinueMalfunctionAction) == 136);
static_assert(sizeof(ArkWeaponAttackInAction) == 136);
static_assert(sizeof(ArkWeaponAttackOutAction) == 136);
static_assert(sizeof(ArkWeaponAttackOutAndUnselectAction) == 144);
static_assert(sizeof(ArkWeaponDeployAction) == 136);
static_assert(sizeof(ArkWeaponReloadAction) == 136);
static_assert(sizeof(ArkWeaponReloadActionOnEvent) == 136);
static_assert(sizeof(ArkWeaponReloadInAction) == 136);
static_assert(sizeof(ArkWeaponReloadOutAction) == 136);
static_assert(sizeof(ArkWeaponSelectAction) == 144);
static_assert(sizeof(ArkWeaponThrowIdleAction) == 136);
static_assert(sizeof(ArkWeaponThrowInAction) == 136);
static_assert(sizeof(ArkWeaponUnselectAction) == 136);
#endif // !MOONCRASH
