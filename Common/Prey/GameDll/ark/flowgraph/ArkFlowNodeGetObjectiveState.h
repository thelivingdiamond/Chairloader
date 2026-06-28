// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeGetObjectiveState
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeGetObjectiveState.h
class CArkFlowNodeGetObjectiveState : public CFlowBaseNode<1>
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
		TRACKING_ENABLED = 1,
		TRACKING_DISABLED = 2,
		ASSIGNED = 3,
		UNASSIGNED = 4,
		COMPLETED = 5,
		FAILED = 6,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeGetObjectiveState(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetObjectiveState* const _this, SFlowNodeConfig& _rConfig)>(0x15D9460);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGetObjectiveState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D9890);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGetObjectiveState* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGetObjectiveState* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D93E0);
};
#endif // MOONCRASH
