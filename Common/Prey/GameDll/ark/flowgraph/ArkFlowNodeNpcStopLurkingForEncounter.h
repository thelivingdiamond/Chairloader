// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcStopLurkingForEncounter
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcStopLurkingForEncounter.h
class ArkFlowNodeNpcStopLurkingForEncounter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_inputIndex_stop = 0,
		k_profileNameInputPortIndex = 1,
		k_encounterNameInputPortIndex = 2,
	};

	enum class EOutputPortIndex
	{
		k_outputIndex_out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	ArkFlowNodeNpcStopLurkingForEncounter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcStopLurkingForEncounter* const _this, SFlowNodeConfig& _configuration)>(0x1248610);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcStopLurkingForEncounter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1248A80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcStopLurkingForEncounter* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
