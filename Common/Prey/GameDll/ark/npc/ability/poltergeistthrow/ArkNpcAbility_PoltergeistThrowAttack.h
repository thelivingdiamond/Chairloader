// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_PoltergeistThrowAttack;
class ArkNpcAnimAction;
enum class EArkNpcAbilityPerformanceResult;
enum class EArkNpcMovementDesireCallbackEvent;
struct IEntity;

// ArkNpcAbilityInstance_PoltergeistThrowAttack
// Header:  Prey/GameDll/ark/npc/ability/poltergeistthrow/ArkNpcAbility_PoltergeistThrowAttack.h
class ArkNpcAbilityInstance_PoltergeistThrowAttack
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Busy
	, public IArkPlayerCarryListener
{ // Size=600 (0x258)
public:
	enum class EStage
	{
		Positioning = 0,
		StartingLift = 1,
		Lifting = 2,
		Appearing = 3,
		Throwing = 4,
		Disappearing = 5,
	};

	// ArkNpcAbilityInstance_PoltergeistThrowAttack::ThrowPropData
	// Header:  Prey/GameDll/ark/npc/ability/poltergeistthrow/ArkNpcAbility_PoltergeistThrowAttack.h
	struct ThrowPropData
	{ // Size=16 (0x10)
		unsigned m_entityId;
		Vec3 m_startPos;
	};

	const ArkNpcAbility_PoltergeistThrowAttack* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	unsigned m_targetEntityId;
	ArkNpcAbilityInstance_PoltergeistThrowAttack::EStage m_stage;
	std::vector<ArkNpcAbilityInstance_PoltergeistThrowAttack::ThrowPropData> m_props;
	std::vector<unsigned int> m_propIds;
	Vec3 m_propAvgPos;
	Vec3 m_liftPos;
	float m_propMoveRadius;
	float m_liftTimer;
	float m_waitForLOSTimer;
	float m_waitForPositionTimer;
	float m_waitForHeightTimer;
	float m_appearTimer;
	float m_disappearTimer;
	float m_multipleThrowDelay;
	float m_throwTimer;
	bool m_bRepositionFailed;
	bool m_bAppeared;

	virtual ~ArkNpcAbilityInstance_PoltergeistThrowAttack();
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnStartCarry(IEntity* const _pEntity);
	void MovementDesireCallback(const EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }

#if 0
	ArkNpcAbilityInstance_PoltergeistThrowAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x132AFA0);
	static inline auto FOnStartCarry = PreyFunction<void(IArkPlayerCarryListener* const _this, IEntity* const _pEntity)>(0x132AFB0);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkNpcAbilityInstance_PoltergeistThrowAttack* const _this, const EArkNpcMovementDesireCallbackEvent _event)>(0x132AEF0);
};

// ArkNpcAbility_PoltergeistThrowAttack
// Header:  Prey/GameDll/ark/npc/ability/poltergeistthrow/ArkNpcAbility_PoltergeistThrowAttack.h
class ArkNpcAbility_PoltergeistThrowAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>
{ // Size=48 (0x30)
public:
	string m_fragmentName;
	float m_preAppearLiftDuration;
	float m_postAppearLiftDuration;
	float m_postLiftDisappearDuration;
	float m_multipleThrowDelay;
	float m_targetLeadTime;
	ArkAudioTrigger m_liftAudioTrigger;
	ArkAudioTrigger m_impulseAudioTrigger;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_PoltergeistThrowAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	bool PropLOS(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { return FPropLOS(this, _abilityInstance); }
	bool PropValidPosition(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { return FPropValidPosition(this, _abilityInstance); }
	bool LiftPosition(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { return FLiftPosition(this, _abilityInstance); }
	void UpdateLift(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance, float _elapsedTime) const { FUpdateLift(this, _abilityInstance, _elapsedTime); }
	void Throw(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { FThrow(this, _abilityInstance); }
	void Exit(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg0_) const;
	void OnMovementFail(ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg0_) const;
	void OnStartCarry(ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg0_) const;
	void Awake(ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132A600);
	static inline auto FArkNpcAbility_PoltergeistThrowAttack = PreyFunction<void(ArkNpcAbility_PoltergeistThrowAttack* const _this)>(0x132A4A0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132B080);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132C020);
	static inline auto FPropLOS = PreyFunction<bool(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132B670);
	static inline auto FPropValidPosition = PreyFunction<bool(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132B6E0);
	static inline auto FLiftPosition = PreyFunction<bool(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132AAD0);
	static inline auto FUpdateLift = PreyFunction<void(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance, float _elapsedTime)>(0x132C600);
	static inline auto FThrow = PreyFunction<void(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132BB20);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132AA90);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_PoltergeistThrowAttack* const _this, ArkNpcAbilityInstance_PoltergeistThrowAttack& _abilityInstance)>(0x132A8F0);
};
#endif // MOONCRASH
