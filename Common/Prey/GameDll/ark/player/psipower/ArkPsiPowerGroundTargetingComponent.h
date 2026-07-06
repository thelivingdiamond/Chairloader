// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>

class IArkPsiPower;

// ArkPsiPowerGroundTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerGroundTargetingComponent.h
class ArkPsiPowerGroundTargetingComponent : public CArkPsiPower3DTargetingComponent
{ // Size=480 (0x1E0)
public:
	int m_rwiFlags;
	int m_ignoredCollisionClasses;
	bool m_bUseMediumAgent;

	ArkPsiPowerGroundTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~ArkPsiPowerGroundTargetingComponent();
	virtual Vec3 UpdateTargetPosition();

#if 0
	void SetCollisionSettings(const int _arg0_, const int _arg1_);
	void UseMediumAgent();
#endif

	static inline auto FArkPsiPowerGroundTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerGroundTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x13BC410);
	static inline auto FUpdateTargetPosition = PreyFunction<Vec3*(ArkPsiPowerGroundTargetingComponent* const _this, Vec3* _return_value_)>(0x13BC630);
};
#endif // MOONCRASH
