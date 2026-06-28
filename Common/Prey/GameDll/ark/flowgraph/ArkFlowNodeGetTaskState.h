// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeGetTaskState
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeGetTaskState.h
class CArkFlowNodeGetTaskState : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		TRIGGER = 0,
		TASK = 1,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
		ACTIVE = 1,
		INACTIVE = 2,
		COMPLETED = 3,
		FAILED = 4,
		TIMER = 5,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeGetTaskState(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetTaskState* const _this, SFlowNodeConfig& _rConfig)>(0x15D9D00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGetTaskState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DA100);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGetTaskState* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
