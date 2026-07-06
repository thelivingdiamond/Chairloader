// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowResetGameToken
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowResetGameToken.h
class ArkFlowResetGameToken : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		reset = 0,
		token = 1,
		group = 2,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowResetGameToken(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowResetGameToken* const _this, SFlowNodeConfig& _config)>(0x124ED90);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowResetGameToken* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124F1A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowResetGameToken* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
