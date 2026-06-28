// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;
struct IEntity;

// ArkNpcAbilityPrereq_HasHitReactShiftLocation
// Header:  Prey/GameDll/ark/npc/ability/prereq/hashitreactshiftlocation/ArkNpcAbilityPrereq_HasHitReactShiftLocation.h
class ArkNpcAbilityPrereq_HasHitReactShiftLocation : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasHitReactShiftLocation,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=48 (0x30)
public:
	float m_maxShiftDistance;
	float m_minShiftDistance;
	float m_searchHeight;
	int m_maxNumberOfLoSChecks;
	float m_backwardsAvoidShiftAngle;
	int m_pointAttemptPartitions;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasHitReactShiftLocation();
	Vec3 FindShiftDestination(const ArkNpc& _npc, const IEntity* _pTargetEntity) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FFindShiftDestination(this, reinterpret_cast<Vec3*>(_return_buf_), _npc, _pTargetEntity); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasHitReactShiftLocation& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132DDE0);
	static inline auto FArkNpcAbilityPrereq_HasHitReactShiftLocation = PreyFunction<void(ArkNpcAbilityPrereq_HasHitReactShiftLocation* const _this)>(0x132DD00);
	static inline auto FFindShiftDestination = PreyFunction<Vec3*(const ArkNpcAbilityPrereq_HasHitReactShiftLocation* const _this, Vec3* _return_value_, const ArkNpc& _npc, const IEntity* _pTargetEntity)>(0x132DE60);
};
#endif // MOONCRASH
