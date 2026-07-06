// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SEntityEvent;
struct SFlowNodeConfig;

// CFlowNode_CheckArea
// Header:  Prey/GameDll/nodes/flowcheckareanode.h
class CFlowNode_CheckArea : public CFlowBaseNode<1>, public IEntityEventListener
{ // Size=80 (0x50)
public:
	enum EInputPorts
	{
		EIP_Trigger = 0,
		EIP_Entity = 1,
		EIP_Automatic = 2,
	};

	enum EOutputPorts
	{
		EOP_IsInside = 0,
		EOP_Enter = 1,
		EOP_Leave = 2,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;
	bool m_bInside;

	virtual ~CFlowNode_CheckArea();
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	void ActivateOutputs() { FActivateOutputs(this); }
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlowNode_CheckArea(IFlowNode::SActivationInfo* _arg0_);
	void RegisterEvents();
	void UnregisterEvents();
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_CheckArea* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_CheckArea* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A0A80);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_CheckArea* const _this, SFlowNodeConfig& config)>(0x18A0AF0);
	static inline auto FActivateOutputs = PreyFunction<void(CFlowNode_CheckArea* const _this)>(0x18A1200);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x18A0F20);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_CheckArea* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A1010);
};
#endif // MOONCRASH
