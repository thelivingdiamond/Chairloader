// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>

// Header: MadeUp
// _unknown/IFlowEdgeIterator.h
struct IFlowEdgeIterator // Id=8001C43 Size=8
{
	struct Edge // Id=8001C44 Size=8
	{
		uint16_t fromNodeId;
		uint8_t fromPortId;
		uint16_t toNodeId;
		uint8_t toPortId;
	};

	virtual ~IFlowEdgeIterator();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual bool Next(IFlowEdgeIterator::Edge &arg0) = 0;
};

