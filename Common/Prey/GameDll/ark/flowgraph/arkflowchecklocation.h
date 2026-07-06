// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeCheckLocation
// Header:  Prey/GameDll/ark/flowgraph/arkflowchecklocation.h
class ArkFlowNodeCheckLocation : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		INP_Trigger = 0,
		INP_Location = 1,
	};

	enum class OutPort
	{
		OUTP_Out = 0,
		OUTP_True = 1,
		OUTP_False = 2,
	};

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeCheckLocation(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeCheckLocation* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x150EFA0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeCheckLocation* const _this, SFlowNodeConfig& _config)>(0x150EFF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeCheckLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x150F390);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeCheckLocation* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
