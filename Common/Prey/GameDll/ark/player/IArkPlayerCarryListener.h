// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/GameDll/ark/player/IArkPlayerCarryListener.h
class IArkPlayerCarryListener // Id=8015416 Size=8
{
public:
	virtual void OnStartCarry(IEntity *const _pEntity);
	virtual void OnStopCarry(IEntity *const _pEntity, bool _bThrown);
	
	static inline auto FOnStartCarry = PreyFunction<void(IArkPlayerCarryListener *const _this, IEntity *const _pEntity)>(0xA13080);
	static inline auto FOnStopCarry = PreyFunction<void(IArkPlayerCarryListener *const _this, IEntity *const _pEntity, bool _bThrown)>(0xA13080);
};

