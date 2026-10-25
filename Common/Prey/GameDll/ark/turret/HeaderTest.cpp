// Header test file for path Prey/GameDll/ark/turret/

#include "ArkDialogTurret.h"
static_assert(sizeof(ArkDialogTurret) == 256);

// Disabled: base build fails inside this header (C1083: Cannot open include file: 'Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h': No such file or d)
//#include "arkflownodesturret.h"
//#ifndef MOONCRASH
//static_assert(sizeof(ArkFlowNode_ArkTurret_EnableFlowgraphControl) == 16);
//static_assert(sizeof(ArkFlowNode_ArkTurret_ManualTarget) == 16);
//static_assert(sizeof(ArkFlowNode_ArkTurret_WeaponProperties) == 16);
//#endif

// Disabled: base build cannot reach this header (gamedll/ark/turret/arkturretweapon.h -> Prey/GameDll/ark/npc/ArkNpcUtils.h)
//#include "ArkTurret.h"
//#ifndef MOONCRASH
//static_assert(sizeof(ArkTurret) == 3720);
//#else
//static_assert(sizeof(ArkTurret) == 3936);
//#endif

#include "ArkTurretAnimFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretAnimFsm::States::Base) == 8);
#endif

#include "ArkTurretController.h"
static_assert(sizeof(ArkTurretController) == 176);

#include "ArkTurretDamageFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretDamageFsm::Config) == 32);
#endif

#include "ArkTurretDialogSpeaker.h"
static_assert(sizeof(ArkTurretDialogSpeaker) == 528);

#include "ArkTurretFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretFsm) == 128);
#else
static_assert(sizeof(ArkTurretFsm) == 104);
#endif

#include "arkturretfsmstates.h"
#ifndef MOONCRASH
static_assert(sizeof(ATStates::Undeployed) == 12);
static_assert(sizeof(ATStates::FallenSpazzing) == 24);
static_assert(sizeof(ATStates::Attacking) == 20);
static_assert(sizeof(ATStates::Searching) == 12);
static_assert(sizeof(ATStates::FlowgraphControlled) == 1);
static_assert(sizeof(ATStates::PlayerControlled) == 1);
static_assert(sizeof(ATStates::PlayerCarried) == 1);
static_assert(sizeof(ATStates::Disabled) == 1);
#endif
#ifdef MOONCRASH
static_assert(sizeof(ATStates::Attacking) == 48);
static_assert(sizeof(ATStates::Disabled) == 1);
static_assert(sizeof(ATStates::PlayerCarried) == 1);
static_assert(sizeof(ATStates::PlayerControlled) == 1);
static_assert(sizeof(ATStates::Searching) == 4);
static_assert(sizeof(ATStates::Undeployed) == 8);
#endif

#include "ArkTurretSignalReceiver.h"
static_assert(sizeof(ArkTurretSignalReceiver) == 72);

#include "ArkTurretUtils.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretUtils::TurretAngle) == 8);
#endif

// Disabled: base build fails inside this header (C1083: Cannot open include file: 'Prey/GameDll/ark/npc/ArkNpcUtils.h': No such file or directory)
//#include "ArkTurretWeapon.h"
//#ifndef MOONCRASH
//static_assert(sizeof(ArkTurretWeapon) == 208);
//#endif

#include "ATStates.h"
static_assert(sizeof(ATStates::BaseState) == 1);

#include "CScriptBind_ArkTurret.h"
static_assert(sizeof(CScriptBind_ArkTurret) == 112);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretAnimAction.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTurretAdditiveAnimAction) == 128);
static_assert(sizeof(ArkTurretAnimAction) == 136);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretCharacter.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTurretCharacter) == 128);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretProperties.h"
#ifdef MOONCRASH
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
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretRandomSpawner.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTurretRandomSpawner) == 96);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretSpawner.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTurretSpawner) == 88);
#endif
#endif
