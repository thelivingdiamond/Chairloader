// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_PoltergeistLift;
class ArkNpcAnimAction;
enum class EArkNpcAbilityPerformanceResult;
enum class EArkNpcFacingDesireCallbackEvent;
struct IParticleEffect;

// ArkNpcAbilityInstance_PoltergeistLift
// Header:  Prey/GameDll/ark/npc/ability/poltergeistlift/ArkNpcAbility_PoltergeistLift.h
class ArkNpcAbilityInstance_PoltergeistLift : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=632 (0x278)
public:
	enum class EStage
	{
		Facing = 0,
		StartCasting = 1,
		Casting = 2,
		Lifting = 3,
	};

	const ArkNpcAbility_PoltergeistLift* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	unsigned m_targetEntityId;
	Vec3 m_targetStartPos;
	unsigned m_liftEntityId;
	float m_facingTimer;
	float m_liftTimer;
	bool m_bAppeared;
	bool m_bTargetInLift;
	float m_appearTimer;
	ArkNpcAbilityInstance_PoltergeistLift::EStage m_stage;
	ArkLooseEffect m_startEffect;
	float m_throwWaitTimer;

	virtual ~ArkNpcAbilityInstance_PoltergeistLift();
	virtual void OnNpcBodyStateStateExit_Busy();
	void FacingDesireCallback(const EArkNpcFacingDesireCallbackEvent _event) { FFacingDesireCallback(this, _event); }

#if 0
	ArkNpcAbilityInstance_PoltergeistLift();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x125D540);
	static inline auto FFacingDesireCallback = PreyFunction<void(ArkNpcAbilityInstance_PoltergeistLift* const _this, const EArkNpcFacingDesireCallbackEvent _event)>(0x125D4D0);
};

// ArkNpcAbility_PoltergeistLift
// Header:  Prey/GameDll/ark/npc/ability/poltergeistlift/ArkNpcAbility_PoltergeistLift.h
class ArkNpcAbility_PoltergeistLift : public ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>
{ // Size=96 (0x60)
public:
	string m_fragmentName;
	string m_liftParticleEffectName;
	float m_startDuration;
	float m_preAppearDuration;
	float m_appearDuration;
	float m_liftDuration;
	float m_liftRadius;
	float m_targetLeadTime;
	float m_targetForwardOffset;
	_smart_ptr<IParticleEffect> m_pLiftStartParticleEffect;
	float m_throwWaitTime;
	float m_throwCeilingDistance;
	float m_throwCeilingImpulse;
	float m_throwWallDistance;
	float m_throwWallImpulse;
	float m_throwFloorImpulse;
	bool m_bThrowEndsAbility;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_PoltergeistLift();
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	bool StartLift(ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance) const { return FStartLift(this, _abilityInstance); }
	void Exit(ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistLift& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_PoltergeistLift& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_PoltergeistLift& _arg0_) const;
	void OnFacingFail(ArkNpcAbilityInstance_PoltergeistLift& _arg0_) const;
	bool TryThrow(ArkNpcAbilityInstance_PoltergeistLift& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125CF00);
	static inline auto FArkNpcAbility_PoltergeistLift = PreyFunction<void(ArkNpcAbility_PoltergeistLift* const _this)>(0x125C960);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_PoltergeistLift* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance)>(0x125D8C0);
	static inline auto FStartLift = PreyFunction<bool(const ArkNpcAbility_PoltergeistLift* const _this, ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance)>(0x125D5E0);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_PoltergeistLift* const _this, ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance)>(0x125D490);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_PoltergeistLift* const _this, ArkNpcAbilityInstance_PoltergeistLift& _abilityInstance)>(0x125D310);
};
#endif // MOONCRASH
