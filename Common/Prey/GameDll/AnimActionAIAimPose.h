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

// CAnimActionAIAimPose
// Header:  Prey/GameDll/AnimActionAIAimPose.h
class CAnimActionAIAimPose : public TAction<SAnimationContext>
{ // Size=136 (0x88)
public:
	using TBase = TAction<SAnimationContext>;

	bool m_bInitialized;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAIAimPose();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	virtual void Install();
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }

#if 0
	void InitialiseAimPoseBlender();
	static int FindFragmentId(const SAnimationContext& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAIAimPose* const _this)>(0x10CFF20);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAIAimPose* const _this)>(0x3E3960);
	static inline auto FCAnimActionAIAimPose = PreyFunction<void(CAnimActionAIAimPose* const _this)>(0x10CFE70);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAIAimPose* const _this)>(0x10D00C0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAIAimPose* const _this, float timePassed)>(0x10D0170);
	static inline auto FInstall = PreyFunction<void(CAnimActionAIAimPose* const _this)>(0x10CFFB0);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D0070);
};

// SMannequinAiAimPoseUserParams
// Header:  Prey/GameDll/AnimActionAIAimPose.h
struct SMannequinAiAimPoseUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiAimPoseUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAIAimPose.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> AimPose;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiAimPoseUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiAimPoseUserParams* const _this, const SControllerDef& controllerDef)>(0x10CFF30);
};
#endif // MOONCRASH
