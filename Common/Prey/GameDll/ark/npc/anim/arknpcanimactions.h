// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <_unknown/ArkIntrusiveList.h>
#include <_unknown/ArkIntrusiveListImpl__ArkIntrusiveListIterator.h>
#include <_unknown/ArkSafeIterator.h>
#include <_unknown/STagState.h>

class ArkNpc;
class ArkNpcAnimActionObserver;
enum class EActionFailure;
class IProceduralClip;
struct IProceduralParams;
struct SAnimationContext;

// ArkNpcAnimAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction : public TAction<SAnimationContext>
{ // Size=184 (0xB8)
public:
	using ObserverList = ArkIntrusiveList<ArkNpcAnimActionObserver>;
	using ObserverIterator = ArkIntrusiveListImpl::ArkIntrusiveListIterator<ArkNpcAnimActionObserver>;
	using SafeObserverIterator = ArkSafeIterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<ArkNpcAnimActionObserver> >;

	ArkNpc* m_pNpc;
	ArkIntrusiveList<ArkNpcAnimActionObserver> m_observers;
	ArkSafeIterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<ArkNpcAnimActionObserver> > m_safeObserverIter;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction(ArkNpc& _npc, int _priority, int _fragmentID, const STagState<12>& _fragTags, unsigned _flags, unsigned _scopeMask, unsigned _userToken);
	ArkNpcAnimAction(ArkNpc& _npc, ArkNpcAnimActionObserver& _observer, int _priority, int _fragmentID, const STagState<12>& _fragTags, unsigned _flags, unsigned _scopeMask, unsigned _userToken);
	ArkNpc& GetNpc() const { return FGetNpc(this); }
	void AddObserver(ArkNpcAnimActionObserver& _observer) { FAddObserver(this, _observer); }
	void RemoveObserver(ArkNpcAnimActionObserver& _observer) { FRemoveObserver(this, _observer); }
	virtual void Enter();
	virtual void OnFragmentStarted();
	virtual void Fail(EActionFailure _actionFailure);
	virtual void Exit();
	void SetPriority(int _newPriority) { FSetPriority(this, _newPriority); }
	virtual void ArkCustomActionEvent(const unsigned _eventLowercaseCrc);
	virtual void OnCustomActionEvent(const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params);
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual void OnProceduralClipBegin(IProceduralClip& _clip, unsigned _clipCrc);
	virtual void OnProceduralClipEnd(IProceduralClip& _clip, unsigned _clipCrc);
	bool SetFragTag(const char* const _pTag) { return FSetFragTagOv1(this, _pTag); }
	void ClearGlobalTagGroup(SAnimationContext& _context, const char* const _pGroup) const { FClearGlobalTagGroup(this, _context, _pGroup); }
	void ClearFragTagGroup(SAnimationContext& _context, const char* const _pGroup) { FClearFragTagGroupOv1(this, _context, _pGroup); }

#if 0
	void ArkCustomActionEvent(const char* const _arg0_);
	bool SetFragTag(const int _arg0_);
	bool SetFragGroupTag(const char* const _arg0_, const char* const _arg1_);
	bool SetFragGroupTag(const int _arg0_, const int _arg1_);
	void ClearFragTagGroup(SAnimationContext& _arg0_, const int _arg1_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction* const _this)>(0x126F580);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimActionOv1 = PreyFunction<void(ArkNpcAnimAction* const _this, ArkNpc& _npc, int _priority, int _fragmentID, const STagState<12>& _fragTags, unsigned _flags, unsigned _scopeMask, unsigned _userToken)>(0x126E9D0);
	static inline auto FArkNpcAnimActionOv0 = PreyFunction<void(ArkNpcAnimAction* const _this, ArkNpc& _npc, ArkNpcAnimActionObserver& _observer, int _priority, int _fragmentID, const STagState<12>& _fragTags, unsigned _flags, unsigned _scopeMask, unsigned _userToken)>(0x126E8D0);
	static inline auto FGetNpc = PreyFunction<ArkNpc& (const ArkNpcAnimAction* const _this)>(0x510580);
	static inline auto FAddObserver = PreyFunction<void(ArkNpcAnimAction* const _this, ArkNpcAnimActionObserver& _observer)>(0x126EF80);
	static inline auto FRemoveObserver = PreyFunction<void(ArkNpcAnimAction* const _this, ArkNpcAnimActionObserver& _observer)>(0x126FD30);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimAction* const _this)>(0x126F110);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkNpcAnimAction* const _this)>(0x126FA90);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimAction* const _this, EActionFailure _actionFailure)>(0x126F3F0);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimAction* const _this)>(0x126F200);
	static inline auto FSetPriority = PreyFunction<void(ArkNpcAnimAction* const _this, int _newPriority)>(0xED82A0);
	static inline auto FArkCustomActionEventOv0 = PreyFunction<void(ArkNpcAnimAction* const _this, const unsigned _eventLowercaseCrc)>(0x1333E90);
	static inline auto FOnCustomActionEvent = PreyFunction<void(ArkNpcAnimAction* const _this, const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params)>(0x126F8E0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkNpcAnimAction* const _this, const unsigned _eventCRC)>(0x126F5E0);
	static inline auto FOnProceduralClipBegin = PreyFunction<void(ArkNpcAnimAction* const _this, IProceduralClip& _clip, unsigned _clipCrc)>(0x126FBB0);
	static inline auto FOnProceduralClipEnd = PreyFunction<void(ArkNpcAnimAction* const _this, IProceduralClip& _clip, unsigned _clipCrc)>(0x126FC70);
	static inline auto FSetFragTagOv1 = PreyFunction<bool(ArkNpcAnimAction* const _this, const char* const _pTag)>(0x126FDA0);
	static inline auto FClearGlobalTagGroup = PreyFunction<void(const ArkNpcAnimAction* const _this, SAnimationContext& _context, const char* const _pGroup)>(0x126F0C0);
	static inline auto FClearFragTagGroupOv1 = PreyFunction<void(ArkNpcAnimAction* const _this, SAnimationContext& _context, const char* const _pGroup)>(0x126EFF0);
};

