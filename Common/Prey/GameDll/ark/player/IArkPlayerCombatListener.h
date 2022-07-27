// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Prey/GameDll/ark/player/IArkPlayerCombatListener.h
class IArkPlayerCombatListener // Id=8015417 Size=8
{
public:
	virtual void OnCombatChange(bool _bInCombat);
	virtual void OnGrenadeThrown(IEntity *const _pGrenade);
	
	static inline auto FOnCombatChange = PreyFunction<void(IArkPlayerCombatListener *const _this, bool _bInCombat)>(0xA13080);
	static inline auto FOnGrenadeThrown = PreyFunction<void(IArkPlayerCombatListener *const _this, IEntity *const _pGrenade)>(0xA13080);
};

