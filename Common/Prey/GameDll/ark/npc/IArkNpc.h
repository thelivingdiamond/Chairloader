// Header file automatically created from a PDB.

#pragma once

//class MovementStyle;
#include <Prey/CryCore/StdAfx.h>
#include "Prey/CryAISystem/MovementStyle.h"


// Header: MadeUp
// _unknown/IArkNpc.h
class IArkNpc // Id=80020DF Size=8
{
public:
	virtual void InitializeTrackviewTempNpc() = 0;
	virtual void OnAnimatedMovement_Start() = 0;
	virtual void OnAnimatedMovement_Stop() = 0;
	virtual bool IsMovementAnimated() const = 0;
	virtual void OnJumpAnimActionSequence_Start() = 0;
	virtual void OnJumpAnimActionSequence_Stop() = 0;
	virtual void OnJumpAnimAction_Fall() = 0;
	virtual void OnMantleAnimAction_Start() = 0;
	virtual void OnMantleAnimAction_Stop() = 0;
	virtual bool PerformMimicReorientation(Vec2 const &arg0) = 0;
	virtual void PerformMimicGlitch() = 0;
	virtual void StopMimicGlitch() = 0;
	virtual unsigned GetTopAttentionTargetEntityId() const = 0;
	virtual void OnTargetDead(unsigned arg0) = 0;
	virtual void ShiftTelegraph(MovementStyle::ShiftType arg0) = 0;
	virtual void ShiftBegin(MovementStyle::ShiftType arg0) = 0;
	virtual void ShiftEnd(MovementStyle::ShiftType arg0) = 0;
	virtual bool SupportsLookAt() const = 0;
	virtual bool IsGlooSlow() const = 0;
	virtual bool IsFalling() const = 0;
	virtual void SetBreakGlooEntity(unsigned arg0) = 0;
	virtual void BreakGlooEntity() = 0;
	virtual void ForceMovementReplan() = 0;
	virtual void ForceReevaluateMovementAnimAction() = 0;
	virtual void CancelMovement() = 0;
	virtual void PushDisableHitReactions() = 0;
	virtual void PopDisableHitReactions() = 0;
	virtual void PushAIAlwaysUpdate() = 0;
	virtual void PopAIAlwaysUpdate() = 0;
	virtual void ResetAIAlwaysUpdate() = 0;
};

