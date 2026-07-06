// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcUnlockBurrow
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcUnlockBurrow.h
class ArkFlowNodeNpcUnlockBurrow : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_inputIndex_unlock = 0,
		k_inputIndex_bForceUnburrow = 1,
	};

	enum class EOutputPortIndex
	{
		k_outputIndex_out = 0,
		k_outputIndex_succeeded = 1,
		k_outputIndex_failed = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	ArkFlowNodeNpcUnlockBurrow(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcUnlockBurrow* const _this, SFlowNodeConfig& _configuration)>(0x11DFEA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcUnlockBurrow* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x11E01D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcUnlockBurrow* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
