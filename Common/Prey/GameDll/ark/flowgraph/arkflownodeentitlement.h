// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_HasEntitlement
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeentitlement.h
class CArkFlowNode_HasEntitlement : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		entitlement = 1,
	};

	enum class EOutputs
	{
		output = 0,
		outputTrue = 1,
		outputFalse = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_HasEntitlement(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_HasEntitlement* const _this, SFlowNodeConfig& _config)>(0x1241530);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_HasEntitlement* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1241AA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_HasEntitlement* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_PopulateBonusContainer
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeentitlement.h
class CArkFlowNode_PopulateBonusContainer : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_PopulateBonusContainer(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_PopulateBonusContainer* const _this, SFlowNodeConfig& _config)>(0x12418B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_PopulateBonusContainer* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1241C00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_PopulateBonusContainer* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
