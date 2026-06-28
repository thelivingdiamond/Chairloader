// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_GroundSlam;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IParticleEffect;

// ArkNpcAbilityInstance_GroundSlam
// Header:  Prey/GameDll/ark/npc/ability/groundslam/ArkNpcAbility_GroundSlam.h
class ArkNpcAbilityInstance_GroundSlam
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=512 (0x200)
public:
	const ArkNpcAbility_GroundSlam* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	int m_fragmentId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;

	virtual ~ArkNpcAbilityInstance_GroundSlam();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_GroundSlam();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1255210);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1333E90);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272A0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x12551D0);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x12550E0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12551D0);
};

// ArkNpcAbility_GroundSlam
// Header:  Prey/GameDll/ark/npc/ability/groundslam/ArkNpcAbility_GroundSlam.h
class ArkNpcAbility_GroundSlam : public ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>
{ // Size=104 (0x68)
public:
	string m_fragmentName;
	uint64_t m_groundSlamDamageSignalPackage;
	float m_groundSlamPackageScale;
	float m_playerImpulse;
	float m_npcImpulse;
	float m_otherImpulse;
	float m_damageConeStartRadius;
	float m_damageConeEndRadius;
	float m_damageConeLength;
	float m_flingAngle;
	float m_damageAreaHeight;
	_smart_ptr<IParticleEffect> m_pGroundSlamParticleEffect;
	_smart_ptr<IParticleEffect> m_pRockSpawnEffect;
	int m_numRocksSpawnedBySlam;
	float m_minRockSpawnDistance;
	float m_rockSpawnHeightBias;
	float m_impulseIgnoreRadius;
	float m_groundTraceCheckAboveFloorDelta;
	float m_groundTraceCheckDistance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_GroundSlam();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_GroundSlam& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_GroundSlam& _abilityInstance) const { FDone(this, _abilityInstance); }
	void DoGroundSlam(ArkNpcAbilityInstance_GroundSlam& _abilityInstance) const { FDoGroundSlam(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_GroundSlam& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_GroundSlam& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_GroundSlam& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_GroundSlam& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_GroundSlam& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_GroundSlam& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_GroundSlam& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_GroundSlam& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_GroundSlam& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1254760);
	static inline auto FArkNpcAbility_GroundSlam = PreyFunction<void(ArkNpcAbility_GroundSlam* const _this)>(0x1254510);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_GroundSlam* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_GroundSlam& _abilityInstance)>(0x1255220);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_GroundSlam* const _this, ArkNpcAbilityInstance_GroundSlam& _abilityInstance)>(0x1255040);
	static inline auto FDoGroundSlam = PreyFunction<void(const ArkNpcAbility_GroundSlam* const _this, ArkNpcAbilityInstance_GroundSlam& _abilityInstance)>(0x12547F0);
};
#endif // MOONCRASH
