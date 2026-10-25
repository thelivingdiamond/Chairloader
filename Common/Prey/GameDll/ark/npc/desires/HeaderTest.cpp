// Header test file for path Prey/GameDll/ark/npc/desires/

#include "ArkNpcDesireBase.h"

#include "ArkNpcSpeedDesireManager.h"
static_assert(sizeof(ArkNpcSpeedDesireManager) == 64);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcMovementDesire.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcMovementDesire) == 248);
static_assert(sizeof(ArkNpcMovementDesire::DestinationParam) == 8);
static_assert(sizeof(ArkNpcMovementDesire::EnableNavMeshQueryParam) == 12);
static_assert(sizeof(ArkNpcMovementDesire::DisableNavMeshQueryParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForcePathParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForceGoToNavMeshParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::StanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::SpeedLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::AccelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::DecelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::StopDistanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::UseExactPositionParam) == 20);
static_assert(sizeof(ArkNpcMovementDesire::ShiftParam) == 24);
static_assert(sizeof(ArkNpcMovementDesire::JumpParam) == 16);
static_assert(sizeof(ArkNpcMovementDesire::HoverParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ContinueMovingParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ScriptMoveParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ObstacleAvoidanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ErrorParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::StrafeParam) == 1);
#endif
#endif
