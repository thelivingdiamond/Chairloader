// Header test file for path Prey/GameDll/ark/turret/turretanimfsm/

#include "arkturretanimfsm_fsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretAnimFsm::Fsm) == 80);
#endif

#include "arkturretanimfsm_states.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretAnimFsm::States::Undeployed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Deploying) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Deployed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::UnDeploying) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Destroyed) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Broken) == 8);
static_assert(sizeof(ArkTurretAnimFsm::States::Search) == 8);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretAnimFsmBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretAnimFsmBase_template_<void>) == 64);
#endif
#endif
