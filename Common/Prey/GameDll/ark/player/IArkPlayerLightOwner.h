// Header file automatically created from a PDB.
#pragma once

// IArkPlayerLightOwner
// Header:  Prey/GameDll/ark/player/IArkPlayerLightOwner.h
class IArkPlayerLightOwner
{ // Size=8 (0x8)
public:
	virtual void LightVisibilityUpdated(bool _bVisible);

	static inline auto FLightVisibilityUpdated = PreyFunction<void(IArkPlayerLightOwner* const _this, bool _bVisible)>(0xA13080);
};

