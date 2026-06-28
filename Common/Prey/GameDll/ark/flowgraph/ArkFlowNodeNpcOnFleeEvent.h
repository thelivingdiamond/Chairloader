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

// ArkFlowNodeNpcOnFleeEvent
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcOnFleeEvent.h
class ArkFlowNodeNpcOnFleeEvent : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EInputPortIndex
	{
		npcEntityID = 0,
	};

	enum class EOutputPortIndex
	{
		failed = 0,
		onFleeStart = 1,
		onFleeEnd = 2,
	};

	IFlowNode::SActivationInfo m_prevActivationInfo;
	unsigned m_prevRegisteredEntityId;
	unsigned m_npcEntityId;

	virtual ~ArkFlowNodeNpcOnFleeEvent();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcOnFleeEvent(IFlowNode::SActivationInfo* _arg0_);
	void OnFleeStart();
	void OnFleeEnd();
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcOnFleeEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1246BB0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcOnFleeEvent* const _this, SFlowNodeConfig& config)>(0x1246C20);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcOnFleeEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1246EE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcOnFleeEvent* const _this, ICrySizer* s)>(0x35A360);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcOnFleeEvent* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcOnFleeEvent* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1247030);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcOnFleeEvent* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1246E80);
};
#endif // MOONCRASH
