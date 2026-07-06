// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeSetObjectiveDescription
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSetObjectiveDescription.h
class CArkFlowNodeSetObjectiveDescription : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		TRIGGER = 0,
		DESCRIPTION = 1,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetObjectiveDescription(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetObjectiveDescription* const _this, SFlowNodeConfig& _rConfig)>(0x15F1D00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetObjectiveDescription* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F2020);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetObjectiveDescription* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
