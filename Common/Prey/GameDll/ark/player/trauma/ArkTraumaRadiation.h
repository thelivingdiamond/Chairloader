// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaRadiation.h
class ArkTraumaRadiation : public ArkTraumaBase // Id=801C0CE Size=296
{
public:
	ArkTraumaRadiation();
	virtual void Activate(int _level);
	virtual ~ArkTraumaRadiation();
	
	static inline auto FActivate = PreyFunction<void(ArkTraumaRadiation *const _this, int _level)>(0x1464EA0);
};

