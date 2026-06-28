// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/Lineseg_tpl.h>
#include <_unknown/STransitionFuture.h>

class CMovementRequest;
class CMovementTransitions;
class CMovementTransitionsController;
class CPlayer;
class CTimeValue;
enum EMovementTransitionState;
struct IAnimationGraphState;
class ICrySizer;
struct IItemParamsNode;
struct SActorFrameMovementParams;
struct SExactPositioningTarget;
struct SMovementTransitionsSample;
struct STransitionMatch;
struct STransitionSelectionParams;

// STransition
// Header:  Prey/GameDll/MovementTransitions.h
struct STransition
{ // Size=88 (0x58)
	string animGraphSignal;
	ETransitionType transitionType;
	EStance stance;
	unsigned context;
	float pseudoSpeed;
	float minDistance;
	float desiredTravelAngle;
	float travelAngleTolerance;
	float maxDistance;
	float prepareDistance;
	float prepareTravelAngleTolerance;
	float desiredTargetTravelAngle;
	float targetTravelAngleTolerance;
	float desiredArrivalAngle;
	float arrivalAngleTolerance;
	float desiredJukeAngle;
	float jukeAngleTolerance;
	EStance targetStance;
	float exit2ndSeg;
	float desiredBodyTurnAngle;
	float bodyTurnAngleTolerance;

	EMovementTransitionState Update(const CMovementTransitions& transitions, const STransitionSelectionParams& transParams, const STransitionMatch& match, const Vec3& playerPos, const Vec3& oldMoveDirection, const Vec3& newMoveDirection, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType, CPlayer* const pPlayer, CMovementTransitionsController* const pController) const { return FUpdate(this, transitions, transParams, match, playerPos, oldMoveDirection, newMoveDirection, pJukeTurnRateFraction, pBodyTarget, pBodyTargetType, pPlayer, pController); }
	bool ReadParams(ETransitionType _transitionType, const IItemParamsNode* const pParams) { return FReadParams(this, _transitionType, pParams); }
	bool ReadStanceParam(const char* name, bool required, const IItemParamsNode* const pParams, EStance* const pStance) const { return FReadStanceParam(this, name, required, pParams, pStance); }

#if 0
	bool IsMatch(const STransitionSelectionParams& _arg0_, STransitionMatch* const _arg1_) const;
	bool CheckSpaceToPerformTransition(const CMovementTransitions& _arg0_, const STransitionSelectionParams& _arg1_, const Vec3& _arg2_, const Vec3& _arg3_, CPlayer* const _arg4_) const;
	void Execute(const STransitionMatch& _arg0_, IAnimationGraphState* const _arg1_) const;
	bool ReadPseudoSpeedParam(const char* _arg0_, bool _arg1_, const IItemParamsNode* const _arg2_, float* const _arg3_) const;
	bool ReadIntParam(const char* _arg0_, bool _arg1_, int _arg2_, int _arg3_, const IItemParamsNode* const _arg4_, int* const _arg5_) const;
	bool ReadFloatParam(const char* _arg0_, bool _arg1_, float _arg2_, float _arg3_, const IItemParamsNode* const _arg4_, float* const _arg5_) const;
	bool ReadAngleParam(const char* _arg0_, bool _arg1_, float _arg2_, float _arg3_, const IItemParamsNode* const _arg4_, float* const _arg5_) const;
#endif

	static inline auto FUpdate = PreyFunction<EMovementTransitionState(const STransition* const _this, const CMovementTransitions& transitions, const STransitionSelectionParams& transParams, const STransitionMatch& match, const Vec3& playerPos, const Vec3& oldMoveDirection, const Vec3& newMoveDirection, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType, CPlayer* const pPlayer, CMovementTransitionsController* const pController)>(0x1898CF0);
	static inline auto FReadParams = PreyFunction<bool(STransition* const _this, ETransitionType _transitionType, const IItemParamsNode* const pParams)>(0x1897F00);
	static inline auto FReadStanceParam = PreyFunction<bool(const STransition* const _this, const char* name, bool required, const IItemParamsNode* const pParams, EStance* const pStance)>(0x1898540);
};

// CMovementTransitions
// Header:  Prey/GameDll/MovementTransitions.h
class CMovementTransitions
{ // Size=48 (0x30)
public:
	using TransitionVector = std::vector<STransition>;

	float m_minDistanceAfterDirectionChange;
	float m_maxStartSpeed;
	std::vector<STransition> m_transitions;
	bool m_isDataValid;
	string m_fileName;

