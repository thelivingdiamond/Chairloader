// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_Fear;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_Fear
// Header:  Prey/GameDll/ark/npc/ability/fear/ArkNpcAbility_Fear.h
class ArkNpcAbilityInstance_Fear
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=336 (0x150)
public:
	const ArkNpcAbility_Fear* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	int m_fragmentId;
	ArkNpcMovementDesire m_movementDesire;

	virtual ~ArkNpcAbilityInstance_Fear();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_Fear();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x13272F0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272A0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272B0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x13272B0);
};

// ArkNpcAbility_Fear
// Header:  Prey/GameDll/ark/npc/ability/fear/ArkNpcAbility_Fear.h
class ArkNpcAbility_Fear : public ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>
{ // Size=32 (0x20)
public:
	string m_fragmentName;
	float m_radius;
	uint64_t m_fearPackageId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Fear();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Fear& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_Fear& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Fear& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_Fear& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_Fear& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_Fear& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_Fear& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_Fear& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_Fear& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_Fear& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x13270B0);
	static inline auto FArkNpcAbility_Fear = PreyFunction<void(ArkNpcAbility_Fear* const _this)>(0x1326ED0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_Fear* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Fear& _abilityInstance)>(0x1327300);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_Fear* const _this, ArkNpcAbilityInstance_Fear& _abilityInstance)>(0x1327210);
};
#endif // MOONCRASH