// ArkNpcAnimAction_ArmsRetracted
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_ArmsRetracted : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	bool m_bStartedOnce;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_ArmsRetracted(ArkNpc& _rNpc, int _priority, int _fragmentId, unsigned _flags);
	virtual void Enter();
	virtual bool GetBlendInOverride(int _fragId, float& _blend) const;

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_ArmsRetracted* const _this)>(0x126F590);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_ArmsRetracted* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_ArmsRetracted = PreyFunction<void(ArkNpcAnimAction_ArmsRetracted* const _this, ArkNpc& _rNpc, int _priority, int _fragmentId, unsigned _flags)>(0x126EA60);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimAction_ArmsRetracted* const _this)>(0x126F1B0);
	static inline auto FGetBlendInOverride = PreyFunction<bool(const ArkNpcAnimAction_ArmsRetracted* const _this, int _fragId, float& _blend)>(0x126F550);
};

// ArkNpcAnimAction_Burrow
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_Burrow : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	uint64_t m_unburrowMeleeDamagePackageId;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_Burrow(ArkNpc& _rNpc, int _priority, int _fragmentId, STagState<12> _fragTags, uint64_t _unburrowMeleeDamagePackageId);
	virtual void OnCustomActionEvent(const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params);
	virtual void Enter();
	virtual void OnFragmentStarted();
	virtual void Fail(EActionFailure _actionFailure);
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_Burrow* const _this)>(0x126F590);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_Burrow = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this, ArkNpc& _rNpc, int _priority, int _fragmentId, STagState<12> _fragTags, uint64_t _unburrowMeleeDamagePackageId)>(0x126EB50);
	static inline auto FOnCustomActionEvent = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this, const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params)>(0x126F9B0);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this)>(0x126F1C0);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this)>(0x126FB30);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this, EActionFailure _actionFailure)>(0x126F4A0);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this)>(0x126F2A0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkNpcAnimAction_Burrow* const _this, const unsigned _eventCRC)>(0x126F690);
};

