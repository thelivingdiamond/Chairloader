// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_WithinArcToTarget
// Header:  Prey/GameDll/ark/npc/ability/prereq/withinarctotarget/ArkNpcAbilityPrereq_WithinArcToTarget.h
class ArkNpcAbilityPrereq_WithinArcToTarget : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_WithinArcToTarget,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	bool m_bUseHeadDirection;
	float m_minAngleToTargetDegrees;
	float m_maxAngleToTargetDegrees;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_WithinArcToTarget();
	float GetMaxAngle() const { return FGetMaxAngle(this); }
	void SetMaxAngle(float _angleDegrees) { FSetMaxAngle(this, _angleDegrees); }
	float GetMinAngle() const { return FGetMinAngle(this); }
	void SetMinAngle(float _angleDegrees) { FSetMinAngle(this, _angleDegrees); }
	void CorrectMinMaxAngle() { FCorrectMinMaxAngle(this); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_WithinArcToTarget& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
	bool WithinAngleRange(float _arg0_, float _arg1_, float _arg2_) const;
	float NormalizeAngle(float _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263F30);
	static inline auto FArkNpcAbilityPrereq_WithinArcToTarget = PreyFunction<void(ArkNpcAbilityPrereq_WithinArcToTarget* const _this)>(0x1263C80);
	static inline auto FGetMaxAngle = PreyFunction<float(const ArkNpcAbilityPrereq_WithinArcToTarget* const _this)>(0x88A4D0);
	static inline auto FSetMaxAngle = PreyFunction<void(ArkNpcAbilityPrereq_WithinArcToTarget* const _this, float _angleDegrees)>(0x12640A0);
	static inline auto FGetMinAngle = PreyFunction<float(const ArkNpcAbilityPrereq_WithinArcToTarget* const _this)>(0x88A4D0);
	static inline auto FSetMinAngle = PreyFunction<void(ArkNpcAbilityPrereq_WithinArcToTarget* const _this, float _angleDegrees)>(0x12640B0);
	static inline auto FCorrectMinMaxAngle = PreyFunction<void(ArkNpcAbilityPrereq_WithinArcToTarget* const _this)>(0x1263CC0);
};
#endif // MOONCRASH
