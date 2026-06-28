// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeSetPortalOcclusion
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeaudiopropagation.h
class ArkFlowNodeSetPortalOcclusion : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		occlusion = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeSetPortalOcclusion(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetPortalOcclusion* const _this, SFlowNodeConfig& _config)>(0x1510590);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetPortalOcclusion* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1510860);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeSetPortalOcclusion* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
