// Header test file for path Prey/GameDll/ark/turret/turretdamagefsm/

#include "arkturretdamagefsm_fsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTurretDamageFsm::Fsm) == 56);
#else
static_assert(sizeof(ArkTurretDamageFsm::Fsm) == 20);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkturretdamagefsm_stateparams.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTurretDamageFsm::StateParams) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTurretDamageFsmBase.h"
static_assert(sizeof(ArkTurretDamageFsmBase_template_<void>) == 20);
#endif
