// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_RepelBlast;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_RepelBlast
// Header:  Prey/GameDll/ark/npc/ability/repelblast/ArkNpcAbility_RepelBlast.h
class ArkNpcAbilityInstance_RepelBlast : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=48 (0x30)
public:
	const ArkNpcAbility_RepelBlast* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	float m_abilityDelayTimer;

	virtual ~ArkNpcAbilityInstance_RepelBlast();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_RepelBlast();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1331870);
};

// ArkNpcAbility_RepelBlast
// Header:  Prey/GameDll/ark/npc/ability/repelblast/ArkNpcAbility_RepelBlast.h
class ArkNpcAbility_RepelBlast : public ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>
{ // Size=56 (0x38)
public:
	float m_radius;
	float m_impulse;
	float m_verticalImpulse;
	float m_minimumExplosionDistanceScale;
	float m_abilityDelayDuration;
	float m_explosionSourceDownTraceDistance;
	uint64_t m_packageId;
	uint64_t m_cameraShakeId;
	string m_damageSourceAttachment;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_RepelBlast();
	void Done(ArkNpcAbilityInstance_RepelBlast& _abilityInstance) const { FDone(this, _abilityInstance); }
	void DoAttack(ArkNpc& _npc, ArkNpcAbilityInstance_RepelBlast& _abilityInstance) const { FDoAttack(this, _npc, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RepelBlast& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_RepelBlast& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_RepelBlast& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_RepelBlast& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_RepelBlast& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1331640);
	static inline auto FArkNpcAbility_RepelBlast = PreyFunction<void(ArkNpcAbility_RepelBlast* const _this)>(0x1331020);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_RepelBlast* const _this, ArkNpcAbilityInstance_RepelBlast& _abilityInstance)>(0x1331800);
	static inline auto FDoAttack = PreyFunction<void(const ArkNpcAbility_RepelBlast* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_RepelBlast& _abilityInstance)>(0x1331110);
};
#endif // MOONCRASH
