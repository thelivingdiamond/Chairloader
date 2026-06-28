// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_ArkPlayerWeaponIdleBreak
// Header:  Prey/GameDll/ark/flowgraph/arkflowplayerweaponidlebreak.h
class CFlowNode_ArkPlayerWeaponIdleBreak : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum INS
	{
		EIP_ENABLE = 0,
		EIP_DISABLE = 1,
	};

	enum OUTS
	{
		EOP_ONENABLED = 0,
		EOP_ONDISABLED = 1,
	};

	virtual ~CFlowNode_ArkPlayerWeaponIdleBreak();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CFlowNode_ArkPlayerWeaponIdleBreak(IFlowNode::SActivationInfo* _arg0_);
	void Enable(IFlowNode::SActivationInfo* _arg0_);
	void Disable(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_ArkPlayerWeaponIdleBreak* const _this, SFlowNodeConfig& config)>(0x124E970);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_ArkPlayerWeaponIdleBreak* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124EC70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_ArkPlayerWeaponIdleBreak* const _this, ICrySizer* _s)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_ArkPlayerWeaponIdleBreak* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x124ED40);
};
#endif // MOONCRASH
