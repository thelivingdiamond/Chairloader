// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeNpcGetHealth
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGetHealth.h
class ArkFlowNodeNpcGetHealth : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_get = 0,
	};

	enum class EOutputPortIndex
	{
		k_out = 0,
		k_percentage = 1,
		k_value = 2,
	};

	virtual ~ArkFlowNodeNpcGetHealth();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcGetHealth(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcGetHealth* const _this, SFlowNodeConfig& config)>(0x15E5CB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcGetHealth* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E5F20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcGetHealth* const _this, ICrySizer* _pSizer)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcGetHealth* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E6030);
};
#endif // MOONCRASH
