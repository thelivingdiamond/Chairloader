// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>

class IArkPsiPower;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiPowerMimicTargetingComponent.h
class ArkPsiPowerMimicTargetingComponent : public ArkPsiPowerIndividualTargetingComponent // Id=80194CE Size=616
{
public:
	ArkPsiPowerMimicTargetingComponent(IArkPsiPower const *_pPower);
	virtual bool ValidateTarget(IEntity const &_entity) const;
	
	static inline auto FValidateTarget = PreyFunction<bool(ArkPsiPowerMimicTargetingComponent const *const _this, IEntity const &_entity)>(0x12F6B30);
};

