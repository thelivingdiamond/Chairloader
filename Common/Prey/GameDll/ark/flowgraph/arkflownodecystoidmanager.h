// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_CystoidManager
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecystoidmanager.h
class CArkFlowNode_CystoidManager : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		enabled = 0,
		disabled = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_CystoidManager(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_CystoidManager* const _this, SFlowNodeConfig& _config)>(0x123FD90);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_CystoidManager* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1240080);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_CystoidManager* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
