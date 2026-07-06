// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/AnimActionAIDetail.h>
#include <Prey/GameDll/FragmentVariationHelper.h>
#include <_unknown/TMannequinAutoInit.h>

class ArkNpc;
class CAnimActionAIStance;
class CPlayer;
class CTagDefinition;
enum class EStance;
struct SAnimActionAIMovementSettings;
struct SControllerDef;
struct SMannequinAIMovementParams;

// CAnimActionAIMovement
// Header:  Prey/GameDll/AnimActionAIMovement.h
class CAnimActionAIMovement : public TAction<SAnimationContext>
{ // Size=336 (0x150)
public:
	enum EMoveState
	{
		eMS_None = 0,
		eMS_Idle = 1,
		eMS_Turn = 2,
		eMS_TurnBig = 3,
		eMS_Move = 4,
		eMS_InAir = 5,
		eMS_Count = 6,
	};

	// CAnimActionAIMovement::SStateInfo
	// Header:  Prey/GameDll/AnimActionAIMovement.h
	struct SStateInfo
	{ // Size=12 (0xC)
		int m_fragmentID;
		EMovementControlMethod m_MCM;
		CAnimActionAIDetail::EMovementDetail m_movementDetail;

	#if 0
		SStateInfo();
	#endif
	};

	using TBase = TAction<SAnimationContext>;

	CAnimActionAIMovement::EMoveState m_moveState;
	CAnimActionAIMovement::EMoveState m_installedMoveState;
	CAnimActionAIMovement::SStateInfo m_moveStateInfo[6];
	CTimeValue m_deviatedOrientationTime;
	const SAnimActionAIMovementSettings& m_settings;
	const SMannequinAIMovementParams* m_pManParams;
	_smart_ptr<CAnimActionAIStance> m_pAnimActionAIStance;
	CFragmentVariationHelper m_fragmentVariationHelper;
	bool m_bWasHovering;
	bool m_bForceReevaluate;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAIMovement(const SAnimActionAIMovementSettings& settings);
	virtual ~CAnimActionAIMovement();
	virtual void Enter();
	virtual void Exit();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	virtual IAction::EStatus UpdatePending(float timePassed);
	virtual void OnSequenceFinished(int layer, unsigned scopeID);
	virtual void OnFragmentStarted();
	void RequestStance(CPlayer& player, EStance requestedStance, bool urgent) { FRequestStance(this, player, requestedStance, urgent); }
	void CancelStanceChange() { FCancelStanceChange(this); }
	CAnimActionAIMovement::EMoveState CalculateState() { return FCalculateState(this); }
	void SetMovementControlMethod(CPlayer& player) { FSetMovementControlMethod(this, player); }
	CPlayer* GetPlayer() const { return FGetPlayer(this); }

#if 0
	void ForceReevaluate();
	EMovementControlMethod CalculatePendingMCM(CPlayer& _arg0_) const;
	bool SetState(const CAnimActionAIMovement::EMoveState _arg0_);
	bool IsAnimTargetForcingMoveState(CPlayer& _arg0_, ArkNpc* _arg1_) const;
	void RequestMovementDetail(CPlayer& _arg0_);
	void ClearMovementDetail(CPlayer& _arg0_);
	bool UpdateFragmentVariation(const bool _arg0_, const bool _arg1_);
	void ResetMovementControlMethod(CPlayer& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAIMovement* const _this)>(0x10D26B0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x3E3960);
	static inline auto FCAnimActionAIMovement = PreyFunction<void(CAnimActionAIMovement* const _this, const SAnimActionAIMovementSettings& settings)>(0x10D1F70);
	static inline auto FEnter = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x10D24F0);
	static inline auto FExit = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x10D25F0);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x10D2A60);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAIMovement* const _this, float timePassed)>(0x10D2E50);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CAnimActionAIMovement* const _this, float timePassed)>(0x10D2FE0);
	static inline auto FOnSequenceFinished = PreyFunction<void(CAnimActionAIMovement* const _this, int layer, unsigned scopeID)>(0x10D2BA0);
	static inline auto FOnFragmentStarted = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x10D2980);
	static inline auto FRequestStance = PreyFunction<void(CAnimActionAIMovement* const _this, CPlayer& player, EStance requestedStance, bool urgent)>(0x10D2BF0);
	static inline auto FCancelStanceChange = PreyFunction<void(CAnimActionAIMovement* const _this)>(0x10D24D0);
	static inline auto FCalculateState = PreyFunction<CAnimActionAIMovement::EMoveState(CAnimActionAIMovement* const _this)>(0x10D2140);
	static inline auto FSetMovementControlMethod = PreyFunction<void(CAnimActionAIMovement* const _this, CPlayer& player)>(0x10D2DE0);
	static inline auto FGetPlayer = PreyFunction<CPlayer* (const CAnimActionAIMovement* const _this)>(0x10D26C0);
};

// SMannequinAIMovementParams
// Header:  Prey/GameDll/AnimActionAIMovement.h
struct SMannequinAIMovementParams : public IMannequinUserParams
{ // Size=40 (0x28)
	// SMannequinAIMovementParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAIMovement.h
	struct FragmentIDs
	{ // Size=20 (0x14)
		TMannequinAutoInit<int,-1> Motion_Idle;
		TMannequinAutoInit<int,-1> Motion_IdleTurn;
		TMannequinAutoInit<int,-1> Motion_IdleTurnBig;
		TMannequinAutoInit<int,-1> Motion_Move;
		TMannequinAutoInit<int,-1> Motion_Air;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinAIMovementParams::FragmentIDs* const _this, const CTagDefinition& tagDefs)>(0x10D2720);
	};

	// SMannequinAIMovementParams::TagIDs
	// Header:  Prey/GameDll/AnimActionAIMovement.h
	struct TagIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> NoGait;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinAIMovementParams::ScopeIDs
	// Header:  Prey/GameDll/AnimActionAIMovement.h
	struct ScopeIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> FullBody3P;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAIMovementParams::FragmentIDs fragmentIDs;
	SMannequinAIMovementParams::TagIDs tagIDs;
	SMannequinAIMovementParams::ScopeIDs scopeIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAIMovementParams* const _this, const SControllerDef& controllerDef)>(0x10D28B0);
};
#endif // MOONCRASH
