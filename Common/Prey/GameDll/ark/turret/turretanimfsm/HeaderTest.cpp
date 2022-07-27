// Header test file for path Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_fsm.h
#include "arkturretanimfsm_fsm.h"
static_assert(sizeof(ArkTurretAnimFsm::Fsm) == 80);

#include "arkturretanimfsm_states.h"
static_assert(sizeof(ArkTurretAnimFsm::States::Undeployed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Deploying) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Deployed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::UnDeploying) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Destroyed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Broken) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Search) == 8);
