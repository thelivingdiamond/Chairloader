// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/ArkNpcAbilityPrereq.h>

class ArkNpc;
class ArkNpcAbilityContextInstanceStorage;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;
class ArkNpcAbilityPrereqInstance_AbilityCooldown;
class ArkNpcAbilityPrereqInstance_AbilityGroupCooldown;
class ArkNpcAbilityPrereqInstance_ContextCooldown;
class ArkNpcAbilityPrereqInstance_ContextGroupCooldown;
class ArkNpcAbilityPrereqInstance_DamagedByTargetTime;
class ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown;
class ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown;
class ArkNpcAbilityPrereqInstance_GlobalContextCooldown;
class ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown;
class ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics;
class ArkNpcAbilityPrereqInstance_LookedAtForLongEnough;
class ArkNpcAbilityPrereqInstance_PercentChance;
class ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget;
class ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed;
class ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime;
class ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance;
class ArkNpcAbilityPrereq_AbilityCooldown;
class ArkNpcAbilityPrereq_AbilityGroupCooldown;
class ArkNpcAbilityPrereq_AreaHasMaxNumCystoids;
class ArkNpcAbilityPrereq_CanCorrupt;
class ArkNpcAbilityPrereq_CanEnterButtonMashSequence;
class ArkNpcAbilityPrereq_CanJump;
class ArkNpcAbilityPrereq_CanSidestep;
class ArkNpcAbilityPrereq_ContextCooldown;
class ArkNpcAbilityPrereq_ContextGroupCooldown;
class ArkNpcAbilityPrereq_DamagedByTargetTime;
class ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger;
class ArkNpcAbilityPrereq_DoomClockLevel;
class ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted;
class ArkNpcAbilityPrereq_GlobalAbilityCooldown;
class ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown;
class ArkNpcAbilityPrereq_GlobalContextCooldown;
class ArkNpcAbilityPrereq_GlobalContextGroupCooldown;
class ArkNpcAbilityPrereq_HasCollisionCapsuleClearance;
class ArkNpcAbilityPrereq_HasDodged;
class ArkNpcAbilityPrereq_HasEMPBlastPosition;
class ArkNpcAbilityPrereq_HasEnergyAoELineOfSight;
class ArkNpcAbilityPrereq_HasEnoughAmmo;
class ArkNpcAbilityPrereq_HasEnoughControlledTurrets;
class ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs;
class ArkNpcAbilityPrereq_HasEnoughNearbyNpcs;
class ArkNpcAbilityPrereq_HasFiringLineOfSight;
class ArkNpcAbilityPrereq_HasGameEffect;
class ArkNpcAbilityPrereq_HasHitReactShiftLocation;
class ArkNpcAbilityPrereq_HasHitReacted;
class ArkNpcAbilityPrereq_HasLineOfSight;
class ArkNpcAbilityPrereq_HasMeleeLineOfSight;
class ArkNpcAbilityPrereq_HasNearbyMoonRocks;
class ArkNpcAbilityPrereq_HasNearbyProp;
class ArkNpcAbilityPrereq_HasNoCombatRole;
class ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType;
class ArkNpcAbilityPrereq_HasPathingLineOfSight;
class ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight;
class ArkNpcAbilityPrereq_HasPistolPointedAtTarget;
class ArkNpcAbilityPrereq_HasSolarFlarePosition;
class ArkNpcAbilityPrereq_HasSpaceForDoppelgangers;
class ArkNpcAbilityPrereq_HasThermogenesisPosition;
class ArkNpcAbilityPrereq_HealthPercent;
class ArkNpcAbilityPrereq_IsBehindTargetReachable;
class ArkNpcAbilityPrereq_IsEtherFormRestricted;
class ArkNpcAbilityPrereq_IsFrenzied;
class ArkNpcAbilityPrereq_IsFrozenInGloo;
class ArkNpcAbilityPrereq_IsHitReacting;
class ArkNpcAbilityPrereq_IsIgnoringRangedAbilities;
class ArkNpcAbilityPrereq_IsInEtherForm;
class ArkNpcAbilityPrereq_IsInLowG;
class ArkNpcAbilityPrereq_IsInMeleeRole;
class ArkNpcAbilityPrereq_IsInRangedRole;
class ArkNpcAbilityPrereq_IsInZeroG;
class ArkNpcAbilityPrereq_IsNotShifting;
class ArkNpcAbilityPrereq_IsOnGround;
class ArkNpcAbilityPrereq_IsOnSlope;
class ArkNpcAbilityPrereq_IsPartiallyGlooed;
class ArkNpcAbilityPrereq_IsPsiSuppressed;
class ArkNpcAbilityPrereq_IsRegainingLoS;
class ArkNpcAbilityPrereq_IsTakingDamage;
class ArkNpcAbilityPrereq_IsTargetArmed;
class ArkNpcAbilityPrereq_IsTargetInSyncedAnimation;
class ArkNpcAbilityPrereq_IsTargetPlayer;
class ArkNpcAbilityPrereq_IsTargetReachable;
class ArkNpcAbilityPrereq_IsUnderground;
class ArkNpcAbilityPrereq_IsUsingUnreachableTargeting;
class ArkNpcAbilityPrereq_LastAbilityContextPerformed;
class ArkNpcAbilityPrereq_LastAbilityPerformed;
class ArkNpcAbilityPrereq_LookedAtForLongEnough;
class ArkNpcAbilityPrereq_LostLineOfSight;
class ArkNpcAbilityPrereq_MaxAngleFromTarget;
class ArkNpcAbilityPrereq_MaxAngleToTarget;
class ArkNpcAbilityPrereq_MaxNumberOfCombatants;
class ArkNpcAbilityPrereq_MaxTargetDeltaHeight;
class ArkNpcAbilityPrereq_MaxTargetDistance;
class ArkNpcAbilityPrereq_MaxTargetDistanceCapsule;
class ArkNpcAbilityPrereq_MinNumberOfCombatants;
class ArkNpcAbilityPrereq_MinTargetDeltaHeight;
class ArkNpcAbilityPrereq_MinTargetDistance;
class ArkNpcAbilityPrereq_MinTargetDistanceCapsule;
class ArkNpcAbilityPrereq_NightmareCrouchHeightMax;
class ArkNpcAbilityPrereq_NightmareCrouchHeightMin;
class ArkNpcAbilityPrereq_PercentChance;
class ArkNpcAbilityPrereq_PercentChanceFromBehindTarget;
class ArkNpcAbilityPrereq_TargetHasMetaTag;
class ArkNpcAbilityPrereq_TargetIsCorrupted;
class ArkNpcAbilityPrereq_TimeInCombat;
class ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed;
class ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence;
class ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer;
class ArkNpcAbilityPrereq_WithinArcToTarget;
class ArkNpcAbilityPrereq_WithinDistanceToTargetForTime;
class ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance;

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_AbilityCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_AbilityCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E2E0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EDC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E8C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E2F0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityCooldown,ArkNpcAbilityPrereqInstance_AbilityCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_AbilityGroupCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_AbilityGroupCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E3F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125F160);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E8C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E400);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AbilityGroupCooldown,ArkNpcAbilityPrereqInstance_AbilityGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_AreaHasMaxNumCystoids& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E570);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E580);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_AreaHasMaxNumCystoids,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_CanCorrupt& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E620);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E630);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanCorrupt,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_CanEnterButtonMashSequence& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E670);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E680);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanEnterButtonMashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_CanJump& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E6F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E700);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanJump,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_CanSidestep& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E7F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261FA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E790);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_CanSidestep,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_ContextCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_ContextCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132CB90);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EDC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E8C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132CBA0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextCooldown,ArkNpcAbilityPrereqInstance_ContextCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_ContextGroupCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_ContextGroupCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125E900);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125F160);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E8C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E960);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_ContextGroupCooldown,ArkNpcAbilityPrereqInstance_ContextGroupCooldown,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_DamagedByTargetTime& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125EB20);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FC40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125EB30);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EBD0);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EA10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EB80);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132CC30);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132CC40);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoesNotHaveActiveDoppelganger,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_DoomClockLevel& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132CCB0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132CCC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132CC90);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125EC20);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EC80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EC30);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_EnoughTimeSinceCombatStarted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalAbilityCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x125ECE0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x1A302A0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EDC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x125EFA0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F070);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125ECF0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x125EE50);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x1A302A0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125F160);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x125EFA0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F070);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE60);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalAbilityGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalContextCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x125EF90);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x1A302A0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EDC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x125EFA0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F070);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EFB0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextCooldown,ArkNpcAbilityPrereqInstance_GlobalContextCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_GlobalContextGroupCooldown& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x125F060);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this)>(0x1A302A0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125F160);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E910);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x125EFA0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F070);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F0D0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_GlobalContextGroupCooldown,ArkNpcAbilityPrereqInstance_GlobalContextGroupCooldown,ArkNpcAbilityPrereqGlobalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125E4F0);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasCollisionCapsuleClearance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125F2F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125F310);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F300);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasCollisionCapsuleClearance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasDodged& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125F930);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F8C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasDodged,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEMPBlastPosition& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132CD20);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132CD30);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132CD10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEMPBlastPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnergyAoELineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1260B30);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260CA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260B40);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnergyAoELineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughAmmo& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125F9D0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x12630F0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125F970);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughAmmo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughControlledTurrets& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125FA40);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125FAC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125FA10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughControlledTurrets,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x125FAB0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125FAC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125FA80);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughCorruptedNpcs,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughNearbyNpcs& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1260830);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260840);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260740);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasFiringLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1260D90);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260CA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260DA0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasFiringLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasGameEffect& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1260AB0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260AC0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260A60);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasGameEffect,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasHitReactShiftLocation& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132DDE0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132DDF0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132DD60);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasHitReacted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132D270);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132D360);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132D280);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReacted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132E430);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132E380);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasMeleeLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1260F50);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260F60);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1260F40);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasMeleeLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNearbyMoonRocks& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12614F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261530);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1261500);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNearbyProp& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132E740);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132E750);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132E5D0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyProp,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNoCombatRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1261570);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1261580);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNoCombatRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12615E0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261700);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12615F0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPathingLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132E470);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132E480);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPathingLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1261390);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1260CA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1261230);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPistolPointedAtTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1261880);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261890);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1261870);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPistolPointedAtTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasSolarFlarePosition& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1261D30);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261FA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1261D40);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasSpaceForDoppelgangers& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132EC80);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132ECA0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132EC90);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HasThermogenesisPosition& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132ED90);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132EDB0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132EDA0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasThermogenesisPosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_HealthPercent& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12620C0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FC40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262010);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HealthPercent,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsBehindTargetReachable& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F320);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F310);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsBehindTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsEtherFormRestricted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12622C0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12622D0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsEtherFormRestricted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsFrenzied& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12621B0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262180);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrenzied,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsFrozenInGloo& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12621F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262200);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsFrozenInGloo,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsHitReacting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F1F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F200);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsHitReacting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsIgnoringRangedAbilities& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262280);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262250);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsIgnoringRangedAbilities,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInEtherForm& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262320);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262330);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInEtherForm,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInLowG& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262370);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262380);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInLowG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInMeleeRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12623E0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12623F0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInMeleeRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInRangedRole& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262480);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262450);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInRangedRole,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsInZeroG& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12624C0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12624D0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsInZeroG,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsNotShifting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F240);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F250);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsNotShifting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsOnGround& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262570);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262580);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnGround,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsOnSlope& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12625C0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12625D0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsOnSlope,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsPartiallyGlooed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12626B0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EC80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262660);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPartiallyGlooed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsPsiSuppressed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12626F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262700);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsPsiSuppressed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsRegainingLoS& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262760);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262770);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsRegainingLoS,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTakingDamage& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F2D0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x13B0900);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F2C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTakingDamage,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetArmed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12627B0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12627C0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetArmed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetInSyncedAnimation& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262880);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262890);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetInSyncedAnimation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetPlayer& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262950);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262920);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsTargetReachable& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F670);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F630);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsTargetReachable,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsUnderground& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262990);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12629A0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUnderground,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_IsUsingUnreachableTargeting& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262A00);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262A10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_IsUsingUnreachableTargeting,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_LastAbilityContextPerformed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F720);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132F730);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F6B0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityContextPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_LastAbilityPerformed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F7E0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132F730);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F770);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LastAbilityPerformed,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_LookedAtForLongEnough& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262B00);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262B30);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262B70);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262A90);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262B10);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_LostLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12613D0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12613E0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LostLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxAngleFromTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262C70);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262C10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleFromTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxAngleToTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F820);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x125EC80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F830);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxAngleToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxNumberOfCombatants& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262CC0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262D30);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262CD0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDeltaHeight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262EE0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262EF0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262DE0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDistance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132F970);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132F980);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MaxTargetDistanceCapsule& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1262FB0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1262FC0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MaxTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MinNumberOfCombatants& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12630E0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x12630F0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263080);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinNumberOfCombatants,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDeltaHeight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263140);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262EF0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263150);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDeltaHeight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDistance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132FB70);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261890);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132FA90);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistance,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_MinTargetDistanceCapsule& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263280);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261890);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263290);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_MinTargetDistanceCapsule,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_NightmareCrouchHeightMax& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12633C0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12633D0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_NightmareCrouchHeightMin& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12637B0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12635E0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMin,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_PercentChance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_PercentChance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_PercentChance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_PercentChance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_PercentChance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_PercentChance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_PercentChance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132FBB0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FC40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12639F0);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132FBC0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChance,ArkNpcAbilityPrereqInstance_PercentChance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263980);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_PercentChanceFromBehindTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263820);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x12639A0);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x12639F0);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263830);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqInstance_PercentChanceFromBehindTarget,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263980);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TargetHasMetaTag& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132FD30);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FD40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132FCE0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TargetIsCorrupted& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x132FDA0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262500);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x132FDB0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetIsCorrupted,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeInCombat& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263A40);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263A50);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeInCombat,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263AF0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x125EE00);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263AD0);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263B00);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263B10);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263BD0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1262C80);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263B60);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastButtonSmashSequence,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263C40);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1261490);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263C50);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinArcToTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1263F30);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x1263F40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x125E710);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1263D10);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinDistanceToTargetForTime& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x12640F0);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FC40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1263930);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1264140);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1264100);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqInstance_WithinDistanceToTargetForTime,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1264120);
};

// ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>
// Header:  Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h
class ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy> : public ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	virtual ~ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>();
	virtual const char* DoGetClassName() const;
	virtual bool DoIsGlobal() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const;

#if 0
	ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>();
	void Initialize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg1_) const;
	void Finalize(const ArkNpc* _arg0_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg1_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg1_) const;
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance& _arg2_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x1264220);
	static inline auto FDoIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this)>(0x13B0900);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpcAbilityPrereq& _other)>(0x132FC40);
	static inline auto FDoMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0x1264240);
	static inline auto FDoGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x12635A0);
	static inline auto FDoInitialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoFinalize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1264230);
	static inline auto FDoOnPerformedContext = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqInstance_WithinNavMeshAllowedDistance,ArkNpcAbilityPrereqLocalScopePolicy>* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1264290);
};
#endif // MOONCRASH
