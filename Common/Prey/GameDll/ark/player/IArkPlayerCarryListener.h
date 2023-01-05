// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// IArkPlayerCarryListener
// Header:  Prey/GameDll/ark/player/IArkPlayerCarryListener.h
class IArkPlayerCarryListener
{ // Size=8 (0x8)
public:
	virtual void OnStartCarry(IEntity* const _pEntity);
	virtual void OnStopCarry(IEntity* const _pEntity, bool _bThrown);

	static inline auto FOnStartCarry = PreyFunction<void(IArkPlayerCarryListener* const _this, IEntity* const _pEntity)>(0xA13080);
	static inline auto FOnStopCarry = PreyFunction<void(IArkPlayerCarryListener* const _this, IEntity* const _pEntity, bool _bThrown)>(0xA13080);
};

