// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;

//! This is a special type which means "no input data".
struct SFlowSystemVoid
{
	void Serialize(TSerialize ser) {}
	void GetMemoryUsage(ICrySizer* pSizer) const {}
};

inline bool operator==(const SFlowSystemVoid& a, const SFlowSystemVoid& b)
{
	return true;
}
