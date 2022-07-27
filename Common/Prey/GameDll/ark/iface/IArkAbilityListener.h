// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/iface/IArkAbilityListener.h
class IArkAbilityListener // Id=8013975 Size=8
{
public:
	virtual void OnAbilityAdded(uint64_t _abilityID);
	virtual void OnBecomeAlien();
	
	static inline auto FOnAbilityAdded = PreyFunction<void(IArkAbilityListener *const _this, uint64_t _abilityID)>(0xA13080);
	static inline auto FOnBecomeAlien = PreyFunction<void(IArkAbilityListener *const _this)>(0xA13080);
};

