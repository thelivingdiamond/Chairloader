// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNode_SilenceTranscribe
// Header:  Prey/GameDll/ark/flowgraph/arkflownodetranscribe.h
class ArkFlowNode_SilenceTranscribe : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	ArkFlowNode_SilenceTranscribe(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SilenceTranscribe* const _this, SFlowNodeConfig& _config)>(0x124DEE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SilenceTranscribe* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124E1A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SilenceTranscribe* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
