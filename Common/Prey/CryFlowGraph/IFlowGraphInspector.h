// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowGraph;
struct IFlowNode;
struct SFlowAddress;

// Header: MadeUp
// _unknown/IFlowGraphInspector.h
struct IFlowGraphInspector // Id=8001C62 Size=8
{
	struct IFilter // Id=8001C63 Size=8
	{
		enum EFilterResult
		{
			eFR_DontCare = 0,
			eFR_Block = 1,
			eFR_Pass = 2,
		};

		virtual ~IFilter();
		virtual void AddRef() = 0;
		virtual void Release() = 0;
		virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
		virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
		virtual IFlowGraphInspector::IFilter::EFilterResult Apply(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
	};

	using IFilter_AutoPtr = _smart_ptr<IFlowGraphInspector::IFilter>;
	using IFilter_AutoArray = std::vector<_smart_ptr<IFlowGraphInspector::IFilter>>;
	using IFilterPtr = _smart_ptr<IFlowGraphInspector::IFilter>;
	
	virtual ~IFlowGraphInspector();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual void PreUpdate(IFlowGraph *arg0) = 0;
	virtual void PostUpdate(IFlowGraph *arg0) = 0;
	virtual void NotifyFlow(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
	virtual void NotifyProcessEvent(IFlowNode::EFlowEvent arg0, IFlowNode::SActivationInfo *arg1, IFlowNode *arg2) = 0;
	virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
	virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
	virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
};

