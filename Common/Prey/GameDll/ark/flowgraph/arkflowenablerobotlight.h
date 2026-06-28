// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowHideRobotLight
// Header:  Prey/GameDll/ark/flowgraph/arkflowenablerobotlight.h
class ArkFlowHideRobotLight : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		show = 0,
		hide = 1,
	};

	enum class OutPort
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowHideRobotLight(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowHideRobotLight* const _this, SFlowNodeConfig& _config)>(0x123D4B0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowHideRobotLight* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123D790);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowHideRobotLight* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
