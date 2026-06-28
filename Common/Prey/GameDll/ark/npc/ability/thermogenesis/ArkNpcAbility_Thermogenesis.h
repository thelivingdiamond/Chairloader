// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_Thermogenesis;
enum class EArkNpcAbilityPerformanceResult;
struct IParticleEffect;

// ArkNpcAbilityInstance_Thermogenesis
// Header:  Prey/GameDll/ark/npc/ability/thermogenesis/ArkNpcAbility_Thermogenesis.h
class ArkNpcAbilityInstance_Thermogenesis : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=216 (0xD8)
public:
	const ArkNpcAbility_Thermogenesis* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	ArkSimpleTimer m_castTimer;
	ArkNpcFacingDesire m_facingDesire;

	virtual ~ArkNpcAbilityInstance_Thermogenesis();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_Thermogenesis();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1331CD0);
};

// ArkNpcAbility_Thermogenesis
// Header:  Prey/GameDll/ark/npc/ability/thermogenesis/ArkNpcAbility_Thermogenesis.h
class ArkNpcAbility_Thermogenesis : public ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>
{ // Size=40 (0x28)
public:
	float m_castTime;
	float m_blastRadius;
	ArkAudioTrigger m_castAudioTrigger;
	_smart_ptr<IParticleEffect> m_pPrecachedTelegraphEffect;
	_smart_ptr<IParticleEffect> m_pPrecachedExplosionEffect;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Thermogenesis();
	void StartThermogenesis(ArkNpc& _npc) const { FStartThermogenesis(this, _npc); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Thermogenesis& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_Thermogenesis& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_Thermogenesis& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_Thermogenesis& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_Thermogenesis& _arg0_) const;
	void Done(ArkNpcAbilityInstance_Thermogenesis& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x13319F0);
	static inline auto FArkNpcAbility_Thermogenesis = PreyFunction<void(ArkNpcAbility_Thermogenesis* const _this)>(0x13318E0);
	static inline auto FStartThermogenesis = PreyFunction<void(const ArkNpcAbility_Thermogenesis* const _this, ArkNpc& _npc)>(0x1331D20);
};
#endif // MOONCRASH
