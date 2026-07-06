// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeSetObjectiveTracked
// Header:  Prey/GameDll/ark/flowgraph/arkflownodesetcurrentobjective.h
class CArkFlowNodeSetObjectiveTracked : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		TRIGGER = 0,
		OBJECTIVE = 1,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSetObjectiveTracked(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetObjectiveTracked* const _this, SFlowNodeConfig& _rConfig)>(0x15F18B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetObjectiveTracked* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1BD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetObjectiveTracked* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeSetObjectiveTracked* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1860);
};
#endif // MOONCRASH
