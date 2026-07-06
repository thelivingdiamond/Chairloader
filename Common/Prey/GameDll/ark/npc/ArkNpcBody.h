// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyFsm.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_MultiStageAnimated.h>
#include <_unknown/ArkNpcBodyStateObserver_Trackview.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcAnimActionObserver;
class ArkNpcBodyStateObserver_Busy;
class ArkNpcBodyStateObserver_Dissipate;
class ArkNpcBodyState_Animated;
class ArkNpcBodyState_MultiStageAnimated;
class ArkNpcBodyState_Trackview;
enum class EArkAiTreeSearchReason;
enum class EArkNpcMimicryReason;
struct IEntity;

// ArkNpcBody
// Header:  Prey/GameDll/ark/npc/ArkNpcBody.h
class ArkNpcBody
	: public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_MultiStageAnimated
	, public ArkNpcBodyStateObserver_Trackview
{ // Size=6344 (0x18C8)
public:
	enum class EFallingState
	{
		notFalling = 0,
		maybeFalling = 1,
		falling = 2,
		fallingOutOfGravShaft = 3,
	};

	ArkNpc* m_pNpc;
	ArkNpcBodyFsm m_fsm;
	float m_jumpStartZ;
	bool m_bCanFallFromJump;
	ArkNpcBody::EFallingState m_fallingState;
	float m_fallingStartZ;
	uint64_t m_liftCount;

	ArkNpcBody(ArkNpc& _npc);
	bool Initialize() { return FInitialize(this); }
	bool Finalize() { return FFinalize(this); }
	bool PlayAnimation(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction) { return FPlayAnimationOv1(this, _pAnimAction); }
	bool ForcePlayAnimation(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction) { return FForcePlayAnimationOv1(this, _pAnimAction); }
	bool PlayAnimation_CallForHelp() { return FPlayAnimation_CallForHelp(this); }
	bool PlayAnimation_GetCorrupted() { return FPlayAnimation_GetCorrupted(this); }
	bool PlayAnimation_GloodPose(int _optionIndex) { return FPlayAnimation_GloodPose(this, _optionIndex); }
	bool PlayAnimation_MarkMimickingMimic(ArkNpcAnimActionObserver& _observer) { return FPlayAnimation_MarkMimickingMimic(this, _observer); }
	bool PlayAnimation_MindJackIn() { return FPlayAnimation_MindJackIn(this); }
	bool PlayAnimation_MindJackOut() { return FPlayAnimation_MindJackOut(this); }
	bool PlayAnimation_PatrolIdle(ArkNpcBodyStateObserver_Animated& _observer) { return FPlayAnimation_PatrolIdle(this, _observer); }
	bool PlayAnimation_Scan() { return FPlayAnimation_Scan(this); }
	bool PlayAnimation_WanderIdle() { return FPlayAnimation_WanderIdle(this); }
	bool CanPerformAnimatedAbility() const { return FCanPerformAnimatedAbility(this); }
	bool CanPerformUnanimatedAbility() const { return FCanPerformUnanimatedAbility(this); }
	bool CanPerformHitReactShift() const { return FCanPerformHitReactShift(this); }
	bool PerformAnimatedAbility(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, ArkNpcBodyStateObserver_Animated& _observer) { return FPerformAnimatedAbility(this, _pAnimAction, _observer); }
	bool PerformUnanimatedAbility(ArkNpcBodyStateObserver_Busy& _observer) { return FPerformUnanimatedAbility(this, _observer); }
	bool PerformHitReactShift(ArkNpcBodyStateObserver_Busy& _observer) { return FPerformHitReactShift(this, _observer); }
	bool InterruptAnimatedAbility() { return FInterruptAnimatedAbility(this); }
	bool InterruptUnanimatedAbility() { return FInterruptUnanimatedAbility(this); }
	bool InterruptHitReactShift() { return FInterruptHitReactShift(this); }
	bool IsBurrowing() const { return FIsBurrowing(this); }
	bool IsUnburrowing() const { return FIsUnburrowing(this); }
	bool BeginAnimatedDistraction(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, ArkNpcBodyStateObserver_Animated& _observer) { return FBeginAnimatedDistraction(this, _pAnimAction, _observer); }
	bool EndAnimatedDistraction() { return FEndAnimatedDistraction(this); }
	bool StartBurrowing(ArkNpcAnimActionObserver& _observer) { return FStartBurrowing(this, _observer); }
	bool StartUnburrowing(ArkNpcAnimActionObserver& _observer, uint64_t _unburrowMeleeDamagePackageId) { return FStartUnburrowing(this, _observer, _unburrowMeleeDamagePackageId); }
	bool StartUnburrowingAttack(ArkNpcAnimActionObserver& _observer, uint64_t _unburrowMeleeDamagePackageId) { return FStartUnburrowingAttack(this, _observer, _unburrowMeleeDamagePackageId); }
	bool BeginCowering() { return FBeginCowering(this); }
	bool EndCowering() { return FEndCowering(this); }
	bool IsCowering() const { return FIsCowering(this); }
	bool BeginDead() { return FBeginDead(this); }
	bool Dissipate(ArkNpcBodyStateObserver_Dissipate& _observer) { return FDissipate(this, _observer); }
	bool DodgeLeft() { return FDodgeLeft(this); }
	bool DodgeRight() { return FDodgeRight(this); }
	bool IsFalling() const { return FIsFalling(this); }
	bool CanPerformFatality() const { return FCanPerformFatality(this); }
	bool PerformFatality(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction) { return FPerformFatality(this, _pAnimAction); }
	bool BeginFrozen() { return FBeginFrozen(this); }
	bool EndFrozen() { return FEndFrozen(this); }
	bool Breakout() { return FBreakout(this); }
	bool EnterGravShaft() { return FEnterGravShaft(this); }
	bool ExitGravShaft() { return FExitGravShaft(this); }
	bool HitReact(const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, bool _bBlockMovement) { return FHitReact(this, _pAnimAction, _bBlockMovement); }
	bool IsHitReacting() const { return FIsHitReacting(this); }
	bool BeginHypnotized(unsigned _flareEntityId) { return FBeginHypnotized(this, _flareEntityId); }
	bool EndHypnotized() { return FEndHypnotized(this); }
	bool IsHypnotized() const { return FIsHypnotized(this); }
	bool BeginJump() { return FBeginJump(this); }
	bool EndJump() { return FEndJump(this); }
	void AllowJumpFalling() { FAllowJumpFalling(this); }
	void AddLift() { FAddLift(this); }
	void RemoveLift() { FRemoveLift(this); }
	bool IsLifted() const { return FIsLifted(this); }
	bool BeginLurking(ArkNpcBodyStateObserver_Animated& _observer) { return FBeginLurking(this, _observer); }
	bool EndLurking() { return FEndLurking(this); }
	bool IsLurking() const { return FIsLurking(this); }
	bool BeginMantle() { return FBeginMantle(this); }
	bool EndMantle() { return FEndMantle(this); }
	bool EndMimicry() { return FEndMimicry(this); }
	bool IsMimicking() const { return FIsMimicking(this); }
	unsigned GetMimickedEntityId() const { return FGetMimickedEntityId(this); }
	EArkNpcMimicryReason GetMimicryReason() const { return FGetMimicryReason(this); }
	bool NoticeTargetPosition(const Vec3& _targetPosition, EArkAiTreeSearchReason _searchReason) { return FNoticeTargetPosition(this, _targetPosition, _searchReason); }
	bool RefreshNotice(const Vec3& _targetPosition, const ArkInterval<float>& _interruptDistance, const ArkInterval<float>& _interruptTime) { return FRefreshNotice(this, _targetPosition, _interruptDistance, _interruptTime); }
	bool PushIndefiniteRagdoll() { return FPushIndefiniteRagdoll(this); }
	bool PopIndefiniteRagdoll() { return FPopIndefiniteRagdoll(this); }
	bool Ragdoll(const ArkInterval<float>& _ragdollInterval) { return FRagdoll(this, _ragdollInterval); }
	bool IsRagdolled() const { return FIsRagdolled(this); }
	bool IsStandingUp() const { return FIsStandingUp(this); }
	bool BeginRaised() { return FBeginRaised(this); }
	bool EndRaised() { return FEndRaised(this); }
	bool IsRaised() const { return FIsRaised(this); }
	bool React() { return FReact(this); }
	bool CanRebound() const { return FCanRebound(this); }
	bool Rebound() { return FRebound(this); }
	bool Resist(const Vec3& _forcePosition, float _duration) { return FResist(this, _forcePosition, _duration); }
	bool IsResisting() const { return FIsResisting(this); }
	bool IsScrunched() const { return FIsScrunched(this); }
	bool GiveUpSearch() { return FGiveUpSearch(this); }
	bool BeginSearchExamine() { return FBeginSearchExamine(this); }
	bool EndSearchExamine() { return FEndSearchExamine(this); }
	bool WaitForAnimatedStunned() const { return FWaitForAnimatedStunned(this); }
	bool BeginAnimatedStunned() { return FBeginAnimatedStunned(this); }
	void EndAnimatedStunned() { FEndAnimatedStunned(this); }
	bool ReactToSurprise(unsigned _targetEntityId) { return FReactToSurprise(this, _targetEntityId); }
	bool BeginTrackview(bool _bDisableVision, bool _bDisableHearing, bool _bInterruptable) { return FBeginTrackview(this, _bDisableVision, _bDisableHearing, _bInterruptable); }
	bool EndTrackview() { return FEndTrackview(this); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void PostSerialize() { FPostSerialize(this); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void SerializeRagdoll(TSerialize _serializer) { FSerializeRagdoll(this, _serializer); }
	bool CanBeInstigated() const { return FCanBeInstigated(this); }
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_MultiStageAnimated(const ArkNpcBodyState_MultiStageAnimated& _state);
	virtual void OnNpcBodyStateStateExit_Trackview(const ArkNpcBodyState_Trackview& _state);
	bool SetCurrentStateReady() { return FSetCurrentStateReady(this); }
	bool ForceCurrentStateReady() { return FForceCurrentStateReady(this); }
	void TryFalling(bool _bCheckForFloor) { FTryFalling(this, _bCheckForFloor); }
	void RefreshFalling() { FRefreshFalling(this); }
	bool BeginAnimatedFall() { return FBeginAnimatedFall(this); }
	void BeginOrContinueLift() { FBeginOrContinueLift(this); }

#if 0
	ArkNpcBody(const ArkNpcBody& _arg0_);
	bool InitializeMimicking(IEntity& _arg0_, EArkNpcMimicryReason _arg1_);
	bool CanPlayAnimation() const;
	bool PlayAnimation(const _smart_ptr<ArkNpcAnimAction>& _arg0_, ArkNpcBodyStateObserver_Animated& _arg1_);
	bool ForcePlayAnimation(const _smart_ptr<ArkNpcAnimAction>& _arg0_, ArkNpcBodyStateObserver_Animated& _arg1_);
	bool IsPerformingAnimatedAbility() const;
	bool IsPerformingUnanimatedAbility() const;
	bool IsPerformingHitReactShift() const;
	bool IsPerformingAbility() const;
	bool IsInAnimatedDistraction() const;
	bool IsDead() const;
	bool IsDissipating() const;
	bool IsDodging() const;
	bool CanBeginFalling() const;
	bool IsPerformingFatality() const;
	bool IsFrozen() const;
	bool IsBreakingOut() const;
	bool IsInGravShaft() const;
	bool CanJump() const;
	bool IsJumping() const;
	bool CanMantle() const;
	bool IsMantling() const;
	bool MimicEntity(const IEntity& _arg0_, EArkNpcMimicryReason _arg1_);
	bool MimicAndReplaceEntity(IEntity& _arg0_, EArkNpcMimicryReason _arg1_);
	bool IsNoticing() const;
	bool IsReacting() const;
	bool IsRebounding() const;
	bool IsSearchExamining() const;
	bool IsInAnimatedStunned() const;
	bool IsSurprised() const;
	bool IsInTrackview() const;
	void SerializeMimicry(TSerialize _arg0_);
	ArkNpcBody& operator=(const ArkNpcBody& _arg0_);
	void EndLift();
#endif

	static inline auto FArkNpcBodyOv1 = PreyFunction<void(ArkNpcBody* const _this, ArkNpc& _npc)>(0x1286CC0);
	static inline auto FInitialize = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288CF0);
	static inline auto FFinalize = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288A40);
	static inline auto FPlayAnimationOv1 = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction)>(0x1289590);
	static inline auto FForcePlayAnimationOv1 = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction)>(0x1288B20);
	static inline auto FPlayAnimation_CallForHelp = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289630);
	static inline auto FPlayAnimation_GetCorrupted = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289680);
	static inline auto FPlayAnimation_GloodPose = PreyFunction<bool(ArkNpcBody* const _this, int _optionIndex)>(0x12896D0);
	static inline auto FPlayAnimation_MarkMimickingMimic = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcAnimActionObserver& _observer)>(0x1289720);
	static inline auto FPlayAnimation_MindJackIn = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289810);
	static inline auto FPlayAnimation_MindJackOut = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289860);
	static inline auto FPlayAnimation_PatrolIdle = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcBodyStateObserver_Animated& _observer)>(0x12898B0);
	static inline auto FPlayAnimation_Scan = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289980);
	static inline auto FPlayAnimation_WanderIdle = PreyFunction<bool(ArkNpcBody* const _this)>(0x12899D0);
	static inline auto FCanPerformAnimatedAbility = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288090);
	static inline auto FCanPerformUnanimatedAbility = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288180);
	static inline auto FCanPerformHitReactShift = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288130);
	static inline auto FPerformAnimatedAbility = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, ArkNpcBodyStateObserver_Animated& _observer)>(0x1289300);
	static inline auto FPerformUnanimatedAbility = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcBodyStateObserver_Busy& _observer)>(0x12894F0);
	static inline auto FPerformHitReactShift = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcBodyStateObserver_Busy& _observer)>(0x1289450);
	static inline auto FInterruptAnimatedAbility = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288D60);
	static inline auto FInterruptUnanimatedAbility = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288DC0);
	static inline auto FInterruptHitReactShift = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288D90);
	static inline auto FIsBurrowing = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288DF0);
	static inline auto FIsUnburrowing = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288F10);
	static inline auto FBeginAnimatedDistraction = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, ArkNpcBodyStateObserver_Animated& _observer)>(0x12873B0);
	static inline auto FEndAnimatedDistraction = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288540);
	static inline auto FStartBurrowing = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcAnimActionObserver& _observer)>(0x128AD00);
	static inline auto FStartUnburrowing = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcAnimActionObserver& _observer, uint64_t _unburrowMeleeDamagePackageId)>(0x128AE00);
	static inline auto FStartUnburrowingAttack = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcAnimActionObserver& _observer, uint64_t _unburrowMeleeDamagePackageId)>(0x128AF00);
	static inline auto FBeginCowering = PreyFunction<bool(ArkNpcBody* const _this)>(0x12876D0);
	static inline auto FEndCowering = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288580);
	static inline auto FIsCowering = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E00);
	static inline auto FBeginDead = PreyFunction<bool(ArkNpcBody* const _this)>(0x12877B0);
	static inline auto FDissipate = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcBodyStateObserver_Dissipate& _observer)>(0x1288220);
	static inline auto FDodgeLeft = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288300);
	static inline auto FDodgeRight = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288420);
	static inline auto FIsFalling = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E10);
	static inline auto FCanPerformFatality = PreyFunction<bool(const ArkNpcBody* const _this)>(0x12880E0);
	static inline auto FPerformFatality = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction)>(0x12893A0);
	static inline auto FBeginFrozen = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287830);
	static inline auto FEndFrozen = PreyFunction<bool(ArkNpcBody* const _this)>(0x12885B0);
	static inline auto FBreakout = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287F90);
	static inline auto FEnterGravShaft = PreyFunction<bool(ArkNpcBody* const _this)>(0x12888B0);
	static inline auto FExitGravShaft = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288990);
	static inline auto FHitReact = PreyFunction<bool(ArkNpcBody* const _this, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, bool _bBlockMovement)>(0x1288C50);
	static inline auto FIsHitReacting = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E20);
	static inline auto FBeginHypnotized = PreyFunction<bool(ArkNpcBody* const _this, unsigned _flareEntityId)>(0x1287850);
	static inline auto FEndHypnotized = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288610);
	static inline auto FIsHypnotized = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E30);
	static inline auto FBeginJump = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287990);
	static inline auto FEndJump = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288640);
	static inline auto FAllowJumpFalling = PreyFunction<void(ArkNpcBody* const _this)>(0x1286F60);
	static inline auto FAddLift = PreyFunction<void(ArkNpcBody* const _this)>(0x1286F40);
	static inline auto FRemoveLift = PreyFunction<void(ArkNpcBody* const _this)>(0x128A5F0);
	static inline auto FIsLifted = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E40);
	static inline auto FBeginLurking = PreyFunction<bool(ArkNpcBody* const _this, ArkNpcBodyStateObserver_Animated& _observer)>(0x1287A50);
	static inline auto FEndLurking = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288680);
	static inline auto FIsLurking = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E60);
	static inline auto FBeginMantle = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287B50);
	static inline auto FEndMantle = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288750);
	static inline auto FEndMimicry = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288780);
	static inline auto FIsMimicking = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E70);
	static inline auto FGetMimickedEntityId = PreyFunction<unsigned(const ArkNpcBody* const _this)>(0x1288BA0);
	static inline auto FGetMimicryReason = PreyFunction<EArkNpcMimicryReason(const ArkNpcBody* const _this)>(0x1288BD0);
	static inline auto FNoticeTargetPosition = PreyFunction<bool(ArkNpcBody* const _this, const Vec3& _targetPosition, EArkAiTreeSearchReason _searchReason)>(0x1289170);
	static inline auto FRefreshNotice = PreyFunction<bool(ArkNpcBody* const _this, const Vec3& _targetPosition, const ArkInterval<float>& _interruptDistance, const ArkInterval<float>& _interruptTime)>(0x128A4B0);
	static inline auto FPushIndefiniteRagdoll = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289AD0);
	static inline auto FPopIndefiniteRagdoll = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289A20);
	static inline auto FRagdoll = PreyFunction<bool(ArkNpcBody* const _this, const ArkInterval<float>& _ragdollInterval)>(0x1289D20);
	static inline auto FIsRagdolled = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288E80);
	static inline auto FIsStandingUp = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288EF0);
	static inline auto FBeginRaised = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287D20);
	static inline auto FEndRaised = PreyFunction<bool(ArkNpcBody* const _this)>(0x12887B0);
	static inline auto FIsRaised = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288EC0);
	static inline auto FReact = PreyFunction<bool(ArkNpcBody* const _this)>(0x1289FB0);
	static inline auto FCanRebound = PreyFunction<bool(const ArkNpcBody* const _this)>(0x12881D0);
	static inline auto FRebound = PreyFunction<bool(ArkNpcBody* const _this)>(0x128A190);
	static inline auto FResist = PreyFunction<bool(ArkNpcBody* const _this, const Vec3& _forcePosition, float _duration)>(0x128A630);
	static inline auto FIsResisting = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288ED0);
	static inline auto FIsScrunched = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288EE0);
	static inline auto FGiveUpSearch = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288C00);
	static inline auto FBeginSearchExamine = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287E10);
	static inline auto FEndSearchExamine = PreyFunction<bool(ArkNpcBody* const _this)>(0x12887E0);
	static inline auto FWaitForAnimatedStunned = PreyFunction<bool(const ArkNpcBody* const _this)>(0x128B260);
	static inline auto FBeginAnimatedStunned = PreyFunction<bool(ArkNpcBody* const _this)>(0x12875F0);
	static inline auto FEndAnimatedStunned = PreyFunction<void(ArkNpcBody* const _this)>(0x1288570);
	static inline auto FReactToSurprise = PreyFunction<bool(ArkNpcBody* const _this, unsigned _targetEntityId)>(0x128A090);
	static inline auto FBeginTrackview = PreyFunction<bool(ArkNpcBody* const _this, bool _bDisableVision, bool _bDisableHearing, bool _bInterruptable)>(0x1287F00);
	static inline auto FEndTrackview = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288810);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBody* const _this, float _elapsedTime)>(0x128B210);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcBody* const _this)>(0x1289A50);
	static inline auto FSerialize = PreyFunction<void(ArkNpcBody* const _this, TSerialize _serializer)>(0x128A860);
	static inline auto FSerializeRagdoll = PreyFunction<void(ArkNpcBody* const _this, TSerialize _serializer)>(0x128AA60);
	static inline auto FCanBeInstigated = PreyFunction<bool(const ArkNpcBody* const _this)>(0x1288070);
	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBody* const _this, const ArkNpcBodyState_Animated& _state)>(0x12892A0);
	static inline auto FOnNpcBodyStateStateExit_MultiStageAnimated = PreyFunction<void(ArkNpcBodyStateObserver_MultiStageAnimated* const _this, const ArkNpcBodyState_MultiStageAnimated& _state)>(0x12892D0);
	static inline auto FOnNpcBodyStateStateExit_Trackview = PreyFunction<void(ArkNpcBodyStateObserver_Trackview* const _this, const ArkNpcBodyState_Trackview& _state)>(0x12892F0);
	static inline auto FSetCurrentStateReady = PreyFunction<bool(ArkNpcBody* const _this)>(0x128AC70);
	static inline auto FForceCurrentStateReady = PreyFunction<bool(ArkNpcBody* const _this)>(0x1288A90);
	static inline auto FTryFalling = PreyFunction<void(ArkNpcBody* const _this, bool _bCheckForFloor)>(0x128B000);
	static inline auto FRefreshFalling = PreyFunction<void(ArkNpcBody* const _this)>(0x128A2B0);
	static inline auto FBeginAnimatedFall = PreyFunction<bool(ArkNpcBody* const _this)>(0x1287450);
	static inline auto FBeginOrContinueLift = PreyFunction<void(ArkNpcBody* const _this)>(0x1287BE0);
};
#endif // MOONCRASH
