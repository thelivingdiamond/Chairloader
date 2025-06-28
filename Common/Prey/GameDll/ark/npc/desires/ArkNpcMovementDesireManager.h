#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryAISystem/MovementRequest.h>
#include <Prey/CryAISystem/MovementRequestStatus.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireManagerBase.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/ArkStubs.h>

class ArkNpc;

// Header: Exact
// CryEngine/crymovie/animsplinetrack.h
class ArkNpcMovementDesireManager : public ArkNpcDesireManagerBase<ArkNpcMovementDesireManager,ArkNpcMovementDesire> // Id=8014112 Size=232
{
public:
    MovementRequestID m_movementRequestId;
    MovementRequestID m_stopRequestId;
    ArkNpcFacingDesire m_facingDesire;
    bool m_bNeedsStop;
    bool m_bNeedsNavMeshReturn;

    ArkNpcMovementDesireManager(ArkNpc &_arkNpc);
    void Refresh() { FRefresh(this); }
    bool HasMovementRequest() const { return FHasMovementRequest(this); }
    MovementRequestID GetMovementRequestId() const { return FGetMovementRequestId(this); }
    bool IsMovementInterruptible() const { return FIsMovementInterruptible(this); }
    bool IsShifting() const { return FIsShifting(this); }
    bool IsJumping() const { return FIsJumping(this); }
    void ShutDown() { FShutDown(this); }
    void Replan() { FReplan(this); }
    void CancelMovement() { FCancelMovement(this); }
    void OnActiveDesireAdded(ArkNpcMovementDesire const *_pPrevActiveDesire) { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
    void OnActiveDesireRemoved(ArkNpcMovementDesire const &_prevActiveDesire) { FOnActiveDesireRemoved(this,_prevActiveDesire); }
    void OnActiveParamsChanged() { FOnActiveParamsChanged(this); }
    void OnActiveResumeDistanceChanged() { FOnActiveResumeDistanceChanged(this); }
    bool TryToResumeMovement() { return FTryToResumeMovement(this); }
    bool TryToRequestMovement() { return FTryToRequestMovement(this); }
    bool TryToReturnToNavMesh() { return FTryToReturnToNavMesh(this); }
    void RequestExactPosition(ArkNpcMovementDesire const &_desire, MovementRequest &_request) { FRequestExactPosition(this,_desire,_request); }
    void SetStance(MovementRequest &_request) { FSetStance(this,_request); }
    void StopMovement() { FStopMovement(this); }
    void MovementRequestCallback(MovementRequestResult const &_result) { FMovementRequestCallback(this,_result); }
    void StopRequestCallback(MovementRequestResult const &_result) { FStopRequestCallback(this,_result); }
    void NavMeshReturnCallback(MovementRequestResult const &_result) { FNavMeshReturnCallback(this,_result); }
    void FailDesire(ArkNpcMovementDesire &_activeDesire, MovementRequestResult::FailureReason _failureReason) { FFailDesire(this,_activeDesire,_failureReason); }
    void FulfillDesire(ArkNpcMovementDesire &_activeDesire) { FFulfillDesire(this,_activeDesire); }

#if 0
    void ActivateDesire(ArkNpcMovementDesire const &arg0) const;
	void DeactivateDesire(ArkNpcMovementDesire const &arg0) const;
	void DebugDraw();
#endif

    static inline auto FRefresh = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x1527850);
    static inline auto FHasMovementRequest = PreyFunction<bool(ArkNpcMovementDesireManager const *const _this)>(0x1527370);
    static inline auto FGetMovementRequestId = PreyFunction<MovementRequestID(ArkNpcMovementDesireManager const *const _this)>(0x9EF7F0);
    static inline auto FIsMovementInterruptible = PreyFunction<bool(ArkNpcMovementDesireManager const *const _this)>(0x15273C0);
    static inline auto FIsShifting = PreyFunction<bool(ArkNpcMovementDesireManager const *const _this)>(0x1527400);
    static inline auto FIsJumping = PreyFunction<bool(ArkNpcMovementDesireManager const *const _this)>(0x1527380);
    static inline auto FShutDown = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x1527E60);
    static inline auto FReplan = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x15279D0);
    static inline auto FCancelMovement = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x1527240);
    static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcMovementDesireManager *const _this, ArkNpcMovementDesire const *_pPrevActiveDesire)>(0x15275D0);
    static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcMovementDesireManager *const _this, ArkNpcMovementDesire const &_prevActiveDesire)>(0x1527680);
    static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x15277A0);
    static inline auto FOnActiveResumeDistanceChanged = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x1527810);
    static inline auto FTryToResumeMovement = PreyFunction<bool(ArkNpcMovementDesireManager *const _this)>(0x1528420);
    static inline auto FTryToRequestMovement = PreyFunction<bool(ArkNpcMovementDesireManager *const _this)>(0x1527FC0);
    static inline auto FTryToReturnToNavMesh = PreyFunction<bool(ArkNpcMovementDesireManager *const _this)>(0x15284F0);
    static inline auto FRequestExactPosition = PreyFunction<void(ArkNpcMovementDesireManager *const _this, ArkNpcMovementDesire const &_desire, MovementRequest &_request)>(0x15279F0);
    static inline auto FSetStance = PreyFunction<void(ArkNpcMovementDesireManager *const _this, MovementRequest &_request)>(0x1527D20);
    static inline auto FStopMovement = PreyFunction<void(ArkNpcMovementDesireManager *const _this)>(0x1527EC0);
    static inline auto FMovementRequestCallback = PreyFunction<void(ArkNpcMovementDesireManager *const _this, MovementRequestResult const &_result)>(0x1527440);
    static inline auto FStopRequestCallback = PreyFunction<void(ArkNpcMovementDesireManager *const _this, MovementRequestResult const &_result)>(0x1527FB0);
    static inline auto FNavMeshReturnCallback = PreyFunction<void(ArkNpcMovementDesireManager *const _this, MovementRequestResult const &_result)>(0x1527510);
    static inline auto FFailDesire = PreyFunction<void(ArkNpcMovementDesireManager *const _this, ArkNpcMovementDesire &_activeDesire, MovementRequestResult::FailureReason _failureReason)>(0x15272D0);
    static inline auto FFulfillDesire = PreyFunction<void(ArkNpcMovementDesireManager *const _this, ArkNpcMovementDesire &_activeDesire)>(0x1527320);
};



