// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcLockUnburrow
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLockUnburrow.h
class ArkFlowNodeNpcLockUnburrow : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_inputIndex_lock = 0,
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
	ArkFlowNodeNpcLockUnburrow(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLockUnburrow* const _this, SFlowNodeConfig& _configuration)>(0x11DFB00);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcLockUnburrow* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x11DFD50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcLockUnburrow* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
