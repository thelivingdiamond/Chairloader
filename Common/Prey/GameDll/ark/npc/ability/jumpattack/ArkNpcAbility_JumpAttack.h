// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_JumpAttack;
enum class EArkNpcAbilityPerformanceResult;
struct IEntity;

// ArkNpcAbilityInstance_JumpAttack
// Header:  Prey/GameDll/ark/npc/ability/jumpattack/ArkNpcAbility_JumpAttack.h
class ArkNpcAbilityInstance_JumpAttack : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=688 (0x2B0)
public:
	const ArkNpcAbility_JumpAttack* m_pAbility;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	uint64_t m_contextId;
	ArkNpcMovementDesire m_jumpDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;

	virtual ~ArkNpcAbilityInstance_JumpAttack();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_JumpAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x12556D0);
};

// ArkNpcAbility_JumpAttack
// Header:  Prey/GameDll/ark/npc/ability/jumpattack/ArkNpcAbility_JumpAttack.h
class ArkNpcAbility_JumpAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>
{ // Size=16 (0x10)
public:
	bool m_bImmediate;
	bool m_bForcePath;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_JumpAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_JumpAttack& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_JumpAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_JumpAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_JumpAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_JumpAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_JumpAttack& _arg0_) const;
	void GetJumpTarget(const IEntity* _arg0_, const IEntity* const _arg1_, const Vec3& _arg2_, const Vec3& _arg3_, Vec3& _arg4_, float& _arg5_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1255540);
	static inline auto FArkNpcAbility_JumpAttack = PreyFunction<void(ArkNpcAbility_JumpAttack* const _this)>(0x1255460);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_JumpAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_JumpAttack& _abilityInstance)>(0x1255730);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_JumpAttack* const _this, ArkNpcAbilityInstance_JumpAttack& _abilityInstance)>(0x1255670);
};
#endif // MOONCRASH
