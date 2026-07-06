// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeNpcDialog
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcDialog.h
class ArkFlowNodeNpcDialog : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	ArkFlowNodeNpcDialog(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcDialog* const _this, SFlowNodeConfig& _config)>(0x1242DD0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcDialog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1243090);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcDialog* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1242D80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcDialog* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
