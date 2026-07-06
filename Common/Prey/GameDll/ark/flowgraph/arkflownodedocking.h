// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNode_UpdateDockingSequence
// Header:  Prey/GameDll/ark/flowgraph/arkflownodedocking.h
class ArkFlowNode_UpdateDockingSequence : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_Trigger = 0,
		eIN_ToBay1 = 1,
		eIN_ToBay2 = 2,
		eIN_FromBay1 = 3,
		eIN_FromBay2 = 4,
	};

	enum EOutputs
	{
		eOUT_Updated = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNode_UpdateDockingSequence(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_UpdateDockingSequence* const _this, SFlowNodeConfig& _config)>(0x1240C50);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_UpdateDockingSequence* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1241310);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_UpdateDockingSequence* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_UpdateDockingSequence* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1240AC0);
};
#endif // MOONCRASH
