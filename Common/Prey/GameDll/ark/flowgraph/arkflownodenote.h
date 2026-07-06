// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeGiveNote
// Header:  Prey/GameDll/ark/flowgraph/arkflownodenote.h
class CArkFlowNodeGiveNote : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		note = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeGiveNote(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveNote* const _this, SFlowNodeConfig& _rConfig)>(0x15E5230);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveNote* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E5560);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveNote* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeHasNote
// Header:  Prey/GameDll/ark/flowgraph/arkflownodenote.h
class CArkFlowNodeHasNote : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		note = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		outTrue = 1,
		outFalse = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeHasNote(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasNote* const _this, SFlowNodeConfig& _rConfig)>(0x15E5710);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasNote* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E5AA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasNote* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
