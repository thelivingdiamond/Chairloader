// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaRadiation
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaRadiation.h
class ArkTraumaRadiation : public ArkTraumaBase
{ // Size=296 (0x128)
public:
	ArkTraumaRadiation();
	virtual void Activate(int _level);

	static inline auto FArkTraumaRadiationOv2 = PreyFunction<void(ArkTraumaRadiation* const _this)>(0x1464E60);
	static inline auto FActivate = PreyFunction<void(ArkTraumaRadiation* const _this, int _level)>(0x1464EA0);
};

