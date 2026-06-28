// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_IsInChallengeMode
// Header:  Prey/GameDll/ark/flowgraph/arkflownodechallengemode.h
class CArkFlowNode_IsInChallengeMode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
		modeActive = 1,
		modeInactive = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_IsInChallengeMode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_IsInChallengeMode* const _this, SFlowNodeConfig& _config)>(0x11DE2D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_IsInChallengeMode* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11DE520);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_IsInChallengeMode* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
