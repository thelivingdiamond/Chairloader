// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CFlowPlayerLinkNode
// Header:  Prey/GameDll/nodes/FlowPlayerStagingNode.h
class CFlowPlayerLinkNode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputPorts
	{
		EIP_Link = 0,
		EIP_Unlink = 1,
		EIP_Target = 2,
		EIP_DrawPlayer = 3,
		EIP_KeepTransform = 4,
	};

	enum EOutputPorts
	{
		EOP_Linked = 0,
		EOP_Unlinked = 1,
	};

	virtual ~CFlowPlayerLinkNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowPlayerLinkNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowPlayerLinkNode* const _this, SFlowNodeConfig& config)>(0x18A7E40);
	static inline auto FProcessEvent = PreyFunction<void(CFlowPlayerLinkNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A83F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowPlayerLinkNode* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowPlayerStagingNode
// Header:  Prey/GameDll/nodes/FlowPlayerStagingNode.h
class CFlowPlayerStagingNode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputPorts
	{
		EIP_Trigger = 0,
		EIP_LimitDir = 1,
		EIP_LocalSpace = 2,
		EIP_LimitYaw = 3,
		EIP_LimitPitch = 4,
		EIP_Lock = 5,
		EIP_Stance = 6,
	};

	enum EOutputPorts
	{
		EOP_Done = 0,
	};

	virtual ~CFlowPlayerStagingNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowPlayerStagingNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowPlayerStagingNode* const _this, SFlowNodeConfig& config)>(0x18A74F0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowPlayerStagingNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A7C50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowPlayerStagingNode* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