// ArkNpcAnimAction_DeathHitReaction
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_DeathHitReaction : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	bool m_bIsDeathReaction;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_DeathHitReaction(ArkNpc& _npc, int _priority, bool _bIsDeathReaction, int _fragmentID, STagState<12> _fragTags);
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual void OnFragmentStarted();
	virtual void Exit();

#if 0
	void SetAnimationControlledMovement();
	void SetEntityControlledMovement();
#endif

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_DeathHitReaction* const _this)>(0x126F5A0);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_DeathHitReaction* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_DeathHitReaction = PreyFunction<void(ArkNpcAnimAction_DeathHitReaction* const _this, ArkNpc& _npc, int _priority, bool _bIsDeathReaction, int _fragmentID, STagState<12> _fragTags)>(0x126EBE0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkNpcAnimAction_DeathHitReaction* const _this, const unsigned _eventCRC)>(0x126F6A0);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkNpcAnimAction_DeathHitReaction* const _this)>(0x126FB40);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimAction_DeathHitReaction* const _this)>(0x126F2B0);
};

// ArkNpcAnimAction_DodgeWrench
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_DodgeWrench : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	const uint64_t m_riposteSignalPackageId;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_DodgeWrench(ArkNpc& _rNpc, int _fragmentId, STagState<12> _fragTags, uint64_t _riposteSignalPackageId);
	virtual void OnCustomActionEvent(const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params);

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_DodgeWrench* const _this)>(0x126F5B0);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_DodgeWrench* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_DodgeWrench = PreyFunction<void(ArkNpcAnimAction_DodgeWrench* const _this, ArkNpc& _rNpc, int _fragmentId, STagState<12> _fragTags, uint64_t _riposteSignalPackageId)>(0x126EC80);
	static inline auto FOnCustomActionEvent = PreyFunction<void(ArkNpcAnimAction_DodgeWrench* const _this, const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params)>(0x126F9B0);
};

// ArkNpcAnimAction_MeleeAttack
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_MeleeAttack : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	const uint64_t m_damageSignalPackageId;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_MeleeAttack(ArkNpc& _rNpc, int _fragmentId, STagState<12> _fragTags, uint64_t _damageSignalPackageId);
	virtual void OnCustomActionEvent(const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params);

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_MeleeAttack* const _this)>(0x126F5C0);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_MeleeAttack* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_MeleeAttack = PreyFunction<void(ArkNpcAnimAction_MeleeAttack* const _this, ArkNpc& _rNpc, int _fragmentId, STagState<12> _fragTags, uint64_t _damageSignalPackageId)>(0x126ED10);
	static inline auto FOnCustomActionEvent = PreyFunction<void(ArkNpcAnimAction_MeleeAttack* const _this, const unsigned _clipCRC, IProceduralClip& _clip, const IProceduralParams& _params)>(0x126FA20);
};

// ArkNpcAnimAction_MimicRebound
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimactions.h
class ArkNpcAnimAction_MimicRebound : public ArkNpcAnimAction
{ // Size=192 (0xC0)
public:
	float m_startZ;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkNpcAnimAction_MimicRebound(ArkNpc& _rNpc, int _bounceFragmentId);
	virtual void Enter();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void Exit();
	virtual void Fail(EActionFailure _actionFailure);

#if 0
	float GetHeightDelta();
#endif

	static inline auto FGetName = PreyFunction<const char* (const ArkNpcAnimAction_MimicRebound* const _this)>(0x126F5D0);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimAction_MimicRebound* const _this)>(0x3E3960);
	static inline auto FArkNpcAnimAction_MimicRebound = PreyFunction<void(ArkNpcAnimAction_MimicRebound* const _this, ArkNpc& _rNpc, int _bounceFragmentId)>(0x126EDA0);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimAction_MimicRebound* const _this)>(0x126F1D0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkNpcAnimAction_MimicRebound* const _this, float _timePassed)>(0x126FEA0);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimAction_MimicRebound* const _this)>(0x126F360);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimAction_MimicRebound* const _this, EActionFailure _actionFailure)>(0x126F4B0);
};
#endif // MOONCRASH
