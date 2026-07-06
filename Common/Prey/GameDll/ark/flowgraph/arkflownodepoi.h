// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNode_SetPOIMarker
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepoi.h
class ArkFlowNode_SetPOIMarker : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		set = 0,
		clear = 1,
		poi = 2,
		minRange = 3,
		maxRange = 4,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNode_SetPOIMarker(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SetPOIMarker* const _this, SFlowNodeConfig& _rConfig)>(0x124C200);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SetPOIMarker* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124C7D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SetPOIMarker* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_SetPOIMarker* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x124C1B0);
};
#endif // MOONCRASH
