// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowGraphDebugger.h>

struct SBreakPoint;
struct STracePoint;

// Header: MadeUp
// _unknown/IFlowGraphDebugListener.h
struct IFlowGraphDebugListener // Id=8004714 Size=8
{
	virtual void OnBreakpointAdded(SBreakPoint const &arg0) = 0;
	virtual void OnBreakpointRemoved(SBreakPoint const &arg0) = 0;
	virtual void OnAllBreakpointsRemovedForNode(_smart_ptr<IFlowGraph> arg0, uint16_t arg1) = 0;
	virtual void OnAllBreakpointsRemovedForGraph(_smart_ptr<IFlowGraph> arg0) = 0;
	virtual void OnBreakpointHit(SBreakPoint const &arg0) = 0;
	virtual void OnTracepointHit(STracePoint const &arg0) = 0;
	virtual void OnBreakpointInvalidated(SBreakPoint const &arg0) = 0;
	virtual void OnEnableBreakpoint(SBreakPoint const &arg0, bool arg1) = 0;
	virtual void OnEnableTracepoint(STracePoint const &arg0, bool arg1) = 0;
	virtual ~IFlowGraphDebugListener();
};

