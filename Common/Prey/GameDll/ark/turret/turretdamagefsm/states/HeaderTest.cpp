// Header test file for path Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h
#include "arkturretdamagefsm_states_base.h"
static_assert(sizeof(ArkTurretDamageFsm::States::Base) == 1);

#include "arkturretdamagefsm_states_damaged.h"
static_assert(sizeof(ArkTurretDamageFsm::States::Damaged) == 1);

#include "arkturretdamagefsm_states_disabled.h"
static_assert(sizeof(ArkTurretDamageFsm::States::Disabled) == 12);

#include "arkturretdamagefsm_states_undamaged.h"
static_assert(sizeof(ArkTurretDamageFsm::States::Undamaged) == 1);
