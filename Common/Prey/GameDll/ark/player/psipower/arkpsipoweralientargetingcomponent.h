// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/psipower/arkpsipower3dtargetingcomponent.h>

class IArkPsiPower;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipoweralientargetingcomponent.h
class CArkPsiPowerAlienTargetingComponent : public CArkPsiPower3DTargetingComponent // Id=801C884 Size=464
{
public:
	std::vector<IEntity *> GetEntitiesInSphere(const float _radius) const { return FGetEntitiesInSphere(this,_radius); }
	
	static inline auto FGetEntitiesInSphere = PreyFunction<std::vector<IEntity *>(CArkPsiPowerAlienTargetingComponent const *const _this, const float _radius)>(0x1584FC0);
};

