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
class ArkNpcAbility_SolarFlare;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IEntityArchetype;
class IProceduralClip;
struct IProceduralParams;

// ArkNpcAbilityInstance_SolarFlare
// Header:  Prey/GameDll/ark/npc/ability/solarflare/ArkNpcAbility_SolarFlare.h
class ArkNpcAbilityInstance_SolarFlare
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=520 (0x208)
public:
	const ArkNpcAbility_SolarFlare* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	int m_fragmentId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	float m_facingTimer;
	bool m_bWaitToStop;

	virtual ~ArkNpcAbilityInstance_SolarFlare();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcCustomActionEvent(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_SolarFlare();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x126C840);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1333E90);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272A0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x126C800);
	static inline auto FOnNpcCustomActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params)>(0x126C850);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x126C800);
};

// ArkNpcAbility_SolarFlare
// Header:  Prey/GameDll/ark/npc/ability/solarflare/ArkNpcAbility_SolarFlare.h
class ArkNpcAbility_SolarFlare : public ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>
{ // Size=40 (0x28)
public:
	string m_fragmentName;
	float m_projectileSpawnDistance;
	string m_projectileSourceAttachment;
	bool m_bStop;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_SolarFlare();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_SolarFlare& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, const float _elapsedTime, ArkNpcAbilityInstance_SolarFlare& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_SolarFlare& _abilityInstance) const { FDone(this, _abilityInstance); }
	void StartPsiAttack(ArkNpc& _npc, ArkNpcAbilityInstance_SolarFlare& _abilityInstance) const { FStartPsiAttack(this, _npc, _abilityInstance); }
	Vec3 CalculateProjectileLaunchPos(ArkNpcAbilityInstance_SolarFlare& _abilityInstance) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FCalculateProjectileLaunchPos(this, reinterpret_cast<Vec3*>(_return_buf_), _abilityInstance); }
	void FireFlare(ArkNpcAbilityInstance_SolarFlare& _abilityInstance, IEntityArchetype* _pProjectileArchetype) const { FFireFlare(this, _abilityInstance, _pProjectileArchetype); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_SolarFlare& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_SolarFlare& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_SolarFlare& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_SolarFlare& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_SolarFlare& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_SolarFlare& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_SolarFlare& _arg0_, EActionFailure _arg1_) const;
	void OnNpcCustomActionEvent(ArkNpcAbilityInstance_SolarFlare& _arg0_, IProceduralClip& _arg1_, unsigned _arg2_, const IProceduralParams& _arg3_) const;
	void Exit(ArkNpcAbilityInstance_SolarFlare& _arg0_) const;
	bool IsMoving(const ArkNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x126C2E0);
	static inline auto FArkNpcAbility_SolarFlare = PreyFunction<void(ArkNpcAbility_SolarFlare* const _this)>(0x126BDE0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_SolarFlare* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_SolarFlare& _abilityInstance)>(0x126C8E0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_SolarFlare* const _this, ArkNpc& _npc, const float _elapsedTime, ArkNpcAbilityInstance_SolarFlare& _abilityInstance)>(0x126CC10);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_SolarFlare* const _this, ArkNpcAbilityInstance_SolarFlare& _abilityInstance)>(0x126C440);
	static inline auto FStartPsiAttack = PreyFunction<void(const ArkNpcAbility_SolarFlare* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_SolarFlare& _abilityInstance)>(0x126CB20);
	static inline auto FCalculateProjectileLaunchPos = PreyFunction<Vec3*(const ArkNpcAbility_SolarFlare* const _this, Vec3* _return_value_, ArkNpcAbilityInstance_SolarFlare& _abilityInstance)>(0x126BFC0);
	static inline auto FFireFlare = PreyFunction<void(const ArkNpcAbility_SolarFlare* const _this, ArkNpcAbilityInstance_SolarFlare& _abilityInstance, IEntityArchetype* _pProjectileArchetype)>(0x126C4E0);
};
#endif // MOONCRASH
