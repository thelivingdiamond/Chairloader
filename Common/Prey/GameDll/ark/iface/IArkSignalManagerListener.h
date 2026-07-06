// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkSignalManagerListener.h
class IArkSignalManagerListener // Id=80156E7 Size=8
{
public:
	virtual void OnRegisteredSignalsChanged(unsigned arg0, std::vector<unsigned __int64> const &arg1, bool arg2);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkSignalManagerListener
// Header:  Prey/GameDll/ark/iface/IArkSignalManagerListener.h
class IArkSignalManagerListener
{ // Size=8 (0x8)
public:
	virtual void OnRegisteredSignalsChanged(unsigned _arg0_, const std::vector<uint64_t>& _arg1_, bool _arg2_);
};
#endif // !MOONCRASH
