// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_Psychoshock;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_Psychoshock
// Header:  Prey/GameDll/ark/npc/ability/psychoshock/ArkNpcAbility_Psychoshock.h
class ArkNpcAbilityInstance_Psychoshock : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=552 (0x228)
public:
	const ArkNpcAbility_Psychoshock* m_pAbility;
	ArkNpc* m_pNpc;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	float m_castTimer;

	virtual ~ArkNpcAbilityInstance_Psychoshock();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_Psychoshock();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1330D90);
};

// ArkNpcAbility_Psychoshock
// Header:  Prey/GameDll/ark/npc/ability/psychoshock/ArkNpcAbility_Psychoshock.h
class ArkNpcAbility_Psychoshock : public ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>
{ // Size=64 (0x40)
public:
	string m_damageSourceAttachment;
	uint64_t m_damagePackageId;
	uint64_t m_cameraShakeId;
	float m_damageRadius;
	float m_castDuration;
	float m_minimumExplosionDistanceScale;
	float m_explosionSourceDownTraceDistance;
	float m_impulse;
	float m_verticalImpulse;
	float m_impulseRadius;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Psychoshock();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Psychoshock& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void OnAttack(ArkNpc& _npc, ArkNpcAbilityInstance_Psychoshock& _abilityInstance) const { FOnAttack(this, _npc, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_Psychoshock& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Psychoshock& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_Psychoshock& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_Psychoshock& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_Psychoshock& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1330630);
	static inline auto FArkNpcAbility_Psychoshock = PreyFunction<void(ArkNpcAbility_Psychoshock* const _this)>(0x13304B0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_Psychoshock* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Psychoshock& _abilityInstance)>(0x1330DA0);
	static inline auto FOnAttack = PreyFunction<void(const ArkNpcAbility_Psychoshock* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_Psychoshock& _abilityInstance)>(0x1330850);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_Psychoshock* const _this, ArkNpcAbilityInstance_Psychoshock& _abilityInstance)>(0x13307B0);
};
#endif // MOONCRASH
