// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
class ITexture;
struct SFlowNodeConfig;

// CFlowNode_ColorGradient
// Header:  Prey/GameDll/nodes/colorgradientnode.h
class CFlowNode_ColorGradient : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum EInputPorts
	{
		eInputPorts_Trigger = 0,
		eInputPorts_TexturePath = 1,
		eInputPorts_TransitionTime = 2,
		eInputPorts_Count = 3,
	};

	static inline auto inputPorts = PreyGlobal<const SInputPortConfig [0]>(0x23F07C0);
	ITexture* m_pTexture;

	virtual ~CFlowNode_ColorGradient();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* activationInformation);
	virtual void GetMemoryUsage(ICrySizer* sizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlowNode_ColorGradient(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_ColorGradient* const _this, SFlowNodeConfig& config)>(0x189C680);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_ColorGradient* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* activationInformation)>(0x189C6A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_ColorGradient* const _this, ICrySizer* sizer)>(0x4BC120);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_ColorGradient* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189C490);
};
#endif // MOONCRASH
