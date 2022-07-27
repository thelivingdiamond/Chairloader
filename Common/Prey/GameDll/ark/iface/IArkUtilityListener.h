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

