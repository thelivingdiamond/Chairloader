// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>

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

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPose* const _this)>(0x10A2160);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPose* const _this)>(0xA97D40);
	static inline auto FCAnimActionAILookPose = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10A1E30);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10A24D0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAILookPose* const _this, float timePassed)>(0x128F7F0);
	static inline auto FInstall = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10A2430);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10A2450);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPose* const _this, const SAnimationContext& context)>(0x10A2020);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10A2310);
#else
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPose* const _this)>(0x10D15C0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPose = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1290);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1930);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAILookPose* const _this, float timePassed)>(0x10D19B0);
	static inline auto FInstall = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1890);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D18B0);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPose* const _this, const SAnimationContext& context)>(0x10D1480);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPose* const _this)>(0x10D1770);
#endif
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

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseEyes* const _this)>(0x10A2170);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0xA97D40);
	static inline auto FCAnimActionAILookPoseEyes = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10A1ED0);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10A2470);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseEyes* const _this, const SAnimationContext& context)>(0x10A2040);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10A2370);
#else
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseEyes* const _this)>(0x10D15D0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPoseEyes = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10D1330);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D18D0);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseEyes* const _this, const SAnimationContext& context)>(0x10D14A0);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseEyes* const _this)>(0x10D17D0);
#endif
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

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseHead* const _this)>(0x10A2180);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0xA97D40);
	static inline auto FCAnimActionAILookPoseHead = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10A1F00);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10A24A0);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseHead* const _this, const SAnimationContext& context)>(0x10A2070);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10A23D0);
#else
	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAILookPoseHead* const _this)>(0x10D15E0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x3E3960);
	static inline auto FCAnimActionAILookPoseHead = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10D1360);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& context)>(0x10D1900);
	static inline auto FFindFragmentId = PreyFunction<int(CAnimActionAILookPoseHead* const _this, const SAnimationContext& context)>(0x10D14D0);
	static inline auto FInitialiseLookPoseBlender = PreyFunction<void(CAnimActionAILookPoseHead* const _this)>(0x10D1830);
#endif
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

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseEyesUserParams* const _this, const SControllerDef& controllerDef)>(0x10A2190);
#else
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseEyesUserParams* const _this, const SControllerDef& controllerDef)>(0x10D15F0);
#endif
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

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseHeadUserParams* const _this, const SControllerDef& controllerDef)>(0x10A2210);
#else
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseHeadUserParams* const _this, const SControllerDef& controllerDef)>(0x10D1670);
#endif
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

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseUserParams* const _this, const SControllerDef& controllerDef)>(0x10A2290);
#else
	static inline auto FInit = PreyFunction<void(SMannequinAiLookPoseUserParams* const _this, const SControllerDef& controllerDef)>(0x10D16F0);
#endif
};

