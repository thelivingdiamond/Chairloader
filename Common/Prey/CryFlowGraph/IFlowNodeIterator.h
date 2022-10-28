// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct IFlowNodeData;

// Header: MadeUp
// _unknown/IFlowNodeIterator.h
struct IFlowNodeIterator // Id=8000F5F Size=8
{
	virtual ~IFlowNodeIterator();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual IFlowNodeData *Next(uint16_t &arg0) = 0;
};

