// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_ExamineWorldUI
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworldui.h
class CArkFlowNode_ExamineWorldUI : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		lock = 0,
		unlock = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_ExamineWorldUI(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_ExamineWorldUI* const _this, SFlowNodeConfig& _config)>(0x152EF40);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_ExamineWorldUI* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152F4C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_ExamineWorldUI* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_KioskElevatorError
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworldui.h
class CArkFlowNode_KioskElevatorError : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		show = 0,
		hide = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_KioskElevatorError(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_KioskElevatorError* const _this, SFlowNodeConfig& _config)>(0x152F200);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_KioskElevatorError* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152F5A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_KioskElevatorError* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
