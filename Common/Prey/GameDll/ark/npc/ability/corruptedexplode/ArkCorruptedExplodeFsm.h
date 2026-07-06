// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkCorruptedExplodeFsmBase_template_.h>
#include <_unknown/ArkCorruptedExplodeState_Base.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

enum class ArkCharacterEffectType;
struct ArkCorruptedExplodeFsm_Config;
class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
struct IEntity;

// ArkCorruptedExplodeFsm
// Header:  Prey/GameDll/ark/npc/ability/corruptedexplode/ArkCorruptedExplodeFsm.h
class ArkCorruptedExplodeFsm : public ArkCorruptedExplodeFsmBase_template_<void>
{ // Size=2016 (0x7E0)
public:
	const ArkCorruptedExplodeFsm_Config* m_pConfig;
	boost::optional<ArkNpcBlackboardCombatGroup> m_optCombatBlackboardGroup;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	float m_dialogRepeatCooldown;
	float m_unreachableTimer;
	bool m_bFinished;

	ArkCorruptedExplodeFsm();
	~ArkCorruptedExplodeFsm();
	void Initialize(ArkNpc& _npc, const ArkCorruptedExplodeFsm_Config& _config) { FInitialize(this, _npc, _config); }
	void Initiate(unsigned _targetEntityId) { FInitiate(this, _targetEntityId); }
	void Terminate() { FTerminate(this); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	bool HasFinished() const { return FHasFinished(this); }
	bool HasFailed() const { return FHasFailed(this); }
	void StartCharacterEffect(ArkCharacterEffectType _corruptedEffectType) const { FStartCharacterEffect(this, _corruptedEffectType); }

#if 0
	void OnFsmCompleted();
	const ArkCorruptedExplodeFsm_Config& GetConfig() const;
	ArkNpc& GetNpc() const;
	IEntity* GetTargetEntity() const;
	unsigned GetTargetEntityId() const;
#endif

	static inline auto FArkCorruptedExplodeFsm = PreyFunction<void(ArkCorruptedExplodeFsm* const _this)>(0x1251000);
	static inline auto FBitNotArkCorruptedExplodeFsm = PreyFunction<void(ArkCorruptedExplodeFsm* const _this)>(0x12515D0);
	static inline auto FInitialize = PreyFunction<void(ArkCorruptedExplodeFsm* const _this, ArkNpc& _npc, const ArkCorruptedExplodeFsm_Config& _config)>(0x1251DD0);
	static inline auto FInitiate = PreyFunction<void(ArkCorruptedExplodeFsm* const _this, unsigned _targetEntityId)>(0x1251DE0);
	static inline auto FTerminate = PreyFunction<void(ArkCorruptedExplodeFsm* const _this)>(0x1252300);
	static inline auto FUpdate = PreyFunction<void(ArkCorruptedExplodeFsm* const _this, float _elapsedTime)>(0x12523E0);
	static inline auto FHasFinished = PreyFunction<bool(const ArkCorruptedExplodeFsm* const _this)>(0x1251DC0);
	static inline auto FHasFailed = PreyFunction<bool(const ArkCorruptedExplodeFsm* const _this)>(0x1251D90);
	static inline auto FStartCharacterEffect = PreyFunction<void(const ArkCorruptedExplodeFsm* const _this, ArkCharacterEffectType _corruptedEffectType)>(0x1252260);
};

// ArkCorruptedExplodeFsm_Config
// Header:  Prey/GameDll/ark/npc/ability/corruptedexplode/ArkCorruptedExplodeFsm.h
struct ArkCorruptedExplodeFsm_Config
{ // Size=72 (0x48)
	string m_telegraphFragmentName;
	string m_telegraphExplodeFragmentName;
	string m_explodeDamageSourceAttachmentName;
	uint64_t m_damagePackageId;
	uint64_t m_cameraShakeId;
	float m_damageRadius;
	float m_damageImpulse;
	float m_damageMinimumDistanceScaleAmount;
	float m_explodeDelay;
	float m_explodeDistance;
	float m_chargeDialogRepeatCooldown;
	float m_unreachableGiveUpDelay;

	ArkCorruptedExplodeFsm_Config();

	static inline auto FArkCorruptedExplodeFsm_ConfigOv2 = PreyFunction<void(ArkCorruptedExplodeFsm_Config* const _this)>(0x12511C0);
};

// ArkCorruptedExplodeState_Charging
// Header:  Prey/GameDll/ark/npc/ability/corruptedexplode/ArkCorruptedExplodeFsm.h
class ArkCorruptedExplodeState_Charging : public ArkCorruptedExplodeState_Base, public ArkNpcBodyStateObserver_Busy
{ // Size=752 (0x2F0)
public:
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcSpeedDesire m_speedDesire;
	float m_fastestSpeedDelayTimer;

	ArkCorruptedExplodeState_Charging();
	void Enter(ArkCorruptedExplodeFsm& _fsm) { FEnter(this, _fsm); }
	virtual void OnNpcBodyStateStateExit_Busy();
	void SetAsAvoidanceObstacle(ArkCorruptedExplodeFsm& _fsm, bool _bBecomeObstacle) { FSetAsAvoidanceObstacle(this, _fsm, _bBecomeObstacle); }

#if 0
	void Update(ArkCorruptedExplodeFsm& _arg0_, const float _arg1_);
	void Exit(ArkCorruptedExplodeFsm& _arg0_);
#endif

	static inline auto FArkCorruptedExplodeState_ChargingOv1 = PreyFunction<void(ArkCorruptedExplodeState_Charging* const _this)>(0x12511F0);
	static inline auto FEnter = PreyFunction<void(ArkCorruptedExplodeState_Charging* const _this, ArkCorruptedExplodeFsm& _fsm)>(0x1251790);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkCorruptedExplodeState_Charging* const _this)>(0xB5DC0);
	static inline auto FSetAsAvoidanceObstacle = PreyFunction<void(ArkCorruptedExplodeState_Charging* const _this, ArkCorruptedExplodeFsm& _fsm, bool _bBecomeObstacle)>(0x1252170);
};

// ArkCorruptedExplodeState_Explode
// Header:  Prey/GameDll/ark/npc/ability/corruptedexplode/ArkCorruptedExplodeFsm.h
class ArkCorruptedExplodeState_Explode
	: public ArkCorruptedExplodeState_Base
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=568 (0x238)
public:
	_smart_ptr<ArkNpcAnimAction> m_pExplodeAction;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;
	ArkCorruptedExplodeFsm* m_pFsm;

	ArkCorruptedExplodeState_Explode();
	void Enter(ArkCorruptedExplodeFsm& _fsm) { FEnter(this, _fsm); }
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, const unsigned _eventCrc);
	void Explode() { FExplode(this); }

#if 0
	void Update(ArkCorruptedExplodeFsm& _arg0_, const float _arg1_);
	void Exit(ArkCorruptedExplodeFsm& _arg0_);
#endif

	static inline auto FArkCorruptedExplodeState_Explode = PreyFunction<void(ArkCorruptedExplodeState_Explode* const _this)>(0x1251400);
	static inline auto FEnter = PreyFunction<void(ArkCorruptedExplodeState_Explode* const _this, ArkCorruptedExplodeFsm& _fsm)>(0x12519F0);
	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkCorruptedExplodeState_Explode* const _this, const ArkNpcBodyState_Animated& _state)>(0x1252160);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1252150);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, const unsigned _eventCrc)>(0x1252070);
	static inline auto FExplode = PreyFunction<void(ArkCorruptedExplodeState_Explode* const _this)>(0x1251C50);
};
#endif // MOONCRASH
