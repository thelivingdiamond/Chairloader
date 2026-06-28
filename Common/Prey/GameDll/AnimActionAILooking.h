// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <_unknown/TMannequinAutoInit.h>

class CTagDefinition;
struct SAnimationContext;
struct SControllerDef;

// CAnimActionAILooking
// Header:  Prey/GameDll/AnimActionAILooking.h
class CAnimActionAILooking : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	using TBase = TAction<SAnimationContext>;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAILooking();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }

#if 0
	static int FindFragmentId(const SAnimationContext& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILooking* const _this)>(0x10D0DA0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILooking* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILooking = PreyFunction<void(CAnimActionAILooking* const _this)>(0x10D0D00);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAILooking* const _this)>(0x10D0E80);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAILooking* const _this, float timePassed)>(0x10D19B0);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D0E30);
};

// SMannequinAiLookingUserParams
// Header:  Prey/GameDll/AnimActionAILooking.h
struct SMannequinAiLookingUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiLookingUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAILooking.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> Looking;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiLookingUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiLookingUserParams* const _this, const SControllerDef& controllerDef)>(0x10D0DB0);
};
#endif // MOONCRASH
