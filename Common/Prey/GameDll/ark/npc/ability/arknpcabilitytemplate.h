// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/npc/ability/ArkNpcAbility.h>

class ArkNpc;
class ArkNpcAbilityInstance;
class ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs;
class ArkNpcAbilityInstance_CombatIdle;
class ArkNpcAbilityInstance_CorruptNpc;
class ArkNpcAbilityInstance_CorruptedEngineerFlame;
class ArkNpcAbilityInstance_CorruptedExplode;
class ArkNpcAbilityInstance_EMPBlast;
class ArkNpcAbilityInstance_Earthquake;
class ArkNpcAbilityInstance_EthericDoppelganger;
class ArkNpcAbilityInstance_Fear;
class ArkNpcAbilityInstance_Frenzy;
class ArkNpcAbilityInstance_GroundSlam;
class ArkNpcAbilityInstance_HitReactShift;
class ArkNpcAbilityInstance_JumpAttack;
class ArkNpcAbilityInstance_LaunchCystoids;
class ArkNpcAbilityInstance_MeleeAttack;
class ArkNpcAbilityInstance_MimicGrabAttack;
class ArkNpcAbilityInstance_OperatorRamAttack;
class ArkNpcAbilityInstance_OperatorScienceZap;
class ArkNpcAbilityInstance_OperatorStrafeAttack;
class ArkNpcAbilityInstance_OperatorSwipeAttack;
class ArkNpcAbilityInstance_PoltergeistDisarm;
class ArkNpcAbilityInstance_PoltergeistLift;
class ArkNpcAbilityInstance_PoltergeistThrowAttack;
class ArkNpcAbilityInstance_PsiAttack;
class ArkNpcAbilityInstance_Psychoshock;
class ArkNpcAbilityInstance_RaisePhantomFromCorpse;
class ArkNpcAbilityInstance_RecycleAttack;
class ArkNpcAbilityInstance_ReloadPistol;
class ArkNpcAbilityInstance_RepelBlast;
class ArkNpcAbilityInstance_RockThrow;
class ArkNpcAbilityInstance_ShiftChargeAttack;
class ArkNpcAbilityInstance_ShootPistol;
class ArkNpcAbilityInstance_Sidestep;
class ArkNpcAbilityInstance_SolarFlare;
class ArkNpcAbilityInstance_Thermogenesis;
class ArkNpcAbilityParams;
class ArkNpcAbility_CallAndActivateEffectOnNpcs;
class ArkNpcAbility_CombatIdle;
class ArkNpcAbility_CorruptNpc;
class ArkNpcAbility_CorruptedEngineerFlame;
class ArkNpcAbility_CorruptedExplode;
class ArkNpcAbility_EMPBlast;
class ArkNpcAbility_Earthquake;
class ArkNpcAbility_EthericDoppelganger;
class ArkNpcAbility_Fear;
class ArkNpcAbility_Frenzy;
class ArkNpcAbility_GroundSlam;
class ArkNpcAbility_HitReactShift;
class ArkNpcAbility_JumpAttack;
class ArkNpcAbility_LaunchCystoids;
class ArkNpcAbility_MeleeAttack;
class ArkNpcAbility_MimicGrabAttack;
class ArkNpcAbility_OperatorRamAttack;
class ArkNpcAbility_OperatorScienceZap;
class ArkNpcAbility_OperatorStrafeAttack;
class ArkNpcAbility_OperatorSwipeAttack;
class ArkNpcAbility_PoltergeistDisarm;
class ArkNpcAbility_PoltergeistLift;
class ArkNpcAbility_PoltergeistThrowAttack;
class ArkNpcAbility_PsiAttack;
class ArkNpcAbility_Psychoshock;
class ArkNpcAbility_RaisePhantomFromCorpse;
class ArkNpcAbility_RecycleAttack;
class ArkNpcAbility_ReloadPistol;
class ArkNpcAbility_RepelBlast;
class ArkNpcAbility_RockThrow;
class ArkNpcAbility_ShiftChargeAttack;
class ArkNpcAbility_ShootPistol;
class ArkNpcAbility_Sidestep;
class ArkNpcAbility_SolarFlare;
class ArkNpcAbility_Thermogenesis;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_CallAndActivateEffectOnNpcs;
	using AbilityInstanceType = ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs;
	using AbilityInstance = ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this)>(0x124F900);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x124F9C0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x124F910);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x124F8A0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x126AF80);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x124FAB0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x124FBF0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x124F980);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_CombatIdle;
	using AbilityInstanceType = ArkNpcAbilityInstance_CombatIdle;
	using AbilityInstance = ArkNpcAbilityInstance_CombatIdle;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CombatIdle& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_CombatIdle& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CombatIdle& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this)>(0x12501E0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12502E0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250240);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250220);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12501F0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1250400);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1250410);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12502A0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_CorruptNpc;
	using AbilityInstanceType = ArkNpcAbilityInstance_CorruptNpc;
	using AbilityInstance = ArkNpcAbilityInstance_CorruptNpc;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptNpc& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_CorruptNpc& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptNpc& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this)>(0x1252D20);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1252EA0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1252D30);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1252D00);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1252FC0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1252FD0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1252E60);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_CorruptedEngineerFlame;
	using AbilityInstanceType = ArkNpcAbilityInstance_CorruptedEngineerFlame;
	using AbilityInstance = ArkNpcAbilityInstance_CorruptedEngineerFlame;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedEngineerFlame& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this)>(0x1250A60);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1250B10);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250A70);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250A10);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12509E0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1250B90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1250CD0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250AD0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_CorruptedExplode;
	using AbilityInstanceType = ArkNpcAbilityInstance_CorruptedExplode;
	using AbilityInstance = ArkNpcAbilityInstance_CorruptedExplode;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptedExplode& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_CorruptedExplode& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this)>(0x12527F0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1252880);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1252800);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12527B0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1252900);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1252950);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1252820);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_EMPBlast;
	using AbilityInstanceType = ArkNpcAbilityInstance_EMPBlast;
	using AbilityInstance = ArkNpcAbilityInstance_EMPBlast;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_EMPBlast& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_EMPBlast& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_EMPBlast& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this)>(0x1324FF0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x13250D0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1325000);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1325180);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1325320);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1325070);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Earthquake;
	using AbilityInstanceType = ArkNpcAbilityInstance_Earthquake;
	using AbilityInstance = ArkNpcAbilityInstance_Earthquake;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Earthquake& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Earthquake& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this)>(0x12537F0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12538D0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1253830);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12648C0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1253800);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x12539A0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1253AD0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1253890);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_EthericDoppelganger;
	using AbilityInstanceType = ArkNpcAbilityInstance_EthericDoppelganger;
	using AbilityInstance = ArkNpcAbilityInstance_EthericDoppelganger;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_EthericDoppelganger& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_EthericDoppelganger& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_EthericDoppelganger& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this)>(0x1325DA0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1325DF0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1325EB0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1325EC0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1325DB0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Fear;
	using AbilityInstanceType = ArkNpcAbilityInstance_Fear;
	using AbilityInstance = ArkNpcAbilityInstance_Fear;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Fear& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Fear& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Fear& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this)>(0x13270B0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1327160);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x13270C0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126AFB0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x126AF80);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1327200);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327120);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Frenzy;
	using AbilityInstanceType = ArkNpcAbilityInstance_Frenzy;
	using AbilityInstance = ArkNpcAbilityInstance_Frenzy;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Frenzy& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Frenzy& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Frenzy& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this)>(0x1254150);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12541A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126BAE0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1266740);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1254120);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1254260);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1254160);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_GroundSlam;
	using AbilityInstanceType = ArkNpcAbilityInstance_GroundSlam;
	using AbilityInstance = ArkNpcAbilityInstance_GroundSlam;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_GroundSlam& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_GroundSlam& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_GroundSlam& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this)>(0x1254760);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1254F60);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1254EC0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12547A0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1254770);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1255030);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1254F20);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_HitReactShift;
	using AbilityInstanceType = ArkNpcAbilityInstance_HitReactShift;
	using AbilityInstance = ArkNpcAbilityInstance_HitReactShift;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_HitReactShift& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_HitReactShift& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this)>(0x1327920);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x13279B0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1327930);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1327A90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1327AA0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327970);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_JumpAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_JumpAttack;
	using AbilityInstance = ArkNpcAbilityInstance_JumpAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_JumpAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_JumpAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_JumpAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this)>(0x1255540);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1255590);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1255640);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1255650);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1255550);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_LaunchCystoids;
	using AbilityInstanceType = ArkNpcAbilityInstance_LaunchCystoids;
	using AbilityInstance = ArkNpcAbilityInstance_LaunchCystoids;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_LaunchCystoids& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_LaunchCystoids& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this)>(0x1255F00);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1255FE0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1255F40);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12648C0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1255F10);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1256100);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1256110);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1255FA0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_MeleeAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_MeleeAttack;
	using AbilityInstance = ArkNpcAbilityInstance_MeleeAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_MeleeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_MeleeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_MeleeAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this)>(0x1328380);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x13284C0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x13283C0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1328390);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12678C0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x13285A0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x13285B0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1328480);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_MimicGrabAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_MimicGrabAttack;
	using AbilityInstance = ArkNpcAbilityInstance_MimicGrabAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_MimicGrabAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_MimicGrabAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this)>(0x12570F0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12572B0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12571E0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1257190);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1257100);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1257390);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1257260);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_OperatorRamAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_OperatorRamAttack;
	using AbilityInstance = ArkNpcAbilityInstance_OperatorRamAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorRamAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_OperatorRamAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorRamAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this)>(0x1329340);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1329440);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1329350);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1329320);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1329480);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1329490);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1329400);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_OperatorScienceZap;
	using AbilityInstanceType = ArkNpcAbilityInstance_OperatorScienceZap;
	using AbilityInstance = ArkNpcAbilityInstance_OperatorScienceZap;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorScienceZap& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_OperatorScienceZap& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this)>(0x1259290);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1259500);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1259350);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12592A0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x12595A0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1259710);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12594C0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_OperatorStrafeAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_OperatorStrafeAttack;
	using AbilityInstance = ArkNpcAbilityInstance_OperatorStrafeAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorStrafeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this)>(0x125A440);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x125A4C0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125A450);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x125A530);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x125A5A0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125A470);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_OperatorSwipeAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_OperatorSwipeAttack;
	using AbilityInstance = ArkNpcAbilityInstance_OperatorSwipeAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorSwipeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this)>(0x1257A80);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1257B20);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1257AA0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1257A90);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1257B90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1257C10);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1257AC0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_PoltergeistDisarm;
	using AbilityInstanceType = ArkNpcAbilityInstance_PoltergeistDisarm;
	using AbilityInstance = ArkNpcAbilityInstance_PoltergeistDisarm;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistDisarm& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this)>(0x125BD30);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x125BD80);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250240);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250220);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x125BCC0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x125BF30);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x125C080);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125BD40);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_PoltergeistLift;
	using AbilityInstanceType = ArkNpcAbilityInstance_PoltergeistLift;
	using AbilityInstance = ArkNpcAbilityInstance_PoltergeistLift;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistLift& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_PoltergeistLift& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistLift& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this)>(0x125CF00);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x125CFE0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125CF10);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125CEE0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x125CE80);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x125D190);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x125D300);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x125CFA0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_PoltergeistThrowAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_PoltergeistThrowAttack;
	using AbilityInstance = ArkNpcAbilityInstance_PoltergeistThrowAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistThrowAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this)>(0x132A600);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x132A770);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x132A6D0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x132A640);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x132A610);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x132A8D0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x132A8E0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x132A730);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_PsiAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_PsiAttack;
	using AbilityInstance = ArkNpcAbilityInstance_PsiAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PsiAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PsiAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PsiAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_PsiAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PsiAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this)>(0x1330040);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1330090);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1254EC0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12547A0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1330050);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x126C420);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x126C430);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126C2F0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Psychoshock;
	using AbilityInstanceType = ArkNpcAbilityInstance_Psychoshock;
	using AbilityInstance = ArkNpcAbilityInstance_Psychoshock;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Psychoshock& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Psychoshock& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Psychoshock& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this)>(0x1330630);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x13306A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1330640);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1330610);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1330760);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1330770);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1330660);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_RaisePhantomFromCorpse;
	using AbilityInstanceType = ArkNpcAbilityInstance_RaisePhantomFromCorpse;
	using AbilityInstance = ArkNpcAbilityInstance_RaisePhantomFromCorpse;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RaisePhantomFromCorpse& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this)>(0x1264910);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12649F0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1264920);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12648C0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1264880);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1264B20);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1264B30);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12649B0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_RecycleAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_RecycleAttack;
	using AbilityInstance = ArkNpcAbilityInstance_RecycleAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RecycleAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RecycleAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RecycleAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_RecycleAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RecycleAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this)>(0x1265830);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1265920);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1265840);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12657D0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12657C0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1265A10);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1265A20);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12658C0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_ReloadPistol;
	using AbilityInstanceType = ArkNpcAbilityInstance_ReloadPistol;
	using AbilityInstance = ArkNpcAbilityInstance_ReloadPistol;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ReloadPistol& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_ReloadPistol& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ReloadPistol& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this)>(0x1266790);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1266800);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12667A0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1266740);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1254120);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1266880);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126BB40);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_RepelBlast;
	using AbilityInstanceType = ArkNpcAbilityInstance_RepelBlast;
	using AbilityInstance = ArkNpcAbilityInstance_RepelBlast;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RepelBlast& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_RepelBlast& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RepelBlast& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this)>(0x1331640);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1331690);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1331630);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x13316F0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x13317A0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331650);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_RockThrow;
	using AbilityInstanceType = ArkNpcAbilityInstance_RockThrow;
	using AbilityInstance = ArkNpcAbilityInstance_RockThrow;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RockThrow& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_RockThrow& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this)>(0x12678B0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x12679B0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1250240);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12678F0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x12678C0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1267AC0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1267AD0);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1267970);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_ShiftChargeAttack;
	using AbilityInstanceType = ArkNpcAbilityInstance_ShiftChargeAttack;
	using AbilityInstance = ArkNpcAbilityInstance_ShiftChargeAttack;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ShiftChargeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this)>(0x126A760);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x126A7B0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x126A880);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x126A890);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126A770);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_ShootPistol;
	using AbilityInstanceType = ArkNpcAbilityInstance_ShootPistol;
	using AbilityInstance = ArkNpcAbilityInstance_ShootPistol;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ShootPistol& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_ShootPistol& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShootPistol& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this)>(0x126B000);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x126B0F0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126B010);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126AFB0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x126AF80);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x126B190);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126B0B0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Sidestep;
	using AbilityInstanceType = ArkNpcAbilityInstance_Sidestep;
	using AbilityInstance = ArkNpcAbilityInstance_Sidestep;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Sidestep& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Sidestep& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this)>(0x126BA40);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x126BB80);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126BAE0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126BA80);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x126BA50);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x126BC00);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1333E90);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126BB40);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_SolarFlare;
	using AbilityInstanceType = ArkNpcAbilityInstance_SolarFlare;
	using AbilityInstance = ArkNpcAbilityInstance_SolarFlare;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_SolarFlare& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_SolarFlare& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_SolarFlare& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this)>(0x126C2E0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x126C330);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1254EC0);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x12547A0);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1330050);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x126C420);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x126C430);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x126C2F0);
};

// ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>
// Header:  Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h
class ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis> : public ArkNpcAbility
{ // Size=8 (0x8)
public:
	using AbilityType = ArkNpcAbility_Thermogenesis;
	using AbilityInstanceType = ArkNpcAbilityInstance_Thermogenesis;
	using AbilityInstance = ArkNpcAbilityInstance_Thermogenesis;

	virtual ~ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const;

#if 0
	ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>();
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Thermogenesis& _arg3_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_Thermogenesis& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Thermogenesis& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this)>(0x13319F0);
	static inline auto FDoMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x1331A70);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A00);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1327960);
	static inline auto FDoCanBePerformed = PreyFunction<bool(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x1252CD0);
	static inline auto FDoPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x1331B00);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x1331C60);
	static inline auto FDoInterrupt = PreyFunction<void(const ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1331A10);
};
#endif // MOONCRASH
