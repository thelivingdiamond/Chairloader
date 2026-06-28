// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkUtilityListener.h
class IArkUtilityListener // Id=80155F1 Size=8
{
public:
	virtual void OnUtilityStateChanged(const uint64_t arg0) = 0;
	virtual void OnUtilityHiddenChanged(const uint64_t arg0);
	virtual void OnUtilityButtonStateChanged(const uint64_t arg0);
	virtual void OnUtilityButtonHiddenChanged(const uint64_t arg0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkUtilityListener
// Header:  Prey/GameDll/ark/iface/IArkUtilityListener.h
class IArkUtilityListener
{ // Size=8 (0x8)
public:
	virtual void OnUtilityStateChanged(const uint64_t _id) = 0;
	virtual void OnUtilityHiddenChanged(const uint64_t _arg0_);
	virtual void OnUtilityButtonStateChanged(const uint64_t _arg0_);
	virtual void OnUtilityButtonHiddenChanged(const uint64_t _arg0_);
};
#endif // !MOONCRASH
