// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/IAnimationGraph.h>
#include <Prey/CrySystem/TimeValue.h>
#include <_unknown/Lineseg_tpl.h>
#include <_unknown/SMovementTransitionsSample.h>
#include <_unknown/STransitionFuture.h>

struct AnimEventInstance;
class CAIAnimationComponent;
class CMovementRequest;
class CMovementTransitions;
class CPlayer;
enum class EStance;
class IAction;
class IActionController;
struct IAnimatedCharacter;
class IAnimationDatabase;
struct ICharacterInstance;
struct IEntity;
struct SActorFrameMovementParams;
struct SAnimationContext;
struct SExactPositioningTarget;
struct SGameObjectEvent;
struct STransition;

// CAnimActionMovementTransition
// Header:  Prey/GameDll/MovementTransitionsController.h
class CAnimActionMovementTransition : public TAction<SAnimationContext>
{ // Size=224 (0xE0)
public:
	using TBase = TAction<SAnimationContext>;

	IAnimatedCharacter& m_animChar;
	const STransition* const m_pTransition;
	STransitionFuture m_future;
	SPredictedCharacterStates m_cachedMotionParameters;

	virtual const char* GetName() const;
	virtual void DoDelete();
	virtual IAction::EStatus Update(float timePassed);
	virtual IAction::EStatus UpdatePending(float timePassed);
	virtual void OnAnimationEvent(ICharacterInstance* pCharacter, const AnimEventInstance& event);
	virtual void Exit();
	virtual void OnFragmentStarted();
	static void FillMotionParameters(SPredictedCharacterStates* pMotionParameters, IEntity& entity, const STransition* pTransition, const STransitionFuture& future) { FFillMotionParameters(pMotionParameters, entity, pTransition, future); }

#if 0
	CAnimActionMovementTransition(int _arg0_, IAnimatedCharacter& _arg1_, const STransition* const _arg2_, const STransitionFuture& _arg3_);
	bool EarlyExitStartTransition();
	const STransition* GetTransition() const;
	void DoExplicitStanceChange(CPlayer& _arg0_, CAIAnimationComponent* _arg1_);
	bool FragmentExistsInDatabase(const SAnimationContext& _arg0_, const IAnimationDatabase& _arg1_) const;
	static float CalculateStopLeg(IEntity& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionMovementTransition* const _this)>(0x1899830);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionMovementTransition* const _this)>(0x3E3960);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionMovementTransition* const _this, float timePassed)>(0x189A750);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CAnimActionMovementTransition* const _this, float timePassed)>(0x189B760);
	static inline auto FOnAnimationEvent = PreyFunction<void(CAnimActionMovementTransition* const _this, ICharacterInstance* pCharacter, const AnimEventInstance& event)>(0x1899910);
	static inline auto FExit = PreyFunction<void(CAnimActionMovementTransition* const _this)>(0x1899430);
	static inline auto FOnFragmentStarted = PreyFunction<void(CAnimActionMovementTransition* const _this)>(0x18999A0);
	static inline auto FFillMotionParameters = PreyFunction<void(SPredictedCharacterStates* pMotionParameters, IEntity& entity, const STransition* pTransition, const STransitionFuture& future)>(0x18994E0);
};

// CCornerSmoother
// Header:  Prey/GameDll/MovementTransitionsController.h
class CCornerSmoother
{ // Size=1640 (0x668)
public:
	// CCornerSmoother::SCurveSettings
	// Header:  Prey/GameDll/MovementTransitionsController.h
	struct SCurveSettings
	{ // Size=24 (0x18)
		float wrongWaySpeed;
		float speedSmoothTime;
		float walkSmoothTime;
		float walkSpeed;
		float runSmoothTime;
		float runSpeed;
	};

	// CCornerSmoother::SPredictionSettings
	// Header:  Prey/GameDll/MovementTransitionsController.h
	struct SPredictionSettings
	{ // Size=56 (0x38)
		const CCornerSmoother::SCurveSettings* pCurveSettings;
		Vec3 playerPos;
		float oldMovementSpeed;
		Vec2 dir2D;
		float desiredSpeed;
		Vec3 moveTarget;
		float maxTurnSpeed;
		float travelSpeedRate;
	};

	// CCornerSmoother::SPrediction
	// Header:  Prey/GameDll/MovementTransitionsController.h
	struct SPrediction
	{ // Size=804 (0x324)
		int numSamples;
		Vec2 samples[100];

	#if 0
		SPrediction();
		void Reset();
	#endif
	};

