// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_EMPBlast;
enum class EArkNpcAbilityPerformanceResult;
struct IEntityArchetype;
struct IParticleEffect;

// ArkNpcAbilityInstance_EMPBlast
// Header:  Prey/GameDll/ark/npc/ability/empblast/ArkNpcAbility_EMPBlast.h
class ArkNpcAbilityInstance_EMPBlast : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=240 (0xF0)
public:
	const ArkNpcAbility_EMPBlast* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	ArkSimpleTimer m_castTimer;
	ArkNpcFacingDesire m_facingDesire;
	IParticleEffect* m_pWarmupEffect;
	IEntityArchetype* m_pElectricalBoxArchetype;
	bool m_bPlacedEmpBlast;

	virtual ~ArkNpcAbilityInstance_EMPBlast();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_EMPBlast();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x13253D0);
};

// ArkNpcAbility_EMPBlast
// Header:  Prey/GameDll/ark/npc/ability/empblast/ArkNpcAbility_EMPBlast.h
class ArkNpcAbility_EMPBlast : public ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>
{ // Size=32 (0x20)
public:
	float m_castTime;
	string m_electricalBoxArchetype;
	string m_warmupEffectName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_EMPBlast();
	void SpawnEmpBlast(ArkNpcAbilityInstance_EMPBlast& _abilityInstance, ArkNpc& _npc) const { FSpawnEmpBlast(this, _abilityInstance, _npc); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_EMPBlast& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_EMPBlast& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_EMPBlast& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_EMPBlast& _arg0_) const;
	void SpawnWarmupEffect(ArkNpcAbilityInstance_EMPBlast& _arg0_, ArkNpc& _arg1_) const;
	void Exit(ArkNpcAbilityInstance_EMPBlast& _arg0_) const;
	void Done(ArkNpcAbilityInstance_EMPBlast& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1324FF0);
	static inline auto FArkNpcAbility_EMPBlast = PreyFunction<void(ArkNpcAbility_EMPBlast* const _this)>(0x1324E70);
	static inline auto FSpawnEmpBlast = PreyFunction<void(const ArkNpcAbility_EMPBlast* const _this, ArkNpcAbilityInstance_EMPBlast& _abilityInstance, ArkNpc& _npc)>(0x1325420);
};
#endif // MOONCRASH