	CMovementTransitions(const string& _fileName);
	~CMovementTransitions();
	void Load() { FLoad(this); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	EMovementTransitionState Update(const uint8_t allowedTransitionFlags, const Lineseg_tpl<float>& safeLine, const CTimeValue runningDuration, const bool bHasLockedBodyTarget, const Vec3& playerPos, const SMovementTransitionsSample& oldSample, const SMovementTransitionsSample& newSample, const float entitySpeed2D, const float entitySpeed2DAvg, const SExactPositioningTarget* const pExactPositioningTarget, CMovementTransitionsController* const pController, CPlayer* const pPlayer, CMovementRequest* const pRequest, SActorFrameMovementParams* const pMoveParams, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType, float minimumSpeedForWalkStop, float minimumSpeedForRunStop, float minimumSpeedForWalkJuke, float minimumSpeedForRunJuke) const { return FUpdate(this, allowedTransitionFlags, safeLine, runningDuration, bHasLockedBodyTarget, playerPos, oldSample, newSample, entitySpeed2D, entitySpeed2DAvg, pExactPositioningTarget, pController, pPlayer, pRequest, pMoveParams, pJukeTurnRateFraction, pBodyTarget, pBodyTargetType, minimumSpeedForWalkStop, minimumSpeedForRunStop, minimumSpeedForWalkJuke, minimumSpeedForRunJuke); }
	void FindBestMatch(const STransitionSelectionParams& transParams, const STransition* * ppBestTransition, int* pBestIndex, STransitionMatch* pBestMatch) const { FFindBestMatch(this, transParams, ppBestTransition, pBestIndex, pBestMatch); }
	bool ReadTransitionsParams(const IItemParamsNode* pParams) { return FReadTransitionsParams(this, pParams); }

#if 0
	float GetMinStopDistance(float _arg0_, float _arg1_) const;
	float GetMinDistanceAfterDirectionChange() const;
	float GetMaxStartSpeed() const;
	const string& GetFileName() const;
	void ReadGeneralParams(const IItemParamsNode* _arg0_);
	string GetXMLFilename() const;
	void Reset();
#endif

	static inline auto FCMovementTransitionsOv1 = PreyFunction<void(CMovementTransitions* const _this, const string& _fileName)>(0x1895DC0);
	static inline auto FBitNotCMovementTransitions = PreyFunction<void(CMovementTransitions* const _this)>(0x1897820);
	static inline auto FLoad = PreyFunction<void(CMovementTransitions* const _this)>(0x1897C60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CMovementTransitions* const _this, ICrySizer* s)>(0x4BAFC0);
	static inline auto FUpdate = PreyFunction<EMovementTransitionState(const CMovementTransitions* const _this, const uint8_t allowedTransitionFlags, const Lineseg_tpl<float>& safeLine, const CTimeValue runningDuration, const bool bHasLockedBodyTarget, const Vec3& playerPos, const SMovementTransitionsSample& oldSample, const SMovementTransitionsSample& newSample, const float entitySpeed2D, const float entitySpeed2DAvg, const SExactPositioningTarget* const pExactPositioningTarget, CMovementTransitionsController* const pController, CPlayer* const pPlayer, CMovementRequest* const pRequest, SActorFrameMovementParams* const pMoveParams, float* const pJukeTurnRateFraction, Vec3* const pBodyTarget, const char* * const pBodyTargetType, float minimumSpeedForWalkStop, float minimumSpeedForRunStop, float minimumSpeedForWalkJuke, float minimumSpeedForRunJuke)>(0x18989A0);
	static inline auto FFindBestMatch = PreyFunction<void(const CMovementTransitions* const _this, const STransitionSelectionParams& transParams, const STransition* * ppBestTransition, int* pBestIndex, STransitionMatch* pBestMatch)>(0x1897860);
	static inline auto FReadTransitionsParams = PreyFunction<bool(CMovementTransitions* const _this, const IItemParamsNode* pParams)>(0x1898710);
};

// STransitionSelectionParams
// Header:  Prey/GameDll/MovementTransitions.h
struct STransitionSelectionParams
{ // Size=92 (0x5C)
	ETransitionType m_transitionType;
	float m_pseudoSpeed;
	EStance m_stance;
	float m_transitionDistance;
	float m_travelAngle;
	float m_targetTravelAngle;
	float m_arrivalAngle;
	float m_bodyTurnAngle;
	unsigned m_context;
	float m_jukeAngle;
	STransitionFuture m_future;
	bool m_bPredicted;

	STransitionSelectionParams(const CMovementTransitions& transitions, const CPlayer& player, const CMovementRequest& request, const Vec3& playerPos, const SMovementTransitionsSample& oldSample, const SMovementTransitionsSample& newSample, const bool bHasLockedBodyTarget, const Vec3& targetBodyDirection, const Lineseg_tpl<float>& safeLine, const CTimeValue runningDuration, const uint8_t _allowedTransitionFlags, const float entitySpeed2D, const float entitySpeed2DAvg, const SExactPositioningTarget* const pExactPositioningTarget, const EStance stance, SActorFrameMovementParams* const pMoveParams, float minimumSpeedForWalkStop, float minimumSpeedForRunStop, float minimumSpeedForWalkJuke, float minimumSpeedForRunJuke, bool _bIsChangingDirection);

	static inline auto FSTransitionSelectionParamsOv2 = PreyFunction<void(STransitionSelectionParams* const _this, const CMovementTransitions& transitions, const CPlayer& player, const CMovementRequest& request, const Vec3& playerPos, const SMovementTransitionsSample& oldSample, const SMovementTransitionsSample& newSample, const bool bHasLockedBodyTarget, const Vec3& targetBodyDirection, const Lineseg_tpl<float>& safeLine, const CTimeValue runningDuration, const uint8_t _allowedTransitionFlags, const float entitySpeed2D, const float entitySpeed2DAvg, const SExactPositioningTarget* const pExactPositioningTarget, const EStance stance, SActorFrameMovementParams* const pMoveParams, float minimumSpeedForWalkStop, float minimumSpeedForRunStop, float minimumSpeedForWalkJuke, float minimumSpeedForRunJuke, bool _bIsChangingDirection)>(0x1895EB0);
};
#endif // MOONCRASH
