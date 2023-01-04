// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>

class IArkPsiPower;
struct IEntity;

// CArkPsiPowerAlienTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerAlienTargetingComponent.h
class CArkPsiPowerAlienTargetingComponent : public CArkPsiPower3DTargetingComponent
{ // Size=464 (0x1D0)
public:
	std::vector<IEntity*> GetEntitiesInSphere(const float _radius) const { alignas(std::vector<IEntity*>) std::byte _return_buf_[sizeof(std::vector<IEntity*>)]; return *FGetEntitiesInSphere(this, reinterpret_cast<std::vector<IEntity*>*>(_return_buf_), _radius); }

#if 0
	CArkPsiPowerAlienTargetingComponent(const IArkPsiPower* const _arg0_);
#endif

	static inline auto FGetEntitiesInSphere = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerAlienTargetingComponent* const _this, std::vector<IEntity*>* _return_value_, const float _radius)>(0x1584FC0);
};

