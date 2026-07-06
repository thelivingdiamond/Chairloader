// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcHasAnyTags
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcHasAnyTags.h
class ArkFlowNodeNpcHasAnyTags : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		check = 0,
		arkMetaTags = 1,
	};

	enum class EOutput
	{
		truePort = 0,
		falsePort = 1,
		out = 2,
	};

	virtual ~ArkFlowNodeNpcHasAnyTags();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	ArkFlowNodeNpcHasAnyTags(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcHasAnyTags* const _this, SFlowNodeConfig& config)>(0x1518F40);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcHasAnyTags* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15192E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcHasAnyTags* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
