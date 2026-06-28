// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkRepairableListener
// Header:  Prey/GameDll/ark/iface/IArkRepairableListener.h
class IArkRepairableListener
{ // Size=8 (0x8)
public:
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced) = 0;
	virtual void OnFortified();

	static inline auto FOnFortified = PreyFunction<void(IArkRepairableListener* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
