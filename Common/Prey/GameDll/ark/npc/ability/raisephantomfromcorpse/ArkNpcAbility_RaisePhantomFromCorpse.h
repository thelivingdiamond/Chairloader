// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/ArkSearchBounds.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_RaisePhantomFromCorpse;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
class ArkPsiCorpsePhantom;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IEntityArchetype;

// ArkNpcAbilityInstance_RaisePhantomFromCorpse
// Header:  Prey/GameDll/ark/npc/ability/raisephantomfromcorpse/ArkNpcAbility_RaisePhantomFromCorpse.h
class ArkNpcAbilityInstance_RaisePhantomFromCorpse
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=880 (0x370)
public:
	const ArkNpcAbility_RaisePhantomFromCorpse* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	IEntityArchetype* m_pPhantomArchetype;
	uint64_t m_contextId;
	unsigned m_corpseTargetId;
	unsigned m_combatTargetId;
	ERaisePhantomStage m_raisePhantomStage;
	Vec3 m_raiseCorpsePosition;
	int m_fragmentId;
	ArkSimpleTimer m_raisePosUpdateTimer;
	ArkPsiCorpsePhantom* m_pPsiCorpsePhantom;
	bool m_bAnimFinishedBeforeAbility;
	bool m_bPsiCorpseFinished;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;

	virtual ~ArkNpcAbilityInstance_RaisePhantomFromCorpse();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);

#if 0
	ArkNpcAbilityInstance_RaisePhantomFromCorpse();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1264DA0);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1264DC0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1264D00);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1264D60);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x1264C20);
};

// ArkNpcAbility_RaisePhantomFromCorpse
// Header:  Prey/GameDll/ark/npc/ability/raisephantomfromcorpse/ArkNpcAbility_RaisePhantomFromCorpse.h
class ArkNpcAbility_RaisePhantomFromCorpse : public ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>
{ // Size=56 (0x38)
public:
	string m_fragmentName;
	string m_phantomArchetypeName;
	string m_startRaiseCorpseEventName;
	float m_distanceFromCorpse;
	float m_timeBetweenRaisePosUpdate;
	bool m_bIgnoreMovement;
	ArkSearchBounds m_navMeshSearchBounds;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_RaisePhantomFromCorpse();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	Vec3 UpdateRaisePhantomPosition(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FUpdateRaisePhantomPosition(this, reinterpret_cast<Vec3*>(_return_buf_), _abilityInstance); }
	void Done(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_, EActionFailure _arg1_) const;
	bool IsCorpseValid(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
	void StartCovertingCorpseIntoPhantom(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1264910);
	static inline auto FArkNpcAbility_RaisePhantomFromCorpse = PreyFunction<void(ArkNpcAbility_RaisePhantomFromCorpse* const _this)>(0x1264580);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_RaisePhantomFromCorpse* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance)>(0x1264DE0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_RaisePhantomFromCorpse* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance)>(0x12651D0);
	static inline auto FUpdateRaisePhantomPosition = PreyFunction<Vec3*(const ArkNpcAbility_RaisePhantomFromCorpse* const _this, Vec3* _return_value_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance)>(0x1265460);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_RaisePhantomFromCorpse* const _this, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _abilityInstance)>(0x1264B40);
};
#endif // MOONCRASH
