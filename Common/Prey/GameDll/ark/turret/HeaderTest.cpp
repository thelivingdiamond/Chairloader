// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/turret/ArkDialogTurret.h
#if 0
#include "ArkDialogTurret.h"
static_assert(sizeof(ArkDialogTurret) == 256);

#if 0
#include "arkflownodesturret.h"
static_assert(sizeof(ArkFlowNode_ArkTurret_EnableFlowgraphControl) == 16);
static_assert(sizeof(ArkFlowNode_ArkTurret_ManualTarget) == 16);
static_assert(sizeof(ArkFlowNode_ArkTurret_WeaponProperties) == 16);
#endif

#include "ArkTurret.h"
static_assert(sizeof(ArkTurret) == 3720);

#include "ArkTurretAnimFsm.h"
static_assert(sizeof(ArkTurretAnimFsm::States::Base) == 8);

#include "ArkTurretController.h"
static_assert(sizeof(ArkTurretController) == 176);

#include "ArkTurretDamageFsm.h"
static_assert(sizeof(ArkTurretDamageFsm::Config) == 32);

#include "ArkTurretDialogSpeaker.h"
static_assert(sizeof(ArkTurretDialogSpeaker) == 528);

#include "ArkTurretFsm.h"
static_assert(sizeof(ArkTurretFsm) == 128);

#include "arkturretfsmstates.h"
static_assert(sizeof(ATStates::Undeployed) == 12);
static_assert(sizeof(ATStates::FallenSpazzing) == 24);
static_assert(sizeof(ATStates::Attacking) == 20);
static_assert(sizeof(ATStates::Searching) == 12);
static_assert(sizeof(ATStates::FlowgraphControlled) == 1);
static_assert(sizeof(ATStates::PlayerControlled) == 1);
static_assert(sizeof(ATStates::PlayerCarried) == 1);
static_assert(sizeof(ATStates::Disabled) == 1);

#include "ArkTurretSignalReceiver.h"
static_assert(sizeof(ArkTurretSignalReceiver) == 72);

#include "ArkTurretUtils.h"
static_assert(sizeof(ArkTurretUtils::TurretAngle) == 8);

#include "ArkTurretWeapon.h"
static_assert(sizeof(ArkTurretWeapon) == 208);

#include "ATStates.h"
static_assert(sizeof(ATStates::BaseState) == 1);

#include "CScriptBind_ArkTurret.h"
static_assert(sizeof(CScriptBind_ArkTurret) == 112);
#endif
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/turret/
#include "ArkDialogTurret.h"
static_assert(sizeof(ArkDialogTurret) == 256);

#include "ArkTurret.h"
static_assert(sizeof(ArkTurret) == 3936);

#include "ArkTurretAnimAction.h"
static_assert(sizeof(ArkTurretAdditiveAnimAction) == 128);
static_assert(sizeof(ArkTurretAnimAction) == 136);

#include "ArkTurretCharacter.h"
static_assert(sizeof(ArkTurretCharacter) == 128);

#include "ArkTurretController.h"
static_assert(sizeof(ArkTurretController) == 176);

#include "ArkTurretDialogSpeaker.h"
static_assert(sizeof(ArkTurretDialogSpeaker) == 528);

#include "ArkTurretFsm.h"
static_assert(sizeof(ArkTurretFsm) == 104);

#include "ArkTurretProperties.h"
static_assert(sizeof(ArkTurretProperties) == 416);
static_assert(sizeof(ArkTurretProperties::ArkBehavior) == 24);
static_assert(sizeof(ArkTurretProperties::ArkDamageFsmConfig) == 40);
static_assert(sizeof(ArkTurretProperties::ArkDialog) == 4);
static_assert(sizeof(ArkTurretProperties::ArkFaction) == 24);
static_assert(sizeof(ArkTurretProperties::ArkFalling) == 24);
static_assert(sizeof(ArkTurretProperties::ArkInteractMessages) == 24);
static_assert(sizeof(ArkTurretProperties::ArkMannequin) == 48);
static_assert(sizeof(ArkTurretProperties::ArkWeapon) == 32);
static_assert(sizeof(ArkTurretProperties::Physics) == 4);
static_assert(sizeof(ArkTurretProperties::Sound) == 60);

#include "ArkTurretRandomSpawner.h"
static_assert(sizeof(ArkTurretRandomSpawner) == 96);

#include "ArkTurretSignalReceiver.h"
static_assert(sizeof(ArkTurretSignalReceiver) == 72);

#include "ArkTurretSpawner.h"
static_assert(sizeof(ArkTurretSpawner) == 88);

#include "CScriptBind_ArkTurret.h"
static_assert(sizeof(CScriptBind_ArkTurret) == 112);

#include "arkturretfsmstates.h"
static_assert(sizeof(ArkTurretStates::Attacking) == 48);
static_assert(sizeof(ArkTurretStates::Disabled) == 1);
static_assert(sizeof(ArkTurretStates::PlayerCarried) == 1);
static_assert(sizeof(ArkTurretStates::PlayerControlled) == 1);
static_assert(sizeof(ArkTurretStates::Searching) == 4);
static_assert(sizeof(ArkTurretStates::Undeployed) == 8);
#endif // !MOONCRASH
