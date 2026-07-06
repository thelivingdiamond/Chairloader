// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasonlyturretswithweapontype/ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType.h
class ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	string m_turretWeaponExtensionName;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12615E0);
	static inline auto FArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType = PreyFunction<void(ArkNpcAbilityPrereq_HasOnlyTurretsWithWeaponType* const _this)>(0x12615B0);
};
#endif // MOONCRASH
