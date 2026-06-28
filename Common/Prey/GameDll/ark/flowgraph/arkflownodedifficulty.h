// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNode_TestDifficultyOption
// Header:  Prey/GameDll/ark/flowgraph/arkflownodedifficulty.h
class ArkFlowNode_TestDifficultyOption : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_Ironman = 0,
		eIN_WeaponDegradation = 1,
		eIN_Traumas = 2,
		eIN_Oxygen = 3,
	};

	enum EOutputs
	{
		eOUT_Result = 0,
		eOUT_Enabled = 1,
		eOUT_Disabled = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNode_TestDifficultyOption(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_TestDifficultyOption* const _this, SFlowNodeConfig& _config)>(0x1240180);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_TestDifficultyOption* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1240630);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_TestDifficultyOption* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
