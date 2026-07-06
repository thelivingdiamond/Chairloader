// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/GameDll/FragmentVariationHelper.h>
#include <_unknown/TMannequinAutoInit.h>

class CTagDefinition;
enum class EPriorityComparison;
class IAction;
struct SAnimationContext;
struct SControllerDef;
struct SMannequinAIDetailParams;

// CAnimActionAIDetail
// Header:  Prey/GameDll/AnimActionAIDetail.h
class CAnimActionAIDetail : public TAction<SAnimationContext>
{ // Size=232 (0xE8)
public:
	enum class EMovementDetail
	{
		None = 0,
		Idle = 1,
		Move = 2,
		Turn = 3,
	};

	using TBase = TAction<SAnimationContext>;

	const SMannequinAIDetailParams* m_pManParams;
	CFragmentVariationHelper m_fragmentVariationHelper;
	int m_requestedDetail;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAIDetail();
	virtual EPriorityComparison ComparePriority(const IAction& actionCurrent) const;
	virtual void Enter();
	virtual void Exit();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	virtual IAction::EStatus UpdatePending(float timePassed);
	virtual void OnSequenceFinished(int layer, unsigned scopeID);
	void RequestDetail(CAnimActionAIDetail::EMovementDetail motionDetail) { FRequestDetail(this, motionDetail); }
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }

#if 0
	void UpdateFragmentVariation(bool _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAIDetail* const _this)>(0x10D0740);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAIDetail* const _this)>(0x3E3960);
	static inline auto FCAnimActionAIDetail = PreyFunction<void(CAnimActionAIDetail* const _this)>(0x10D0620);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const CAnimActionAIDetail* const _this, const IAction& actionCurrent)>(0x4FD7F0);
	static inline auto FEnter = PreyFunction<void(CAnimActionAIDetail* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(CAnimActionAIDetail* const _this)>(0x2DA4C0);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAIDetail* const _this)>(0x10D0900);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAIDetail* const _this, float timePassed)>(0x10D0A10);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CAnimActionAIDetail* const _this, float timePassed)>(0x10D0A60);
	static inline auto FOnSequenceFinished = PreyFunction<void(CAnimActionAIDetail* const _this, int layer, unsigned scopeID)>(0x10D0970);
	static inline auto FRequestDetail = PreyFunction<void(CAnimActionAIDetail* const _this, CAnimActionAIDetail::EMovementDetail motionDetail)>(0x10D09C0);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D08A0);
};

// SMannequinAIDetailParams
// Header:  Prey/GameDll/AnimActionAIDetail.h
struct SMannequinAIDetailParams : public IMannequinUserParams
{ // Size=24 (0x18)
	// SMannequinAIDetailParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAIDetail.h
	struct FragmentIDs
	{ // Size=16 (0x10)
		TMannequinAutoInit<int,-1> MotionDetail_Idle;
		TMannequinAutoInit<int,-1> MotionDetail_Move;
		TMannequinAutoInit<int,-1> MotionDetail_IdleTurn;
		TMannequinAutoInit<int,-1> MotionDetail_Nothing;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAIDetailParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAIDetailParams* const _this, const SControllerDef& controllerDef)>(0x10D0750);
};
#endif // MOONCRASH
