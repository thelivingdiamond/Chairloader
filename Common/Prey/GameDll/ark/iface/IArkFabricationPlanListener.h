// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkFabricationPlanListener.h
class IArkFabricationPlanListener // Id=8015541 Size=8
{
public:
	virtual void OnFabricationPlanAdded(const uint64_t arg0) = 0;
	virtual void OnFabricationPlanUsed(const uint64_t arg0) = 0;
	virtual void OnFabricationErrorSet(const uint64_t arg0);
	virtual void OnFabricationErrorCleared(const uint64_t arg0);
};

