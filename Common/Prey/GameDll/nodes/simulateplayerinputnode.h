// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CFlowNode_SimulatePlayerInput
// Header:  Prey/GameDll/nodes/simulateplayerinputnode.h
class CFlowNode_SimulatePlayerInput : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputPorts
	{
		eInputPorts_Action = 0,
		eInputPorts_Press = 1,
		eInputPorts_Hold = 2,
		eInputPorts_Release = 3,
		eInputPorts_Value = 4,
	};

	enum EOutputPorts
	{
		eOutputPort_Pressed = 0,
		eOutputPort_Held = 1,
		eOutputPort_Released = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* sizer) const;

#if 0
	CFlowNode_SimulatePlayerInput(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_SimulatePlayerInput* const _this, SFlowNodeConfig& config)>(0x18B89F0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_SimulatePlayerInput* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B9010);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_SimulatePlayerInput* const _this, ICrySizer* sizer)>(0x455F00);
};
#endif // MOONCRASH
