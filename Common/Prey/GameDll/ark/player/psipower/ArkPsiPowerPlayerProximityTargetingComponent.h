// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>

class IArkPsiPower;

// ArkPsiPowerPlayerProximityTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerPlayerProximityTargetingComponent.h
class ArkPsiPowerPlayerProximityTargetingComponent : public CArkPsiPower3DTargetingComponent
{ // Size=464 (0x1D0)
public:
	ArkPsiPowerPlayerProximityTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~ArkPsiPowerPlayerProximityTargetingComponent();
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	virtual bool UsePositionEmitter() const;

#if 0
	Vec3 GetTargetPos() const;
#endif

	static inline auto FArkPsiPowerPlayerProximityTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerPlayerProximityTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x13B84A0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerPlayerProximityTargetingComponent* const _this, const float _frameTime)>(0x13B84D0);
	static inline auto FUsePositionEmitter = PreyFunction<bool(const ArkPsiPowerPlayerProximityTargetingComponent* const _this)>(0x13B0900);
};
#endif // MOONCRASH
