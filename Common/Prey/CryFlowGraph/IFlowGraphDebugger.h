// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryExtension/ICryUnknown.h>
#include <Prey/CryFlowGraph/IFlowGraphDebugger.h>
#include <_unknown/DynArray_SBreakPoint,int,NArray__SmallDynStorage_NAlloc__AllocCompatible_NAlloc__ModuleAlloc_ _ _.h>

struct CryGUID;
struct IFlowGraph;
struct IFlowGraphDebugListener;
struct SBreakPoint;
struct SFlowAddress;
class TFlowInputData;

// Header: MadeUp
// _unknown/IFlowGraphDebugger.h
struct IFlowGraphDebugger : public ICryUnknown // Id=8004711 Size=8
{
	virtual ~IFlowGraphDebugger();
	virtual bool AddBreakpoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1) = 0;
	virtual bool RemoveBreakpoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1) = 0;
	virtual bool RemoveAllBreakpointsForNode(_smart_ptr<IFlowGraph> arg0, uint16_t arg1) = 0;
	virtual bool RemoveAllBreakpointsForGraph(_smart_ptr<IFlowGraph> arg0) = 0;
	virtual bool HasBreakpoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1) const = 0;
	virtual bool HasBreakpoint(_smart_ptr<IFlowGraph> arg0, uint16_t arg1) const = 0;
	virtual bool HasBreakpoint(_smart_ptr<IFlowGraph> arg0) const = 0;
	virtual bool EnableBreakpoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1, bool arg2) = 0;
	virtual bool EnableTracepoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1, bool arg2) = 0;
	virtual bool IsBreakpointEnabled(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1) const = 0;
	virtual bool IsTracepoint(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1) const = 0;
	virtual SBreakPoint const &GetBreakpoint() const = 0;
	virtual void InvalidateBreakpoint() = 0;
	virtual bool BreakpointHit() const = 0;
	virtual bool RegisterListener(IFlowGraphDebugListener *arg0, const char *arg1) = 0;
	virtual void UnregisterListener(IFlowGraphDebugListener *arg0) = 0;
	virtual bool PerformActivation(_smart_ptr<IFlowGraph> arg0, SFlowAddress const &arg1, TFlowInputData const &arg2) = 0;
	virtual bool PerformActivation(_smart_ptr<IFlowGraph> arg0, int arg1, SFlowAddress const &arg2, SFlowAddress const &arg3, TFlowInputData const &arg4) = 0;
	virtual bool RePerformActivation() = 0;
	virtual void ClearBreakpoints() = 0;
	virtual bool GetBreakpoints(DynArray<SBreakPoint,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > &arg0) = 0;
	virtual _smart_ptr<IFlowGraph> GetRootGraph(_smart_ptr<IFlowGraph> arg0) const = 0;
	virtual void SetStepMode(EFlowGraphStepMode arg0) = 0;
	virtual bool IsStepModeEnabled() = 0;
	virtual bool AddIgnoredFlowgraph(_smart_ptr<IFlowGraph> arg0) = 0;
	virtual bool RemoveIgnoredFlowgraph(_smart_ptr<IFlowGraph> arg0) = 0;
	virtual bool IsFlowgraphIgnored(_smart_ptr<IFlowGraph> arg0) = 0;
	virtual bool IgnoreFlowgraphType(IFlowGraph::EFlowGraphType arg0, bool arg1) = 0;
	virtual bool IsFlowgraphTypeIgnored(IFlowGraph::EFlowGraphType arg0) = 0;
	
#if 0
	static CryGUID const &IID();
#endif
};

