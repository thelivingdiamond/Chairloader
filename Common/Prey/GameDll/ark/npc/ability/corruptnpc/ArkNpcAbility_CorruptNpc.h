// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_CorruptNpc;
enum class EArkNpcAbilityPerformanceResult;
struct IParticleEffect;

// ArkNpcAbilityInstance_CorruptNpc
// Header:  Prey/GameDll/ark/npc/ability/corruptnpc/ArkNpcAbility_CorruptNpc.h
class ArkNpcAbilityInstance_CorruptNpc : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=832 (0x340)
public:
	const ArkNpcAbility_CorruptNpc* m_pAbility;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	uint64_t m_contextId;
	unsigned m_startAttachmentCrc;
	unsigned m_targetAttachmentCrc;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcSpeedDesire m_speedDesire;
	ECorruptNpcStage m_corruptNpcStage;
	ArkSimpleTimer m_castTimer;
	ArkSimpleTimer m_preAbilityFacingTimer;
	Vec3 m_corruptionEffectWorldPosition;
	EntityEffects::CEffectsController m_effectController;
	ArkEntityAttachmentEffect m_castEffect;
	ArkLooseEffect m_projectileEffect;

	virtual ~ArkNpcAbilityInstance_CorruptNpc();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_CorruptNpc();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1253060);
};

// ArkNpcAbility_CorruptNpc
// Header:  Prey/GameDll/ark/npc/ability/corruptnpc/ArkNpcAbility_CorruptNpc.h
class ArkNpcAbility_CorruptNpc : public ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>
{ // Size=64 (0x40)
public:
	string m_projectileSourceAttachment;
	string m_projectileTargetAttachment;
	float m_castTime;
	float m_preAbilityFacingTime;
	float m_corruptionProjectileRadius;
	float m_corruptionProjectileSpeed;
	_smart_ptr<IParticleEffect> m_pCastParticleEffect;
	string m_castParticleEffectAttachmentName;
	_smart_ptr<IParticleEffect> m_pProjectileParticleEffect;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_CorruptNpc();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_CorruptNpc& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_CorruptNpc& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_CorruptNpc& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptNpc& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_CorruptNpc& _arg0_) const;
	void StartCorruptionProjectile(ArkNpcAbilityInstance_CorruptNpc& _arg0_, ArkNpc& _arg1_) const;
	bool UpdateCorruptionProjectile(ArkNpcAbilityInstance_CorruptNpc& _arg0_, ArkNpc& _arg1_, float _arg2_) const;
	void PerformCorruption(ArkNpcAbilityInstance_CorruptNpc& _arg0_, ArkNpc& _arg1_) const;
	void Exit(ArkNpcAbilityInstance_CorruptNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1252D20);
	static inline auto FArkNpcAbility_CorruptNpc = PreyFunction<void(ArkNpcAbility_CorruptNpc* const _this)>(0x12529F0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_CorruptNpc* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_CorruptNpc& _abilityInstance)>(0x1253070);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_CorruptNpc* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_CorruptNpc& _abilityInstance)>(0x1253320);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_CorruptNpc* const _this, ArkNpcAbilityInstance_CorruptNpc& _abilityInstance)>(0x1252FE0);
};
#endif // MOONCRASH
