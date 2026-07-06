// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcRecycleAttack
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcRecycleAttack.h
class ArkFlowNodeNpcRecycleAttack : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum INPUTS
	{
		eInputPort_Start = 0,
		eInputPort_Stop = 1,
	};

	enum OUTPUTS
	{
		eOutputPort_Out = 0,
	};

	bool m_bActive;

	virtual ~ArkFlowNodeNpcRecycleAttack();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(const IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* const _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* const _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* const _pActInfo, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* const _pActInfo);

#if 0
	ArkFlowNodeNpcRecycleAttack(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcRecycleAttack* const _this, SFlowNodeConfig& config)>(0x11E2B10);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcRecycleAttack* const _this, const IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* const _pActInfo)>(0x11E2DF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcRecycleAttack* const _this, ICrySizer* s)>(0x4BC120);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcRecycleAttack* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcRecycleAttack* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* const _pActInfo)>(0x11E2AC0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcRecycleAttack* const _this, IFlowNode::SActivationInfo* const _pActInfo, TSerialize ser)>(0x11E2EC0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcRecycleAttack* const _this, IFlowNode::SActivationInfo* const _pActInfo)>(0x11E2F10);
};
#endif // MOONCRASH
