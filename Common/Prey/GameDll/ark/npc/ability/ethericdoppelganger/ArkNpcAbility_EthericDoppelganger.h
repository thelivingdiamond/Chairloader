// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_EthericDoppelganger;
enum class EArkNpcAbilityPerformanceResult;
struct IParticleEffect;

// ArkNpcAbilityInstance_EthericDoppelganger
// Header:  Prey/GameDll/ark/npc/ability/ethericdoppelganger/ArkNpcAbility_EthericDoppelganger.h
class ArkNpcAbilityInstance_EthericDoppelganger : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=488 (0x1E8)
public:
	const ArkNpcAbility_EthericDoppelganger* m_pAbility;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	uint64_t m_contextId;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;
	EArkEthericDoppelgangerStage m_currentAttackStage;
	ArkSimpleTimer m_castTimer;
	ArkSimpleTimer m_doppelgangerMoveTimer;

	virtual ~ArkNpcAbilityInstance_EthericDoppelganger();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_EthericDoppelganger();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1325F40);
};

// ArkNpcAbility_EthericDoppelganger
// Header:  Prey/GameDll/ark/npc/ability/ethericdoppelganger/ArkNpcAbility_EthericDoppelganger.h
class ArkNpcAbility_EthericDoppelganger : public ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>
{ // Size=72 (0x48)
public:
	float m_castTime;
	float m_doppelgangerMoveTime;
	float m_doppelgangerLifeTime;
	uint64_t m_doppelgangerOutboundModifierId;
	uint64_t m_doppelgangerGameEffectId;
	string m_doppelgangerArchetype;
	_smart_ptr<IParticleEffect> m_pDisappearParticleEffect;
	_smart_ptr<IParticleEffect> m_pTrailParticleEffect;
	_smart_ptr<IParticleEffect> m_pReappearParticleEffect;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_EthericDoppelganger();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void PlayDoppelgangerEffect(ArkNpc& _npc, bool _bDisappear) const { FPlayDoppelgangerEffect(this, _npc, _bDisappear); }
	void PlayDoppelgangerTrailEffect(ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance, ArkNpc& _npc, const Vec3& _destination) const { FPlayDoppelgangerTrailEffect(this, _abilityInstance, _npc, _destination); }
	void CreateEthericDoppelganger(ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance, ArkNpc& _originalNpc, const Vec3& _spawnLocation, unsigned _entityToAttack, float _doppelgangerLifetime) const { FCreateEthericDoppelganger(this, _abilityInstance, _originalNpc, _spawnLocation, _entityToAttack, _doppelgangerLifetime); }
	void Done(ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_EthericDoppelganger& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_EthericDoppelganger& _arg0_) const;
	void StartDoppelgangerTrailEffects(ArkNpcAbilityInstance_EthericDoppelganger& _arg0_, ArkNpc& _arg1_) const;
	void SpawnPhantoms(ArkNpcAbilityInstance_EthericDoppelganger& _arg0_, ArkNpc& _arg1_) const;
	void Exit(ArkNpcAbilityInstance_EthericDoppelganger& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1325DA0);
	static inline auto FArkNpcAbility_EthericDoppelganger = PreyFunction<void(ArkNpcAbility_EthericDoppelganger* const _this)>(0x13256B0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance)>(0x1325F50);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance)>(0x1326C90);
	static inline auto FPlayDoppelgangerEffect = PreyFunction<void(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpc& _npc, bool _bDisappear)>(0x1326160);
	static inline auto FPlayDoppelgangerTrailEffect = PreyFunction<void(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance, ArkNpc& _npc, const Vec3& _destination)>(0x13264D0);
	static inline auto FCreateEthericDoppelganger = PreyFunction<void(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance, ArkNpc& _originalNpc, const Vec3& _spawnLocation, unsigned _entityToAttack, float _doppelgangerLifetime)>(0x1325800);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_EthericDoppelganger* const _this, ArkNpcAbilityInstance_EthericDoppelganger& _abilityInstance)>(0x1325ED0);
};
#endif // MOONCRASH
