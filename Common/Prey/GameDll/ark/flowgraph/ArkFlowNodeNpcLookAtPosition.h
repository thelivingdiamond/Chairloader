// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcLookAtPosition
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLookAtPosition.h
class ArkFlowNodeNpcLookAtPosition : public CFlowBaseNode<1>
{ // Size=240 (0xF0)
public:
	enum class EInputPortIndex
	{
		request = 0,
		lookAtPosition = 1,
		cancel = 2,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		canceled = 1,
		out = 2,
	};

	ArkNpcLookDesire m_lookDesire;

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcLookAtPosition(IFlowNode::SActivationInfo* _arg0_);
	bool ProcessRequest(IFlowNode::SActivationInfo* _arg0_);
	bool ProcessCancel(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLookAtPosition* const _this, SFlowNodeConfig& config)>(0x151DB50);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcLookAtPosition* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x151DF70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcLookAtPosition* const _this, ICrySizer* s)>(0x151E1A0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcLookAtPosition* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcLookAtPosition* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcLookAtPosition* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcLookAtPosition* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151E1C0);
};
#endif // MOONCRASH
