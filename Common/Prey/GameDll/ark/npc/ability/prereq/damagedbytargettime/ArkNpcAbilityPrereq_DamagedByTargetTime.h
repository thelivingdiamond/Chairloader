// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_DamagedByTargetTime;

// ArkNpcAbilityPrereq_DamagedByTargetTime
// Header:  Prey/GameDll/ark/npc/ability/prereq/damagedbytargettime/ArkNpcAbilityPrereq_DamagedByTargetTime.h
class ArkNpcAbilityPrereq_DamagedByTargetTime : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DamagedByTargetTime,ArkNpcAbilityPrereqInstance_DamagedByTargetTime,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_minTime;
	float m_maxTime;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_DamagedByTargetTime();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_DamagedByTargetTime& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg2_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg2_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_DamagedByTargetTime& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125EB20);
	static inline auto FArkNpcAbilityPrereq_DamagedByTargetTime = PreyFunction<void(ArkNpcAbilityPrereq_DamagedByTargetTime* const _this)>(0x125E9E0);
};
#endif // MOONCRASH
