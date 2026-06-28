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
class ArkNpcAbility_CorruptedEngineerFlame;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_CorruptedEngineerFlame
// Header:  Prey/GameDll/ark/npc/ability/corruptedengineerflame/ArkNpcAbility_CorruptedEngineerFlame.h
class ArkNpcAbilityInstance_CorruptedEngineerFlame
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=96 (0x60)
public:
	const ArkNpcAbility_CorruptedEngineerFlame* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	int m_fragmentId;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	float m_abilityTimer;

	virtual ~ArkNpcAbilityInstance_CorruptedEngineerFlame();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_CorruptedEngineerFlame();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1250E00);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1250DB0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1250DC0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1250DC0);
};

// ArkNpcAbility_CorruptedEngineerFlame
// Header:  Prey/GameDll/ark/npc/ability/corruptedengineerflame/ArkNpcAbility_CorruptedEngineerFlame.h
class ArkNpcAbility_CorruptedEngineerFlame : public ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>
{ // Size=32 (0x20)
public:
	string m_fragmentName;
	uint64_t m_damagePackageId;
	float m_abilityDuration;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_CorruptedEngineerFlame();
	void Done(ArkNpcAbilityInstance_CorruptedEngineerFlame& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	void OnStateExit_Animated(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1250A60);
	static inline auto FArkNpcAbility_CorruptedEngineerFlame = PreyFunction<void(ArkNpcAbility_CorruptedEngineerFlame* const _this)>(0x12508C0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_CorruptedEngineerFlame* const _this, ArkNpcAbilityInstance_CorruptedEngineerFlame& _abilityInstance)>(0x1250D30);
};
#endif // MOONCRASH