	static constexpr const int MAX_SAMPLES = 100;
	static constexpr const int MAX_PREDICTIONS_PER_FRAME = 6;
	static inline auto m_lastPredictionFrameID = PreyGlobal<int>(0x2D8E60C);
	static inline auto m_numPredictionsThisFrame = PreyGlobal<int>(0x2D8E610);
	static inline auto normalCurveSettings = PreyGlobal<CCornerSmoother::SCurveSettings>(0x23F0778);
	CPlayer* m_pPlayer;
	Vec3 m_oldMoveTarget;
	float m_dirSmoothTime;
	CCornerSmoother::SPrediction m_prediction;
	CCornerSmoother::SPrediction m_simplePrediction;
	float m_travelSpeedRate;
	float m_maxTurnSpeed;

	void Reset() { FReset(this); }
	void Update(const Vec3& playerPos, const Vec2& oldMovementDir, const float oldMovementSpeed, const Vec3& animBodyDirection, const float desiredSpeed, const Vec3& desiredMovement, const float distToPathEnd, const Vec3& moveTarget, const bool hasLockedBodyTarget, const float maxTurnSpeed, const float frameTime, float* const pNewDesiredSpeed, Vec3* const pNewDesiredMovement) { FUpdate(this, playerPos, oldMovementDir, oldMovementSpeed, animBodyDirection, desiredSpeed, desiredMovement, distToPathEnd, moveTarget, hasLockedBodyTarget, maxTurnSpeed, frameTime, pNewDesiredSpeed, pNewDesiredMovement); }
	void PredictAndVerifySmoothTurn(const CCornerSmoother::SPredictionSettings& settings) { FPredictAndVerifySmoothTurn(this, settings); }
	static void PredictSmoothTurn(const CCornerSmoother::SPredictionSettings& settings, CCornerSmoother::SPrediction* const pPrediction) { FPredictSmoothTurn(settings, pPrediction); }
	static void SimplifyPrediction(const Vec3& playerPos, const CCornerSmoother::SPrediction& input, CCornerSmoother::SPrediction* const pOutput) { FSimplifyPrediction(playerPos, input, pOutput); }
	static float CalculateDirSmoothTime(const CCornerSmoother::SCurveSettings& settings, const float desiredSpeed, const float distToMoveTarget2D, const float endOfPathDistance) { return FCalculateDirSmoothTime(settings, desiredSpeed, distToMoveTarget2D, endOfPathDistance); }

#if 0
	CCornerSmoother(CPlayer* _arg0_);
	bool IsRunning() const;
	void Cancel();
	void DebugRender(float _arg0_);
	void SmoothLocalVDir(Vec3* const _arg0_, const float _arg1_) const;
	float GetMaxTurnSpeed() const;
	void UpdatePathFollowerState() const;
	static bool CheckWalkability(const CCornerSmoother::SPrediction& _arg0_, CPlayer* _arg1_);
	static bool EnoughTimePassedSinceLastPrediction(const int _arg0_);
	static void RememberLastPredictionFrameID(const int _arg0_);
#endif

	static inline auto FReset = PreyFunction<void(CCornerSmoother* const _this)>(0x189A420);
	static inline auto FUpdate = PreyFunction<void(CCornerSmoother* const _this, const Vec3& playerPos, const Vec2& oldMovementDir, const float oldMovementSpeed, const Vec3& animBodyDirection, const float desiredSpeed, const Vec3& desiredMovement, const float distToPathEnd, const Vec3& moveTarget, const bool hasLockedBodyTarget, const float maxTurnSpeed, const float frameTime, float* const pNewDesiredSpeed, Vec3* const pNewDesiredMovement)>(0x189AB60);
	static inline auto FPredictAndVerifySmoothTurn = PreyFunction<void(CCornerSmoother* const _this, const CCornerSmoother::SPredictionSettings& settings)>(0x1899AC0);
	static inline auto FPredictSmoothTurn = PreyFunction<void(const CCornerSmoother::SPredictionSettings& settings, CCornerSmoother::SPrediction* const pPrediction)>(0x1899C70);
	static inline auto FSimplifyPrediction = PreyFunction<void(const Vec3& playerPos, const CCornerSmoother::SPrediction& input, CCornerSmoother::SPrediction* const pOutput)>(0x189A5A0);
	static inline auto FCalculateDirSmoothTime = PreyFunction<float(const CCornerSmoother::SCurveSettings& settings, const float desiredSpeed, const float distToMoveTarget2D, const float endOfPathDistance)>(0x1899330);
};

