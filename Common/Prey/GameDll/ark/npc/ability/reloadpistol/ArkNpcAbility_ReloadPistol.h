// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_ReloadPistol;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_ReloadPistol
// Header:  Prey/GameDll/ark/npc/ability/reloadpistol/ArkNpcAbility_ReloadPistol.h
class ArkNpcAbilityInstance_ReloadPistol
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=88 (0x58)
public:
	const ArkNpcAbility_ReloadPistol* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	int m_fragmentId;

	virtual ~ArkNpcAbilityInstance_ReloadPistol();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);

#if 0
	ArkNpcAbilityInstance_ReloadPistol();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1266AB0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1266A70);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1266A70);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x12669E0);
};

// ArkNpcAbility_ReloadPistol
// Header:  Prey/GameDll/ark/npc/ability/reloadpistol/ArkNpcAbility_ReloadPistol.h
class ArkNpcAbility_ReloadPistol : public ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>
{ // Size=24 (0x18)
public:
	string m_actionEvent;
	string m_fragmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_ReloadPistol();
	void Done(ArkNpcAbilityInstance_ReloadPistol& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ReloadPistol& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_ReloadPistol& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_ReloadPistol& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_ReloadPistol& _arg0_, EActionFailure _arg1_) const;
	void Reload(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_ReloadPistol& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1266790);
	static inline auto FArkNpcAbility_ReloadPistol = PreyFunction<void(ArkNpcAbility_ReloadPistol* const _this)>(0x12665A0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_ReloadPistol* const _this, ArkNpcAbilityInstance_ReloadPistol& _abilityInstance)>(0x1266970);
};
#endif // MOONCRASH
