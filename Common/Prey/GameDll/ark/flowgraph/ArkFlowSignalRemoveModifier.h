// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowSignalRemoveModifier
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSignalRemoveModifier.h
class ArkFlowSignalRemoveModifier : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		modifierId = 0,
		trigger = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		success = 1,
		failure = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowSignalRemoveModifier(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSignalRemoveModifier* const _this, SFlowNodeConfig& _config)>(0x15FA8A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSignalRemoveModifier* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15FAC40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSignalRemoveModifier* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowSignalRemoveModifier* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15FA850);
};
#endif // MOONCRASH
