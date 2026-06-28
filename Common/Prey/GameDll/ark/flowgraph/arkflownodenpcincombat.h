// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeInCombat
// Header:  Prey/GameDll/ark/flowgraph/arkflownodenpcincombat.h
class ArkFlowNodeInCombat : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_get = 0,
	};

	enum class EOutputPortIndex
	{
		k_out = 0,
		k_true = 1,
		k_false = 2,
	};

	virtual ~ArkFlowNodeInCombat();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeInCombat(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeInCombat* const _this, SFlowNodeConfig& config)>(0x151A6A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeInCombat* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x151A910);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeInCombat* const _this, ICrySizer* _pSizer)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeInCombat* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151A9C0);
};
#endif // MOONCRASH
