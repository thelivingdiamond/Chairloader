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
