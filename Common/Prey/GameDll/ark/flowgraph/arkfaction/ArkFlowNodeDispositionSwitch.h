// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkfactionflowgraphcommon.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct SFlowNodeConfig;

// ArkFlowNodeDispositionSwitch
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/ArkFlowNodeDispositionSwitch.h
class ArkFlowNodeDispositionSwitch : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 0,
	};

	virtual ~ArkFlowNodeDispositionSwitch();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeDispositionSwitch(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDispositionSwitch* const _this, SFlowNodeConfig& config)>(0x15B5960);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDispositionSwitch* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B5B60);
};
#endif // MOONCRASH
