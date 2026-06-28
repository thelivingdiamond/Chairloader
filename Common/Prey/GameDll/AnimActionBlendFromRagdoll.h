// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <_unknown/STagState.h>
#include <_unknown/TMannequinAutoInit.h>

class CCryActor;
class CTagDefinition;
struct SControllerDef;

// CAnimActionBlendFromRagdoll
// Header:  Prey/GameDll/AnimActionBlendFromRagdoll.h
class CAnimActionBlendFromRagdoll : public TAction<SAnimationContext>
{ // Size=208 (0xD0)
public:
	using TAnimationIds = std::vector<unsigned int>;
	using TBase = TAction<SAnimationContext>;

	CCryActor& m_actor;
	std::shared_ptr<IAnimationPoseMatching> m_pPoseMatching;
	STagState<12> m_fragTagsTarget;
	std::vector<unsigned int> m_animIds;
	bool m_bSetAnimationFrag;
	unsigned m_animID;
	const char* m_pRootJointName;

	virtual const char* GetName() const;
	virtual void DoDelete();
	virtual void OnInitialise();
	virtual void Enter();
	virtual void Exit();
	virtual IAction::EStatus Update(float timePassed);
	virtual void OnFragmentStarted();
	void GenerateAnimIDs() { FGenerateAnimIDs(this); }

#if 0
	CAnimActionBlendFromRagdoll(int _arg0_, CCryActor& _arg1_, const int& _arg2_, const STagState<12> _arg3_, const char* _arg4_);
	void DispatchPoseModifier();
	void QueryPose();
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionBlendFromRagdoll* const _this)>(0x10D4D20);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x3E3960);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x10D4E10);
	static inline auto FEnter = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x10D47A0);
	static inline auto FExit = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x10D4B10);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionBlendFromRagdoll* const _this, float timePassed)>(0x10D4EB0);
	static inline auto FOnFragmentStarted = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x10D4DC0);
	static inline auto FGenerateAnimIDs = PreyFunction<void(CAnimActionBlendFromRagdoll* const _this)>(0x10D4B70);
};

// CAnimActionBlendFromRagdollSleep
// Header:  Prey/GameDll/AnimActionBlendFromRagdoll.h
class CAnimActionBlendFromRagdollSleep : public TAction<SAnimationContext>
{ // Size=264 (0x108)
public:
	using TBase = TAction<SAnimationContext>;

	HitInfo m_hitInfo;
	STagState<12> m_fragTagsTarget;
	CCryActor& m_actor;
	const char* m_pRootJointName;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionBlendFromRagdollSleep(int priority, CCryActor& actor, const HitInfo& hitInfo, const STagState<12>& sleepTagState, const STagState<12>& fragTags, const char* pRootJointName, bool bIndefinite);
	virtual void OnInitialise();
	virtual void Enter();

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionBlendFromRagdollSleep* const _this)>(0x10D4D30);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionBlendFromRagdollSleep* const _this)>(0x3E3960);
	static inline auto FCAnimActionBlendFromRagdollSleep = PreyFunction<void(CAnimActionBlendFromRagdollSleep* const _this, int priority, CCryActor& actor, const HitInfo& hitInfo, const STagState<12>& sleepTagState, const STagState<12>& fragTags, const char* pRootJointName, bool bIndefinite)>(0x10D4510);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionBlendFromRagdollSleep* const _this)>(0x10D4E60);
	static inline auto FEnter = PreyFunction<void(CAnimActionBlendFromRagdollSleep* const _this)>(0x10D4930);
};

// SMannequinFallAndPlayParams
// Header:  Prey/GameDll/AnimActionBlendFromRagdoll.h
struct SMannequinFallAndPlayParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinFallAndPlayParams::FragmentIDs
	// Header:  Prey/GameDll/AnimActionBlendFromRagdoll.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> BlendRagdoll;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinFallAndPlayParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinFallAndPlayParams* const _this, const SControllerDef& controllerDef)>(0x10D4D40);
};
#endif // MOONCRASH
