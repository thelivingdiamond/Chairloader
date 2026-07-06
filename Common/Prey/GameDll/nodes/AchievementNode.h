// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CAchievementNode
// Header:  Prey/GameDll/nodes/AchievementNode.h
class CAchievementNode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum INPUTS
	{
		EIP_Trigger = 0,
		EIP_Achievement = 1,
	};

	enum OUTPUTS
	{
		EOP_Output = 0,
	};

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CAchievementNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CAchievementNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FGetConfiguration = PreyFunction<void(CAchievementNode* const _this, SFlowNodeConfig& config)>(0x189BF70);
	static inline auto FProcessEvent = PreyFunction<void(CAchievementNode* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x189C2C0);
};
#endif // MOONCRASH
