// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_Frenzy;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_Frenzy
// Header:  Prey/GameDll/ark/npc/ability/frenzy/ArkNpcAbility_Frenzy.h
class ArkNpcAbilityInstance_Frenzy
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=504 (0x1F8)
public:
	const ArkNpcAbility_Frenzy* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	int m_fragmentId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;

	virtual ~ArkNpcAbilityInstance_Frenzy();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_Frenzy();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1254500);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x12544C0);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x1254430);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12544C0);
};

// ArkNpcAbility_Frenzy
// Header:  Prey/GameDll/ark/npc/ability/frenzy/ArkNpcAbility_Frenzy.h
class ArkNpcAbility_Frenzy : public ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>
{ // Size=24 (0x18)
public:
	string m_fragmentName;
	string m_actionEvent;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Frenzy();
	void Done(ArkNpcAbilityInstance_Frenzy& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Frenzy& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_Frenzy& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Frenzy& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_Frenzy& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_Frenzy& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_Frenzy& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_Frenzy& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_Frenzy& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_Frenzy& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1254150);
	static inline auto FArkNpcAbility_Frenzy = PreyFunction<void(ArkNpcAbility_Frenzy* const _this)>(0x1253F00);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_Frenzy* const _this, ArkNpcAbilityInstance_Frenzy& _abilityInstance)>(0x12543A0);
};
#endif // MOONCRASH
