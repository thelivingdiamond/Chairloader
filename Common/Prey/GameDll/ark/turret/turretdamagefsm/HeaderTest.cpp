// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/turret/turretdamagefsm/arkturretdamagefsm_fsm.h
#if 0
#include "arkturretdamagefsm_fsm.h"
static_assert(sizeof(ArkTurretDamageFsm::Fsm) == 56);
#endif
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/turret/turretdamagefsm/
#include "arkturretdamagefsm_fsm.h"
static_assert(sizeof(ArkTurretDamageFsm::Fsm) == 20);

#include "arkturretdamagefsm_stateparams.h"
static_assert(sizeof(ArkTurretDamageFsm::StateParams) == 16);
#endif // !MOONCRASH
