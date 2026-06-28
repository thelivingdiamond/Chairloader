// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/ArkNpcCollisionObserver.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_OperatorRamAttack;
enum class EArkNpcAbilityPerformanceResult;
enum class EArkNpcMovementDesireCallbackEvent;
struct EventPhysCollision;
struct IParticleEffect;

// ArkNpcAbilityInstance_OperatorRamAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorram/ArkNpcAbility_OperatorRamAttack.h
class ArkNpcAbilityInstance_OperatorRamAttack
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcCollisionObserver
{ // Size=808 (0x328)
public:
	enum class EStage
	{
		PreAbilityFacing = 0,
		Charging = 1,
		Ramming = 2,
		Colliding = 3,
		Completed = 4,
	};

	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	const ArkNpcAbility_OperatorRamAttack* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	unsigned m_collidedEntityId;
	float m_timer;
	ArkNpcAbilityInstance_OperatorRamAttack::EStage m_stage;
	EntityEffects::CEffectsController m_effectController;
	ArkEntityAttachmentEffect m_orientEffect;
	ArkEntityAttachmentEffect m_chargeEffect;
	ArkEntityAttachmentEffect m_ramEffect;

	virtual ~ArkNpcAbilityInstance_OperatorRamAttack();
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent);
	void MovementDesireCallback(const EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }

#if 0
	ArkNpcAbilityInstance_OperatorRamAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1329700);
	static inline auto FOnNpcCollision = PreyFunction<void(ArkNpcCollisionObserver* const _this, ArkNpc& _npc, const EventPhysCollision& _collisionEvent)>(0x1329710);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkNpcAbilityInstance_OperatorRamAttack* const _this, const EArkNpcMovementDesireCallbackEvent _event)>(0x13296B0);
};

// ArkNpcAbility_OperatorRamAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorram/ArkNpcAbility_OperatorRamAttack.h
class ArkNpcAbility_OperatorRamAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>
{ // Size=112 (0x70)
public:
	float m_orientDuration;
	float m_chargeDuration;
	float m_ramDuration;
	float m_explosionRadius;
	uint64_t m_explosionDamageSignalPackageId;
	uint64_t m_explosionSelfDestroySignalPackageId;
	uint64_t m_collisionSelfDamageSignalPackageId;
	uint64_t m_deathExplosionDamageSignalPackageId;
	uint64_t m_cameraShakeId;
	ArkAudioTrigger m_orientAudioTrigger;
	ArkAudioTrigger m_chargeAudioTrigger;
	ArkAudioTrigger m_ramAudioTrigger;
	_smart_ptr<IParticleEffect> m_pOrientParticleEffect;
	_smart_ptr<IParticleEffect> m_pChargeParticleEffect;
	_smart_ptr<IParticleEffect> m_pRamParticleEffect;
	string m_particleEffectAttachmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_OperatorRamAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance) const { return FPerformOv0(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Exit(ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorRamAttack& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
	void OnMovementFail(ArkNpcAbilityInstance_OperatorRamAttack& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_OperatorRamAttack& _arg0_) const;
	void OnNpcCollision(ArkNpcAbilityInstance_OperatorRamAttack& _arg0_, const EventPhysCollision& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1329340);
	static inline auto FArkNpcAbility_OperatorRamAttack = PreyFunction<void(ArkNpcAbility_OperatorRamAttack* const _this)>(0x1329110);
	static inline auto FPerformOv0 = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_OperatorRamAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance)>(0x1329770);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_OperatorRamAttack* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance)>(0x1329AD0);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_OperatorRamAttack* const _this, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance)>(0x1329670);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_OperatorRamAttack* const _this, ArkNpcAbilityInstance_OperatorRamAttack& _abilityInstance)>(0x13294A0);
};
#endif // MOONCRASH
