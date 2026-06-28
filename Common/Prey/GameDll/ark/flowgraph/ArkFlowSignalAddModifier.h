// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowSignalAddModifier
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSignalAddModifier.h
class ArkFlowSignalAddModifier : public CFlowBaseNode<1>
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
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowSignalAddModifier(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSignalAddModifier* const _this, SFlowNodeConfig& _config)>(0x15F9480);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSignalAddModifier* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F97D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSignalAddModifier* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowSignalAddModifier* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F9430);
};
#endif // MOONCRASH
