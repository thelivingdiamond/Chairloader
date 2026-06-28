// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ArkNpcMeleeDamageDealer.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/STagState.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_MeleeAttack;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IAttachment;
class IProceduralClip;
struct IProceduralParams;

// ArkNpcAbilityInstance_MeleeAttack
// Header:  Prey/GameDll/ark/npc/ability/meleeattack/ArkNpcAbility_MeleeAttack.h
class ArkNpcAbilityInstance_MeleeAttack
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=568 (0x238)
public:
	// ArkNpcAbilityInstance_MeleeAttack::ClipDamageDealerPair
	// Header:  Prey/GameDll/ark/npc/ability/meleeattack/ArkNpcAbility_MeleeAttack.h
	struct ClipDamageDealerPair
	{ // Size=96 (0x60)
		const IProceduralClip* m_pClip;
		ArkNpcMeleeDamageDealer m_damageDealer;

	#if 0
		ClipDamageDealerPair(const IProceduralClip& _arg0_, const ArkNpc& _arg1_, IAttachment& _arg2_, float _arg3_, uint64_t _arg4_, float _arg5_, float _arg6_, float _arg7_, float _arg8_);
	#endif
	};

	using DamageDealerArray = std::array<boost::optional<ArkNpcAbilityInstance_MeleeAttack::ClipDamageDealerPair>, 2>;

	const ArkNpcAbility_MeleeAttack* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	STagState<12> m_fragTags;
	uint64_t m_contextId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	ArkNpcMovementDesire m_movementDesire;
	unsigned m_targetEntityId;
	float m_delayTimer;
	std::array<boost::optional<ArkNpcAbilityInstance_MeleeAttack::ClipDamageDealerPair>, 2> m_damageDealers;

	virtual ~ArkNpcAbilityInstance_MeleeAttack();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionProceduralClipBegin(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc);
	virtual void OnNpcAnimActionProceduralClipEnd(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcCustomActionEvent(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params);

#if 0
	ArkNpcAbilityInstance_MeleeAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1328950);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1328960);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1328720);
	static inline auto FOnNpcAnimActionProceduralClipBegin = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc)>(0x1328770);
	static inline auto FOnNpcAnimActionProceduralClipEnd = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc)>(0x13288D0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1328730);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1328730);
	static inline auto FOnNpcCustomActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params)>(0x1328980);
};

// ArkNpcAbility_MeleeAttack
// Header:  Prey/GameDll/ark/npc/ability/meleeattack/ArkNpcAbility_MeleeAttack.h
class ArkNpcAbility_MeleeAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>
{ // Size=96 (0x60)
public:
	string m_fragmentName;
	string m_distanceTagGroupName;
	string m_directionTagGroupName;
	string m_distanceTag;
	string m_directionTag;
	bool m_bCrouchNightmare;
	bool m_bReorientMimic;
	ArkInterval<float> m_delay;
	uint64_t m_damageSignalPackageId;
	float m_damageSignalPackageScale;
	float m_playerImpulse;
	float m_npcImpulse;
	float m_otherImpulse;
	float m_rockSpawnRequiredDistToTarget;
	bool m_bEnableMoonRockSpawnEvents;
	bool m_bDisableHitReactions;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_MeleeAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_MeleeAttack& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_MeleeAttack& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_MeleeAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_MeleeAttack& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_MeleeAttack& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_MeleeAttack& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_MeleeAttack& _arg0_) const;
	void OnNpcAnimActionProceduralClipBegin(ArkNpcAbilityInstance_MeleeAttack& _arg0_, IProceduralClip& _arg1_, unsigned _arg2_) const;
	void OnNpcAnimActionProceduralClipEnd(ArkNpcAbilityInstance_MeleeAttack& _arg0_, IProceduralClip& _arg1_, unsigned _arg2_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_MeleeAttack& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_MeleeAttack& _arg0_, EActionFailure _arg1_) const;
	void OnNpcCustomActionEvent(ArkNpcAbilityInstance_MeleeAttack& _arg0_, IProceduralClip& _arg1_, unsigned _arg2_, const IProceduralParams& _arg3_) const;
	void Exit(ArkNpcAbilityInstance_MeleeAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1328380);
	static inline auto FArkNpcAbility_MeleeAttack = PreyFunction<void(ArkNpcAbility_MeleeAttack* const _this)>(0x1327EF0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_MeleeAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_MeleeAttack& _abilityInstance)>(0x1328AF0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_MeleeAttack* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_MeleeAttack& _abilityInstance)>(0x1328D60);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_MeleeAttack* const _this, ArkNpcAbilityInstance_MeleeAttack& _abilityInstance)>(0x13285C0);
};
#endif // MOONCRASH
