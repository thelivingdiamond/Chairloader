// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/GameDll/ark/npc/anim/arknpcanimactions.h>
#include <_unknown/STagState.h>

class ArkNpc;
class ArkNpcAnimActionObserver;
enum class EPriorityComparison;
class IAction;

// CNpcMultiStageAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcmultistageanimactions.h
class CNpcMultiStageAction : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	NpcActionStage m_currentStage;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CNpcMultiStageAction(ArkNpc& _rNpc, int _priority, int _fragmentId, const STagState<12>& _fragTags, unsigned _flags);
	virtual void Install();
	virtual void Enter();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void Exit();
	virtual void OnActionFinished();
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void ArkCustomActionEvent(const unsigned _eventLowercaseCrc);
	virtual void OnStart();
	virtual void OnMiddle();
	virtual void OnEnd();
	virtual void OnFinish();
	void TransitionToNextState() { FTransitionToNextState(this); }

#if 0
	CNpcMultiStageAction(ArkNpc& _arg0_, ArkNpcAnimActionObserver& _arg1_, int _arg2_, int _arg3_, const STagState<12>& _arg4_, unsigned _arg5_);
	NpcActionStage GetCurrentStage() const;
#endif

	static inline auto FGetName = PreyFunction<const char* (const CNpcMultiStageAction* const _this)>(0x1278CA0);
	static inline auto FDoDelete = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x3E3960);
	static inline auto FCNpcMultiStageActionOv1 = PreyFunction<void(CNpcMultiStageAction* const _this, ArkNpc& _rNpc, int _priority, int _fragmentId, const STagState<12>& _fragTags, unsigned _flags)>(0x1278860);
	static inline auto FInstall = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1278CC0);
	static inline auto FEnter = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1278B10);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CNpcMultiStageAction* const _this, float _timePassed)>(0x1278ED0);
	static inline auto FExit = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1278B70);
	static inline auto FOnActionFinished = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1278CF0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const CNpcMultiStageAction* const _this, const IAction& _actionCurrent)>(0x4FD7F0);
	static inline auto FArkCustomActionEvent = PreyFunction<void(CNpcMultiStageAction* const _this, const unsigned _eventLowercaseCrc)>(0x1278A80);
	static inline auto FOnStart = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1333E90);
	static inline auto FOnMiddle = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1333E90);
	static inline auto FOnEnd = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1333E90);
	static inline auto FOnFinish = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1333E90);
	static inline auto FTransitionToNextState = PreyFunction<void(CNpcMultiStageAction* const _this)>(0x1278D60);
};

// CNpcMultiStageDurationAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcmultistageanimactions.h
class CNpcMultiStageDurationAction : public CNpcMultiStageAction
{ // Size=200 (0xC8)
public:
	const float m_totalDuration;
	float m_duration;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CNpcMultiStageDurationAction(ArkNpc& _rNpc, int _priority, int _fragmentId, float _duration, const STagState<12>& _fragTags, unsigned _flags);
	virtual IAction::EStatus Update(float _timePassed);

#if 0
	void ResetDuration();
	float GetRemainingDuration() const;
#endif

	static inline auto FGetName = PreyFunction<const char* (const CNpcMultiStageDurationAction* const _this)>(0x125C4B0);
	static inline auto FDoDelete = PreyFunction<void(CNpcMultiStageDurationAction* const _this)>(0x3E3960);
	static inline auto FCNpcMultiStageDurationAction = PreyFunction<void(CNpcMultiStageDurationAction* const _this, ArkNpc& _rNpc, int _priority, int _fragmentId, float _duration, const STagState<12>& _fragTags, unsigned _flags)>(0x12788B0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CNpcMultiStageDurationAction* const _this, float _timePassed)>(0x1278EE0);
};

// CNpcMultiStageHitDeathReactionAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcmultistageanimactions.h
class CNpcMultiStageHitDeathReactionAction : public CNpcMultiStageDurationAction
{ // Size=208 (0xD0)
public:
	const bool m_bIsDeathReaction;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CNpcMultiStageHitDeathReactionAction(ArkNpc& _rNpc, int _priority, int _fragmentId, float _duration, bool _bIsDeathReaction, const STagState<12>& _fragTags);
	virtual IAction::EStatus Update(float _timePassed);
	virtual void Enter();
	virtual void Exit();

	static inline auto FGetName = PreyFunction<const char* (const CNpcMultiStageHitDeathReactionAction* const _this)>(0x1278CB0);
	static inline auto FDoDelete = PreyFunction<void(CNpcMultiStageHitDeathReactionAction* const _this)>(0x3E3960);
	static inline auto FCNpcMultiStageHitDeathReactionAction = PreyFunction<void(CNpcMultiStageHitDeathReactionAction* const _this, ArkNpc& _rNpc, int _priority, int _fragmentId, float _duration, bool _bIsDeathReaction, const STagState<12>& _fragTags)>(0x1278920);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CNpcMultiStageHitDeathReactionAction* const _this, float _timePassed)>(0x1278F40);
	static inline auto FEnter = PreyFunction<void(CNpcMultiStageHitDeathReactionAction* const _this)>(0x1278B30);
	static inline auto FExit = PreyFunction<void(CNpcMultiStageHitDeathReactionAction* const _this)>(0x1278BD0);
};

// CNpcMultiStageHypnotizedAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcmultistageanimactions.h
class CNpcMultiStageHypnotizedAction : public CNpcMultiStageAction
{ // Size=200 (0xC8)
public:
	const unsigned m_flareEntityId;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CNpcMultiStageHypnotizedAction(ArkNpc& _rNpc, int _fragmentId, unsigned _flareEntityId);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FGetName = PreyFunction<const char* (const CNpcMultiStageHypnotizedAction* const _this)>(0x125C4B0);
	static inline auto FDoDelete = PreyFunction<void(CNpcMultiStageHypnotizedAction* const _this)>(0x3E3960);
	static inline auto FCNpcMultiStageHypnotizedAction = PreyFunction<void(CNpcMultiStageHypnotizedAction* const _this, ArkNpc& _rNpc, int _fragmentId, unsigned _flareEntityId)>(0x1278990);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CNpcMultiStageHypnotizedAction* const _this, float _timePassed)>(0x12790A0);
};
#endif // MOONCRASH
