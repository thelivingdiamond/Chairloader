// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics;

// ArkNpcAbilityPrereq_HasEnoughNearbyNpcs
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasenoughnearbynpcs/ArkNpcAbilityPrereq_HasEnoughNearbyNpcs.h
class ArkNpcAbilityPrereq_HasEnoughNearbyNpcs : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasEnoughNearbyNpcs,ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=80 (0x50)
public:
	float m_checkRadius;
	float m_checkHeight;
	uint64_t m_requiredTag;
	uint64_t m_disqualifyingGameEffectId;
	bool m_bMustBeReachable;
	unsigned m_minNumberOfNpcs;
	unsigned m_maxNumberOfNpcsFromSpawners;
	float m_spawnerCheckPlayerExclusionRadius;
	float m_spawnerCheckPlayerExclusionConeAngle;
	float m_spawnerCheckCooldown;
	string m_spawnerNpcArchetype;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasEnoughNearbyNpcs();
	uint64_t CountSurroundingActiveNPCs(const ArkNpc& _npc, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _prereqInstance) const { return FCountSurroundingActiveNPCs(this, _npc, _prereqInstance); }
	uint64_t CountSurroundingNPCSpawners(const ArkNpc& _npc, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _prereqInstance) const { return FCountSurroundingNPCSpawners(this, _npc, _prereqInstance); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasEnoughNearbyNpcs& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg2_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg2_) const;
	bool IsValidNpc(const ArkNpc& _arg0_, const ArkNpc& _arg1_, const Vec3& _arg2_) const;
	uint64_t CountTotalNpcTargets(const ArkNpc& _arg0_, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1260830);
	static inline auto FArkNpcAbilityPrereq_HasEnoughNearbyNpcs = PreyFunction<void(ArkNpcAbilityPrereq_HasEnoughNearbyNpcs* const _this)>(0x125FF60);
	static inline auto FCountSurroundingActiveNPCs = PreyFunction<uint64_t(const ArkNpcAbilityPrereq_HasEnoughNearbyNpcs* const _this, const ArkNpc& _npc, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _prereqInstance)>(0x1260010);
	static inline auto FCountSurroundingNPCSpawners = PreyFunction<uint64_t(const ArkNpcAbilityPrereq_HasEnoughNearbyNpcs* const _this, const ArkNpc& _npc, ArkNpcAbilityPrereqInstance_HasEnoughNearbyMimics& _prereqInstance)>(0x12602A0);
};
#endif // MOONCRASH
