// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>

class IArkPsiPower;
struct IEntity;

// ArkPsiPowerMimicTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMimicTargetingComponent.h
class ArkPsiPowerMimicTargetingComponent : public ArkPsiPowerIndividualTargetingComponent
{ // Size=616 (0x268)
public:
	ArkPsiPowerMimicTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~ArkPsiPowerMimicTargetingComponent();
	virtual bool ValidateTarget(const IEntity& _entity) const;

	static inline auto FArkPsiPowerMimicTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerMimicTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x12F6A90);
	static inline auto FValidateTarget = PreyFunction<bool(const ArkPsiPowerMimicTargetingComponent* const _this, const IEntity& _entity)>(0x12F6B30);
};

