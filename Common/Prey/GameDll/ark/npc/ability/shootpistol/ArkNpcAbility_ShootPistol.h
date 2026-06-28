// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_ShootPistol;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IParticleEffect;

// ArkNpcAbilityInstance_ShootPistol
// Header:  Prey/GameDll/ark/npc/ability/shootpistol/ArkNpcAbility_ShootPistol.h
class ArkNpcAbilityInstance_ShootPistol
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=256 (0x100)
public:
	const ArkNpcAbility_ShootPistol* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	int m_fragmentId;
	ArkNpcFacingDesire m_facingDesire;

	virtual ~ArkNpcAbilityInstance_ShootPistol();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);

#if 0
	ArkNpcAbilityInstance_ShootPistol();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x126B6C0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272A0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x126B680);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x126B680);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x126B5F0);
};

// ArkNpcAbility_ShootPistol
// Header:  Prey/GameDll/ark/npc/ability/shootpistol/ArkNpcAbility_ShootPistol.h
class ArkNpcAbility_ShootPistol : public ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>
{ // Size=64 (0x40)
public:
	string m_actionEvent;
	string m_bulletArchetype;
	string m_projectileSourceAttachment;
	string m_fragmentName;
	float m_shotSpread;
	_smart_ptr<IParticleEffect> m_pMuzzleFlashParticleEffect;
	string m_muzzleFlashAttachmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_ShootPistol();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_ShootPistol& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void FireBullet(ArkNpcAbilityInstance_ShootPistol& _abilityInstance) const { FFireBullet(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_ShootPistol& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ShootPistol& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_ShootPistol& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_ShootPistol& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_ShootPistol& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_ShootPistol& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_ShootPistol& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_ShootPistol& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_ShootPistol& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x126B000);
	static inline auto FArkNpcAbility_ShootPistol = PreyFunction<void(ArkNpcAbility_ShootPistol* const _this)>(0x126ACB0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_ShootPistol* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_ShootPistol& _abilityInstance)>(0x126B6D0);
	static inline auto FFireBullet = PreyFunction<void(const ArkNpcAbility_ShootPistol* const _this, ArkNpcAbilityInstance_ShootPistol& _abilityInstance)>(0x126B220);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_ShootPistol* const _this, ArkNpcAbilityInstance_ShootPistol& _abilityInstance)>(0x126B1A0);
};
#endif // MOONCRASH
