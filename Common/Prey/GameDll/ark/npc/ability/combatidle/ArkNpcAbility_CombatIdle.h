// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_CombatIdle;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
enum class EArkNpcFacingDesireCallbackEvent;

// ArkNpcAbilityInstance_CombatIdle
// Header:  Prey/GameDll/ark/npc/ability/combatidle/ArkNpcAbility_CombatIdle.h
class ArkNpcAbilityInstance_CombatIdle
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=744 (0x2E8)
public:
	enum class EStage
	{
		Facing = 0,
		StartAnim = 1,
		PlayAnim = 2,
		Failed = 3,
	};

	const ArkNpcAbility_CombatIdle* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;
	unsigned m_targetEntityId;
	ArkNpcAbilityInstance_CombatIdle::EStage m_stage;

	virtual ~ArkNpcAbilityInstance_CombatIdle();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	void FacingDesireCallback(const EArkNpcFacingDesireCallbackEvent _event) { FFacingDesireCallback(this, _event); }

#if 0
	ArkNpcAbilityInstance_CombatIdle();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x12505D0);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x12505E0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1250590);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1250590);
	static inline auto FFacingDesireCallback = PreyFunction<void(ArkNpcAbilityInstance_CombatIdle* const _this, const EArkNpcFacingDesireCallbackEvent _event)>(0x1250520);
};

// ArkNpcAbility_CombatIdle
// Header:  Prey/GameDll/ark/npc/ability/combatidle/ArkNpcAbility_CombatIdle.h
class ArkNpcAbility_CombatIdle : public ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>
{ // Size=24 (0x18)
public:
	string m_fragmentName;
	bool m_bFaceTargetFirst;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_CombatIdle();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_CombatIdle& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_CombatIdle& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CombatIdle& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_CombatIdle& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_CombatIdle& _arg0_, EActionFailure _arg1_) const;
	void OnFacingFail(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_CombatIdle& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12501E0);
	static inline auto FArkNpcAbility_CombatIdle = PreyFunction<void(ArkNpcAbility_CombatIdle* const _this)>(0x1250040);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_CombatIdle* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_CombatIdle& _abilityInstance)>(0x12505F0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_CombatIdle* const _this, ArkNpcAbilityInstance_CombatIdle& _abilityInstance)>(0x1250470);
};
#endif // MOONCRASH
