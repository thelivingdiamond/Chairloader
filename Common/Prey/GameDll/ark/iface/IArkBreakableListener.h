// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/GameDll/ark/iface/IArkBreakableListener.h
class IArkBreakableListener // Id=80155FF Size=8
{
public:
	virtual void OnBroken(IEntity const &_entity);
	virtual void OnRepaired(IEntity const &_entity);
	
#ifndef MOONCRASH
	static inline auto FOnBroken = PreyFunction<void(IArkBreakableListener *const _this, IEntity const &_entity)>(0xA13080);
	static inline auto FOnRepaired = PreyFunction<void(IArkBreakableListener *const _this, IEntity const &_entity)>(0xA13080);
#else
	static inline auto FOnBroken = PreyFunction<void(IArkBreakableListener* const _this, const IEntity& _entity)>(0x1333E90);
	static inline auto FOnRepaired = PreyFunction<void(IArkBreakableListener* const _this, const IEntity& _entity)>(0x1333E90);
#endif
};
