// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcLockMimicry
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLockMimicry.h
class ArkFlowNodeNpcLockMimicry : public CFlowBaseNode<0>
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
	ArkFlowNodeNpcLockMimicry(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLockMimicry* const _this, SFlowNodeConfig& _configuration)>(0x12467E0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcLockMimicry* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1246A30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcLockMimicry* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
