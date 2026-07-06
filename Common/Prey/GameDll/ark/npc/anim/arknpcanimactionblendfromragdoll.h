// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/GameDll/ark/npc/anim/arknpcanimactions.h>
#include <_unknown/STagState.h>

class ArkNpc;
class ArkNpcAnimActionStandUp;
enum class EActionFailure;

// ArkNpcAnimActionRagdollAndStandUp
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactionblendfromragdoll.h
class ArkNpcAnimActionRagdollAndStandUp : public ArkNpcAnimAction
{ // Size=200 (0xC8)
public:
	_smart_ptr<ArkNpcAnimActionStandUp> m_pDelayedStandUpAction;
	float m_stoppingTime;
	bool m_bStopping;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimActionRagdollAndStandUp(ArkNpc& _npc, int priority, const int& fragID, const STagState<12>& sleepTagState, const _smart_ptr<ArkNpcAnimActionStandUp>& _pStandupAnimAction, bool bIndefinite);
	virtual void Enter();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void Exit();
	virtual void Fail(EActionFailure _actionFailure);
	void Stop() { FStop(this); }
	const _smart_ptr<ArkNpcAnimActionStandUp>& GetStandUpAnimAction() const { return FGetStandUpAnimAction(this); }
	void StartStandup() { FStartStandup(this); }

#if 0
	void ForceFinish();
	bool IsStopping() const;
#endif

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x126E350);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimActionRagdollAndStandUp = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this, ArkNpc& _npc, int priority, const int& fragID, const STagState<12>& sleepTagState, const _smart_ptr<ArkNpcAnimActionStandUp>& _pStandupAnimAction, bool bIndefinite)>(0x126D930);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x126DB70);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkNpcAnimActionRagdollAndStandUp* const _this, float _timePassed)>(0x126E5C0);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x126DF50);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this, EActionFailure _actionFailure)>(0x126E090);
	static inline auto FStop = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x126E5A0);
	static inline auto FGetStandUpAnimAction = PreyFunction<const _smart_ptr<ArkNpcAnimActionStandUp>& (const ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x65D590);
	static inline auto FStartStandup = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp* const _this)>(0x126E460);
};

// ArkNpcAnimActionStandUp
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactionblendfromragdoll.h
class ArkNpcAnimActionStandUp : public ArkNpcAnimAction
{ // Size=288 (0x120)
public:
	std::shared_ptr<IAnimationPoseMatching> m_pPoseMatching;
	STagState<12> m_fragTagsTarget;
	std::vector<unsigned int> m_animIds;
	const char* m_pRootJointName;
	bool m_bStopping;
	Vec3 m_startPos;
	Vec3 m_floorPos;
	float m_floorInterpDuration;
	float m_floorInterpTimer;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimActionStandUp(ArkNpc& _npc, int priority, const int& fragID, const STagState<12> fragTags, const char* pRootJointName);
	void Stop() { FStop(this); }
	virtual void OnInitialise();
	virtual void Enter();
	virtual IAction::EStatus Update(float timePassed);
	virtual void Exit();
	virtual void Fail(EActionFailure _actionFailure);
	virtual void OnFragmentStarted();
	void GenerateAnimIDs() { FGenerateAnimIDs(this); }

#if 0
	void ForceFinish();
	void DispatchPoseModifier();
	bool QueryPose();
	void SetFinalFloorPosition();
#endif

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimActionStandUp* const _this)>(0x126E360);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimActionStandUp = PreyFunction<void(ArkNpcAnimActionStandUp* const _this, ArkNpc& _npc, int priority, const int& fragID, const STagState<12> fragTags, const char* pRootJointName)>(0x126D9B0);
	static inline auto FStop = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126E5B0);
	static inline auto FOnInitialise = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126E3C0);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126DC30);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkNpcAnimActionStandUp* const _this, float timePassed)>(0x126E760);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126DFB0);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimActionStandUp* const _this, EActionFailure _actionFailure)>(0x126E0E0);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126E370);
	static inline auto FGenerateAnimIDs = PreyFunction<void(ArkNpcAnimActionStandUp* const _this)>(0x126E180);
};
#endif // MOONCRASH
