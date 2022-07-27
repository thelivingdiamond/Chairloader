// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Prey/GameDll/ark/iface/IArkBreakableListener.h
class IArkBreakableListener // Id=80155FF Size=8
{
public:
	virtual void OnBroken(IEntity const &_entity);
	virtual void OnRepaired(IEntity const &_entity);
	
	static inline auto FOnBroken = PreyFunction<void(IArkBreakableListener *const _this, IEntity const &_entity)>(0xA13080);
	static inline auto FOnRepaired = PreyFunction<void(IArkBreakableListener *const _this, IEntity const &_entity)>(0xA13080);
};

