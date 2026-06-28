// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_MimicMorphEffect
// Header:  Prey/GameDll/ark/flowgraph/arkflownodemimicmorpheffect.h
class CArkFlowNode_MimicMorphEffect : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_MORPH_OUT = 0,
		eIN_MORPH_IN = 1,
		eIN_MORPH_RESET_VISIBLE = 2,
		eIN_MORPH_RESET_INVISIBLE = 3,
		eIN_MORPH_TIME = 4,
		eIN_CONTROL_PHYSICS = 5,
	};

	enum EOutputs
	{
		eOUT_MORPHING_OUT = 0,
		eOUT_MORPHING_IN = 1,
		eOUT_MORPHING_RESET = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_MimicMorphEffect(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_MimicMorphEffect* const _this, SFlowNodeConfig& _config)>(0x15E43A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_MimicMorphEffect* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E4A20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_MimicMorphEffect* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
