// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowInhibitJump
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowInhibitJump.h
class ArkFlowInhibitJump : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		inhibit = 0,
		allow = 1,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowInhibitJump(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowInhibitJump* const _this, SFlowNodeConfig& _config)>(0x123D8A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowInhibitJump* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123DB80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowInhibitJump* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
