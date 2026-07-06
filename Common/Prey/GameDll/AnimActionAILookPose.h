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

// CAnimActionAILookPose
// Header:  Prey/GameDll/AnimActionAILookPose.h
class CAnimActionAILookPose : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	using TBase = TAction<SAnimationContext>;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAILookPose();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	virtual void Install();
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }
	virtual int FindFragmentId(const SAnimationContext& context);
	virtual void InitialiseLookPoseBlender();

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPose* const _this)>(0x10D15C0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPose = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1290);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1930);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAILookPose* const _this, float timePassed)>(0x10D19B0);
	static inline auto FInstall = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1890);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D18B0);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPose* const _this, const SAnimationContext& context)>(0x10D1480);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1770);
};

// CAnimActionAILookPoseEyes
// Header:  Prey/GameDll/AnimActionAILookPose.h
class CAnimActionAILookPoseEyes : public CAnimActionAILookPose
{ // Size=128 (0x80)
public:
	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAILookPoseEyes();
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }
	virtual int FindFragmentId(const SAnimationContext& context);
	virtual void InitialiseLookPoseBlender();

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseEyes* const _this)>(0x10D15D0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPoseEyes = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10D1330);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D18D0);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseEyes* const _this, const SAnimationContext& context)>(0x10D14A0);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10D17D0);
};

// CAnimActionAILookPoseHead
// Header:  Prey/GameDll/AnimActionAILookPose.h
class CAnimActionAILookPoseHead : public CAnimActionAILookPose
{ // Size=128 (0x80)
public:
	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAILookPoseHead();
	static bool IsSupported(const SAnimationContext& context) { return FIsSupported(context); }
	virtual int FindFragmentId(const SAnimationContext& context);
	virtual void InitialiseLookPoseBlender();

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseHead* const _this)>(0x10D15E0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPoseHead = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10D1360);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D1900);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseHead* const _this, const SAnimationContext& context)>(0x10D14D0);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10D1830);
};

// SMannequinAiLookPoseEyesUserParams
// Header:  Prey/GameDll/AnimActionAILookPose.h
struct SMannequinAiLookPoseEyesUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiLookPoseEyesUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAILookPose.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> LookPoseEyes;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiLookPoseEyesUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseEyesUserParams* const _this, const SControllerDef& controllerDef)>(0x10D15F0);
};

// SMannequinAiLookPoseHeadUserParams
// Header:  Prey/GameDll/AnimActionAILookPose.h
struct SMannequinAiLookPoseHeadUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiLookPoseHeadUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAILookPose.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> LookPoseHead;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiLookPoseHeadUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseHeadUserParams* const _this, const SControllerDef& controllerDef)>(0x10D1670);
};

// SMannequinAiLookPoseUserParams
// Header:  Prey/GameDll/AnimActionAILookPose.h
struct SMannequinAiLookPoseUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiLookPoseUserParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionAILookPose.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> LookPose;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiLookPoseUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseUserParams* const _this, const SControllerDef& controllerDef)>(0x10D16F0);
};
#endif // MOONCRASH
