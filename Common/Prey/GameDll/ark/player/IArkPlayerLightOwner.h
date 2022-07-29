// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/player/IArkPlayerLightOwner.h
class IArkPlayerLightOwner // Id=80134CF Size=8
{
public:
	virtual void LightVisibilityUpdated(bool _bVisible);
	
	static inline auto FLightVisibilityUpdated = PreyFunction<void(IArkPlayerLightOwner *const _this, bool _bVisible)>(0xA13080);
};

