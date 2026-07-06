// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_CheckArchetype
// Header:  Prey/GameDll/ark/flowgraph/arkflownodearchetype.h
class CArkFlowNode_CheckArchetype : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		archetype = 1,
	};

	enum class EOutputs
	{
		match = 0,
		different = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_CheckArchetype(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_CheckArchetype* const _this, SFlowNodeConfig& _config)>(0x150F670);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_CheckArchetype* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x150F9D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_CheckArchetype* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
