// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkRepairableListener.h
class IArkRepairableListener // Id=8014330 Size=8
{
public:
	virtual void OnBrokenChanged(bool arg0, bool arg1) = 0;
	virtual void OnFortified();
	
	static inline auto FOnFortified = PreyFunction<void(IArkRepairableListener *const _this)>(0xA13080);
};

