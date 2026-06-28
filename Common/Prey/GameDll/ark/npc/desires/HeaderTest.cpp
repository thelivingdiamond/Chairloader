// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
//
// Created by theli on 8/23/2022.
//

#include "ArkNpcDesireBase.h"
#include "ArkNpcSpeedDesireManager.h"

static_assert(sizeof(ArkNpcDesireBase<ArkNpcSpeedDesireManager,ArkNpcSpeedDesire,EArkNpcSpeedDesirePriority>) == 64);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/desires/
#include "ArkNpcDesireTarget.h"
static_assert(sizeof(ArkNpcAttentionProxyDesireTargetImpl) == 28);
static_assert(sizeof(ArkNpcCameraDesireTargetImpl) == 16);
static_assert(sizeof(ArkNpcDesireTarget) == 36);
static_assert(sizeof(ArkNpcEntityBoneDesireTargetImpl) == 24);
static_assert(sizeof(ArkNpcEntityBoundsCenterTargetImpl) == 20);
static_assert(sizeof(ArkNpcEntityDesireTargetImpl) == 20);

#include "ArkNpcFacingDesire.h"
static_assert(sizeof(ArkNpcFacingDesire) == 168);
static_assert(sizeof(ArkNpcFacingDesire::MaintainTurnAlignParam) == 8);
static_assert(sizeof(ArkNpcFacingDesire::MinSpeedParam) == 4);
static_assert(sizeof(ArkNpcFacingDesire::TargetParam) == 8);

#include "ArkNpcFacingDesireManager.h"
static_assert(sizeof(ArkNpcFacingDesireManager) == 48);

#include "ArkNpcLookDesire.h"
static_assert(sizeof(ArkNpcLookDesire) == 224);
static_assert(sizeof(ArkNpcLookDesire::AimParam) == 1);
static_assert(sizeof(ArkNpcLookDesire::AllowLowerBodyTurnParam) == 1);
static_assert(sizeof(ArkNpcLookDesire::BlendTimeParam) == 32);
static_assert(sizeof(ArkNpcLookDesire::BodyOrientationParam) == 4);
static_assert(sizeof(ArkNpcLookDesire::LookPoseParam) == 16);
static_assert(sizeof(ArkNpcLookDesire::MaxAngleParam) == 32);
static_assert(sizeof(ArkNpcLookDesire::MinSpeedParam) == 4);
static_assert(sizeof(ArkNpcLookDesire::PolarOffsetParam) == 8);
static_assert(sizeof(ArkNpcLookDesire::SmoothTimeParam) == 16);
static_assert(sizeof(ArkNpcLookDesire::StyleParam) == 4);
static_assert(sizeof(ArkNpcLookDesire::TargetParam) == 8);

#include "ArkNpcLookDesireManager.h"
static_assert(sizeof(ArkNpcLookDesireManager) == 152);

#include "ArkNpcMovementDesire.h"
static_assert(sizeof(ArkNpcMovementDesire) == 248);
static_assert(sizeof(ArkNpcMovementDesire::AccelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ContinueMovingParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::DecelLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::DestinationParam) == 8);
static_assert(sizeof(ArkNpcMovementDesire::DisableNavMeshQueryParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::EnableNavMeshQueryParam) == 12);
static_assert(sizeof(ArkNpcMovementDesire::ErrorParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForceGoToNavMeshParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ForcePathParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::HoverParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::JumpParam) == 16);
static_assert(sizeof(ArkNpcMovementDesire::ObstacleAvoidanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::ScriptMoveParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::ShiftParam) == 24);
static_assert(sizeof(ArkNpcMovementDesire::SpeedLiteralParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::StanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::StopDistanceParam) == 4);
static_assert(sizeof(ArkNpcMovementDesire::StrafeParam) == 1);
static_assert(sizeof(ArkNpcMovementDesire::UseExactPositionParam) == 20);

#include "ArkNpcMovementDesireManager.h"
static_assert(sizeof(ArkNpcMovementDesireManager) == 232);

#include "ArkNpcNoiseStateDesire.h"
static_assert(sizeof(ArkNpcNoiseStateDesire) == 72);
static_assert(sizeof(ArkNpcNoiseStateDesire::StateParam) == 4);

#include "ArkNpcNoiseStateDesireManager.h"
static_assert(sizeof(ArkNpcNoiseStateDesireManager) == 80);

#include "ArkNpcSpeedDesire.h"
static_assert(sizeof(ArkNpcSpeedDesire) == 88);
static_assert(sizeof(ArkNpcSpeedDesire::SpeedParam) == 4);
static_assert(sizeof(ArkNpcSpeedDesire::TurnSpeedLiteralParam) == 4);

#include "ArkNpcSpeedDesireManager.h"
static_assert(sizeof(ArkNpcSpeedDesireManager) == 64);
#endif // !MOONCRASH