// CMovementTransitionsController
// Header:  Prey/GameDll/MovementTransitionsController.h
class CMovementTransitionsController
{ // Size=184 (0xB8)
public:
	CPlayer* m_pPlayer;
	CMovementTransitions* m_pMovementTransitions;
	Lineseg_tpl<float> m_safeLine;
	uint8_t m_allowedTransitionFlags;
	uint8_t m_blockTransitionFlagsFilter;
	float m_prevEntitySpeed2D;
	CTimeValue m_runStartTime;
	bool m_bUpdateAIMinSpeeds;
	float m_minSpeedForWalkStop;
	float m_minSpeedForRunStop;
	float m_minSpeedForWalkJuke;
	float m_minSpeedForRunJuke;
	SMovementTransitionsSample m_oldMovementSample;
	SMovementTransitionsSample m_newMovementSample;
	EMovementTransitionState m_state;
	_smart_ptr<IAction> m_pAnimAction;
	_smart_ptr<IAction> m_pPendingAnimAction;

	CMovementTransitionsController(CPlayer* pPlayer);
	~CMovementTransitionsController();
	void Reset() { FReset(this); }
	void Update(const Vec3& playerPos, const float newPseudoSpeed, const Vec3& currentBodyDirection, const Vec3& newMoveDirection, const bool bHasLockedBodyTarget, const SExactPositioningTarget* const pExactPositioningTarget, CMovementRequest* const pRequest, SActorFrameMovementParams* const pMoveParams, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType) { FUpdate(this, playerPos, newPseudoSpeed, currentBodyDirection, newMoveDirection, bHasLockedBodyTarget, pExactPositioningTarget, pRequest, pMoveParams, pJukeTurnRateFraction, pBodyTarget, pBodyTargetType); }
	void UpdatePathFollowerState() { FUpdatePathFollowerState(this); }
	bool HandleEvent(const SGameObjectEvent& event) { return FHandleEvent(this, event); }
	bool RequestTransition(const char* szFragmentID, const STransition* const pTransition, const STransitionFuture& future) { return FRequestTransition(this, szFragmentID, pTransition, future); }
	void CancelTransition() { FCancelTransition(this); }
	EStance GetUpcomingStance() const { return FGetUpcomingStance(this); }
	bool IsChangingDirection() const { return FIsChangingDirection(this); }

#if 0
	bool IsEnabled() const;
	bool IsTransitionRequestedOrPlaying() const;
	void BlockTransitionFlags(uint8_t _arg0_);
	void UpdateSafeLine(const CMovementRequest& _arg0_, const Vec3& _arg1_, const Vec3& _arg2_);
	CTimeValue UpdateRunningDuration(const float _arg0_);
	IActionController* GetActionController() const;
#endif

	static inline auto FCMovementTransitionsControllerOv1 = PreyFunction<void(CMovementTransitionsController* const _this, CPlayer* pPlayer)>(0x18991B0);
	static inline auto FBitNotCMovementTransitionsController = PreyFunction<void(CMovementTransitionsController* const _this)>(0x18992D0);
	static inline auto FReset = PreyFunction<void(CMovementTransitionsController* const _this)>(0x189A450);
	static inline auto FUpdate = PreyFunction<void(CMovementTransitionsController* const _this, const Vec3& playerPos, const float newPseudoSpeed, const Vec3& currentBodyDirection, const Vec3& newMoveDirection, const bool bHasLockedBodyTarget, const SExactPositioningTarget* const pExactPositioningTarget, CMovementRequest* const pRequest, SActorFrameMovementParams* const pMoveParams, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType)>(0x189B110);
	static inline auto FUpdatePathFollowerState = PreyFunction<void(CMovementTransitionsController* const _this)>(0x189B680);
	static inline auto FHandleEvent = PreyFunction<bool(CMovementTransitionsController* const _this, const SGameObjectEvent& event)>(0x1899870);
	static inline auto FRequestTransition = PreyFunction<bool(CMovementTransitionsController* const _this, const char* szFragmentID, const STransition* const pTransition, const STransitionFuture& future)>(0x189A180);
	static inline auto FCancelTransition = PreyFunction<void(CMovementTransitionsController* const _this)>(0x18993A0);
	static inline auto FGetUpcomingStance = PreyFunction<EStance(const CMovementTransitionsController* const _this)>(0x1899840);
	static inline auto FIsChangingDirection = PreyFunction<bool(const CMovementTransitionsController* const _this)>(0x18998E0);
};
#endif // MOONCRASH
