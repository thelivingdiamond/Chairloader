// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_IsArchetypeInWorld
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeisarchetypeinworld.h
class CArkFlowNode_IsArchetypeInWorld : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		archetype = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		outTrue = 1,
		outFalse = 2,
		entity = 3,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_IsArchetypeInWorld(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_IsArchetypeInWorld* const _this, SFlowNodeConfig& _config)>(0x15142A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_IsArchetypeInWorld* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1514670);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_IsArchetypeInWorld* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
