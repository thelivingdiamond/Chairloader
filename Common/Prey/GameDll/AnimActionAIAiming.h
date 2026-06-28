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

// CAnimActionAIAiming
// Header:  Prey/GameDll/AnimActionAIAiming.h
class CAnimActionAIAiming : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	using TBase = TAction<SAnimationContext>;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAIAiming();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }

#if 0
	static int FindFragmentId(const SAnimationContext& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAIAiming* const _this)>(0x10CF930);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAIAiming* const _this)>(0x3E3960);
	static inline auto FCAnimActionAIAiming = PreyFunction<void(CAnimActionAIAiming* const _this)>(0x10CF890);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAIAiming* const _this)>(0x10CFA10);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAIAiming* const _this, float timePassed)>(0x10D19B0);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10CF9C0);
};

// SMannequinAiAimingUserParams
// Header:  Prey/GameDll/AnimActionAIAiming.h
struct SMannequinAiAimingUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiAimingUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAIAiming.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> Aiming;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiAimingUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiAimingUserParams* const _this, const SControllerDef& controllerDef)>(0x10CF940);
};
#endif // MOONCRASH
