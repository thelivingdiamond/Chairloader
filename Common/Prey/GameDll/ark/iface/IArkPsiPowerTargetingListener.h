// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkPsiPowerTargetingListener.h
class IArkPsiPowerTargetingListener // Id=8014068 Size=8
{
public:
	virtual void OnPsiTargetingStart(const unsigned arg0) = 0;
	virtual void OnPsiTargetingStop(const unsigned arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkPsiPowerTargetingListener
// Header:  Prey/GameDll/ark/iface/IArkPsiPowerTargetingListener.h
class IArkPsiPowerTargetingListener
{ // Size=8 (0x8)
public:
	virtual void OnPsiTargetingStart(const unsigned _targetedEntity) = 0;
	virtual void OnPsiTargetingStop(const unsigned _targetedEntity) = 0;
};
#endif // !MOONCRASH
