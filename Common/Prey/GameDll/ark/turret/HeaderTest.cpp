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
